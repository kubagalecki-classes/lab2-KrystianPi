#include <iostream>
using namespace std;
class wektor
{
public:
    double* w;
    wektor(int n) : dlugosc(n), pojemnosc(n)
    {
        w = new double[dlugosc];
        for (int i = 0; i < dlugosc; ++i) {
            w[i] = 0.;
        }
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
    ~wektor() { delete[] w; }

private:
    int dlugosc;
    int pojemnosc;
};

int main()
{
    wektor w1(5);
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(7);
    w1.w[0] = 5;
    w1.w[1] = 5;
    w1.w[2] = 5;
    w1.w[3] = 5;
    w1.w[4] = 5;
    w1.w[5] = 5;
    w1.w[6] = 5;
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
}
