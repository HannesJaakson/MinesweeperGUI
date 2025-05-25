#pragma once
#include "Ruut.h"
#include <vector>
#include <string>

// Kogu mängulaud
class Laud {
public:
    Laud(int read, int veerud, int miinid);

    // Tagastab false, kui avati miin.
    bool avaRuut(int rida, int veerg);

    void lülitaLipp(int rida, int veerg);

    bool kasVõit() const;

    // Sümbol (vastavalt Ruut::kuva) antud koordinaadil
    char kuva(int rida, int veerg) const;

    // Tagastab true kui on miin
    bool onMiin(int rida, int veerg) const;

    int ridadeArv() const { return read; }
    int veergudeArv() const { return veerud; }

    bool piirides(int r, int v) const;

private:
    int read;
    int veerud;
    int miinid;

    std::vector<std::vector<Ruut>> ruudud;

    // Arvutab ja salvestab kõikidele ruutudele (isend Ruut) naabermiinide koguse
    void arvutaNaabrid();

    // Rekursiivselt avab kõik tühjad naaberruudud, kui kasutaja valis ruudu, kus naaberruut on tühi(naabermiinide arv 0)
    void laiendaTühjad(int r, int v);
};
