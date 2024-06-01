//Source.cpp;
//функции для нажатий кнопок и сортировок
//Ельнова Екатерина, группа 3091, 1 курс
//29.05.24-31.05.24

#include "MyForm.h"
#include "Stack.h"
#include <iostream>

const int nmax = 1000;
using namespace System;
using namespace System::Windows::Forms;

Stack<double> stack; //основной стэк

//добавление в стэк
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnPush_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        unsigned int varik = comboBox1->SelectedIndex;
        double temp;
        int tem;
        char ch;
        switch (varik) {
        case 0:
            tem = Convert::ToInt32(txtInput->Text);
            stack.push(tem);
            lstStack->Items->Add(tem);
            txtInput->Clear();
            break;
        case 1:
            temp = Convert::ToDouble(txtInput->Text);
            stack.push(temp);
            lstStack->Items->Add(temp);
            txtInput->Clear();
            break;
        case 2:
            ch = Convert::ToChar(txtInput->Text);
            stack.push(ch);
            lstStack->Items->Add(ch);
            txtInput->Clear();
            break;
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка ввода!");
    }
}

//прибавление к последнему элементу стэка значения определённого
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double result;
        double temp = 0;

        temp = Convert::ToDouble(txtInput->Text);
        result = stack.add(temp);
        stack.push(result);
        lstStack->Items->Add(result);
        
        txtInput->Clear();
    }
    catch (std::out_of_range& ex) {
        MessageBox::Show("Не к чему прибавлять! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка ввода!");
    }
}

//отнятие от последнего элемента стэка значения определённого
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnSubtract_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double result;
        double temp = 0;

        temp = Convert::ToDouble(txtInput->Text);
        result = stack.subtract(temp);
        stack.push(result);
        lstStack->Items->Add(result);

        txtInput->Clear();
    }
    catch (std::out_of_range& ex) {
        MessageBox::Show("Не от чего отнимать! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка ввода!");
    }
}

//умножение последнего элемента стэка на значение определённое
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnMultiply_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        double result;
        double temp = 0;

        temp = Convert::ToDouble(txtInput->Text);
        result = stack.multiply(temp);
        stack.push(result);
        lstStack->Items->Add(result);

        txtInput->Clear();
    }
    catch (std::out_of_range& ex) {
        MessageBox::Show("Нечего умножать! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка ввода в окно");
    }
}

//деление последнего элемента стэка на значение определённое
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnDivide_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        unsigned int varik = comboBox1->SelectedIndex;
        double result;
        double temp = 0;

        temp = Convert::ToDouble(txtInput->Text);
        result = stack.divide(temp);
        stack.push(result);
        lstStack->Items->Add(result);

        txtInput->Clear();
    }
    catch (std::out_of_range& ex) {
        MessageBox::Show("Нечего делить! :(");
    }
    catch (std::invalid_argument& ex) {
        MessageBox::Show("Делить на ноль нельзя... не будь глупи");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Ошибка ввода!");
    }
}

//удаление последнего элемента из стэка
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnPop_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (lstStack->Items->Count>0) {
            stack.pop();
            lstStack->Items->RemoveAt(lstStack->Items->Count - 1);
        }else
            MessageBox::Show("Не отнимай! и так ничего нет...");
    }
    catch (std::out_of_range&) {
        MessageBox::Show("Не отнимай! и так ничего нет...");
    }
}

//перенос элементов из массива в стэк
//массив и его размер(double ar[], int size)
//void
void PrintArr(double ar[], int size) {
    for (unsigned int j = 0; j < size; j++) {
        double temp = ar[j];
        stack.push(temp);
    }
}

//сортировка Выборкой
//массив и его размер(double ar[], int size)
//void
void selectionSort(double ar[], int size) {

    for (unsigned int i = 0; i < size - 1; i++) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < size; j++) {
            if (ar[j] < ar[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(ar[i], ar[minIndex]);
    }
    PrintArr(ar, size);
}

// Алгоритм простых вставок для сортировки массива
//массив и его размер(double ar[], int size)
//void
void insertionSort(double ar[], int size) {

    for (unsigned int i = 1; i < size; i++) {
        double temp = ar[i];
        unsigned int j = i - 1;
        while (j >= 0 && ar[j] > temp) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = temp;
    }
    PrintArr(ar, size);
}

//Пузырьковая сортировка
//массив и его размер(double ar[], int size)
//void
void BublSort(double ar[], int size) {
    unsigned int i = size - 1;
    bool flag = true;
    while (i >= 0 && flag) {
        flag = false;
        for (int j = 0; j < (size - 1); j++) {
            if (ar[j] > ar[j + 1]) {
                std::swap(ar[j], ar[j + 1]);
                flag = true;
            }
        }
        i--;
    }
    PrintArr(ar, size);
}

// Рекурсивная функция для быстрой сортировки (метод Хоара)
//массив, 0 и его размер-1 (double ar[], int left, int right)
//void
void quickSortRecursive(double ar[], int left, int right) {
    double mid = ar[(left + right) / 2];
    unsigned int i = left;
    unsigned int j = right;
    while (i <= j) {
        while (ar[i] < mid) {   //пока серединный элемент больше левого элемента
            i++;
        }
        while (ar[j] > mid) {  //пока серединный элемент меньше правого элемента
            j--;
        }

        //левый элемент больший среднего и правый элемент меньший среднего меняются местами, 
        // если индекс левого меньше индекса правого или равен ему
        if (i <= j) {
            std::swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSortRecursive(ar, left, j); //возврат к сортировки левой части массива (она также разбивается на левую и правую части)
    }
    if (i < right) {
        quickSortRecursive(ar, i, right); //возврат к сортировки правой части массива (она также разбивается на левую и правую части)
    }

}

// Функция Шейкер-сортировки
//массив и его размер(double ar[], int size)
//void
void shekerSort(double ar[], int size)
{
    unsigned int left = 0;
    unsigned int right = size - 1; // левая и правая границы сортируемой области массива
    bool flag = true;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag)
    {
        flag = false;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (ar[i] > ar[i + 1]) // если следующий элемент меньше текущего,
            {
                std::swap(ar[i], ar[i + 1]);// меняем их местами
                flag = true;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (ar[i - 1] > ar[i]) // если предыдущий элемент больше текущего,
            {
                std::swap(ar[i], ar[i - 1]);// меняем их местами
                flag = true;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
    PrintArr(ar, size);
}

//сортировка выбранным методом
//объекты графики (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnSort_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        lstStack->Items->Clear();
        unsigned int var = comboBox2->SelectedIndex;
        double ar[nmax];
        int i = 0;
        while (!stack.empty()) {
            ar[i] = stack.top(); stack.pop();
            i++;
        }
        switch (var) {
        case 0:
            selectionSort(ar, i);
            for (int y = 0; y < i; y++) {
                lstStack->Items->Add(ar[y]);
            }
            break;
        case 1:
            insertionSort(ar, i);
            for (int y = 0; y < i; y++) {
                lstStack->Items->Add(ar[y]);
            }
            break;
        case 2:
            BublSort(ar, i);
            for (int y = 0; y < i; y++) {
                lstStack->Items->Add(ar[y]);
            }
            break;
        case 3:
            quickSortRecursive(ar, 0, i - 1);
            PrintArr(ar, i);
            for (int y = 0; y < i; y++) {
                lstStack->Items->Add(ar[y]);
            }
            break;
        case 4:
            shekerSort(ar, i);
            
            for (int y = 0; y < i; y++) {
                lstStack->Items->Add(ar[y]);
            }
            break;
        default:
            MessageBox::Show("Выберите вариант сортировки!");
        }
    }
    catch (std::out_of_range&) {
        MessageBox::Show("Empty");
    }
}


