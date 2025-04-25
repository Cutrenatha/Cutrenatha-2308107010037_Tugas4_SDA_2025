#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_data.h"

// Fungsi untuk menghasilkan data angka acak
void generate_random_numbers(int *arr, int jumlah) {
    srand(time(NULL));
    for (int i = 0; i < jumlah; i++) {
        arr[i] = rand() % 1000;  // Men-generate angka acak antara 0 dan 999
    }
}

// Fungsi untuk membaca data kata dari file
void baca_kata_dari_file(const char *filename, char **arr, int jumlah) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < jumlah; i++) {
        arr[i] = malloc(100 * sizeof(char));  // Alokasi memori untuk kata
        if (fscanf(file, "%s", arr[i]) != 1) {
            break;  // Jika mencapai akhir file
        }
    }

    fclose(file);
}

void test_sorting_angka(int jumlah) {
    printf("\nMemproses %d data angka...\n", jumlah);

    int *arr = malloc(sizeof(int) * jumlah);
    int *temp = malloc(sizeof(int) * jumlah);

    generate_random_numbers(arr, jumlah);

    clock_t start, end;
    double duration;
    size_t mem_used = sizeof(int) * jumlah; // Estimasi memori temp[] untuk setiap algoritma

    // Bubble Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    bubble_sort_int(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort    : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    // Selection Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    selection_sort_int(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    // Insertion Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    insertion_sort_int(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    // Merge Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    merge_sort_int(temp, 0, jumlah - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort     : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    // Quick Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    quick_sort_int(temp, 0, jumlah - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort     : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    // Shell Sort
    for (int i = 0; i < jumlah; i++) temp[i] = arr[i];
    start = clock();
    shell_sort_int(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Shell Sort     : %.6f detik | Memori: %.2f KB\n", duration, mem_used / 1024.0);

    free(arr);
    free(temp);
}

void test_sorting_kata(int jumlah) {
    printf("\nMemproses %d data kata...\n", jumlah);

    char **arr = malloc(sizeof(char *) * jumlah);
    char **temp = malloc(sizeof(char *) * jumlah);

    baca_kata_dari_file("data_kata.txt", arr, jumlah);

    clock_t start, end;
    double duration;

    // Bubble Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    bubble_sort_str(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort    : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    // Selection Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    selection_sort_str(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    // Insertion Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    insertion_sort_str(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    // Merge Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    merge_sort_str(temp, 0, jumlah - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort     : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    // Quick Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    quick_sort_str(temp, 0, jumlah - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort     : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    // Shell Sort
    for (int i = 0; i < jumlah; i++) temp[i] = strdup(arr[i]);
    start = clock();
    shell_sort_str(temp, jumlah);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Shell Sort     : %.6f detik | Memori: %.2f KB\n", duration, jumlah * 100 / 1024.0);
    for (int i = 0; i < jumlah; i++) free(temp[i]);

    free(arr);
    free(temp);
}

// Fungsi menu untuk sorting data angka
void menu_data_angka() {
    int pilihan;
    int ukuran[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};

    do {
        printf("\n--- Sorting Data Angka ---\n");
        for (int i = 0; i < 8; i++) {
            printf("%d. Sorting %d angka\n", i + 1, ukuran[i]);
        }
        printf("9. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 8) {
            test_sorting_angka(ukuran[pilihan - 1]);
        }

    } while (pilihan != 9);
}

// Fungsi menu untuk sorting data kata
void menu_data_kata() {
    int pilihan;
    int ukuran[] = {10000, 50000, 100000, 250000, 500000, 1000000, 1500000, 2000000};

    do {
        printf("\n--- Sorting Data Kata ---\n");
        for (int i = 0; i < 8; i++) {
            printf("%d. Sorting %d kata\n", i + 1, ukuran[i]);
        }
        printf("9. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= 8) {
            test_sorting_kata(ukuran[pilihan - 1]);
        }

    } while (pilihan != 9);
}

// Fungsi utama
int main() {
    int pilihan;

    do {
        printf("\n--- Menu Sorting ---\n");
        printf("1. Sorting Data Angka\n");
        printf("2. Sorting Data Kata\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            menu_data_angka();
        } else if (pilihan == 2) {
            menu_data_kata();
        }

    } while (pilihan != 3);

    return 0;
}
