//
//  utils_test.cpp
//  staitstics
//
//  Created by 王玉彬 on 2019/1/18.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#include <stdio.h>
#include "SqliteUtils.h"
#include "TwoDynamicArray.hpp"

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
