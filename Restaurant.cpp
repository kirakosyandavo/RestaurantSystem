#include"Restaurant.h"
Restaurant::Restaurant(const Restaurant& other):menu(other.menu){
   for(int i=0;i<other.customers.size();i++){
    customers.push_back(new Customer(*other.customers[i]));
   }
   for(int i=0;i<other.orders.size();i++){
    orders.push_back(*(new Order(other.orders[i])));
   } 
}
Restaurant& Restaurant::operator=(const Restaurant& other){
    if(this==&other){
        return *this;
    }
  menu=other.menu;
  for(int i=0;i<customers.size();i++){
    delete customers[i];
  }
  customers.clear();
  for(int i=0;i<other.customers.size();i++){
    customers.push_back(new Customer(*other.customers[i]));
  }
  orders.clear();
  for(int i=0;i<other.orders.size();i++){
    orders.push_back(*(new Order(other.orders[i])));
  }
  return *this;
}
Restaurant::Restaurant(Restaurant&& other) noexcept{
menu=move(other.menu);
customers=move(other.customers);
orders=move(other.orders);
other.customers.clear();
other.orders.clear();
}
Restaurant& Restaurant::operator=(Restaurant&& other)noexcept{
    menu=move(other.menu);
    for(int i=0;i<customers.size();i++){
        delete customers[i];
    }
    customers.clear();
    customers=move(other.customers);
    other.customers.clear();
    orders.clear();
    orders=move(other.orders);
    other.orders.clear();
    return *this;
}
Restaurant::~Restaurant(){
    menu.~Menu();
    for(int i=0;i<customers.size();i++){
        delete customers[i];
    }
    customers.clear();
    for(int i=0;i<orders.size();i++){
        orders[i].~Order();
    }
    orders.clear();
}
void Restaurant::showMenu() const{
  menu.displayMenu();
}
Customer* Restaurant::getCustomerByName(const string& name){
    for(int i=0;i<customers.size();i++){
        if(customers[i]->getName()==name){
            return customers[i];
        }
    }
    cout<<"there is no such costumer"<<endl;
    return nullptr;
}
void Restaurant::placeNewOrder(const string& customerName){
       Customer* customer=getCustomerByName(customerName); 
          if(!customer){
        string contact;
        std::cin >> contact;
        customer = new Customer(customerName, contact);
        customers.push_back(customer);
    }
    Order order(customer);
    while(true){
    string dishname;
    cout<<"enter the dishname or q to exit"<<endl;
    cin>>dishname;
    if(dishname=="q"){
        return;
    }
    Dish*dish=menu.getDishByName(dishname);
     if(dish){
        order.addDish(dish);
        cout<<"the dish is added"<<endl;
    }
    }
    order.calculateTotal();
    customer->placeOrder(order);
    order.display();
}
void Restaurant::viewCustomerOrderHistory(const string& customerName){
    if(getCustomerByName(customerName)){
        getCustomerByName(customerName)->viewOrderHistory();

    }
    else{
        cout<<"there is no such costumer";
    }
}
void Restaurant::addDishtoMenu(Dish*dish){
    menu.addDish(dish);
}



          

        
    







     












