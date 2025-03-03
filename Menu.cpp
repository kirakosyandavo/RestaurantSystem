#include"Menu.h"
Menu::Menu(const Menu& other){
    for(int i=0;i<dishes.size();i++){
        dishes.push_back(new Dish(*other.dishes[i]));
    }
}
Menu& Menu::operator=(const Menu& other){
    if(this==&other){
        return *this;
    }
    for(int i=0;i<dishes.size();i++){
        delete dishes[i];
    }
    dishes.clear();
    for(int i=0;i<dishes.size();i++){
        dishes.push_back(new Dish(*other.dishes[i]));
    }
    return *this;
}
Menu::Menu(Menu&& other) noexcept{
    dishes=move(other.dishes);
    other.dishes.clear();
}
Menu& Menu::operator=(Menu&& other)noexcept{
    if(this==&other){
        return *this;
    }
    for(int i=0;i<dishes.size();i++){
        delete dishes[i];
    }
    dishes=move(other.dishes);
    for(int i=0;i<other.dishes.size();i++){
        other.dishes[i]=nullptr;
    }
    return *this;
}
void Menu::addDish(Dish*dish){
    dishes.push_back(dish);
}
void Menu::displayMenu()const{
    for(int i=0;i<dishes.size();i++){
        dishes[i]->display();
    }
}
Dish* Menu::getDishByName(const string& dishName)const{
    for(int i=0;i<dishes.size();i++){
        if(dishes[i]->getName()==dishName){
            return dishes[i];
        }
    }
       cout<<"there is no such dish";
       return nullptr;
}
Menu::~Menu(){
  for(int i=0;i<dishes.size();i++){
    delete dishes[i];
  }
  dishes.clear();
}
