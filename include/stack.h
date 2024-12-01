#pragma once

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack
{
private:
    std::vector<T> data;
public:
    Stack() {}

    Stack(const Stack& other) {
        if (!other.empty()) {
            for (int i = 0; i < other.size(); i++) {
                data.push_back(other.data[i]);
            }
        }
    }

    Stack& operator=(const Stack& other) {
        data.clear();
        if (!other.empty()) {
            for (int i = 0; i < other.size(); i++) {
                data.push_back(other.data[i]);
            }
        }
        return *this;
    }

    Stack(Stack&& other) noexcept : data(std::move(other.data)) { }

    Stack& operator=(Stack&& other) noexcept {
        if (*this != other) {
            data = std::move(other.data);
        }
        return *this;
    }

    bool operator==(const Stack& other) {
        return data == other.data;
    }

    bool operator!=(const Stack& other) {
        return data != other.data;
    }
    bool empty() const {
        return data.empty();
    }
    size_t size() const {
        return data.size();
    }
    void push(T value) {
        data.push_back(value);
    }
    void pop() {
        if (empty()) { throw "incorectable operation"; }
        data.pop_back();
    }
    T& top() {
        if (empty()) { throw "incorectable operation"; }
        return data.back();
    }
    const T& top() const {
        if (empty()) { throw "incorectable operation"; }
        return data.back();
    }
    void clear() {
        data.clear();
    }
    void swap(Stack& other) noexcept {
        data.swap(other.data);
    }
    ~Stack() {
        data.clear();
    }
};



