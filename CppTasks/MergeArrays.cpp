#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename Itr> void printContainer(Itr begin, Itr end){
    for(auto itr = begin; itr != end; ++itr){
        std::cout << (*itr) << std::endl;
    }
}

// два вектора
std::vector<int> mergeTwoArrays(const std::vector<int> &v1, const std::vector<int> &v2){
    std::vector<int> res;
    res.resize(v1.size() + v2.size() );

    std::copy(v1.begin(), v1.end(), res.begin() );
    std::copy(v2.begin(), v2.end(), res.begin() + v1.size() );

    return res;
}

std::size_t getSumOvSizes(const std::vector< std::vector<int> > &vectors){
    auto accumulateFunc = [](std::size_t v_size, const std::vector<int> &vec){
        return v_size + vec.size();
    };
    return std::accumulate(vectors.begin(), vectors.end(), 0, accumulateFunc);
}

// несколько векторов
std::vector<int> mergeArrays(const std::vector< std::vector<int> > &vectors ){
    std::vector<int> res;
    res.resize( getSumOvSizes(vectors) );

    auto currItr = res.begin();
    for(const auto &vector : vectors){
        std::copy(vector.begin(), vector.end(), currItr);
        currItr = currItr + vector.size();
    }

    return res;
}

// Более обобщенный вариант

int main(){
    std::vector<int> v1{4,5,6,7,8};
    std::vector<int> v2{3,2,1,2,32,1};
    std::vector<int> v3{10,10,10};

    auto result = mergeArrays( std::vector< std::vector<int> >{v1, v2, v3} );
    printContainer(result.begin(), result.end());

    return 0;
}
