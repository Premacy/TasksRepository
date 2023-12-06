#include <iostream>
#include <vector>

/* упаковываем два вектора в один, чередуя элементы */
std::vector<int> zip( const std::vector<int> &a, const std::vector<int> &b ){
    const int n = a.size() + b.size();
    std::vector<int> result( n );

    size_t i, j, k;
    i = j = 0;
    k = 0;

    while( k < n ){
        if( k % 2 == 0 ){
            result[k] = a[i];
            i++;
        }else{
            result[k] = b[j];
            j++;
        }
        k = i + j;
    }

    return result;
}

void readVector( std::vector<int> &v ){
    const size_t n = v.size();

    for( int i = 0; i < n; i++ ){
        std::cin >> v[i];
    }
}

void printVector( const std::vector<int> &v ){
    for( int elem : v ){
        std::cout << elem;
    }
}

int main(){
    
    int n;
    std::cin >> n;

    std::vector<int> a( n );
    std::vector<int> b( n );

    readVector( a );
    readVector( b );

    printVector( zip( a, b ) );

    return 0;
}
