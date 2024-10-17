# Hodiny na věži

## Úkol
Úkolem je realizovat funkci (ne celý program, pouze funkci), která bude počítat, kolikrát budou zvonit zvony na věži v zadaném časovém intervalu.

Předpokládáme hodiny na věži, které dokáží zvonit na zvony a tím odbíjet čas. Hodiny jsou vybavené dvojicí zvonů:

1. **Zvon #1**, který odbíjí minuty. Zvoní vždy v násobcích 15 minut, zvoní 1x až 4x:
   - XX:00 - 4x
   - XX:15 - 1x
   - XX:30 - 2x
   - XX:45 - 3x

2. **Zvon #2**, který odbíjí hodiny. Zvoní tolikrát, kolik ukazuje hodinová ručička. Tedy v půlnoci 12x, v 1:00 1x, ve 2:00 2x, ..., ve 12:00 12x. Poté ve 13:00 1x, ve 14:00 2x, a tak dále.

V neděli je odbíjení po celý den vypnuté. Tedy naposledy se zvoní v sobotu ve 23:45 a pak až v pondělí v 00:00.

## Rozhraní funkce

Funkce dostane parametrem dva časové údaje - počátek a konec časového intervalu. Počátek i konec je dán rokem, měsícem, dnem, hodinou a minutou. Funkce spočítá, kolikrát hodiny v tomto intervalu odbijí na jednom a na druhém zvonu. **Pro výpočet uvažujeme uzavřený interval**, tedy pokud se odbíjí na začátku/konci zadaného intervalu, do výsledku zahrneme i tato odbíjení.

```c
int bells(
    int y1, int m1, int d1, int h1, int i1,
    int y2, int m2, int d2, int h2, int i2,
    long long int *b1, long long int *b2
);
```

- `y1, m1, d1, h1, i1`: vstupní parametry představující rok, měsíc, den, hodinu a minutu počátku intervalu.
- `y2, m2, d2, h2, i2`: vstupní parametry představující rok, měsíc, den, hodinu a minutu konce intervalu.
- `b1`: výstupní parametr, do kterého funkce uloží vypočtený počet odbití zvonu #1.
- `b2`: výstupní parametr, do kterého funkce uloží vypočtený počet odbití zvonu #2.

Funkce bude nastavovat výstupní parametry pouze pokud jsou zadané vstupy správné. Pokud jsou zadané nesprávné vstupy, funkce signalizuje neúspěch a ponechá výstupní parametry beze změn.

## Návratová hodnota

- Funkce vrací hodnotu `1`, pokud jsou všechny vstupní parametry správné a výpočet proběhl úspěšně.
- Funkce vrací hodnotu `0`, pokud jsou vstupní parametry nesprávné nebo není možné výsledek určit. V takovém případě funkce ponechá výstupní parametry (`b1` a `b2`) beze změn.

### Příklady nesprávných vstupů:
- Rok je menší než 1600.
- Měsíc je mimo platné rozmezí (1 až 12).
- Den je mimo platné rozmezí (1 až počet dní v měsíci).
- Hodina je mimo platné rozmezí (0 až 23).
- Minuta je mimo platné rozmezí (0 až 59).
- Počáteční okamžik intervalu je pozdější než koncový okamžik.

## Příklad

Testy pro mezní hodnoty:

```c
bells(2000, 12, 26, 0, 0, 2000, 12, 31, 0, 0, &b1, &b2);
// Očekávaná návratová hodnota: 1
// Očekávaný b1: 1200
// Očekávaný b2: 780

bells(2000, 12, 27, 0, 0, 2000, 12, 27, 0, 0, &b1, &b2);
// Očekávaná návratová hodnota: 1
// Očekávaný b1: 4
// Očekávaný b2: 12
```

Test s náhodnými daty:

```c
bells(1932, 4, 8, 21, 50, 1980, 2, 26, 1, 22, &b1, &b2);
// Očekávaná návratová hodnota: 1
// Očekávaný b1: 3,597,635
// Očekávaný b2: 2,338,474

bells(1954, 9, 13, 19, 30, 2012, 11, 11, 21, 6, &b1, &b2);
// Očekávaná návratová hodnota: 1
// Očekávaný b1: 4,370,205
// Očekávaný b2: 2,840,642
```

## Doplňující poznámky
- Při výpočtu času uvažujeme Gregoriánský kalendář. Měsíce mají buď 30 nebo 31 dní, s výjimkou února, který má buď 28 dní (v nepřestupném roce) nebo 29 dní (v přestupném roce).
- Pravidla pro přestupný rok:
  - Rok je přestupný, pokud je dělitelný 4, s výjimkou roků dělitelných 100. Nicméně roky dělitelné 400 jsou přestupné.
  - Roky dělitelné 4000 nejsou přestupné, i když toto pravidlo ještě nikdy nebylo uplatněno a není oficiálně přijato.

Tedy roky 1600, 2000 a 2400 jsou přestupné, zatímco roky 1700, 1800, 1900 a 2100 nejsou.

## Optimalizace

Program bude spuštěn v omezeném testovacím prostředí s omezeným časem běhu a velikostí dostupné paměti. Časové limity jsou nastaveny tak, aby rozumná implementace naivního algoritmu prošla všemi povinnými testy. Pro větší intervaly (bonusové testy) může být počet odbití obrovský. Datový typ `long long int` je pro tento účel dostatečný.

Pro efektivní zpracování velkých intervalů se vyplatí předpočítat si počet odbití za celý den a iterovat po dnech nebo delších časových úsecích. Naivní přístup, který by kontroloval každé jednotlivé odbití, by byl pro větší intervaly příliš pomalý, ale optimalizované algoritmy budou fungovat dobře jak pro povinné, tak pro bonusové testy.
