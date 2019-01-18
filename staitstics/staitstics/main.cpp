//
//  main.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include <iostream>
#include "statistics.h"

#include "MusicTheory.h"

#include <assert.h>
#include <iomanip>

#include <sstream>
#include <cmath>

#include "SqliteUtils.h"
#include "TwoDynamicArray.hpp"

using namespace std;

double round(double number, unsigned int bits) {
    stringstream ss;
    ss << fixed << setprecision(bits) << number;
    ss >> number;
    return number;
}

void statisticsTest(){
    double data[] = { 53  ,  61  ,  49  ,  66  ,  78  , 47};
    
    double mean = Statistics::mean(data, 1, 6);
    std::cout << "mean=" << mean << std::endl;
    
    double variance = Statistics::variance(data, 1, 6);
    assert(variance == Statistics::variance(data, 1, 6, mean));
    std::cout << "variance=" << variance << std::endl;
    
    double sd = Statistics::sd(data, 1, 6);
    assert(sd == Statistics::sd(data, 1, 6, mean));
    assert(round(sd, 4) == 10.7548);
    std::cout << "sd=" << sd << std::endl;
    
    double kurtosis = Statistics::kurtosis(data, 1, 6);
    assert(round(kurtosis, 4) == 2.0526);
    std::cout << "kurtosis="<< kurtosis << std::endl;
    
    double skewness = Statistics::skewness(data, 1, 6);
    assert(round(skewness, 4) == 0.5716);
    std::cout << "skewness="<< skewness << std::endl;
    
    size_t index;
    double max = Statistics::max(data, 1, 6, index);
    assert(max == 78);
    assert(index == 4);
    cout << "max=" << max << endl;
    
    double min = Statistics::min(data, 1, 6, index);
    assert(min == 47);
    assert(index == 5);
    cout << "min=" << min << endl;
    
    
}

void musicTheoryTest(){
    assert(abs(69 - MusicTheory::freq_to_semitone(440)) < 1E-6);
    assert(abs(690.0 - MusicTheory::semitone_to_freq( MusicTheory::freq_to_semitone(690))) < 1E-6 );
}

void sqliteUtilsTest(){
//    SqliteUtils utils("ugc.db");
//    assert(utils.open() == 0);
//    assert(utils.createTable() == 0);
    
    const int rows = 100;
    const int cols = 10;
    TwoDynamicArray<double> arr(rows,cols);
    assert(arr.malloc() == 0);
    assert(arr.fillZeros()==0);
    arr.print();
    for (int i=0; i<arr.getRows(); i++) {
        for (int j=0; j<arr.getCols(); j++) {
            (arr.get())[i][j] = 1;
        }
    }
    arr.print();
    arr.free();
}

#include <fstream>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

//75hz <-> 38.3659
//1000hz <-> 83.2131
// 384 —— 832   //448
const int minFreq = 75;
const int maxFreq = 1000;
const int minBin = floor(MusicTheory::freq_to_semitone(minFreq)*10 + 0.5);//四舍五入
const int maxBin = floor(MusicTheory::freq_to_semitone(maxFreq)*10 + 0.5);//四舍五入
const int BinCount = maxBin - minBin + 1;

int parmsToFile(const char* filename ,std::ostream & out, double &sum){
    std::ifstream f(filename);
    if (!f.is_open()) {
        cout << "open file failed!" << endl;
        return -1;
    }
//    vector<float> time;
    vector<float> freq;
    vector<float> intensity;
    
    float tmp;
    while (!f.eof()) {
        f >> tmp;
//        time.push_back(tmp);
        f >> tmp;
        freq.push_back(tmp);
        f >> tmp;
        intensity.push_back(tmp);
    }
    
    //直方图
    double arr[BinCount];//计数
    double histogram[9];//中心点周围各s4个
    memset(arr, 0, BinCount*sizeof(double));
    
    for (int i=0; i<freq.size(); i++) {
        if (freq[i] == 0 || intensity[i] <= 0.9) {
            continue;
        }
        int cents10 = floor(MusicTheory::freq_to_semitone(freq[i])*10 + 0.5) - minBin;
        if (cents10 >= 0 /*&& cents10 < BinCount*/) {
            arr[cents10] += 1;
        }
    }
    double prisum = Statistics::sum(arr, 1, BinCount);

    if(sum == 0){
        sum = prisum;
    }else{
        if (prisum > sum) {//修正,如果自己的pitch数比基准还多，那就以自己的为准
            cout << "唱的太多了吧" << endl;
        }else{//如果自己的pitch数小于sum，那么就以基准的pitch数，做归一化分母
            prisum = sum;
        }
    }
    //归一化
    for (int i=0; i<BinCount; i++) {
        arr[i] = arr[i] / prisum;
    }
    size_t flag;
    double maxBin = Statistics::max(arr, 1, BinCount, flag);
//    cout << "maxBin" << maxBin << " flag=" << flag;
    for (int i=0; i<9; i++) {
        histogram[i] = arr[flag-4+i];
        cout << histogram[i] << endl;
    }
    
    double kurtosis = Statistics::kurtosis(histogram, 1, 9);
    double skewness = Statistics::skewness(histogram, 1, 9);
    
//    cout << kurtosis << endl;
//    cout << skewness << endl;
    path p(filename);
    out << p.stem() << "\t";
    out << kurtosis << "\t" << skewness <<"\t";
    for (int i=0; i<8; i++) {
        out << histogram[i] << "\t";
    }
    out << histogram[8] << "\t" << flag <<"\r\n";
    
    f.close();
    return 0;
}

int UgcTest(){
    // insert code here...
    //分析打分基准
    path b("/Users/wangyubin/MATLAB/noReferenceEnvaluate/humanPitch/test/sn.txt");
    
    //分析作品pitch
    path p("/Users/wangyubin/MATLAB/noReferenceEnvaluate/humanPitch/test1");
    if (!exists(p)) {
        cout << "is not exists: " << p << endl;
        return -1;
    }
    if (!is_directory(p)){
        cout << "is not directory: " << p << endl;
        return -1;
    }
    
    //遍历目录
    std::ofstream log("log.txt");
    if (!log.is_open()) {
        cout << "open failed!" << endl;
        return -1;
    }
    
    std::vector<path> v;
    v.push_back(b);
    for (auto&& x : directory_iterator(p))
        v.push_back(x.path());
    
    std::sort(v.begin()+1, v.end());
    double sum = 0;
    for (auto && x : v){
        if(is_regular(x) && x.extension() == ".txt"){
            cout << x.c_str() << endl;
            parmsToFile(x.c_str(), log, sum);
        }
        cout << x << endl;
//        break;
    }
    log.close();
    return 0;
}

int main(int argc, const char * argv[]) {
//    UgcTest();
    sqliteUtilsTest();
    return 0;
}
