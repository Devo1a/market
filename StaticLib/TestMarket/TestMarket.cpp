#include <iostream>
#include "..\Market_lib\Market.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Marketplace::MarketplaceDB MarketDB;

    // ������������ ������� ����� ������
    std::cout << "���� ���������� �1" << std::endl;
    Marketplace::Customer customer1 = MarketDB.InputCustomerFromUser();
    std::cout << "���� ���������� �2" << std::endl;
    Marketplace::Customer customer2 = MarketDB.InputCustomerFromUser();
    std::cout << "���� ������" << std::endl;
    Marketplace::Order order = MarketDB.InputOrderFromUser();
    std::cout << "���� ������" << std::endl;
    Marketplace::Product product = MarketDB.InputProductFromUser();
    std::cout << "���� ��������" << std::endl;
    Marketplace::Operation operation = MarketDB.InputOperationFromUser();

    // ���������� ������ � ���� ������
    MarketDB.AddCustomer(customer1);
    MarketDB.AddCustomer(customer2);
    MarketDB.AddOrder(order);
    MarketDB.AddProduct(product);
    MarketDB.AddOperation(operation);

    // ������������ ������� ������ ������
    MarketDB.PrintCustomerList();
    MarketDB.PrintOrderList();
    MarketDB.PrintProductList();
    MarketDB.PrintOperationList();

    return 0;
}