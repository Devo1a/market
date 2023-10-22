#pragma once
#include <string>
#include <vector>

namespace Marketplace {

    class Customer {
    private:
        std::string fio;
        std::string tel;
        std::string address;

    public:
        Customer(const std::string& fio, const std::string& tel, const std::string& address);
        std::string GetFIO() const;
        std::string GetTel() const;
        std::string GetAddress() const;
    };

    class Order {
    private:
        std::string date;
        std::string order_id;

    public:
        Order(const std::string& date, const std::string& order_id);
        std::string GetDate() const;
        std::string GetOrderID() const;
    };

    class Product {
    private:
        std::string product_name;
        std::string company_name;
        std::string price;

    public:
        Product(const std::string& product_name, const std::string company_name, const std::string price);
        std::string GetProductName() const;
        std::string GetCompanyName() const;
        std::string GetPrice() const;
    };

    class Operation {
    private:
        std::string order_operation;
        std::string operation_date;
        std::string order_id;
        std::string tel;

    public:
        Operation(const std::string& order_operation, const std::string& operation_date, const std::string& tel, const std::string& order_id);
        Operation(const std::string& order_operation, const std::string& operation_date, const Order& order, const Customer& customer);
        std::string GetOperation() const;
        std::string GetOperationDate() const;
        std::string GetOrderID() const;
        std::string GetTel() const;
    };

    class MarketplaceDB {
    public:
        MarketplaceDB();
        ~MarketplaceDB();

        void AddCustomer(const Customer& customer);
        void AddOrder(const Order& order);
        void AddProduct(const Product& product);
        void AddOperation(const Operation& operation);

        void PrintCustomerList() const;
        void PrintProductList() const;
        void PrintOrderList() const;
        void PrintOperationList() const;

        Customer InputCustomerFromUser();
        Order InputOrderFromUser();
        Product InputProductFromUser();
        Operation InputOperationFromUser();

    private:
        bool IsInteger(const std::string& str) const;

    private:
        std::vector<Customer> customers;
        std::vector<Order> orders;
        std::vector<Product> products;
        std::vector<Operation> operations;
    };
}

