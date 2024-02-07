// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Prosze napisac klasę MapPoint, ktora reprezentuje punkt na
// mapie skladajacy sie z nazwy, dlugosci (longitude) i szerokosci
// (latitude) geograficznej bez oznaczania polkol.

// Metoda mp.distanceVal(dest) zwraca moduł z punktu tworzonego 
// przez różnicę położeń z podanych punktów czyli x_new = dest.x - mp.x, itd.
//
// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz makefile, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "MapPoint.h"

int main() {
  using std::cout;

  cout<<"========== KRK & NYC\n";
  MapPoint krk(19.9383,50.0613);
  MapPoint nyc;
  krk.print();
  nyc.print();
  nyc.set_coordinates(40.7127,-74.0059);
  nyc.print();

  cout<<"========== PORTO & Null Island \n";
  MapPoint porto(41.1621, -8.6219);
  const MapPoint nullIsland;
  porto.print();
  nullIsland.print();

  cout<<"========== DISTANCE VALUE \n";
  cout<<"PRT-Null: "<<nullIsland.distanceVal(porto) << std::endl;
  cout<<"PRT-KRK: "<<krk.distanceVal(&porto) << std::endl;
  return 0;
}
/** Wynik dzialania programu:
========== KRK & NYC
Point: (19.9383, 50.0613)
Point: (0, 0)
Point: (40.7127, -74.0059)
========== PORTO & Null Island 
Point: (41.1621, -8.6219)
Point: (0, 0)
========== DISTANCE VALUE 
PRT-Null: 42.0554
PRT-KRK: 62.403
*/
