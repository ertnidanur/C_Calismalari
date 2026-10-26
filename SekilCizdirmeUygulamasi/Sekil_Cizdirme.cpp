#include <stdio.h>

#define MAX_BOYUT 30

void kareCiz(int boyut, char karakter);
void dikUcgenCiz(int boyut, char karakter);
void tersUcgenCiz(int boyut, char karakter);
void piramitCiz(int boyut, char karakter);
void tersPiramitCiz(int boyut, char karakter);
void baklavaCiz(int boyut, char karakter);
void kelebekCiz(int boyut, char karakter);
void iciBosKareCiz(int boyut, char karakter);

void menuGoster(void);
void karakterYaz(char karakter, int adet);
void satirTemizle(void);
int tamSayiOku(const char *mesaj, int *sayi);

int main(void) {
    int secim;
    int boyut;
    char karakter;

    while (1) {
        menuGoster();

        int sonuc = tamSayiOku("Seciminiz: ", &secim);

        if (sonuc == EOF) {
            break;
        }

        if (sonuc == 0) {
            printf("Lutfen bir tam sayi girin.\n");
            continue;
        }

        if (secim == 0) {
            printf("Program kapatildi.\n");
            break;
        }

        if (secim < 1 || secim > 8) {
            printf("Gecersiz secim.\n");
            continue;
        }

        sonuc = tamSayiOku("Boyut: ", &boyut);

        if (sonuc == EOF) {
            break;
        }

        if (sonuc == 0) {
            printf("Lutfen bir tam sayi girin.\n");
            continue;
        }

        if (boyut < 1 || boyut > MAX_BOYUT) {
            printf("Boyut 1 ile %d arasinda olmali.\n", MAX_BOYUT);
            continue;
        }

        printf("Cizim karakteri (ornek: * veya #): ");

        if (scanf(" %c", &karakter) != 1) {
            break;
        }

        satirTemizle();

        printf("\n");

        switch (secim) {
            case 1:
                kareCiz(boyut, karakter);
                break;

            case 2:
                dikUcgenCiz(boyut, karakter);
                break;

            case 3:
                tersUcgenCiz(boyut, karakter);
                break;

            case 4:
                piramitCiz(boyut, karakter);
                break;

            case 5:
                tersPiramitCiz(boyut, karakter);
                break;

            case 6:
                baklavaCiz(boyut, karakter);
                break;

            case 7:
                kelebekCiz(boyut, karakter);
                break;

            case 8:
                iciBosKareCiz(boyut, karakter);
                break;
        }
    }

    return 0;
}

void menuGoster(void) {
    printf("\n--- SEKIL CIZDIRME UYGULAMASI ---\n");
    printf("1 - Kare\n");
    printf("2 - Dik ucgen\n");
    printf("3 - Ters ucgen\n");
    printf("4 - Piramit\n");
    printf("5 - Ters piramit\n");
    printf("6 - Baklava\n");
    printf("7 - Kelebek\n");
    printf("8 - Ici bos kare\n");
    printf("0 - Cikis\n");
}

void karakterYaz(char karakter, int adet) {
    for (int i = 0; i < adet; i++) {
        printf("%c", karakter);
    }
}

void kareCiz(int boyut, char karakter) {
    for (int i = 0; i < boyut; i++) {
        karakterYaz(karakter, boyut);
        printf("\n");
    }
}

void dikUcgenCiz(int boyut, char karakter) {
    for (int i = 1; i <= boyut; i++) {
        karakterYaz(karakter, i);
        printf("\n");
    }
}

void tersUcgenCiz(int boyut, char karakter) {
    for (int i = boyut; i >= 1; i--) {
        karakterYaz(karakter, i);
        printf("\n");
    }
}

void piramitCiz(int boyut, char karakter) {
    for (int i = 1; i <= boyut; i++) {
        karakterYaz(' ', boyut - i);
        karakterYaz(karakter, 2 * i - 1);
        printf("\n");
    }
}

void tersPiramitCiz(int boyut, char karakter) {
    for (int i = boyut; i >= 1; i--) {
        karakterYaz(' ', boyut - i);
        karakterYaz(karakter, 2 * i - 1);
        printf("\n");
    }
}

void baklavaCiz(int boyut, char karakter) {
    piramitCiz(boyut, karakter);

    for (int i = boyut - 1; i >= 1; i--) {
        karakterYaz(' ', boyut - i);
        karakterYaz(karakter, 2 * i - 1);
        printf("\n");
    }
}

void kelebekCiz(int boyut, char karakter) {
    for (int i = 1; i <= boyut; i++) {
        karakterYaz(karakter, i);
        karakterYaz(' ', 2 * (boyut - i));
        karakterYaz(karakter, i);
        printf("\n");
    }

    for (int i = boyut - 1; i >= 1; i--) {
        karakterYaz(karakter, i);
        karakterYaz(' ', 2 * (boyut - i));
        karakterYaz(karakter, i);
        printf("\n");
    }
}

void iciBosKareCiz(int boyut, char karakter) {
    for (int i = 0; i < boyut; i++) {
        for (int j = 0; j < boyut; j++) {
            if (i == 0 || i == boyut - 1 ||
                j == 0 || j == boyut - 1) {
                printf("%c", karakter);
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void satirTemizle(void) {
    int karakter;

    while ((karakter = getchar()) != '\n' && karakter != EOF) {
    }
}

int tamSayiOku(const char *mesaj, int *sayi) {
    printf("%s", mesaj);

    int sonuc = scanf("%3d", sayi);

    if (sonuc == EOF) {
        return EOF;
    }

    if (sonuc != 1) {
        satirTemizle();
        return 0;
    }

    int karakter;
    int gecerli = 1;

    while ((karakter = getchar()) != '\n' && karakter != EOF) {
        if (karakter != ' ' && karakter != '\t' && karakter != '\r') {
            gecerli = 0;
        }
    }

    return gecerli;
}
