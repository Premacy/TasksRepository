#include <iostream>

template< typename T > void debug( const T &v){
    std::cout << v << std::endl;
}

double myFabs( double x ){
    if( x > 0 ) return x;
    else        return -x;
}

double myPow( double x, int n ){
    double y(1.0);
    const int N = myFabs( n );

    if( n > 0 ){
        for( int i = 0; i < N; i++ ){
            y *= x;
        }
    }else if( n < 0 ){
        for( int i = 0; i < N; i++ ){
            y *= ( 1.0 / x );
        }
    }

    return y;
}

int main(void){

    debug( myPow( 2, 10 ) );
    debug( myPow( 2.1, 3 ) );
    debug( myPow( 2, -2 ) );

    return 0;
}