#include"Dish.h"
#include<vector>
class Menu {
    private:
        vector<Dish*> dishes;
    public:
        Menu()=default; 
        Menu(const Menu& other);
        Menu& operator=(const Menu& other);
        Menu(Menu&& other) noexcept;
        Menu& operator=(Menu&& other) noexcept;
        ~Menu();
        void addDish(Dish* dish);
        void displayMenu() const;
        Dish* getDishByName(const string& dishName) const;
};