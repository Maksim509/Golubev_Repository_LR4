#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;
//глобальные переменные - стороны прямоугольника 
int x, y;

//функция ввода данных
function<void()> EnterNumber(int& varLink, string label){
    //разрабатывается Developer1 - ветка branch_fun_1 
    return [&varLink, label](){
        std::cout << label <<" = " ;
        std::cin >> varLink;
    };
}

//разрабатывается Developer1 - ветка branch_fun_1
void EnterX(){

}

//разрабатывается Developer2 - ветка branch_fun_2
void EnterY(){
    do {
        cout << "Введите Y (>0): ";
        cin >> y;
    } while (y <= 0);
}

//разрабатывается Developer3 - ветка branch_fun_3
void CalcSR(){
}

//разрабатывается Developer4 - ветка branch_fun_4
void CalcGR(){
}

//структра меню
struct MenuItem{
    string title;
    function<void()> action;
};
int main(){
    map<int, MenuItem> menu = {
    {1, {"Bвод x", EnterX}},
    {2, {"Ввод y", EnterY}},
    {3, {"Среднее арифметическое", CalcSR}},
    {4, {"Среднее геометрическое ", CalcGR}},
    };
    int choice = 0;

    while (true) {
        cout << "Меню:" <<endl;
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". "<< item.second.title << endl;
        }
        cout << "0. Выход" <<endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) {
            cout << "© 2025 FirstName LastName" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()) {
            menu [choice].action();
        } else {
            cout<< "Некорректный ввод.";
        }
        cout << endl ;
    }
    return 0;
}