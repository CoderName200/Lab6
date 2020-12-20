#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() {
        this->i = 0;
        cout << "Запущен конструктор Base1 без параметров" << endl;
    }

    Base1(int i):i(i) {
        cout << "Запущен конструктор Base1 с параметрами" << endl;
    }

    void _seti(int i) {
        this->i = i;
    }
    int _geti() {
        return this->i;
    }
protected:
    int i;
};

class Base2 {
public:
    Base2() {
        strcpy_s(this->name, "Пусто");
        cout << "Запущен конструктор Base2 без параметров" << endl;
    }

    Base2(char* name) {
        strcpy_s(this->name, name);
        cout << "Запущен конструктор Base2 с параметрами" << endl;
    }

    void _setname(char* name) {
        strcpy_s(this->name, name);
    }
    char* _getname() {
        return this->name;
    }
protected:
    char name[20];
};

class Derived : public Base1, public Base2 {
    friend ostream& operator <<(ostream& out, Derived& obj) {
        return out << "i: " << obj._geti() << "\nname: " << obj._getname() << "\nch: " << obj._getch() << endl;
    }
public:
    Derived() {
        strcpy_s(this->ch, "V");
        cout << "Запущен конструктор Derived без параметров" << endl;
    }

    Derived(int i, char* name, char* ch ) : Base1(i), Base2(name) {
        strcpy_s(this->ch,ch);
        cout << "Запущен конструктор Derived с параметрами" << endl;
    }

    void _setch(char *ch) {
        strcpy_s(this->ch, ch);
    }
    char* _getch() {
        return this->ch;
    }
protected:
    char ch[2];
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Derived test;

    int i = 1;
    char name[20] = "test";
    char ch[2] = "С";
    Derived test2(i, name, ch);
    cout << test2 << endl;
}
