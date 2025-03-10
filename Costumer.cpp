#include"Costumer.h"
Customer::Customer(string customerName,string contact){
 name=customerName;
 contactInfo=contact;
}
Customer::Customer(const Customer& other){
    name=other.name;
    contactInfo=other.contactInfo;
    for(int i=0;i<other.orderHistory.size();i++){
        orderHistory.push_back(Order(other.orderHistory[i]));
    }

}
Customer& Customer::operator=(const Customer& other){
    if(this==&other){
        return *this;
    }
  name=other.name;
  contactInfo=other.contactInfo;
  orderHistory.clear();
  orderHistory=move(other.orderHistory);
  return *this;
}
Customer::Customer(Customer&& other) noexcept{
   name=move(other.name);
   contactInfo=move(other.contactInfo);
   orderHistory=other.orderHistory;
    other.orderHistory.clear();   
}
Customer& Customer::operator=(Customer&&other)noexcept{
    if(this==&other){
        return *this;
    }
    name=move(other.name);
    contactInfo=move(other.contactInfo);
    orderHistory=std::move(other.orderHistory);
    other.orderHistory.clear();
    return *this;
}
void Customer::placeOrder(Order order){
    orderHistory.push_back(order);
}
void Customer::viewOrderHistory() const{
    for(int i=0;i<orderHistory.size();i++){
        orderHistory[i].display();
    }
}
string Customer::getName() const{
    return name;
}





