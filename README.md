# Third-task-in-Operatsion-systems

# Operatsion tizimlar: 3-topshiriq (18-variant)

**Talaba:** Anvarbek Xolboyev
**Fan:** Operatsion tizimlar
**Variant:** 18
**Mavzu:** C tilida satrlar, belgilar va fayllar bilan ishlash, dinamik xotira

## Masalalar

| Fayl | Masala | Ishlatilgan asosiy funksiyalar |
|---|---|---|
| `v18_m1.c` | Satrdagi har bir belgini ikki marta takrorlash (`"abc"` → `"aabbcc"`) | `malloc`, `free`, `strlen`, `fgets`, `strcspn` |
| `v18_m2.c` | N ta satrni `char **` massivga o'qib, eng uzun satrni topish | `malloc`, `free`, `strlen`, `strcpy`, `fgets`, `sscanf`, `strcspn` |
| `v18_m3.c` | Fayldagi qatorlarni `realloc` bilan dinamik massivga yuklab, teskari tartibda `reversed_lines.txt` ga yozish | `fopen`, `fclose`, `fgets`, `fprintf`, `realloc`, `malloc`, `free`, `perror` |

## Kirish fayli

3-masala uchun `input.txt` fayli kerak (8 qatorli namuna repoda mavjud). Dastur uni hozirgi papkadan o'qiydi, shuning uchun `input.txt` va `v18_m3.exe` bir papkada bo'lishi kerak.

## Kompilyatsiya va ishga tushirish

Har bir masala alohida kompilyatsiya qilinadi:

```bash
gcc -Wall -Wextra -std=c11 v18_m1.c -o v18_m1
gcc -Wall -Wextra -std=c11 v18_m2.c -o v18_m2
gcc -Wall -Wextra -std=c11 v18_m3.c -o v18_m3
```

Ishga tushirish:

- **Windows (PowerShell):** `.\v18_m1.exe`, `.\v18_m2.exe`, `.\v18_m3.exe`
- **Linux / WSL:** `./v18_m1`, `./v18_m2`, `./v18_m3`

Xotira oqishini tekshirish (Linux / WSL):

```bash
valgrind --leak-check=full ./v18_m2
```

## Talablar

- Kompilyatsiya ogohlantirishsiz o'tadi (`-Wall -Wextra -std=c11`).
- Satr kiritishda faqat `fgets` ishlatilgan, oxiridagi `'\n'` olib tashlanadi.
- `fopen` natijasi `NULL` ga tekshiriladi, xatoda `perror` chiqadi, har bir fayl `fclose` bilan yopiladi.
- Ajratilgan barcha xotira `free` bilan bo'shatiladi.

## Namuna

**1-masala**

```
Satrni kiriting: abc
Natija: aabbcc
```

**3-masala** (`input.txt` dagi qatorlar `reversed_lines.txt` ga teskari tartibda yoziladi)

```
8 ta qator teskari tartibda yozildi.
```
