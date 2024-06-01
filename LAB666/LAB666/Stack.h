//Stack.h
//класс стэка
//Ельнова Екатерина, группа 3091, 1 курс
//29.05.24-31.05.24
#pragma once
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    //добавление в стэк
    //T const& elem
    //void
    void Stack<T>::push(T const& elem) {
        elements.push_back(elem);
    }

    //удаление элемента из стэка
    //
    //void
    void Stack<T>::pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elements.pop_back();
    }

    //взятие элемента из стэка
    //
    //T
    T Stack<T>::top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
            MessageBox::Show("Стэк пуст!");
        }
        return elements.back();
    }

    //прибавление к последнему элементу стэка значения определённого
    //
    //bool
    bool Stack<T>::empty() const {
        return elements.empty();
    }

    //прибавление к последнему элементу стэка значения определённого
    //значение для прибавки (T b)
    //T
    T Stack<T>::add(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("Не к чему прибавлять!:)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a + b;
        elements.push_back(result);
        return result;
    }

    //отнятие от последнего элемента стэка значения определённого
    //значение для отнятия (T b)
    //T
    T Stack<T>::subtract(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("Не от чего отнимать! :)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a - b;
        elements.push_back(result);
        return result;
    }

    //умножение последнего элемента стэка на значение определённое
    //значение для умножения (T b)
    //T
    T Stack<T>::multiply(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("Нечего умножать! :)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a * b;
        elements.push_back(result);
        return result;
    }

    //деление последнего элемента стэка на значение определённое
    //значение для деления (T b)
    //T
    T Stack<T>::divide(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("Нечего делить! :)");
        }
        T a = elements.back(); elements.pop_back();
        if (b == 0) {
            throw std::invalid_argument("Не глупи, на ноль делить нельзя!");
        }
        T result = a / b;
        elements.push_back(result);
        return result;
    }
};

