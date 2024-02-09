// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Celem zadania jest refaktoryzacja i rozszerzenie klas Point3D oraz VPointCloud z poprzednich zajęć.
// Kolejne funkcjonalności zostały opisane w ramach funkcji main()
//
// Przy wykonaniu zadania nie wolno korzystać z internetu z wyjątkiem linków podanych wyżej,
// notatek, ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz CMakeLists.txt, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "PointCloud.h"

int main() {

  const Point3D myPoint3D_1({1.1, 2.2, 3.3});
  myPoint3D_1.displayCoordinates();

  Point3D myPoint3D_2 = 1;      // konwersja
  myPoint3D_2.displayCoordinates();

  // Konwersja Point3D na double, zwracamy długość wektora wyznaczonego
  // od początku ukł. współ. do danego punktu
  //double magnitude = myPoint3D_2; // konwersja niejawna zabroniona, 
                                    // to się nie powinno kompilować!
  double magnitude = static_cast<double>(myPoint3D_2); // ale to już OK.
  std::cout << "myPoint3D_2 (magnitude): " << magnitude << std::endl;
    
  // Konwersja na std::string, należy tutaj również wykorzystać std::to_string()
  // Dedykowana metoda:
  std::string myPoint3D_1_str1 = Point3D::to_string(myPoint3D_1);
  std::cout << "myPoint3D_1 str1: " << myPoint3D_1_str1 << std::endl;
  // Ale możliwa jest też kowersja niejawna:
  
  std::string myPoint3D_1_str2 = myPoint3D_1;
  std::cout << "myPoint3D_1 str2: " << myPoint3D_1_str2 << std::endl;
    
  std::cout << "Chmura punktów 1:\n";
  VPointCloud myVPointCloud_1; // wersja z std::vector
  myVPointCloud_1.addPoint(new Point3D({2.0, 3.0, 4.0})); // przechowujemy wskaźniki na Point3D
  myVPointCloud_1.addPoint();
  myVPointCloud_1.displayPoints();
    
  std::cout << "Chmura 1 + Chmura 1:\n"; // tak to nie pomyłka! W tym przypadku nic nie jest kopiowane!
  myVPointCloud_1.add(myVPointCloud_1);
  myVPointCloud_1.displayPoints();
    
  std::cout << "Przenoszenie punktów między obiektami, 1 -> 2:\n";
  VPointCloud myVPointCloud_2(std::move(myVPointCloud_1));
  std::cout << "Chmura mv:\n";
  myVPointCloud_2.displayPoints();
  std::cout << "Chmura 1:\n";
  myVPointCloud_1.displayPoints();
  std::cout << "... puste" << std::endl;
    
  return 0;
}

/* wynik dzialania
(1.10, 2.20, 3.30)
(1.00, 1.00, 1.00)
myPoint3D_2 (magnitude): 1.73
myPoint3D_1 str1: (1.100000,2.200000,3.300000)
myPoint3D_1 str2: (1.100000,2.200000,3.300000)
Chmura punktów 1:
(2.00, 3.00, 4.00)
(0.00, 0.00, 0.00)
Chmura 1 + Chmura 1:
(2.00, 3.00, 4.00)
(0.00, 0.00, 0.00)
Przenoszenie punktów między obiektami, 1 -> 2:
Chmura mv:
(2.00, 3.00, 4.00)
(0.00, 0.00, 0.00)
Chmura 1:
... puste
 */
