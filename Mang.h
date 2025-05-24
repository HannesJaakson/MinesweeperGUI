#pragma once
#include "Laud.h"
#include <string>

class Mang {
public:
    Mang(int read, int veerud, int miinid);

    // Käivita mäng. Tagastab 0 kui võit, 1 mäng läbi.
    int käivita();

private:
    Laud laud;

    // Töötle ühe rea kasutaja sisendit.  Tagastab false, kui mäng läbi.
    bool töötleSisend(const std::string &rida);
};
