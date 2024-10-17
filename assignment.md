# Body v rovině

- **Hodnocení:** 5.0 bodů (maximálně 5.0 bodů)
- **Termín odevzdání:** 07.11.2022 11:59:59

## Zadání

Úkolem je realizovat program, který pro trojici zadaných bodů ve 2D rovině rozhodne, zda leží na společné přímce.

### Vstup
Vstupem programu jsou **X** a **Y** souřadnice trojice bodů ve 2D rovině. Souřadnice jsou zadané jako dvě desetinná čísla, přičemž první číslo reprezentuje složku **X** a druhé číslo složku **Y**.

### Cíl programu
Program analyzuje vzájemnou polohu zadaných bodů a rozhodne, který ze tří závěrů je platný:
1. Dva nebo všechny tři zadané body splývají,
2. Zadané tři body jsou navzájem různé a neleží na jedné přímce, nebo
3. Zadané tři body jsou navzájem různé a leží na jedné přímce (v tomto případě program navíc určí prostřední bod).

### Výstup
Formát výstupu je zřejmý z ukázek níže.

Program musí kontrolovat správnost vstupních dat. Pokud je na vstupu zadána nesprávná hodnota (např. nečíselná), program detekuje chybu, zobrazí chybové hlášení podle ukázky a ukončí se.

## Ukázka práce programu

```
Bod A:
1 2
Bod B:
3 4
Bod C:
5 6
Body lezi na jedne primce.
Prostredni je bod B.

Bod A:
0.1 0.2
Bod B:
0.3 0.4
Bod C:
0.5 0.6
Body lezi na jedne primce.
Prostredni je bod B.

Bod A:
10 10
Bod B:
0 10
Bod C:
10 0
Body nelezi na jedne primce.

Bod A:
0 1
Bod B:
0 3
Bod C:
0 2
Body lezi na jedne primce.
Prostredni je bod C.

Bod A:
1 0
Bod B:
2 0
Bod C:
-3 0
Body lezi na jedne primce.
Prostredni je bod A.

Bod A:
1 1
Bod B:
2 2
Bod C:
1 1
Nektere body splyvaji.

Bod A:
10 20
Bod B:
5 xyz
Nespravny vstup.
```

## Poznámky

- Ukázkové běhy zachycují očekávané výpisy programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použito pouze zde, aby byl výpis lépe čitelný. Program pouze zobrazuje text bez jakéhokoliv zvýrazňování.
- Každý výpis programu musí končit znakem odřádkování (`\n`), včetně případných chybových hlášení.
- Při řešení se snažte minimalizovat počet podmínek. Lze s výhodou využít vektorové algebry.
