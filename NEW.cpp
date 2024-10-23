// shree ganeshaya namaha:|
// shree chamudamataya namaha:|
// shree saraswatimataya namaha:|

/*
 * Copyright (c) [2023-2024] BVM COLLEGE
 *AUTHORS- RUDRA CHAUHAN[23CP010]
         - SHYAM RAMANI [23CP001]
         - SUJAL PATEL  [23CP010]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this copy and source files, to deal
 * with the code/program without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the program is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE PROGRAM CUM CODE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * CODE/PROGRAM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Details {
    std::string name;
    std::string num;
    std::string gmail;
    int noofwall;
    int repainted;
};

Details d1;

int main() {
    label:
    int cus;
    std::cout << "ARE YOU NEW CUSTOMER (yes=1/NO=0) :";
    std::cin >> cus;

    if (cus == 1) {
        std::string new_id;
        std::cout << "ENTER THE NEW ID :";
        std::cin >> new_id;
        new_id += ".txt";

        std::ofstream outFile(new_id);
        
        std::cout << "ENTER THE name :";
        std::cin >> d1.name;
        std::cout << "ENTER THE NUMBER :";
        std::cin >> d1.num;
        std::cout << "ENTER THE GMAIL :";
        std::cin >> d1.gmail;
        std::cout << "ENTER THe noofwall :";
        std::cin >> d1.noofwall;

        outFile << d1.name << "\n" << d1.num << "\n" << d1.gmail << "\n" << d1.noofwall << "\n";
        outFile.close();

        label1:
        std::string wall;
        std::cout << "\nENTER THE PATTERN OF WALL :";
        std::cin >> wall;

        if (wall.length() == d1.noofwall) {
            int fb = wall.find_first_of("Bb");
            int lb = wall.find_last_of("Bb");

            float price;
            std::cout << "ENTER THE PRICE OF EACH WALL :";
            std::cin >> price;

            d1.repainted = lb - fb + 1;
            float tax = d1.repainted * 0.12 * price;
            float netamount = (price * d1.repainted) + tax;

            std::cout << "---------------------INVOICE ---------------------\n";
            std::cout << "---------COMPUTERISED_BLACK_WHITE_COMPANY---------\n";
            std::cout << "CUSTOMER NAME                        : " << d1.name << "\n";
            std::cout << "CUSTOMER NUMBER                      : " << d1.num << "\n";
            std::cout << "NUMBER OF WALL TO BE REPAINTED       : " << d1.repainted << "\n";
            std::cout << "PRICE OF Each wall to be repainted   : " << std::fixed << std::setprecision(2) << price << "\n";
            std::cout << "TAXES OF GOODS ARE 12percent         : " << std::fixed << std::setprecision(2) << tax << "\n";
            std::cout << "THE NET AMOUNT TO PAY                : " << std::fixed << std::setprecision(2) << netamount << "\n";
        } else {
            std::cout << "ENTER THE VALID PATTERN OF WALL ACCORDING TO NUMBER\n";
            goto label1;
        }
    } else if (cus == 0) {
        std::string old_id;
        std::cout << "ENTER THE OLD ID NUMBER :";
        std::cin >> old_id;

        for (int i = 23000; i <= 23100; i++) {
            std::string file = std::to_string(i);
            if (file == old_id) {
                file += ".txt";
                std::ifstream inFile(file);
                
                std::getline(inFile, d1.name);
                std::cout << "\nENTER THE NAME: " << d1.name << "\n";
                std::getline(inFile, d1.num);
                std::cout << "ENTER THE number : " << d1.num << "\n";
                inFile.close();

                std::cout << "THIS IS HOW WE CAN EXTRACT THE ALL THE DEATILS OF CUSTOMER ONCE CREATED\n";
            }
        }
    } else {
        std::cout << "ENTER THE NUMBER 1 OR 0 ACCORDING TO NEW AND OLD\n";
        goto label;
    }

    return 0;
}

