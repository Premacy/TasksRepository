#include <iostream>
#include <vector>
#include <map>
#include <string>


void filterString(std::string &str, const std::string_view &filter){
    for(auto filterChar : filter){
        str.erase( std::remove(str.begin() + 1, str.end(), filterChar), str.end() );
    }
}

void fillZeros(std::string &str){
    std::size_t i = str.size();
    while(i < 4){
        str.push_back('0');
        i++;
    }
}

void deleteRepeats(std::string &str){
        // Убрали повторы
    auto itr = str.begin() + 1;
    while(itr != str.end()){
        if( *(itr) == *(itr + 1) ){
            str.erase(itr + 1);
            continue;
        }
        ++itr;
    }
}

std::string Soundex(std::string str){
    // фильтрую
    std::string filter = "aehiouwy";
    filterString(str, filter);

    // через чур хитро но как тренировка пойдет
    std::map<int, std::string> m = {
        {1, "bfpv"},
        {2, "cgjkqsxz"},
        {3, "dt"},
        {4, "l"},
        {5, "m,n"},
        {6, "r"}
    };

    for(char &ch : str){
        for(auto [key, value] : m){
            auto itr = std::find(value.begin(), value.end(), ch);
            if( itr != value.end() ){
               ch = static_cast<char>(std::to_string(key)[0]);
               break;
            }
        }
    }

    deleteRepeats(str);

    if(str.size() < 4){
        fillZeros(str);
    }else{
        str.erase(str.begin() + 4, str.end() );
    }
    
    return str;
}

int main(){

    std::string str;

    std::getline(std::cin, str);
    auto resultStr = Soundex(str);

    std::cout << resultStr << std::endl;

    return 0;
}   
