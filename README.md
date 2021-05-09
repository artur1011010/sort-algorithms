# sort-algorithms
Analysis of different sorting techniques in c++


## Badanie złożoności algorytmów sortowania

## Wstęp i cel zadania:  
Celem jest zbadanie złożoności i wydajności popularnych algorytmów sortowania na podstawie 2 algorytmów: algorytm sortowania bąbelkowego (bubble sort) w prymitywnej wersji bez optymalizacji oraz w wersji zoptymalizowanej flagą wskazującą czy elementy są ułożone w kolejności i drugim algorytmem sortowania przez wstawianie (insertion sort). 

## Opis:
Pomiary wydajności zostały wykonane na podstawie operacji dominujących czyli w tym przypadku porównań poszczególnych liczb całkowitych znajdujących się w tablicy, ale nie są to jedyne operacje które wykonuje procesor podczas wykonywania algorytmu. Dodatkowo w funkcjach umieszczone są liczniki oraz funkcje wypisujące na konsole pomocnicze informacje które znacząco obciążają procesor, mają one wpływ ma czas wykonania który też został umieszczony w tabeli tylko w celach poglądowych. Wszystkie pomiary są wykonane w programie napisanym w języku c++. Pomiary wykonałem dla 2 scenariuszy: 
•	Scenariusz losowy, liczby całkowite w tabeli generowane są za pomocą funkcji rand()
•	Scenariusz pesymistyczny z wygenerowana tablica w odwrotnej kolejności

## Wyniki:
![ASD1_ZaczekA_BubbleSort_20210318](https://user-images.githubusercontent.com/43014461/117566714-94b08700-b0b8-11eb-914c-5eecccdc7171.jpg)

## Wnioski:
Wyniki wskazują że 2 testowane algorytmy maja wydajność zbliżoną do n^2, szczególnie scenariusz pesymistyczny:
 
Oba testowane algorytmy są wysoce niewydajne i nie stosuje się i w obecnej informatyce, większość języków programowania wysokiego poziomu domyślnie dla struktur danych rodzaju tablic czy list ma zaimplementowany algorytm sortowania szybkiego (quick sort) który cechuje się zdecydowanie wyższą wydajnością (n log n). Z dwóch testowanych algorytmów lepiej wypada algorytm sortowania przez wstawianie (insertion sort).

Opis interfacu i dostępnych funkcji:

###	int *populateRandomArray(int size) 
  * Funkcja generuje tablice losowych integerow
   * @param size - wielkosc tablicy
   * @return - zwraca wygenrowana tablice
###	int *populatePessimistScenarioArray(int size) 
 * Funkcja generuje tablice elementow odwrotnym porzadku 3,2,1...
 * @param size - wielkosc tablicy
 * @return - zwraca wygenrowana tablice
###	void printArray(int *arr, int size) 
* Funkcja wyswietla zawartosc przekazanej tablicy
 * @param arr - tablica integerow
 * @param size - wielkosc tablicy
###	void bubbleSort(int *arr, int size) 
* Funkcja za pomoca sortowania babelkowego sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
###	void bubbleSortPlus(int *arr, int size)
* Funkcja za pomoca sortowania babelkowego z flaga ktora okresla czy elementy sa juz ulozone sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
###	void insertionSort(int *tab, int size) 
 * Funkcja za pomoca sortowania przez wstawianie sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param size - wielosc tablicy
###	void quickSort(int *arr, int left, int right,long long *counter) 
 * Funkcja za pomoca sortowania szybkiego sortuje elementy przekazanej jako wskaznik tablicy
 * @param arr - referencja do sortowanej tablicy
 * @param left - zakres sortowanej tablicy z lewej strony (lewy indeks)
 * @param right - zakres sortowanej tablicy z prawej strony (prawy indeks)
 * @param counter wskaznik to licznika operacji dominujacych
###	void display()
* Funkcja uruchamia konsolowy interface

