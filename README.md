# rain_of_falling_stars
Ogólny opis:

Jako końcowy projekt zamierzam wykonać grę zręcznościową. Gra będzie miała tytuł "Rain of shooting stars". Gra nie będzie posiadała fabuły, a jej celem będzie uzyskanie jak największej ilości punktów. Do wyboru będą dwa różne poziomy trudności łatwy oraz trudny.Różniły będą się między sobą prędkością spadających obiektów oraz tym jak często będą spadać. Parametry od których będzie zależeć rodzaj poziomu będą przekazane za pomocą wektora.

Rozgrywka będzie polegała na tym, że jako nasza postać będziemy musieli unikać spadających z nieba przedmiotów oraz będzie można zbierać specjalne spadające przedmioty aby zdobyć bonusowe punkty.

W grze jako sterowanie będzie używana klawiatura, najprawdopodobniej tylko przyciski WSAD do przemieszczania postacią. Poprzez wciśnięcie odpowiedniego klawisza naszemu bohaterowi będzie dodawana prędkość. Wyskok w górę będzie opierał się na rzucie pionowym lub ukośnym w górę przy z góry założonej prędkości początkowej wzdłuż osi OY.  

Interakcje między obiektami:

Spadające obiekty będą mogły odbijać się od siebie. Odbijanie będzie niesprężyste. Po zderzeniu spadającego obiektu z postacią rozpadnie się ona, a postać w zależności od rodzaju obiektu straci punkty życia lub zyska bonus. Gdy spadający obiekt dotknie podłoża również się rozpadnie, jednak nie wywoła to żadnego odkształcenia na podłożu. Bohater będzie chodził po podłożu jak po platformie.
 
 Szczegółowy opis obiektów:
 W menu głównym:

Klasa Score, której obiekt jest tworzony po odpowiednim kliknięciu w menu. W obiekcie przechowywany jest wektor w którym zapisane są wszystkie dotychczasowe pliki, które zapisywane są z pliku. Obiekt ten posiada metodę wyświtlającą najlepsze wyniki w oknie.
 
 Klasa Information, sluży do wyświetlania w oknie informacji na temat rozgrywki.
 
 Podczas rozgrywki:
 Tworzone są obiekty głównej postaci oraz meteorytów. klasy tych obiektów dziedziczą od wspólnej klasy która posiada takie atrybuty jak prędkość na osi 0X i OY. Oraz ramy w jakich mogą się poruszać obiekty.
 
Obiekt głównej postaci którą sterujemy podczas rozgrywki.
Postać posiada atrybuty:
zdrowie, punktacja, nazwa, prędkość w osi 0X oraz OY, wysokość na jaką może maksymalnie wyskoczyć.

Główny bohater może poruszać się w lewo oraz w prawo oraz może skakać. Wchodzi on w interakcje z podłożem po którym się porusza oraz ze spadającymi meteorytami. Postać ta także posiada odpowiednią animacje podczas wykonywania odpowiedniego ruchu.

Kolejnymi obiektami są spadające mateoryty,będzie można wyróżnić cztery rodzaje meteorytów. 
Wszystkie rodzaje będą wchodzić w interakcje między sobą, bohaterem oraz podłożem.
Wszystkie obiekty meteorytów posiadają własności takie jak: bonus zdrowia, bonus punktów, prędkość w osi OX oraz OY.

Meteoryty spadają z góry. Podczas spadania odbijają się od siebie oraz od ram w jakich spadają.

Z czterech rodzajów meteorytów będzie można wyróżnić:
Czerwony- Występuje najczęściej, zabiera on życie głównej postaci.
Żółty- Występuje troche rzadziej od czerwonego, zabiera on zdobyte punkty.
Zielony- Występuje jeszcze rzadziej, jest to meteoryt który warto zbierać, ponieważ dodaje dodatowe punkty.
Niebieski- Występuje najrzadziej, daje dodatkowe punkty zdrowia.

Poniżej zamieszczony został szkic interfejsu:

![](https://github.com/Michal1017kow/rain_of_falling_stars/blob/master/szkic_interfejs.png)

Przedstawienie wstępnego szkicu ekranu gry podczas rozrywki:

![](https://github.com/Michal1017kow/rain_of_falling_stars/blob/master/ekran_gry.png)


Instrukcja obsługi do gry:

Instrukcja do menu główne:

Po uruchomieniu gry wyświetla się menu główne. Wyświetlają się opcje: Start, Score, Quit, Write Name, Easy, Hard oraz Information.

Po kliknięciu Start uruchamia się rozgrywka i można zacząć grać.
Po kliknięciu opcje Score wyswietli się lista najlepszych wyników jakie dotychczas uzyskano.
Przycisk Quit będzie odpowiadać za opuszczenie gry.
Write Name w menu informuje o tym, żeby wpisać nazwę gracza. Aby to wykonać nie trzeba nic klikać,tylko podczas wyświetlania menu wpisać nazwę gracza za pomocą klawiatury. Po wpisaniu kolejnych liter na ekranie ukazują się te litery.
Dwa przyciski Easy oraz Hard slużą do wyboru poziomu trudności podczas rozgrywki.Działają one jak przełącznik. Aktualnie wybrany kolor jest podświetlony, aby zmienić poziom należy kliknąć na jeden z dwóch przycisków.
Ostatnią opcją jest Information. Po kliknięciu na napis ukazuje się okno z informacjami odnośnie rozgrywki, czyli jak sterować postacią oraz jaki kolor meteorytu jest odpowiedzialny za co.

Instrukcja do rozgrywki:

Po kliknięciu przycisku start w menu głównym rozpoczyna się rozgrywka.

Celem rozgrywki jest zdobycie jak największej liczby punktów.

Postacią można sterować przyciskami:
W- skok
A- poruszanie się w lewo
D- poruszanie się w prawo

Na ekranie rozgrywki wyświetla się także poziom naszega zdrowia oraz liczba zdobytych punktów.

Rozgrywka polega na unikaniu lub zbieraniu odpowiednich meteorytów spadających z nieba.

Rozgrywka kończy się kiedy poziom zycia spadnie do 0 lub poniżej.
