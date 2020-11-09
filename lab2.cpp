#include <iostream>
using namespace std;
class wektor
{
public:
    wektor(int n) : dlugosc{n}, pojemnosc{n} // konstruktor parametryczny
    {
        w = new double[dlugosc];
        for (int i = 0; i < dlugosc; ++i) {
            w[i] = 0.;
        }
    }
    wektor(wektor& v)
        : dlugosc{v.get_dlugosc()}, pojemnosc{v.get_pojemnosc()} // konstruktor kopiujący
    {
        w = new double[dlugosc];
        w = v.w;
    }
    wektor(wektor&& v) // konstruktor przenoszący
    {
        *this = move(v);
        v.w   = nullptr;
    }
    int  get_dlugosc() { return dlugosc; }
    int  get_pojemnosc() { return pojemnosc; }
    void zmien_dlugosc(int n1)
    {
        if (n1 <= get_pojemnosc()) {
            for (int i = n1; i < get_pojemnosc(); ++i) {
                w[i] = 0.;
            }
            dlugosc = n1;
        }
        else {
            double* wekt;
            wekt = w;
            w    = new double[n1];
            for (int i = 0; i < get_pojemnosc(); ++i) {
                w[i] = wekt[i];
            }
            for (int i = dlugosc; i < get_pojemnosc(); ++i) {
                w[i] = 0.;
            }
            dlugosc   = n1;
            pojemnosc = n1;
            delete[] wekt;
        }
    }

    void print()
    {
        for (int i = 0; i < get_dlugosc(); ++i) {
            cout << w[i] << endl;
        }
    }
    ~wektor() { delete[] w; }          // destruktor
    wektor& operator=(const wektor& v) // operator przypisania
    {
        if (this != &v)
            w = v.w;
        return *this;
    }
    double& operator[](int i) // operator wyłuskania
    {
        if (i > get_dlugosc()) {
            zmien_dlugosc(i + 1);
            return w[i];
        }
        else {
            return w[i];
        }
    }

private:
    int     dlugosc;
    int     pojemnosc;
    double* w;
};

int main()
{
    wektor w1(5);
    cout << " " << endl;
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(7);
    w1[0] = 5;
    w1[1] = 5;
    w1[2] = 5;
    w1[3] = 5;
    w1[4] = 5;
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(3);
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(10);
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(6);
    w1.print();
    cout << w1.get_dlugosc() << " " << w1.get_pojemnosc() << endl;
    cout << " " << endl;
    w1[9] = 7;
    w1.print();
    cout << w1.get_dlugosc() << " " << w1.get_pojemnosc() << endl;
    wektor w2{w1};
    cout << " " << endl;
    w2.print();
    cout << " " << endl;
    wektor w3(5);
    w3 = w2;
    w3.print();
}
