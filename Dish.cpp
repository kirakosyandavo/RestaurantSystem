#include"Dish.h"
Dish::Dish(const Dish& other){
    name=other.name;
    price=other.price;
}
Dish::Dish(Dish&& other)noexcept{
    name=move(other.name);
    price=other.price;
    other.price=0.0;
}
Dish& Dish::operator=(const Dish& other){
    if(this== &other){
        return *this;
    }
    name=other.name;
    price=other.price;
    return *this;
}
Dish& Dish::operator=(Dish&& other)noexcept{
    if(this== &other){
        return *this;
    }
    name=move(other.name);
    price=other.price;
    return *this;
}
void Dish::display()const{
    cout<<name<<" ";
    cout<<price<<" ";
}
double Dish::getPrice()const{
    return price;
}
string Dish::getName()const{
    return name;
}
Appetizer:: Appetizer(string dishName, double dishPrice, bool spicy):Dish(dishName,dishPrice){
    isSpicy=spicy;

}
void Appetizer::display()const{
    Dish::display();
    cout<<isSpicy<<endl;
     
}
Entree::Entree(string dishName, double dishPrice, int cal):Dish(dishName,dishPrice){
    calories=cal;
}
void Entree::display()const{
    Dish::display();
    cout<<calories<<endl;
}
Dessert::Dessert(std::string dishName, double dishPrice, bool nuts):Dish(dishName,dishPrice){
    containsNuts=nuts;
}
void Dessert::display()const{
    Dish::display();
    cout<<containsNuts<<endl;
}

        
        
    

