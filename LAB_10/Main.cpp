// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o wykorzystanie kodu programu z wcześniejszych zajęć
// Klasy Line która reprezentuje linię,
// wg. matetycznego równania: y = a *x + b, oraz pozwala na wyliczania
// wartości operatorem (), i punktu przecięcia z osią odcietych (x'ów) wg równania
// x0 = - b / a;
//
// Należy uzupełnić implementację zadania o klasę LineSmartPtr, która w rzeczywistości
// może odpowiadać tzw. std::shared_ptr, ogólnie sprytny wskaźnik.
// Funkcjonalność LineSmartPtr opiera się o następujące założenia:
// Klasa LineSmartPtr przechowuje wskaźnik do klasy Line, oraz liczbę takich odniesień,
// tzn. liczbę kopii LineSmartPtr, z których każda wskazuje na ten sam obiekt Line.
// W przypadku gdy liczba takich odniesień zostaje zredukowana do 0 to LineSmartPtr
// odpowiada za zwolnienie wskazywanego zasobu klasy Line.
// Oczywiście, należałoby pamiętać o zasadzie 0/3/5,
// co jednak do poprawności tego zadania nie jest niezbędne.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab12/
// * archiwum nie powinno zawierać katalogu build/

#include "Line.h"
#include <vector>
#include <algorithm>

int main (){
  auto fa = new Line(1,2);			 // y = 1*x + 2
  std::cout << *fa << std::endl; // Przeciążony opertor << dla std::ostream
    
  // Inicjalizacja SmartPointer
  std::cout << "line_sptr_1..." << std::endl;
  LineSmartPtr line_sptr_1(fa);
  std::cout << *line_sptr_1 << std::endl;
    
  // Internal scope:
  {
    // Inicjalizacja kolejnego SmartPointer
    LineSmartPtr line_sptr_2(new Line(2,1));
    std::cout << "line_sptr_2..." << std::endl;
    std::cout << *line_sptr_2 << std::endl;
    // Przypisanie wskaźnika:
    // line_sptr_1 zwalnia* zasoby wcześniej przechowywane
    // *pytanie: co znaczy zwalnia?
    line_sptr_1 = line_sptr_2;
  } // Koniec internal scope

  std::cout << "line_sptr_1..." << std::endl;
  std::cout << *line_sptr_1 << std::endl;
    
	return 0;
}
/* wynik dzialania programu:
y = 1* x + 2    x0 = -2
line_sptr_1...
y = 1* x + 2    x0 = -2
line_sptr_2...
y = 2* x + 1    x0 = -0.5
line_sptr_1...
y = 2* x + 1    x0 = -0.5
*/
