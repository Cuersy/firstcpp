#include <iostream>
#include <cstdlib>
#include <ctime>
#include<math.h>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
int kok(int koklu);
int test(int bir, int iki);
int algorithm(int num);
int decode(int num);
int uslu(int taban, int us);
int maya = 51;
int main() {
srand(time(NULL));
    int a;
    cout << "Example For : ";
    for (a = 5; a <= 9; a++) {
        cout << a << " ";
    }
    cout << "\nRandom Nums : ";
    int b = 0;
    int c = 15;
    while (b <= 10) {
        cout << test(b, c) << " ";
        b++;
    }
    int tsss = test(1600, 2541254);
    cout << tsss;
    int gets = algorithm(211111);
    int decod = decode(3800003);
    cout << "\n" << gets;
    cout << "\nDecoded : " << decod;
    cout << endl;
    std::cout << "Uslu Sayi : " << uslu(5, 2) << std::endl;
    std::cout << "Koklu Sayi : " << kok(16) << std::endl;
    return 0;
 
}
int kok(int koklu) {
    return std::sqrt(koklu);
}
int uslu(int taban, int us) {
    return std::pow(taban, us);
}
int algorithm(int num) {
    int first = num * 12;
    int second = num * 12 - 200 /51;
    int third = num  * 12 - 500 / 51;
    int fourth = num * 12 * 1555 / 51;
    int getmax = max(fourth, third);
    int getmax2 = max(first, second);
    int getfullmax = max(getmax, getmax2);
    int sonhal = getfullmax - getmax /2 + getmax2;
    if (sonhal <  0) {
        cout << "\n0dan kucuk\n";
        sonhal = sonhal + 199999 * 611 / 151;
        return sonhal;
    }
    else {
        return sonhal;
    }
}
int test(int bir, int iki) {
    int a = 1 + rand() % 100;
    return a + bir / iki;
}
int decode(int num) {
    int first = num / 12;
    int second = num / 12 + 200 * 51;
    int third = num / 12 + 500 * 51;
    int fourth = num / 12 / 1555 * 51;
    int getmax = max(fourth, third);
    int getmax2 = max(first, second);
    int getfullmax = max(getmax, getmax2);
    int sonhal = getfullmax + getmax * 2 - getmax2;
    if (sonhal < 0) {
        cout << "\n0dan kucuk\n";
        sonhal = sonhal - 199999 / 611 * 151;
        return sonhal;
    }
    else {
        return sonhal;
    }
}
