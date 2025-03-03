#include"Order.h"
Order::Order(Customer* customer):m_customer{customer},totalPrice{0}{}


Order::Order(const Order& other){
    m_customer=new Customer(*(other.m_customer));
    totalPrice=other.totalPrice;
    for(int i=0;i<other.orderedDishes.size();i++){
    orderedDishes.push_back(new Dish(*other.orderedDishes[i]));
    }
}
Order& Order::operator=(const Order& other){
    if(this==&other){
        return *this;
    }
    totalPrice=other.totalPrice;
    delete m_customer;
    m_customer=new Customer(*(other.m_customer));
    for(int i=0;i<orderedDishes.size();i++){
        delete orderedDishes[i];   
    }
    orderedDishes.clear();
    for(int i=0;i<other.orderedDishes.size();i++){
          orderedDishes.push_back(new Dish(*other.orderedDishes[i]));
    }
    return *this;
}

void Order::display()const{
for(int i=0;i<orderedDishes.size();i++){
    orderedDishes[i]->display();
}
cout<<totalPrice;
}
Order::~Order(){
    delete m_customer;
    for(int i=0;i<orderedDishes.size();i++){
        delete orderedDishes[i];
    }
    orderedDishes.clear();
    totalPrice=0;
}
Order::Order(Order&& other)noexcept{
    m_customer=other.m_customer;
    other.m_customer=nullptr;
    totalPrice=other.totalPrice;
    orderedDishes=move(other.orderedDishes);
    other.orderedDishes.clear();     

}
Order& Order::operator=(Order&& other)noexcept{
    if(this==&other){
        return *this;
    }
    delete m_customer;
    m_customer=other.m_customer;
    other.m_customer=nullptr;
    orderedDishes.clear();
    orderedDishes=move(other.orderedDishes);
    other.orderedDishes.clear();
    totalPrice=other.totalPrice;
    return *this;
}
void Order::addDish(Dish* dish){
    orderedDishes.push_back(dish);
}
void Order::calculateTotal(){
    totalPrice=0;
  for(int i=0;i<orderedDishes.size();i++){
    totalPrice+=orderedDishes[i]->getPrice();
  }

}
