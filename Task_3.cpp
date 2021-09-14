#include <iostream>
#include <windows.h>

using namespace std;

class FooString {
    char *buf;
    int n;
public:
    FooString(char *tbuf) {
        int i = 0;
        while (tbuf[i] != 0)
            ++i;
        n = i;
        buf = new char[n];
        buf = tbuf;
    };

    ~FooString() {
    };

    void show() {
        for (int i = 0; i < n; ++i)
            cout << buf[i];
        cout << endl;
    }

    // Вариант 4 – перевыделить память и добавить строку str в конец

    void add(FooString &str) {
        int n_2 = returnern() + str.returnern();
        char *buf_2 = new char[n_2];
        for (int i = 0; i < returnern(); ++i) {
            buf_2[i] = Mass(i);
        }
        for (int i = returnern(); i <= n_2; ++i) {
            buf_2[i] = str.Mass(i - returnern());
        }
        n = n_2;
        buf = new char[n];
        buf = buf_2;
    }

    int Mass(int i) {
        if ((i >= 0) && (i <= n)) {
            return buf[i];
        }
    }

    void setn(int newn) {
        n = newn;
    }

    int returnern() {
        return n;
    }
};

int test(char *a, char *b, char *ans) {
    bool exit = true;
    FooString sl(a);
    FooString slNew(b);
    sl.add(slNew);
    FooString t1(ans);
    for (int i = 0; i <= t1.returnern(); ++i) {
        if (sl.Mass(i) != t1.Mass(i))
            return -1;
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char test_a[60] = "Hello,";
    char test_b[60] = " world!";
    char test_ans[60] = "Hello, world!";
    if (test(test_a, test_b, test_ans) == 0) {
        cout << "Ок" << endl;
    }
    else {
        cout << "Ошибка!" << endl;
    }
    return 0;
}