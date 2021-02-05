// lab17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
using namespace std;

int* fastsort(int* num, int l, int r)
{
    int p;
    int lh = l;
    int rh = r;
    p = num[l];
    while (l < r)
    {
        while ((num[r] >= p) && (l < r))
        {
            r--;
        }
        if (l != r)
        {
            num[l] = num[r];
            l++;
        }
        while ((num[l] <= p) && (l < r))
        {
            l++;
        }
        if (l != r)
        {
            num[r] = num[l];
            r--;
        }
    }
    num[l] = p;
    p = l;
    l = lh;
    r = rh;
    if (l < p)
        fastsort(num, l, p - 1);
    if (r > p)
        fastsort(num, p + 1, r);
    return num;
}

int* podschet(int* a, int k)
{
    int c[1001];
    for (int i = 0; i < 1001; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < k; i++)
    {
        c[a[i]] = c[a[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < 1001; j++) {
        while (c[j] != 0)
        {
            a[i] = j;
            c[j]--;
            i++;
        }
    }
    return a;
}

int main()
{
    setlocale(LC_ALL, "rus");
    bool v = false;
    int* res;
    int n, m;
    int A[256];
    ifstream t("input.txt");
    {
        if (t.is_open())
        {
            n = 0;
            while (!t.eof())
            {
                t >> m;
                n++;
            }
            t.seekg(0, ios::beg);
            t.clear();
            cout << "Начальное множество чисел из файла:" << '\n';
            for (int i = 0; i < n; i++)
            {
                t >> A[i];
                cout << A[i] << " ";
            }
            t.close();
        }
        else
        {
            cout << "Файл не найден, использовано резервное множество." << '\n';
            A[0] = 12;
            A[1] = 34;
            A[2] = 35;
            A[3] = 41;
            A[4] = 43;
            A[5] = 51;
            A[6] = 52;
            A[7] = 73;
            A[8] = 88;
            A[9] = 93;
            n = 10;
            for (int i = 0; i < n; i++)
            {
                cout << A[i] << " ";
            }
        }
    }
    cout << '\n' << "Выберите метод сортировки:" << '\n' << "1-быстрая"<< '\n' << "2-подсчетом" << '\n';
    while (v == false)
    {
        cin >> m;
        if ((m == 1) || (m == 2))
        {
            v = true;
        }
        else
        {
            cout << "Вы ввели неправильное значение. Введите еще раз." << '\n';
        }
    }
    if (m == 1)
    {
        cout << "Выбрана быстрая сортировка." << '\n';
        res = fastsort(A, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
    }
    else if (m == 2)
    {
        cout << "Выбрана сортировка подсчетом." << '\n';
        res = podschet(A, n);
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
    }
}