//
// Created by codjs on 2024-04-18.
//
#include "Cart.h"
#include "algorithm"
#include <iostream>

//Cart::Cart(Checkout* checkout) : checkout_(checkout) {};

void Cart::addItem(const Item& item) {
    items.push_back(item);
}

void Cart::deleteItem(int id) {
    const_iterator last = std::remove_if(items.begin(),items.end(),
                   [id](Item& i){return id == i.getId();});

    items.erase(last,items.end());
}
int Cart::checkout() {
    int total = 0;
    std::for_each(items.begin(),items.end(),
                  [&total](Item i){ total = total + i.getPrice()*i.getQuantity();});

    return total;
}
void Cart::viewItemDetails(int id, std::ostream &out) const {

    const_iterator search = std::find_if(items.begin(), items.end(),
                                         [id](const Item &i) { return id == i.getId(); });
    // viewItemDetails 멤버함수가 const로 선언되어있어서
    // 멤버변수를 인자로 줄 때에도 const 로 줘야 함..
    if (search != items.end()) {
        out << "Item " << (*search).getId() << ":" << std::endl;
        out << "Name: " << (*search).getName() << std::endl;
        out << "Quantity: " << (*search).getQuantity() << std::endl;
        out << "Price: " << (*search).getPrice() << std::endl;
    }
    else { out <<  " Item not found." << std::endl;}

}

const_iterator Cart::cbegin() const { return items.begin(); }

const_iterator Cart::cend() const { return items.end();}