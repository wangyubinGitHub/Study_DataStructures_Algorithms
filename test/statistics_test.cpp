//
//  statistics.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/18.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "statistics.h"
#include <assert.h>
#include <sstream>
#include <iomanip>

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
