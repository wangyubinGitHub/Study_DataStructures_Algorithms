//
//  statistics.cpp
//  statistics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include "statistics.h"
#include <cmath>

double Statistics::variance(const double data[], const size_t stride, const size_t n) {
    double mean = Statistics::mean(data, stride, n);
    return Statistics::variance(data, stride, n, mean);
}


double Statistics::variance(const double data[], const size_t stride, const size_t n, const double mean) { 
    long double variance = 0;
    
    for (int i=0; i<n; i++) {
        const long double delta = (data[i * stride] - mean);
        variance += (delta * delta - variance) / (i+1);
    }
    return variance;
}


double Statistics::mean(const double data[], const size_t stride, const size_t n) {
    long double mean = 0;
    for (int i=0; i<n; i++) {
        mean += (data[i * stride] - mean) / (i+1);
    }
    return mean;
}

double Statistics::sd(const double data[], const size_t stride, const size_t n) { 
    const double variance = Statistics::variance(data, stride, n);
    const double sd = sqrt (variance);
    return sd;
}

double Statistics::sd(const double data[], const size_t stride, const size_t n, const double mean) { 
    const double variance = Statistics::variance(data, stride, n, mean);
    const double sd = sqrt(variance);
    return sd;
}

double Statistics::kurtosis(const double data[], const size_t stride, const size_t n) {
    long double kurtosis = 0;
    const double mean = Statistics::mean(data, stride, n);
    const double sd = Statistics::sd(data, stride, n, mean);
    for (int i=0; i<n; i++) {
        const long double x = (data[i * stride] - mean ) / sd;
        kurtosis += ( x * x * x * x - kurtosis) / (i+1);//4
    }
    return kurtosis;
}

double Statistics::skewness(const double data[], const size_t stride, const size_t n) { 
    long double skewness = 0;
    const double mean = Statistics::mean(data, stride, n);
    const double sd = Statistics::sd(data, stride, n, mean);
    for (int i=0; i<n; i++) {
        const long double x = (data[i * stride] - mean ) / sd;
        skewness += ( x * x * x - skewness) / (i+1);//3
    }
    return skewness;
}






