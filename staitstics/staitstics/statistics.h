//
//  statistics.h
//  statistics
//
//  Created by 王玉彬 on 2019/1/16.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#ifndef statistics_h
#define statistics_h

#include <iostream>

class Statistics {
    
public:

    static double variance(const double data[], const size_t stride, const size_t n);
    
    static double variance(const double data[], const size_t stride, const size_t n, const double mean);
    
    static double mean(const double data[], const size_t stride, const size_t n);
    
    static double sd(const double data[], const size_t stride, const size_t n);
    
    static double sd(const double data[], const size_t stride, const size_t n, const double mean);

    static double kurtosis(const double data[], const size_t stride, const size_t n);
    
    static double skewness(const double data[], const size_t stride, const size_t n);
    
    template <typename T>
    static T max(const T data[], const size_t stride, const size_t n, size_t &flag) {
        T max = data[0 * stride];
        flag = 0 * stride;
        
        for (int i=0; i<n; i++) {
            T xi = data[i * stride];
            
            if (xi > max) {
                max = xi;
                flag = i;
            }
        }
        return max;
    }
    
    template <typename T>
    static T min(const T data[], const size_t stride, const size_t n, size_t & flag){
        T min = data[0 * stride];
        flag = 0 * stride;
        
        for (int i=0; i<n; i++) {
            T xi = data[i * stride];
            
            if (xi < min) {
                min = xi;
                flag = i;
            }
        }
        return min;
    }
    
    template <typename T>
    static T sum(const T data[], const size_t stride, const size_t n){
        T sum = 0;
        for (int i=0; i<n; i++) {
            sum += data[i * stride];
        }
        return sum;
    }
};

#endif /* statistics_h */
