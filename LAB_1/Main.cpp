// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Pliku Main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod).
// UWAGA na temat pragma once oraz podziału programu na pliki:
// #pragma once po prostu blokuje icludowanie danego pliku 
// > tej samej jednostce kompilacji < więcej niż raz, 
// ale nie blokuje includowanie tego samego pliku
// > w różnych jednostkach kompilacji <
// Dlatego, jeśli funkcje są zdefiniowane w nagłówku i nie znajdują się 
// wewnątrz struktury lub klasy (a więc są globalne lub znajdują się w przestrzeni nazw),
// to należy albo zdefiniować je inline, albo podzielić ich definicję na plik .cpp.
// 
// Celem zadania jest implementacja listy jednokierunkowej,
// która przechowuje dane typu int o nazwie _id. 
// W pozostałej części zadania należy zaimplementować funkcje operujące
// na elementach listy TStudent
//
// Programem valgrind należy sprawdzić poprawne zarządzanie pamięcią.
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum nie powinno zawierać katalogu build/
// * tworzenie archiwum: tar -czvf nazwa.tar.gz katalog/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "Student.h"
#include "StudentList.h"

int main()
{
    TStudent* head = nullptr; //Lista jest pusta na start
    show(head);
    TStudent* next = InitTStudent();
    next->_id=1;
    next->_next= head;
    head=next;
    show(head);
    push_front(&head, 2);
    push_front(&head, 3);
    push_front(&head, 4);
    show(head);
    clear(&head);
    show(head);
    return 0;
}
/** Wynik dzialania programu:
Aktualny stan listy:
Lista jest pusta
Aktualny stan listy:
id: 1

Aktualny stan listy:
id: 4
id: 3
id: 2
id: 1

Aktualny stan listy:
Lista jest pusta
*/

