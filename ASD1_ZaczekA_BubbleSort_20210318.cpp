#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Funkcja generuje tablice losowych integerow
 * @param size - wielkosc tablicy
 * @return - zwraca wygenrowana tablice
 */
int *populateRandomArray(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() + (rand() % 50); ///liczby pseudolosowe z zakresu od 0 do 32767 + (0-50)
    }
    return arr;
}

/**
 * Funkcja generuje tablice elementow odwrotnym porzadku 3,2,1...
 * @param size - wielkosc tablicy
 * @return - zwraca wygenrowana tablice
 */
int *populatePessimistScenarioArray(int size) {
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
    return arr;
}

/**
 * Funkcja wyswietla zawartosc przekazanej tablicy
 * @param arr - tablica integerow
 * @param size - wielkosc tablicy
 */

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/**
 * Funkcja za pomoca sortowania babelkowego sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
 */
void bubbleSort(int *arr, int size) {
    int temp = 0;
    long long counter = 0;
    clock_t start, stop;
    double time;
    start = clock();
    cout << "_________________\n" << "wielosc tablicy w sortowaniu bubble sort: " << size << endl;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            counter++;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    stop = clock();
    time = (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "wykonana w czasie: " << time << " s" << endl;
    cout << "ilosc operacji dominujacych: " << counter << endl;
}

/**
 * Funkcja za pomoca sortowania babelkowego z flaga ktora okresla czy elementy sa juz ulozone sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
 */
void bubbleSortPlus(int *arr, int size) {
    int temp;
    long long counter = 0;
    bool flag;
    clock_t start, stop;
    double time;
    start = clock();
    cout << "_________________\n" << "wielosc tablicy w sortowaniu bubble sort plus: " << size << endl;
    for (int j = 0; j < size; j++) {
        flag = false;
        for (int i = 0; i < size - 1; i++) {
            counter++;
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                flag = true;
            }
        }
        if (!flag) {
            cout << "wyjscie z petli po: " << j << " iteracji" << endl;
            break;
        }
    }
    stop = clock();
    time = (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "wykonana w czasie: " << time << " s" << endl;
    cout << "ilosc operacji dominujacych: " << counter << endl;
}

/**
 * Funkcja za pomoca sortowania przez wstawianie sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
 */
void insertionSort(int *tab, int size) {
    int temp, j;
    long long counter = 0;
    clock_t start, stop;
    double time;
    start = clock();
    cout << "_________________\n" << "wielosc tablicy w sortowaniu insertionSort: " << size << endl;
    for (int i = 1; i < size; i++) {
        temp = tab[i];
        for (j = i - 1; j >= 0 && tab[j] > temp; j--) {
            counter += 2;
            tab[j + 1] = tab[j];
        }
        tab[j + 1] = temp;
    }
    stop = clock();
    time = (double) (stop - start) / CLOCKS_PER_SEC;
    cout << "wykonana w czasie: " << time << " s" << endl;
    cout << "ilosc operacji dominujacych: " << counter << endl;
}

/**
 * Funkcja za pomoca sortowania szybkiego sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param left - zakres sortowanej tablicy z lewej strony (lewy indeks)
 * @param right - zakres sortowanej tablicy z prawej strony (prawy indeks)
 * @param counter wskaznik to licznika operacji dominujacych
 */
void quickSort(int *arr, int left, int right,long long *counter) {
    if (right <= left) return;
    int i = left - 1, j = right + 1, pivot = arr[(left + right) / 2]; /// punkt odniesienia
    while (true) {
        //szuka elementu wiekszego lub rownego piwota stojacego
        //po prawej stronie wartosci pivot
        while (pivot > arr[++i]);
        *counter = *counter + 1;
        //szuka elementu mniejszego lub rownego pivota stojacego
        //po lewej stronie wartosci pivot
        while (pivot < arr[--j]);
        *counter = *counter + 1;
        //jesli liczniki sie nie minely to zamień elementy ze soba
        //stojace po niewlasciwej stronie elementu pivota
        if (i <= j)
            //funkcja swap zamienia wartosciami tab[i] z tab[j]
            swap(arr[i], arr[j]);
        else
            break;
    }
    if (j > left)
        quickSort(arr, left, j, counter);
    if (i < right)
        quickSort(arr, i, right, counter);
}

/**
 * Funkcja uruchamia konsolowy interface
 */
void display() {
    int elements, scenario;
    cout << "podaj ilosc elementow do posortowania (0 - 100.000)" << endl;
    cin >> elements;
    if (elements < 0 || elements > 100000) {
        cout << "podano nieprawidlowy zakres" << endl;
        display();
    }
    cout << "typ wygenerowanej tablicy (cyfra 1-2): "
            "\n 1- liczby losowe "
            "\n 2- pesymistyczny scenariusz z liczbami w odwrotnej kolejnosci" << endl;
    cin >> scenario;
    if (scenario != 1 && scenario != 2) {
        cout << "podano nieprawidlowy scenariusz" << endl;
        display();
    }
    int *arr;
    switch (scenario) {
        case 1:
            arr = populateRandomArray(elements);
            cout << "-----scenariusz losowy-----: " << endl;
            cout << "tablica przed sortowaniem: " << endl;
            printArray(arr, elements);
            bubbleSort(arr, elements);
            arr = populateRandomArray(elements);
            bubbleSortPlus(arr, elements);
            arr = populateRandomArray(elements);
            insertionSort(arr, elements);
            cout << "-----posortowana tablica-----" << endl;
            printArray(arr, elements);
            break;
        case 2:
            arr = populatePessimistScenarioArray(elements);
            cout << "-----scenariusz pesymistyczny-----: " << endl;
            cout << "tablica przed sortowaniem: " << endl;
            printArray(arr, elements);
            bubbleSort(arr, elements);
            arr = populatePessimistScenarioArray(elements);
            bubbleSortPlus(arr, elements);
            arr = populatePessimistScenarioArray(elements);
            insertionSort(arr, elements);
            cout << "-----posortowana tablica-----" << endl;
            printArray(arr, elements);
            break;
    }
    cout << "1- zakonczenie pracy \ninna wartosc kontynuacja " << endl;
    cin >> elements;
    if (elements == 1) {
        return;
    }
    display();
}

int main() {
//    int arrayLength = 200;
//    long long counter = 0;
//    int *arr = populateRandomArray(arrayLength);
//    quickSort(arr,0, arrayLength-1, &counter);
    display();
    return 0;
}
