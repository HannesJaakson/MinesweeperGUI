# MinesweeperGUI – projekt

**Grupi liikmed:**  
Hannes Jaakson, Morris Tann

---

## 1 · Lühikokkuvõte

MinesweeperGUI on graafiline miinide otsimise mäng, kirjutatud C++17-s ja kasutades **Qt6** raamistikku.  
Enne mängu algust saab kasutaja määrata laua ridade, veergude ja miinide arvu  
(vaikeväärtus 10 × 10 ruutu ja 10 miini).  
Programmi eesmärk on pakkuda lihtsat, lõbusat ajaviidet ning demonstreerida:

- objektorienteeritud disaini  
- Qt signaal-/slot-mudelit  
- CMake ehitussüsteemi kasutust  

---

## 2 · Programmi töö

1. Käivitumisel avaneb **ConfigDialog**, kus saab määrata:  
   - **Read** – ridade arv (5–40)  
   - **Veerud** – veergude arv (5–40)  
   - **Miinid** – miinide arv (max = read × veerud − 1)  

2. Pärast **OK** vajutamist luuakse mänguaken pealkirjaga **“Minesweeper”**,  
   mille suurus vastab täpselt valitud ruudustikule (aken ei ole venitatav).  

3. **Juhtimine:**  
   - **Vasak klikk** – ruudu avamine  
   - **Parem klikk** – lipu panek või äravõtmine  

4. **Kaotus:**  
   - Miini avamisel kuvatakse kõik miinid  
   - Ilmub teade **“Kaotus”**  

5. **Võit:**  
   - Kui kõik miinid on lipustatud ja ohutud ruudud avatud  
   - Ilmub teade **“Võit”**  

---

## 3 · Failistruktuur

| Fail(id)         | Kirjeldus                                           |
|------------------|------------------------------------------------------|
| `main.cpp`       | programmi käivitaja; avab dialoogi                   |
| `configdialog.*` | kasutajalt parameetrite küsimine (`QDialog`)        |
| `mainwindow.*`   | põhiaken ja mänguloogika GUI-s                       |
| `Laud.*`         | mängulaua mudel: miinide asetus, avamine, võit      |
| `Ruut.*`         | ühe ruudu olek                                      |
| `ruudunupp.*`    | `QPushButton`-alamklass iga ruudu jaoks             |
| `CMakeLists.txt` | projektikonfiguratsioon                             |
| `README.md`      | see dokumentatsioonifail                            |

---

## 4 · Eeldatav tulemus

- Projekt kompileerub veavabalt kõigil toetatud platvormidel.  
- Käivitamisel kuvab seadistusdialoogi, mille järel avaneb fikseeritud suurusega mänguaken.  
- Ruudustik kuvab korrektse värviga numbreid ja sümboleid.  
- Ruudud on avatavad ja lipustatavad vastavalt klikkidele.  
- Mängu lõpus kuvatakse sobiv **“Võit”** või **“Kaotus”** teade.  

---

**Head mängimist!**
