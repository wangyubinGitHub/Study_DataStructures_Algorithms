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

using namespace std;

double round(double number, unsigned int bits) {
    stringstream ss;
    ss << fixed << setprecision(bits) << number;
    ss >> number;
    return number;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
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
    
    assert(abs(69 - MusicTheory::freq_to_semitone(440)) < 1E-6);
    assert(abs(690.0 - MusicTheory::semitone_to_freq( MusicTheory::freq_to_semitone(690))) < 1E-6 );
    
    return 0;
}
