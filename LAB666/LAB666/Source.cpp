//Source.cpp;
//ôóíêöèè äëÿ íàæàòèé êíîïîê è ñîðòèðîâîê
//Åëüíîâà Åêàòåðèíà, ãðóïïà 3091, 1 êóðñ
//29.05.24-31.05.24

#include "MyForm.h"
#include "Stack.h"
#include <iostream>

const int nmax = 1000;
using namespace System;
using namespace System::Windows::Forms;

Stack<double> stack; //îñíîâíîé ñòýê

//äîáàâëåíèå â ñòýê
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
        MessageBox::Show("Îøèáêà ââîäà!");
    }
}

//ïðèáàâëåíèå ê ïîñëåäíåìó ýëåìåíòó ñòýêà çíà÷åíèÿ îïðåäåë¸ííîãî
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
        MessageBox::Show("Íå ê ÷åìó ïðèáàâëÿòü! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Îøèáêà ââîäà!");
    }
}

//îòíÿòèå îò ïîñëåäíåãî ýëåìåíòà ñòýêà çíà÷åíèÿ îïðåäåë¸ííîãî
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
        MessageBox::Show("Íå îò ÷åãî îòíèìàòü! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Îøèáêà ââîäà!");
    }
}

//óìíîæåíèå ïîñëåäíåãî ýëåìåíòà ñòýêà íà çíà÷åíèå îïðåäåë¸ííîå
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
        MessageBox::Show("Íå÷åãî óìíîæàòü! :(");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Îøèáêà ââîäà â îêíî");
    }
}

//äåëåíèå ïîñëåäíåãî ýëåìåíòà ñòýêà íà çíà÷åíèå îïðåäåë¸ííîå
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
        MessageBox::Show("Íå÷åãî äåëèòü! :(");
    }
    catch (std::invalid_argument& ex) {
        MessageBox::Show("Äåëèòü íà íîëü íåëüçÿ... íå áóäü ãëóïè");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Îøèáêà ââîäà!");
    }
}

//óäàëåíèå ïîñëåäíåãî ýëåìåíòà èç ñòýêà
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
//void
void LAB666::MyForm::btnPop_Click(System::Object^ sender, System::EventArgs^ e) {
    try {
        if (lstStack->Items->Count>0) {
            stack.pop();
            lstStack->Items->RemoveAt(lstStack->Items->Count - 1);
        }else
            MessageBox::Show("Íå îòíèìàé! è òàê íè÷åãî íåò...");
    }
    catch (std::out_of_range&) {
        MessageBox::Show("Íå îòíèìàé! è òàê íè÷åãî íåò...");
    }
}

//ïåðåíîñ ýëåìåíòîâ èç ìàññèâà â ñòýê
//ìàññèâ è åãî ðàçìåð(double ar[], int size)
//void
void PrintArr(double ar[], int size) {
    for (unsigned int j = 0; j < size; j++) {
        double temp = ar[j];
        stack.push(temp);
    }
}

//ñîðòèðîâêà Âûáîðêîé
//ìàññèâ è åãî ðàçìåð(double ar[], int size)
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

// Àëãîðèòì ïðîñòûõ âñòàâîê äëÿ ñîðòèðîâêè ìàññèâà
//ìàññèâ è åãî ðàçìåð(double ar[], int size)
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

//Ïóçûðüêîâàÿ ñîðòèðîâêà
//ìàññèâ è åãî ðàçìåð(double ar[], int size)
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

// Ðåêóðñèâíàÿ ôóíêöèÿ äëÿ áûñòðîé ñîðòèðîâêè (ìåòîä Õîàðà)
//ìàññèâ, 0 è åãî ðàçìåð-1 (double ar[], int left, int right)
//void
void quickSortRecursive(double ar[], int left, int right) {
    double mid = ar[(left + right) / 2];
    unsigned int i = left;
    unsigned int j = right;
    while (i <= j) {
        while (ar[i] < mid) {   //ïîêà ñåðåäèííûé ýëåìåíò áîëüøå ëåâîãî ýëåìåíòà
            i++;
        }
        while (ar[j] > mid) {  //ïîêà ñåðåäèííûé ýëåìåíò ìåíüøå ïðàâîãî ýëåìåíòà
            j--;
        }

        //ëåâûé ýëåìåíò áîëüøèé ñðåäíåãî è ïðàâûé ýëåìåíò ìåíüøèé ñðåäíåãî ìåíÿþòñÿ ìåñòàìè, 
        // åñëè èíäåêñ ëåâîãî ìåíüøå èíäåêñà ïðàâîãî èëè ðàâåí åìó
        if (i <= j) {
            std::swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSortRecursive(ar, left, j); //âîçâðàò ê ñîðòèðîâêè ëåâîé ÷àñòè ìàññèâà (îíà òàêæå ðàçáèâàåòñÿ íà ëåâóþ è ïðàâóþ ÷àñòè)
    }
    if (i < right) {
        quickSortRecursive(ar, i, right); //âîçâðàò ê ñîðòèðîâêè ïðàâîé ÷àñòè ìàññèâà (îíà òàêæå ðàçáèâàåòñÿ íà ëåâóþ è ïðàâóþ ÷àñòè)
    }

}

// Ôóíêöèÿ Øåéêåð-ñîðòèðîâêè
//ìàññèâ è åãî ðàçìåð(double ar[], int size)
//void
void shekerSort(double ar[], int size)
{
    unsigned int left = 0;
    unsigned int right = size - 1; // ëåâàÿ è ïðàâàÿ ãðàíèöû ñîðòèðóåìîé îáëàñòè ìàññèâà
    bool flag = true;  // ôëàã íàëè÷èÿ ïåðåìåùåíèé
    // Âûïîëíåíèå öèêëà ïîêà ëåâàÿ ãðàíèöà íå ñîìêí¸òñÿ ñ ïðàâîé
    // è ïîêà â ìàññèâå èìåþòñÿ ïåðåìåùåíèÿ
    while ((left < right) && flag)
    {
        flag = false;
        for (int i = left; i < right; i++)  //äâèãàåìñÿ ñëåâà íàïðàâî
        {
            if (ar[i] > ar[i + 1]) // åñëè ñëåäóþùèé ýëåìåíò ìåíüøå òåêóùåãî,
            {
                std::swap(ar[i], ar[i + 1]);// ìåíÿåì èõ ìåñòàìè
                flag = true;      // ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
            }
        }
        right--; // ñäâèãàåì ïðàâóþ ãðàíèöó íà ïðåäûäóùèé ýëåìåíò
        for (int i = right; i > left; i--)  //äâèãàåìñÿ ñïðàâà íàëåâî
        {
            if (ar[i - 1] > ar[i]) // åñëè ïðåäûäóùèé ýëåìåíò áîëüøå òåêóùåãî,
            {
                std::swap(ar[i], ar[i - 1]);// ìåíÿåì èõ ìåñòàìè
                flag = true;    // ïåðåìåùåíèÿ â ýòîì öèêëå áûëè
            }
        }
        left++; // ñäâèãàåì ëåâóþ ãðàíèöó íà ñëåäóþùèé ýëåìåíò
    }
    PrintArr(ar, size);
}

//ñîðòèðîâêà âûáðàííûì ìåòîäîì
//îáúåêòû ãðàôèêè (System::Object^ sender, System::EventArgs^ e)
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
            MessageBox::Show("Âûáåðèòå âàðèàíò ñîðòèðîâêè!");
        }
    }
    catch (std::out_of_range&) {
        MessageBox::Show("Empty");
    }
}


