# Şekil Çizdirme Uygulaması

Kullanıcının seçtiği boyut ve karakterle konsolda farklı şekiller çizen C uygulaması. Döngüleri, fonksiyonları ve kullanıcı girdilerini kontrol etmeyi çalışmak için hazırlanmıştır.

## Çizilebilen Şekiller

1. Kare
2. Dik üçgen
3. Ters üçgen
4. Piramit
5. Ters piramit
6. Baklava
7. Kelebek
8. İçi boş kare

## Özellikler

- Menü üzerinden şekil seçimi
- 1–30 arasında boyut belirleme
- `*`, `#` veya `+` gibi tek bir çizim karakteri seçme
- Her şekil için ayrı fonksiyon
- Geçersiz menü seçimi, boyut ve sayı girdilerinin kontrolü
- Çıkış seçilene kadar tekrar işlem yapabilme

## Kullanım

1. Menüden bir şekil seçin.
2. Boyutu girin.
3. Çizimde kullanılacak karakteri girin.
4. Başka bir şekil çizmek için menüden yeniden seçim yapın.
5. Çıkmak için `0` girin.

Kare ve üçgenlerde boyut, satır sayısını belirtir. Baklava ve kelebekte toplam satır sayısı `2 * boyut - 1` olur. Baklava genişliği en fazla `2 * boyut - 1`, kelebek genişliği ise `2 * boyut` karakterdir.

## Kullanılan Konular

- `for` ve `while` döngüleri
- İç içe döngüler
- `if / else` ve `switch / case`
- Fonksiyon prototipleri ve parametreler
- Pointer aracılığıyla fonksiyondan değer aktarma
- `scanf`, `printf` ve `getchar`
- `EOF` ve giriş satırını temizleme

## Çalıştırma

Kaynak kodunu `main.c` olarak kaydedin. C99 veya üzerini destekleyen bir derleyici gerekir.

### GCC ile

Proje klasöründe terminal açarak derleyin:

```bash
gcc -std=c99 -Wall -Wextra main.c -o sekil_cizdirme
```

Linux veya macOS:

```bash
./sekil_cizdirme
```

Windows PowerShell:

```powershell
.\sekil_cizdirme.exe
```

### Dev-C++ ile

`main.c` dosyasını açın, derleyin ve çalıştırın. Derleyici C standardıyla ilgili hata verirse C99 veya üzeri bir standart seçin.

## Mevcut Sınırlar

- Grafik arayüz yerine konsol kullanılır.
- Çizim karakteri olarak tek bir ASCII karakteri kullanılması önerilir; çok baytlı Unicode karakterler desteklenmez.
- Çizimler dosyaya kaydedilmez.
- Sayı girişi en fazla üç karakter okunarak kontrol edilir; boyut yine 1–30 ile sınırlandırılır.
