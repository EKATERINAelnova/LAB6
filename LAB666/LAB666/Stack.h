//Stack.h
//����� �����
//������� ���������, ������ 3091, 1 ����
//29.05.24-31.05.24
#pragma once
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    //���������� � ����
    //T const& elem
    //void
    void Stack<T>::push(T const& elem) {
        elements.push_back(elem);
    }

    //�������� �������� �� �����
    //
    //void
    void Stack<T>::pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elements.pop_back();
    }

    //������ �������� �� �����
    //
    //T
    T Stack<T>::top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
            MessageBox::Show("���� ����!");
        }
        return elements.back();
    }

    //����������� � ���������� �������� ����� �������� ������������
    //
    //bool
    bool Stack<T>::empty() const {
        return elements.empty();
    }

    //����������� � ���������� �������� ����� �������� ������������
    //�������� ��� �������� (T b)
    //T
    T Stack<T>::add(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("�� � ���� ����������!:)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a + b;
        elements.push_back(result);
        return result;
    }

    //������� �� ���������� �������� ����� �������� ������������
    //�������� ��� ������� (T b)
    //T
    T Stack<T>::subtract(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("�� �� ���� ��������! :)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a - b;
        elements.push_back(result);
        return result;
    }

    //��������� ���������� �������� ����� �� �������� �����������
    //�������� ��� ��������� (T b)
    //T
    T Stack<T>::multiply(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("������ ��������! :)");
        }
        T a = elements.back(); elements.pop_back();
        T result = a * b;
        elements.push_back(result);
        return result;
    }

    //������� ���������� �������� ����� �� �������� �����������
    //�������� ��� ������� (T b)
    //T
    T Stack<T>::divide(T b) {
        if (elements.size() < 1) {
            throw std::out_of_range("������ ������! :)");
        }
        T a = elements.back(); elements.pop_back();
        if (b == 0) {
            throw std::invalid_argument("�� �����, �� ���� ������ ������!");
        }
        T result = a / b;
        elements.push_back(result);
        return result;
    }
};

