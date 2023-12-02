#include <iostream>
#include <string>
#include <vector>
#include <memory>

template< typename T> void debug( const T &val ){
    std::cout << val << std::endl;
}

/*Напишите функцию, которая обрезает пробелы в конце переданной ей строки.
 Функция должна быть написана в расчёте на работу с очень длинными строками 
 с очень большим количеством пробелов, 
оптимизирована по количеству обращений к памяти. Сигнатура:*/

inline bool isEndOfString( char c ){
    return c == '\0';
}

inline bool isSpace( char c ){
    return c == ' ';
}

// а если пробелов вообще не было
// а если только пробелы
// а если пустая строка
// один пробел в конце

 void TrimRight( char *s ){
    bool inSpaces;
    char currentSymb;

    int inSpacesStart;
    int i;

    i = 0;
    inSpacesStart = 0;
    inSpaces = false;
    
    // алгоритм делает один проход по строке
    // сложность O(n) 
    while( !isEndOfString( s[i] ) ){
        currentSymb = s[i];

        if( isSpace( currentSymb ) && !inSpaces ){  // если зашли в область с пробелами
            inSpacesStart = i;
            inSpaces = true;
        }
        else if( !isSpace( currentSymb ) ){         // если вышли из области с пробелами
            inSpaces = false;   
        }

        i++;
    }

    if( inSpaces ) {    // если пробелы вообще были( как то можно это более элегантно обойти)
        s[ inSpacesStart ] = '\0';  // передвинули символ конца строки на начало области с пробелами
    }
 }

/*********** ТЕСТЫ *************/
/*
class BaseTests{
public:
    virtual void runTests() = 0;
};

// тесты
class TrimRightTests : public BaseTests{
private:

    TrimRightTests();   // делаем конструктор приватным 

public:

    void runTests(){
        if( !test1() ){
            debug( "test1 - false ");
        }
    }

    bool test1(){
        std::string str = "Hello, world! ";
        std::string rightResult = "Hello, world!";
        std::string result = std::string( TrimRight( const_cast< char* > ( str.c_str() ) ) );

        return rightResult == std::string( TrimRight( const_cast< char* > ( str.c_str() ) ) );
    }

    static BaseTests *Create(){     // фабрика
        return new TrimRightTests;
    }
};

//typedef std::shared_ptr<BaseTests> pBaseTests;

class TestManager{
public:

    void registerTest( BaseTests *test){
        tests.push_back( test );
    }

    void run(){
        for( const auto &test : tests ){
            test->runTests();
        }
    }

private:

    std::vector< BaseTests* > tests;
};
*/

int main(){
    
    /*TestManager tManager;
    tManager.registerTest( TrimRightTests::Create() );  // регестрируем тесты

    tManager.run(); // запускаем наши тесты */

    char t[256] = "Hello, world ";
    TrimRight( t );

    std::cout << t << std::endl;

    return 0;
}