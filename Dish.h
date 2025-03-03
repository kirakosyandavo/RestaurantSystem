#ifndef DISH
#define DISH

#include<iostream>
using namespace std;
 class Dish{
 protected:
  string name;
  double price;
  public:
  Dish(string dishName,double dishPrice):name(dishName),price(dishPrice){}
  Dish(const Dish& other);
  Dish(Dish&& other)noexcept;
  Dish& operator=(const Dish& other);
  Dish& operator=(Dish&& other)noexcept;
  void display()const;
  double getPrice()const;
  string getName()const;
 };
class Appetizer:public Dish{
    private:
    bool isSpicy;
    public:
    Appetizer(string dishName, double dishPrice, bool spicy);
    void display()const;
};
class Entree: public Dish{
    private:
    int calories;
    public:
    Entree(std::string dishName, double dishPrice, int cal);
    void display() const;
};
class Dessert : public Dish {
    private:
        bool containsNuts;
    public:
        Dessert(std::string dishName, double dishPrice, bool nuts);
        void display() const;
    };
    
#endif 
