# Magazin online


# Descrierea proiectului

Proiectul implementează o aplicație de tip magazin online, care permite gestionarea produselor, plasarea comenzilor și returnarea acestora. Aplicația este construită folosind principiile fundamentale ale Programării Orientate pe Obiecte (POO): abstractizare, moștenire, polimorfism, încapsulare și tratarea erorilor prin excepții.


# Structura aplicatiei

1. Clasa Product (clasă abstractă)

Clasa Product reprezintă baza tuturor produselor din sistem. Aceasta definește comportamentul comun și caracteristicile generale ale oricărui produs.

 - Atribute:
     1. id – identificator unic pentru fiecare produs 
     2. name – numele produsului
     3. price – prețul produsului
     4. stock – cantitatea disponibilă în stoc
     5. static int nextID – variabilă statică pentru generarea automată a ID-urilor

 - Metode:
    1. getID() – returnează ID-ul produsului
    2. getPrice() – returnează prețul
    3. getStock() – returnează stocul disponibil
    4. decreaseStock(int A) – scade stocul cu validare (nu permite valori invalide sau stoc insuficient)
    5. increaseStock(int A) – mărește stocul
    6. type() – metodă virtuală pură care returnează tipul produsului
    7. print() – metodă virtuală pură care definește modul de afișare

Clasa este abstractă, ceea ce înseamnă că nu poate fi instanțiată direct, ci doar prin clasele derivate.

2. Clasa Clothing

Reprezintă un tip concret de produs: haine.

 - Atribute:
 size – mărimea hainelor (S, M, L, XL etc.)

 - Metode:
    1. type() – returnează tipul produsului („Haina”)
    2. print() – afișează informațiile despre produs într-un format specific

3. Clasa Footwear
   
Reprezintă un alt tip concret de produs: încălțăminte.

 - Atribute:
size – mărimea numerică a încălțămintei (40, 41, 42 etc.)
 - Metode:
    1. type() – returnează tipul produsului („Incaltaminte”)
    2. print() – afișează informațiile despre produs într-un format specific

4. Structura OrderItem
   
Reprezintă o poziție dintr-o comandă.

Conține:
Product* product – pointer către produsul comandat
int quantity – cantitatea comandată

5. Clasa Order
   
Clasa Order reprezintă o comandă plasată de utilizator.

 - Atribute:
     1. id – identificator unic
     2. static int nextID – generator de ID-uri
     3. bool returned – indică dacă comanda a fost returnată
     4. address – adresa de livrare
     5. vector<OrderItem> items – lista de produse din comandă
 - Metode:
     1. getID() – returnează ID-ul comenzii
     2. isReturned() – verifică dacă este returnată
     3. totalBeforeRules() – calculează suma inițială
     4. totalFinal() – aplică reguli comerciale:
     5. reducere de 100 lei pentru comenzi peste 500 lei
     6. taxă de transport de 20 lei pentru comenzi sub 100 lei
     7. returnOrder() – marchează comanda ca returnată și restabilește stocurile
     8. print() – afișează informațiile despre comandă

6. Clasa Store
   
Reprezintă magazinul propriu-zis și gestionează produsele și comenzile.
 - Atribute:
     1. vector<Product*> products – lista de produse disponibile
     2. vector<Order> orders – lista comenzilor
     3. findProductById(int id) – metodă privată pentru căutarea produselor
 - Metode:
     1. addProduct() – adaugă un produs în magazin
     2. listProducts() – afișează toate produsele
     3. placeOrderOneItem() – plasează o comandă pentru un produs
     4. returnOrderById() – returnează o comandă
     5. listOrders() – afișează toate comenzile
     6. previewOrderCost() – calculează costul unei comenzi înainte de plasare

# Funcționalitățile pentru utilizator (End User)

Prin intermediul acestui program, utilizatorul poate:
  - Vizualiza toate produsele disponibile, cu informații complete (nume, preț, stoc, mărime).
  -  Plasa o comandă, alegând produsul, cantitatea și adresa de livrare.
  -  Vizualiza toate comenzile plasate și statusul acestora (activă / returnată).
  -  Returna o comandă, caz în care:
      1. primește banii înapoi
      2. stocul produselor este refăcut
  - Gestiona un buget, care scade la cumpărare și crește la returnare.
  - Primește mesaje de eroare clare în cazul unor acțiuni invalide (stoc insuficient, ID greșit, comandă deja returnată etc.).

