#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <iostream>
#include <string>
#include <locale.h>

#define TEST_LOG(TEST_NAME, X) std::cout << TEST_NAME << ": " << X << std::endl;

template<typename ValueType, 
         typename Func,
         typename ...Argc>
void test(ValueType rightValue, Func func, std::string test_name, Argc... argc){
    static std::size_t  testCase = 0;
    testCase++;

    ValueType testValue = func(std::forward<Argc>(argc)...);

    if(testValue == rightValue){
      TEST_LOG("TEST " + std::to_string(testCase) +  " PASSED", test_name);
    }else{
      TEST_LOG("TEST " + std::to_string(testCase) +  " FAILED", test_name);
    }
}

bool check_boxes(int box1[3], int box2[3]){
  return true;
}

void testCasesBox(){
  // test case 1
  {
    int box1[3] = {1, 1, 1};
    int box2[3] = {1, 1, 1};

    test(true, check_boxes, "Same boxes", box1, box2);
  }

    // test case 2
  {
    int box1[3] = {1, 2, 3};
    int box2[3] = {1, 1, 1};

    test(true, check_boxes, "First > second", box1, box2);
  }

    // test case 3
  {
    int box1[3] = {1, 1, 1};
    int box2[3] = {2, 1, 1};

    test(false, check_boxes, "First < second", box1, box2);
  }
}

int main(){
    setlocale(LC_ALL, "Russian");
  // int box1[N] = {3, 5, 1};
  // int box2[N] = {4, 2, 1};

  // if(box1[0] > box1[1] && box1[0] > box1[2]) {
  //   if(box1[1] < box1[2]){
  //     // swap
  //   }
  // }else if(box1[1] > box1[0] && box1[1] > box1[2]) {
  //   //swap
  //   if(box1[1] > box1[2]){
  //     //swap
  //   }

  testCasesBox();
    
  return 0;
}

void BubleSort(int array[], int N){
  int temp;
    for(int i = 0; i < N; i++){
      for(int j = i; j < N; j++){
        if(array[i] < array[j]){
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
      }
  }
}
// g++ -std=c++17 -O2 -pthread main.cpp
// g++ -std=c++17 -O2 -pthread -fsanitize=thread main.cpp