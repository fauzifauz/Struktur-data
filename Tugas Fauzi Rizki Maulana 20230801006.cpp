/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stack>
#include <string>

// Fungsi untuk menampilkan menu
void displayMenu() {
    std::cout << "\nPilih operasi yang ingin dilakukan:\n";
    std::cout << "1. Push (menambahkan buku)\n";
    std::cout << "2. Pop (menghapus buku teratas)\n";
    std::cout << "3. Peek (melihat buku teratas)\n";
    std::cout << "4. isEmpty (cek apakah tumpukan kosong)\n";
    std::cout << "5. Size (cek jumlah buku dalam tumpukan)\n";
    std::cout << "6. Exit (keluar)\n";
}

int main() {
    std::stack<std::string> bookStack;  // Deklarasi stack untuk menyimpan buku
    int choice;  // Variabel untuk menyimpan pilihan pengguna
    std::string book;  // Variabel untuk menyimpan nama buku

    while (true) {  // Loop utama program
        displayMenu();  // Menampilkan menu kepada pengguna
        std::cout << "Masukkan pilihan: ";
        std::cin >> choice;  // Membaca pilihan pengguna

        switch (choice) {  // Memilih operasi berdasarkan pilihan pengguna
            case 1:
                std::cout << "Masukkan nama buku: ";
                std::cin.ignore();  // Membersihkan buffer input agar getline bisa digunakan
                std::getline(std::cin, book);  // Membaca nama buku
                bookStack.push(book);  // Menambahkan buku ke dalam stack
                std::cout << "Buku '" << book << "' telah ditambahkan ke tumpukan.\n";
                break;
            case 2:
                if (!bookStack.empty()) {  // Memeriksa apakah stack tidak kosong
                    std::cout << "Buku '" << bookStack.top() << "' telah dihapus dari tumpukan.\n";
                    bookStack.pop();  // Menghapus buku teratas dari stack
                } else {
                    std::cout << "Tumpukan kosong, tidak ada buku untuk dihapus.\n";
                }
                break;
            case 3:
                if (!bookStack.empty()) {  // Memeriksa apakah stack tidak kosong
                    std::cout << "Buku teratas adalah: " << bookStack.top() << "\n";  // Menampilkan buku teratas
                } else {
                    std::cout << "Tumpukan kosong.\n";
                }
                break;
            case 4:
                if (bookStack.empty()) {  // Memeriksa apakah stack kosong
                    std::cout << "Tumpukan kosong.\n";
                } else {
                    std::cout << "Tumpukan tidak kosong.\n";
                }
                break;
            case 5:
                std::cout << "Jumlah buku dalam tumpukan: " << bookStack.size() << "\n";  // Menampilkan jumlah buku dalam stack
                break;
            case 6:
                std::cout << "Keluar dari program.\n";
                return 0;  // Keluar dari program
            default:
                std::cout << "Pilihan tidak valid, coba lagi.\n";  // Menangani pilihan yang tidak valid
        }
    }
    return 1;  // Mengembalikan nilai 1 sebagai indikasi bahwa program berakhir dengan normal (tidak akan pernah tercapai karena return 0 di case 6)
}
