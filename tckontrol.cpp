#include<iostream>
#include<string>
#include<math.h>
bool tccheck(std::string tc) {
    int ilkontoplam = 0;
    for (int i = 0; i < 10; ++i) {
        ilkontoplam += tc[i] - '0';
    }
    int ilkontoplamilkbasamak = ilkontoplam % 10;
    int onbir = tc[10] - '0';
    if (onbir == ilkontoplamilkbasamak) {
        return true;
    }
    else {
        return false;
    }
}
bool ikincialgoritma(std::string tc) {
    bool sonuc;
    // ilk
    int ilktoplam = 0;
    int ilkson = 0;
    for (int i = 0; i <= 8; i += 2) {
         ilktoplam += int(tc[i] - '0');
    }
    ilkson = ilktoplam * 7;
    // ikinci
    int ikincitoplam = 0;
    int ikincison = 0;
    for (int i = 1; i < 9; i += 2) {
        ikincitoplam += int(tc[i] - '0');
    }
    ikincison = ikincitoplam * 9;
    int enson = ikincison + ilkson;
    int ensonrakam = enson % 10;
    if (ensonrakam == int(tc[9] - '0')) {
        sonuc = true;
    }
    else {
        sonuc = false;
    }
    return sonuc;
}
bool ucuncualgoritma(std::string tc) {
    bool sonuc;
    int rakamtoplam = 0;
    for (int i = 0; i <= 8; i += 2) {
        rakamtoplam += tc[i] - '0';
    }
    rakamtoplam = rakamtoplam * 8;
    int rakamtoplamson = rakamtoplam % 10;
    if (rakamtoplamson == int(tc[10] - '0')){
        sonuc = true;
    }else {
        sonuc = false;
    }
    return sonuc;
}
int main() {
    std::string tc;
    std::cout << "TC gir la : ";
    std::cin >> tc;
    if ((tccheck(tc) == true) && (ikincialgoritma(tc) == true) && ucuncualgoritma(tc) == true){
        std::cout << "Bu tc kimlik dogru aga" << std::endl;
        return 1;
    }
    else {
        std::cout << "Bu tc kimlik hatali amk" << std::endl;
        return 0;
    }
    return 0;
}
