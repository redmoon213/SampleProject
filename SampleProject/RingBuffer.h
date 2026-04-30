#pragma once
#include <iostream>
#include <ostream>
#include <vector>

//고정 크기 배열 + head 인덱스로 순환 저장
//꽉 차면 가장 오래된 항목을 덮어쓰도록 구성
//전투 로그에 사용
template <typename T>
class RingBuffer
{
private:
    std::vector<T> data;    // 고정 크기 배열 (capacity 만큼 미리 확보)
    int capacity;           //최대 저장 가능 항목 수
    int head;               //다음 위치 지정하는 순환 인덱스
    int count;              //현재 저장된 항목 수 
    
public:
    RingBuffer(int capacity)
    : data(capacity), capacity(capacity), head(0), count(0){}
    
    void push(const T& value)
    {
        data[head] = value;
        head = (head + 1) % capacity;
        if (count < capacity) count++;
    }
    
    void printAll() const
    {
        int start = (count < capacity) ? 0 : head; //가장 오래된 항목 위치
        for (int i =0; i<count; i++)
        {
            int index = (start + i) % capacity;
            std::cout << data[index] << std::endl;
        }
    }
    
    int size() const {return count;}
    int empty() const {return count == 0;}
};
