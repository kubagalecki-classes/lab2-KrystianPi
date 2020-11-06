#include <iostream>
using namespace std;
class wektor
{
public:
    wektor() : dlugosc(0), pojemnosc(0) { w = new double[dlugosc]; }
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
            dlugosc = n1;
            for (int i = n1 + 1; i <= get_pojemnosc(); ++i) {
                delete &w[i];
            }
        }
        else {
            dlugosc   = n1;
            double* p = new double[dlugosc];
            for (int i = 0; i < get_pojemnosc(); ++i) {
                p[i] = w[i];
            }
            for (int i = dlugosc; i < get_pojemnosc(); ++i) {
                p[i] = 0.;
            }

            delete[] w;
        }
    }

    void print()
    {
        for (int i = 0; i < get_dlugosc(); ++i) {
            cout << w[i] << endl;
        }
    }
    ~wektor() { delete[] w; }
    wektor& operator=(const wektor&) { return *this; }
    wektor  get_wektor() { return wektor(); }

private:
    int     dlugosc;
    double* w;
    int     pojemnosc;
};

int main()
{
    wektor w1(5);
    w1.print();
    cout << " " << endl;
    w1.zmien_dlugosc(7);
    w1.print();
}
