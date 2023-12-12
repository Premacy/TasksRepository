#include <vector>
#include <iostream>

std::pair<size_t, size_t> MatrixArgMax(const std::vector< std::vector<int> >& matrix){
    int max = matrix[0][0];
    std::pair<size_t, size_t> result;
    
    result.first = 0;
    result.second = 0;

    if(matrix.size() == 1){
        for(size_t i = 0; i < matrix[0].size(); i++){
            if( matrix[0][i] > max){
                result.second = i;
                max = matrix[0][i];
            }
        }
        return result;
    }

    for(size_t i = 0; i < matrix.size(); i++){
        for(size_t j = 0; j < matrix[0].size(); j++){
            if( matrix[i][j] > max ){
                result.first = i;
                result.second = j;
                
                max = matrix[i][j];
            }
        }
    }

    return result;
}