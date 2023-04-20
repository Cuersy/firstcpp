#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int main() {
    try {
        int islem;
        std::cout << "(1) Key Sorgu, (2): scriptid'den keyleri cekmek\n";
        std::cout << "Islem secin : ";
        std::cin >> islem;
        if (islem == 1) {
            std::cin.ignore();
            std::string key;
            std::cout << "Key girin : ";
            std::getline(std::cin, key);
            sql::Driver* driver = get_driver_instance();
            sql::Connection* con = driver->connect("localhost", "root", "");

            con->setSchema("u791328001_cuersymain");
            int a[2];
            sql::PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM v2");
            sql::ResultSet* res = pstmt->executeQuery();
            std::cout << "\n\n#########Sonuclar##########\n";
            int index = 0;
            bool bulundu = false;
            bool band = false;
            while (res->next()) {
                string scriptid = res->getString("scriptid");
                string allkeys = res->getString("anahtar");
                if (allkeys == key) {
                    if (res->getInt("ban") == 1) {
                        band = true;
                    }
                    else if (res->getInt("ban") == 0) {
                        band = false;
                    }
                    std::cout << "Scriptid : " << scriptid << " | Key : " << key << " | Hwid : " << res->getString("hwid") << " | Ban durumu : " << band << endl;
                    a[index] = 115;
                    bulundu = true;
                    break;
                }
            }
            if (bulundu == false) {
                std::cout << "Sonuc yok!";
            }
            delete res;
            delete pstmt;
            delete con;

        }
        else if (islem == 2) {
            std::cin.ignore();
            std::string scriptid;
            std::cout << "Scriptid girin : ";
            std::getline(std::cin, scriptid);
            sql::Driver* driver = get_driver_instance();
            sql::Connection* con = driver->connect("localhost", "root", "");

            con->setSchema("u791328001_cuersymain");
            int a[2];
            sql::PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM v2");
            sql::ResultSet* res = pstmt->executeQuery();
            std::cout << "\n\n#########Sonuclar##########\n";
            int index = 0;
            bool bulundu = false;
            bool band = false;
            while (res->next()) {
                string allscriptid = res->getString("scriptid");
                string allkeys = res->getString("anahtar");
                if (allscriptid == scriptid) {
                    std::cout << "Scriptid : " << scriptid << " | Key : " << allkeys << " | HWID : " << res->getString("hwid") << " Ban Durumu : " << res->getInt("ban") << endl;
                    bulundu = true;
                }
            }
            if (bulundu == false) {
                std::cout << "Sonuc yok!";
            }
            delete res;
            delete pstmt;
            delete con;
        }
        else {
            std::cout << "Adam akilli islem gir (1,2)";
        }
        }
        catch (sql::SQLException& e) {
            cout << "Hata: " << e.what() << endl;
        }
    return 0;
}
