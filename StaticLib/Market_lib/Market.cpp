#include "Market.h"
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;
namespace Marketplace {
//------------------------------------------------------------------------------------------------------------------
    Customer::Customer(const std::string& fio, const std::string& tel, const std::string& address)
        : fio(fio), tel(tel), address(address) {}

    std::string Customer::GetFIO() const {
        return fio;
    }

    std::string Customer::GetTel() const {
        return tel;
    }

    std::string Customer::GetAddress() const {
        return address;
    }
//------------------------------------------------------------------------------------------------------------------
    Order::Order(const std::string& date, const std::string& order_id)
        : date(date), order_id(order_id) {}

    std::string Order::GetDate() const {
        return date;
    }

    std::string Order::GetOrderID() const {
        return order_id;
    }

//------------------------------------------------------------------------------------------------------------------
    Product::Product(const std::string& product_name, const std::string company_name, const std::string price)
        : product_name(product_name), company_name(company_name), price(price) {}

    std::string Product::GetProductName() const {
        return product_name;
    }

    std::string Product::GetCompanyName() const {
        return company_name;
    }

    std::string Product::GetPrice() const {
        return price;
    }
//------------------------------------------------------------------------------------------------------------------
    Operation::Operation(const std::string& order_operation, const std::string& operation_date, const std::string& tel, const std::string& order_id)
        : order_operation(order_operation), operation_date(operation_date), tel(tel), order_id(order_id) {}

    Operation::Operation(const std::string& order_operation, const std::string& operation_date, const Order& order, const Customer& customer)
        : order_operation(order_operation), operation_date(operation_date), tel(customer.GetTel()), order_id(order.GetOrderID()) {}

    std::string Operation::GetOperation() const {
        return order_operation;
    }

    std::string Operation::GetOperationDate() const {
        return operation_date;
    }

    std::string Operation::GetOrderID() const {
        return order_id;
    }

    std::string Operation::GetTel() const {
        return tel;
    }
//------------------------------------------------------------------------------------------------------------------
    MarketplaceDB::MarketplaceDB() {}
    MarketplaceDB::~MarketplaceDB() {}
    void MarketplaceDB::AddCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void MarketplaceDB::AddOrder(const Order& order) {
        orders.push_back(order);
    }

    void MarketplaceDB::AddProduct(const Product& product) {
        products.push_back(product);
    }

    void MarketplaceDB::AddOperation(const Operation& operation) {
        operations.push_back(operation);
    }
//*********************
    void MarketplaceDB::PrintCustomerList() const {
        if (customers.empty()) {
            std::cout << "Список покупателей пуст..." << std::endl;
        }
        else {
            std::cout << "            Список покупателей" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Customer& customer : customers) {
                std::cout << "ФИО: " << customer.GetFIO() << std::endl;
                std::cout << "Телефон: " << customer.GetTel() << std::endl;
                std::cout << "Адрес: " << customer.GetAddress() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void MarketplaceDB::PrintOrderList() const {
        if (orders.empty()) {
            std::cout << "Список заказов пуст..." << std::endl;
        }
        else {
            std::cout << "              Список Заказов" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Order& order : orders) {
                std::cout << "Дата заказа: " << order.GetDate() << std::endl;
                std::cout << "Номер заказа: " << order.GetOrderID() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void MarketplaceDB::PrintProductList() const {
        if (products.empty()) {
            std::cout << "Список Товаров пуст..." << std::endl;
        }
        else {
            std::cout << "            Список Товаров" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Product& product : products) {
                std::cout << "Название товара: " << product.GetProductName() << std::endl;
                std::cout << "Название фирмы: " << product.GetCompanyName() << std::endl;
                std::cout << "Цена: " << product.GetPrice() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }

    void MarketplaceDB::PrintOperationList() const {
        if (operations.empty()) {
            std::cout << "Список операций пуст..." << std::endl;
        }
        else {
            std::cout << "              Список операций" << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
            for (const Operation& operation : operations) {
                std::cout << "Тип операции: " << operation.GetOperation() << std::endl;
                std::cout << "Дата операции: " << operation.GetOperationDate() << std::endl;
                std::cout << "ID Заказа: " << operation.GetOrderID() << std::endl;
                std::cout << "Телефон: " << operation.GetTel() << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
            }
        }
    }
    Customer MarketplaceDB::InputCustomerFromUser() {
        std::string fio;
        std::string tel;
        std::string address;

        std::cout << " ";
        std::cout << "Введите ФИО: ";
        std::getline(std::cin, fio);

        std::cout << "Введите телефон: ";
        std::getline(std::cin, tel);

        std::cout << "Введите адрес: ";
        std::getline(std::cin, address);

        return Customer(fio, tel, address);
    }

    Order MarketplaceDB::InputOrderFromUser() {
        std::string date;
        std::string order_id;
        std::cout << " ";
        std::cout << "Введите дату заказа: ";
        std::getline(std::cin, date);
        std::cout << "Введите номер заказа: ";
        std::getline(std::cin, order_id);

        return Order(date, order_id);
    }

    Product MarketplaceDB::InputProductFromUser() {
        std::string company_name;
        std::string product_name;
        std::string price;
        std::cout << " ";
        std::cout << "Введите название фирмы: ";
        std::getline(std::cin, company_name);

        std::cout << "Введите название товара: ";
        std::getline(std::cin, product_name);

        std::cout << "Введите цену: ";
        std::getline(std::cin, price);
        return Product(product_name, company_name, price);
    }

    Operation MarketplaceDB::InputOperationFromUser() {
        std::string order_operation;
        std::string operation_date;
        std::string order_id;
        std::string tel;
        std::cout << "Введите тип операции (выдача товара или возврат товара): ";
        std::getline(std::cin, order_operation);

        std::cout << "Введите дату операции: ";
        std::getline(std::cin, operation_date);

        std::cout << "Введите номер товара: ";
        std::getline(std::cin, order_id);
        
        std::cout << "Введите номер телефона: ";
        std::getline(std::cin, tel);

        return Operation(order_operation, operation_date, tel, order_id);
    }

    bool MarketplaceDB::IsInteger(const std::string& str) const {
        if (str.empty()) return false;
        for (char c : str) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    }

}