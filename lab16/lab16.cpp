// lab16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>

int BMura(std::string st, std::string ct)
{
    int stl, ctl, r = -1;
    stl = st.size();
    ctl = ct.size();
    if (stl != 0 && ctl != 0)
    {
        int i, p;
        int b[256];
        for (i = 0; i < 256; i++)
        {
            b[i] = ctl;
        }
        for (i = ctl - 2; i >= 0; i--)
        {
            if (b[int((unsigned char)ct[i])] == ctl)
            {
                b[int((unsigned char)ct[i])] = ctl - i - 1;
            }
        }
        p = ctl - 1;
        while (p < stl)
        {
            if (ct[ctl - 1] != st[p])
            {
                p += b[int((unsigned char)st[p])];
            }
            else
            {
                for (i = ctl - 1; i >= 0; i--)
                {
                    if (ct[i] != st[p - ctl + i + 1])
                    {
                        p += b[int((unsigned char)st[p - ctl + i + 1])];
                        break;
                    }
                    else if (i == 0)
                    {
                        return p - ctl + 1;
                    }
                }
            }
        }
    }
}

int interpol(int* ar, int size, int k)
{
    int l = 0;
    int r = size - 1;
    int m = 0;
    bool f = false;
    if (k<ar[l] || k>ar[r])
    {
        return -1;
    }
    else
    {
        if (ar[l] == k)
        {
            return l;
        }
        else if (ar[r] == k)
        {
            return r;
        }
        while ((l <= r) && (f != true) && (m >= l) && (m <= r))
        {
            m = l + (((k - ar[l]) * (r - l)) / (ar[r] - ar[l]));
            if (ar[m] < k)
            {
                l = m + 1;
            }
            else if (ar[m] > k)
            {
                r = m + 1;
            }
            else
            {
                f = true;
            }
        }
        if (ar[m] == k)
        {
            return m;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int res;
    int A[10];
    int chr;
    int n = 10;
    std::string text("My name is Dima.");
    std::string ctr;
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
    std::cout << "Дан текст: ";
    std::cout << text<<std::endl;
    std::cout << "Введите слово для поиска: ";
    std::getline(std::cin, ctr);
    res = BMura(text, ctr);
    if (res >= 0 && res <= text.size())
    {
        std::cout << "Результат поиска: " << res << std::endl;
    }
    else
    {
        std::cout << "Результат поиска: такое слово отсутствует" << std::endl;
    }
    std::cout << "Дано множество:"<<std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Введите число для поиска: ";
    std::cin >> chr;
    res = interpol(A, n, chr);
    if (res >= 0)
    {
        std::cout << "Результат поиска: Число с порядковым номером " << res + 1 << std::endl;
    }
    else
    {
        std::cout << "Результат поиска: такое число отсутствует" << std::endl;
    }
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"