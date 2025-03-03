#ifndef CUSTOMER
#define CUSTOMER
#include"Dish.h"
#include"Order.h"
#include"vector"
class Order;
class Customer {
    private:
        string name;
        string contactInfo;
        vector<Order> orderHistory;
    public:
            Customer(std::string customerName, std::string contact);
        Customer(const Customer& other);
        Customer& operator=(const Customer& other);
        Customer(Customer&& other) noexcept;
        Customer& operator=(Customer&& other) noexcept;
        ~Customer() = default;
        void placeOrder(Order order);
        void viewOrderHistory() const;
        string getName() const;
    };
    
    
#endif