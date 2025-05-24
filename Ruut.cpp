#include "Ruut.h"

Ruut::Ruut() = default;

char Ruut::kuva() const {
    if (avatud) {
        if (kasMiin) return '*';
        if (naaberMiinideArv == 0) return ' ';
        return static_cast<char>('0' + naaberMiinideArv);
    } else {
        if (lipustatud) return 'F';
        return '#';
    }
}
