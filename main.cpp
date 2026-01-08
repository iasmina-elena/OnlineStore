#include <iostream>     // pentru cin / cout
#include "Store.h"      // clasa Store
#include "Clothing.h"   // clasa Clothing
#include "Footwear.h"   // clasa Footwear

int main() {

    int buget = 1000;
    Store store;        // creăm magazinul

    // Adăugăm câteva produse inițiale
    store.addProduct(new Clothing("Tricou", 50, 10, "M"));
    store.addProduct(new Clothing("Bluza", 120, 8, "L"));
    store.addProduct(new Clothing("Geaca", 300, 5, "XL"));
    store.addProduct(new Clothing("Pantaloni", 150, 7, "M"));

    // INCALTAMINTE
    store.addProduct(new Footwear("Adidasi", 200, 6, 42));
    store.addProduct(new Footwear("Pantofi", 250, 4, 41));
    store.addProduct(new Footwear("Ghete", 350, 3, 43));
    store.addProduct(new Footwear("Sandale", 100, 10, 40));

    while (true) {      // meniu care rulează până la exit
        try {
            std::cout << "============================================";
            std::cout << "\nBuget disponibil : " << buget << " lei\n";
            std::cout << "\n--- MENIU ---\n";
            std::cout << "1. Afiseaza produse\n";
            std::cout << "2. Plaseaza comanda\n";
            std::cout << "3. Afiseaza comenzi\n";
            std::cout << "4. Returneaza comanda\n";
            std::cout << "0. Iesire\n";
            std::cout << "\nCe optiune alegi? ";

            int opt;
            std::cin >> opt;   // citim opțiunea

            if (opt == 1) {
                // afișăm produsele
                store.listProducts();
            }
            else if (opt == 2) {
                int id, A;
                std::string address;

                // citim datele comenzii
                std::cout << "ID produs: ";
                std::cin >> id;

                std::cout << "Cantitate: ";
                std::cin >> A;

                std::cout << "Adresa livrare (fara spatii): ";
                std::cin >> address;

                // plasăm comanda
                double cost = store.previewOrderCost(id, A);

                if (cost > buget) {
                    std::cout << "Buget insuficient! Cost comanda: " << cost << " lei\n";
                }
                else {
                    int idComanda = store.placeOrderOneItem(id, A, address);
                    buget -= cost;

                    std::cout << "Comanda plasata cu succes\n";
                    std::cout << "ID comanda este: " << idComanda << "\n";
                    std::cout << "Buget ramas: " << buget << " lei\n";
                }
            }
            else if (opt == 3) {
                // afișăm comenzile
                store.listOrders();
            }
            else if (opt == 4) {
                int orderId;
                std::cout << "ID comanda: ";
                std::cin >> orderId;

                double refund = store.returnOrderById(orderId);
                buget += refund;

                std::cout << "Ai primit inapoi: " << refund << " lei\n";
                std::cout << "Buget acum:" << buget << " lei\n";
            }
            else if (opt == 0) {
                // ieșim din program
                break;
            }
            else {
                std::cout << "Optiune invalida!\n";
            }
        }
        catch (const std::exception& e) {
            // prindem toate erorile
            std::cout << "Eroare: " << e.what() << "\n";
        }
    }

    return 0;   // program terminat cu succes
}
