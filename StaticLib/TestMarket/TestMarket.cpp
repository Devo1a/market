#include <iostream>
#include "..\Market_lib\Market.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Marketplace::MarketplaceDB MarketDB;

    // Тестирование функций ввода данных
    std::cout << "Ввод Покупателя №1" << std::endl;
    Marketplace::Customer customer1 = MarketDB.InputCustomerFromUser();
    std::cout << "Ввод Покупателя №2" << std::endl;
    Marketplace::Customer customer2 = MarketDB.InputCustomerFromUser();
    std::cout << "Ввод заказа" << std::endl;
    Marketplace::Order order = MarketDB.InputOrderFromUser();
    std::cout << "Ввод товара" << std::endl;
    Marketplace::Product product = MarketDB.InputProductFromUser();
    std::cout << "Ввод операции" << std::endl;
    Marketplace::Operation operation = MarketDB.InputOperationFromUser();

    // Добавление данных в базу данных
    MarketDB.AddCustomer(customer1);
    MarketDB.AddCustomer(customer2);
    MarketDB.AddOrder(order);
    MarketDB.AddProduct(product);
    MarketDB.AddOperation(operation);

    // Тестирование функций вывода данных
    MarketDB.PrintCustomerList();
    MarketDB.PrintOrderList();
    MarketDB.PrintProductList();
    MarketDB.PrintOperationList();

    return 0;
}