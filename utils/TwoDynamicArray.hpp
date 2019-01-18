//
//  TwoDynamicArray.h
//  staitstics
//
//  Created by 王玉彬 on 2019/1/18.
//  Copyright © 2019 王玉彬. All rights reserved.
//

#ifndef TwoDynamicArray_h
#define TwoDynamicArray_h

#include <iostream>

template <class T>
class TwoDynamicArray {
    T **arr;
    const size_t rows;
    const size_t cols;
public:
    TwoDynamicArray(size_t rows, size_t cols):rows(rows),cols(cols),arr(nullptr){}
    
    bool checkAvail(){
        if (rows <= 0 && cols <= 0) {
            return false;
        }
        if (arr == nullptr) {
            return false;
        }
        for (int i=0; i<rows; i++) {
            if(arr[i] == nullptr){
                return false;
            }
        }
        return true;
    }
    
    T** get(){
        return arr;
    }
    
    size_t getRows(){
        return rows;
    }
    
    size_t getCols(){
        return cols;
    }
    
    int fillZeros(){
        if(checkAvail()){
            for (int  i=0; i<rows; i++) {
                memset(arr[i],0,cols*sizeof(T));
            }
            return 0;
        }
        return -1;
    }
    
    int malloc(){
        arr = new T* [rows];
        if (arr == NULL) {
//            cout << "malloc failed!"<<endl;
            return -1;
        }
        int err = 0;
        //arr != 0
        for (int i=0; i<rows; i++) {
            arr[i] = new T[cols];
            if (arr[i] == NULL) {
//                cout <<"malloc failed!\n";
                err = -1;
                break;
            }
        }
        if(err == -1){
            for (int i=0; i<rows; i++) {
                if(arr[i] != nullptr){
                    delete [] arr[i];
                }
            }
            delete [] arr;
        }
        return err;
    }
    
    void free(){
        if (arr != nullptr) {
            for (int i=1; i<rows; i++) {
                if (arr[i] != nullptr) {
                    delete [] arr[i];
                }
            }
            delete [] arr;
            arr = nullptr;
        }
    }
    
    void print(){
        if( checkAvail()){
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++) {
                    std::cout << arr[i][j] << ",";
                }
                std::cout << std::endl;
            }
        }
    }
    
    ~TwoDynamicArray(){
        free();
    }
};

#endif /* TwoDynamicArray_h */
