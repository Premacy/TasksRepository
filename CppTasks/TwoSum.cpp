#include <iostream>
#include <vector>

/* TWO-SUM*/

// n * n,  O(n^2) - по сложности
void findTwoSum1( const std::vector<int> &arr, int x ){

    const size_t n = arr.size();
    int sum;
    int a, b;

    a = b = 0;
    sum = 0;

    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            sum = arr[i] + arr[j];
            if( sum == x ){
                a = arr[i];
                b = arr[j];

                std::cout << " a = " << a << " b  " << b << std::endl;
                return;
            }
        }
    }
}

// ( n * n ) / 2 , O(n ^ 2 ) - по сути та же сложность(асимптотически)
// но по факту операций меньше
void findTwoSum2( const std::vector<int> &arr, int x ){
    const size_t n = arr.size();
    int sum;
    int a, b;

    a = b = 0;
    sum = 0;

    for( int i = 0; i < n; i++ ){
        for( int j = i; j < n; j++ ){
            sum = arr[i] + arr[j];
            if( sum == x ){
                a = arr[i];
                b = arr[j];

                std::cout << " a = " << a << " b  " << b << std::endl;
                return;
            }
        }
    }
}

int main(){
    std::vector<int> test1 = { 1 ,2 ,3, 4, 5};
    std::vector<int> test2 = { 2, 4};

    findTwoSum1( test1, 5 );
    findTwoSum2( test2 , 6 );
    
    return 0;
}