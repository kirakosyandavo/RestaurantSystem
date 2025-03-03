#ifndef ORDER
#define ORDER
#include"Dish.h"
#include"Costumer.h"
#include<vector>
class Customer;
class Order {
    private:
        Customer* m_customer;
        vector<Dish*> orderedDishes;
        double totalPrice;
    public:
    Order()=default;
    explicit Order(Customer* customer);
    Order(const Order& other);
    Order& operator=(const Order& other);
    Order(Order&& other)noexcept;
     Order& operator=(Order&& other)noexcept;
    void addDish(Dish* dish);
    void display()const;
    void calculateTotal();
    ~Order();

};

#endif
