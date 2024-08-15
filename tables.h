#pragma once
#include "Wt/Dbo/Dbo.h"
#include "Wt/Dbo/backend/Postgres.h"
#include <iostream>
#include <vector>


namespace dbo = Wt::Dbo;

class Book;

class Publisher
{
public:
    std::string name = "";
    dbo::collection<dbo::ptr<Book>> books;

    template <class Action>
    void persist(Action& a)
    {
        dbo::field(a, name, "name");
        dbo::hasMany(a, books, dbo::ManyToOne, "publisher");
    }
};



class Stock;

class Book 
{
public:
    std::string title = "";
    dbo::ptr<Publisher> publisher;
    dbo::collection<dbo::ptr<Stock>> stocks;
    template <class Action>

    void persist(Action& a) 
    {
        dbo::field(a, title, "title");
        dbo::belongsTo(a, publisher, "publisher");
        dbo::hasMany(a, stocks, dbo::ManyToMany, "book");

    }
};

class Stock;

class Shop 
{
public:
    std::string name = "";
    dbo::collection<dbo::ptr<Stock>> stocks;

    template <class Action>
    void persist(Action& a) 
    {
        dbo::field(a, name, "name");
        dbo::hasMany(a, stocks, dbo::ManyToMany, "shop");
    }
};

class Sale;

class Stock 
{
public:
    int count = 0;
    dbo::ptr<Book> book;
    dbo::ptr<Shop> shop;
    dbo::collection<dbo::ptr<Sale>> sales;

    template <class Action>
    void persist(Action& a) 
    {
        dbo::belongsTo(a, book, "book");
        dbo::belongsTo(a, shop, "shop");
        dbo::field(a, count, "count");
        dbo::hasMany(a, sales, dbo::ManyToOne, "stock");
    }

};

class Sale 
{
public:
    float price = 0.0f;
    std::string date_sale = "";
    dbo::ptr<Stock> stock;
    int count = 0;

    template <class Action>
    void persist(Action& a) 
    {
        dbo::field(a, price, "price");
        dbo::field(a, date_sale, "date_sale");
        dbo::belongsTo(a, stock, "stock");
        dbo::field(a, count, "count");
    }
};