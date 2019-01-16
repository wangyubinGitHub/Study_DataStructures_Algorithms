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

};

#endif /* statistics_h */
