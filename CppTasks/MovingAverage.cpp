#include <iostream>
#include <vector>

/*Вам дана статистика по числу запросов в секунду к вашему любимому 
рекомендательному сервису.
Измерения велись n секунд.
В секунду i поступает qi запросов.
Примените метод скользящего среднего с длиной окна k к этим данным и 
выведите результат.*/

struct statistic_data_t{
    size_t size;
    size_t smoth_window_size;

    std::vector<int> data;

    int operator[]( size_t i ) const { return data[i]; }
    int& operator[]( size_t i ) { return data[i]; }
};

// читаем статистику с консоли
void readStatistic( statistic_data_t &stat ){
    std::cin >> stat.size;
    stat.data.resize( stat.size );

    for( size_t i = 0; i < stat.size; i++ ){
        std::cin >> stat[i];
    }

    std::cin >> stat.smoth_window_size;
}

// считаем скользящее среднее
void getSmoothMidle( const statistic_data_t &stat, 
                     std::vector<double>  &result){
    
    const size_t smth_window_sz = stat.smoth_window_size;
    const size_t stat_size      = stat.size;
    
    double first_sum = 0;

    for( size_t i = 0; i < smth_window_sz; i ++ ){
        first_sum += stat[i];
    }

    size_t begin_index, end_index;
    int num;
    double currValue;

    begin_index = 0;
    end_index = smth_window_sz - 1;
    num = smth_window_sz;

    currValue = first_sum / num;

    while( end_index < stat_size ){
        result.push_back( currValue );

        first_sum -= stat[ begin_index ];
        end_index++;
        first_sum += stat[ end_index ];
        begin_index++;

        currValue = first_sum / num;
    }
}

// выводим веткор
template<typename T>
void printVector( const std::vector<T> &vec ){
    for( const auto & elem : vec ){
        std::cout << elem << std::endl;
    }
}

int main() {
    
    statistic_data_t data;
    std::vector<double> result;

    readStatistic( data );
    getSmoothMidle( data, result );

    printVector( result );

    return 0;
}