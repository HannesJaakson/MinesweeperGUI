#include "Mang.h"
#include <iostream>
#include <sstream>

Mang::Mang(int read, int veerud, int miinid)
    : laud(read, veerud, miinid) {
}

int Mang::käivita() {
    std::cout << "Tere tulemast mängima Minesweeperit!\n"
            "Käsud:\n"
            "  e              - lõpetab programmi töö\n"
            "  o RIDA VEERG   - astu ruudule\n"
            "  f RIDA VEERG   - märgista miiniga (märgistab F tähega (Flag))\n"
            "Reanumbrid ja veerunumbrid algavad nullist.\n"
            "Sisesta oma käsk ja vajuta Enter!\n\n";

    while (true) {
        //laud.prindi();
        std::cout << "> ";
        std::string rida;
        if (!std::getline(std::cin, rida) || rida.empty())
            continue;
        if (!töötleSisend(rida))
            break;
        std::cout << "\n";
    }

    if (laud.kasVõit()) {
        return 0;
    } else {
        std::cout << "Mängu lõpp tabel:\n";
        //laud.prindi(true);
        return 1;
    }
}

bool Mang::töötleSisend(const std::string &rida) {
    std::istringstream ss(rida);
    char käsk;
    int r, v; // rida, veerg
    if (!(ss >> käsk >> r >> v)) {
        if (käsk == 'E' || käsk == 'e') {
            std::cout << "Programm lõpetab töö. Tänan mängimast!\n";
            return false; // lõpetab programmi töö
        }
        std::cout << "Vigane sisend. Kasuta näiteks: o 3 4 või f 2 5\n";
        return true;
    } else if (!laud.piirides(r, v)) {
        std::cout << "Sisend on piiridest väljas.\n";
        return true; // jätkab mängu
    }

    switch (käsk) {
        case 'o':
        case 'O':
            if (!laud.avaRuut(r, v)) {
                std::cout << "Kahjuks avasid miini.\n";
                return false; // kui avas miini, siis mäng läbi
            }
            if (laud.kasVõit()) {
                std::cout << "Palju õnne, võitsid!\n";
                return false; // kui kõik ruudud avatud, siis võit!
            }
            break;

        case 'f':
        case 'F':
            laud.lülitaLipp(r, v);
            std::cout << "Lipp lisatud!";
            break;

        default:
            std::cout << "Tundmatu käsk. Kasuta 'o' (ava) või 'f' (lipp).\n";
            break;
    }

    return true;
}
