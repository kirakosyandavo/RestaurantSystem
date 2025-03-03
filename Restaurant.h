#include"Menu.h"
#include"Costumer.h"
#include"Order.h"
 class Restaurant{
    private:
    Menu menu;
    vector<Customer*> customers;
    vector<Order> orders;
public:

    Restaurant()=default;
    Restaurant(const Restaurant& other);
    Restaurant& operator=(const Restaurant& other);
    Restaurant(Restaurant&& other) noexcept;
    Restaurant& operator=(Restaurant&& other) noexcept;
    ~Restaurant();
    void addDishtoMenu(Dish*); 
    void showMenu() const;
    Customer* getCustomerByName(const std::string& name);
    void placeNewOrder(const string& customerName);
    void viewCustomerOrderHistory(const std::string& customerName);
}; 
  