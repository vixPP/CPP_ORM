#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
#include "tables.h"


using namespace std;

namespace dbo = Wt::Dbo;

void findShop(dbo::Session& s, string NPublisher);

int main()
{


	try
	{
		cout << "Hello" << endl;

		std::string connString =
			"host=localhost "
			"port=5432 "
			"dbname=TEST "
			"user=postgres "
			"password=postgres ";

		auto postgres = make_unique<dbo::backend::Postgres>(connString);
		dbo::Session s;

			s.setConnection(std::move(postgres));

			s.mapClass<Sale>("sale");
			s.mapClass<Stock>("stock");
			s.mapClass<Book>("book");
			s.mapClass<Shop>("shop");
			s.mapClass<Publisher>("publisher");



			try
			{
				s.createTables();
			}
			catch (const std::exception& e)
			{
				std::cout << "Exception happened: " << e.what() << std::endl;
			}

		

		
			//ДОБАВЛЕНИЕ издателя 
			dbo::Transaction transaction{ s };


			unique_ptr<Publisher> Litres{ new Publisher() };
			Litres->name = "Litres";
			Wt::Dbo::ptr<Publisher> Litres_ptr = s.add(move(Litres));

			unique_ptr<Publisher> Eksmo{ new Publisher() };
			Eksmo->name = "Eksmo";
			Wt::Dbo::ptr<Publisher> Eksmo_ptr = s.add(move(Eksmo));

			unique_ptr<Publisher> Altapress{ new Publisher() };
			Altapress->name = "Altapress";
			Wt::Dbo::ptr<Publisher> Altapress_ptr = s.add(move(Altapress));


			//ДОБАВЛЕНИЕ Book

			//ThinkAndGetRich
			unique_ptr<Book> ThinkAndGetRich1{ new Book() };
			ThinkAndGetRich1->title = "Думай и богатей";
			ThinkAndGetRich1->publisher = Litres_ptr;
			Wt::Dbo::ptr<Book> ThinkAndGetRich1_ptr = s.add(move(ThinkAndGetRich1));

			unique_ptr<Book> ThinkAndGetRich2{ new Book() };
			ThinkAndGetRich2->title = "Думай и богатей";
			ThinkAndGetRich2->publisher = Eksmo_ptr;
			Wt::Dbo::ptr<Book> ThinkAndGetRich2_ptr = s.add(move(ThinkAndGetRich2));


			//It
			unique_ptr<Book> It1{ new Book() };
			It1->title = "Оно1";
			It1->publisher = Eksmo_ptr;
			Wt::Dbo::ptr<Book> It1_ptr = s.add(move(It1));

			unique_ptr<Book> It2{ new Book() };
			It2->title = "Оно";
			It2->publisher = Altapress_ptr;
			Wt::Dbo::ptr<Book> It2_ptr = s.add(move(It2));


			//Psychology of influence
			unique_ptr<Book> PsychologyOfiInfluence1{ new Book() };
			PsychologyOfiInfluence1->title = "Психология влияния";
			PsychologyOfiInfluence1->publisher = Litres_ptr;
			Wt::Dbo::ptr<Book> PsychologyOfiInfluence1_ptr = s.add(move(PsychologyOfiInfluence1));

			unique_ptr<Book> PsychologyOfiInfluence2{ new Book() };
			PsychologyOfiInfluence2->title = "Психология влияния";
			PsychologyOfiInfluence2->publisher = Eksmo_ptr;
			Wt::Dbo::ptr<Book> PsychologyOfiInfluence2_ptr = s.add(move(PsychologyOfiInfluence2));

			unique_ptr<Book> PsychologyOfiInfluence3{ new Book() };
			PsychologyOfiInfluence3->title = "Психология влияния";
			PsychologyOfiInfluence3->publisher = Altapress_ptr;
			Wt::Dbo::ptr<Book> PsychologyOfiInfluence3_ptr = s.add(move(PsychologyOfiInfluence3));


			//ДОБАВЛЕНИЕ Shop

			unique_ptr<Shop> Labirint{ new Shop() };
			Labirint->name = "Labirint";
			Wt::Dbo::ptr<Shop> Labirint_ptr = s.add(move(Labirint));

			unique_ptr<Shop> Book24{ new Shop() };
			Book24->name = "Book24";
			Wt::Dbo::ptr<Shop> Book24_ptr = s.add(move(Book24));

			unique_ptr<Shop> Alpina_Book{ new Shop() };
			Alpina_Book->name = "Альпина.Книги";
			Wt::Dbo::ptr<Shop> Alpina_Book_ptr = s.add(move(Alpina_Book));


			//ДОБАВЛЕНИЕ stock

			//Sclad1
			unique_ptr<Stock> Sclad1_1{ new Stock() };
			Sclad1_1->book = It1_ptr;
			Sclad1_1->shop = Labirint_ptr;
			Sclad1_1->count = 150;
			Wt::Dbo::ptr<Stock> Sclad1_1_ptr = s.add(move(Sclad1_1));

			unique_ptr<Stock> Sclad1_2{ new Stock() };
			Sclad1_2->book = ThinkAndGetRich1_ptr;
			Sclad1_2->shop = Labirint_ptr;
			Sclad1_2->count = 75;
			Wt::Dbo::ptr<Stock> Sclad1_2_ptr = s.add(move(Sclad1_2));


			unique_ptr<Stock> Sclad1_3{ new Stock() };
			Sclad1_3->book = PsychologyOfiInfluence1_ptr;
			Sclad1_3->shop = Labirint_ptr;
			Sclad1_3->count = 90;
			Wt::Dbo::ptr<Stock> Sclad1_3_ptr = s.add(move(Sclad1_3));


			//Sclad2

			unique_ptr<Stock> Sclad2_1{ new Stock() };
			Sclad2_1->book = ThinkAndGetRich2_ptr;
			Sclad2_1->shop = Book24_ptr;
			Sclad2_1->count = 45;
			Wt::Dbo::ptr<Stock> Sclad2_1_ptr = s.add(move(Sclad2_1));

			unique_ptr<Stock> Sclad2_2{ new Stock() };
			Sclad2_2->book = PsychologyOfiInfluence2_ptr;
			Sclad2_2->shop = Book24_ptr;
			Sclad2_2->count = 70;
			Wt::Dbo::ptr<Stock> Sclad2_2_ptr = s.add(move(Sclad2_2));


			//Sclad3

			unique_ptr<Stock> Sclad3_1{ new Stock() };
			Sclad3_1->book = It2_ptr;
			Sclad3_1->shop = Alpina_Book_ptr;
			Sclad3_1->count = 121;
			Wt::Dbo::ptr<Stock> Sclad3_1_ptr = s.add(move(Sclad3_1));

			unique_ptr<Stock> Sclad3_2{ new Stock() };
			Sclad3_2->book = PsychologyOfiInfluence3_ptr;
			Sclad3_2->shop = Alpina_Book_ptr;
			Sclad3_2->count = 170;
			Wt::Dbo::ptr<Stock> Sclad3_2_ptr = s.add(move(Sclad3_2));



			//ДОБАВЛЕНИЕ sale

			//Sale1
			unique_ptr<Sale> Sale_1{ new Sale() };
			Sale_1->price = 3.5;
			Sale_1->count = 200;
			Sale_1->date_sale = "21.05.2024";
			Sale_1->stock = Sclad1_1_ptr;
			Wt::Dbo::ptr<Sale> Sale_1_ptr = s.add(move(Sale_1));


			//Sale2
			unique_ptr<Sale> Sale_2{ new Sale() };
			Sale_2->price = 2;
			Sale_2->count = 100;
			Sale_2->date_sale = "01.07.2023";
			Sale_2->stock = Sclad2_2_ptr;
			Wt::Dbo::ptr<Sale> Sale_2_ptr = s.add(move(Sale_2));


			//sale3
			unique_ptr<Sale> Sale_3{ new Sale() };
			Sale_3->price = 2.1;
			Sale_3->count = 70;
			Sale_3->date_sale = "12.01.2024";
			Sale_3->stock = Sclad3_1_ptr;
			Wt::Dbo::ptr<Sale> Sale_3_ptr = s.add(move(Sale_3));


			string NPublisher;
			std::cout << "Введите name publisher: ";
			std::cin >> NPublisher;
			findShop(s, NPublisher);

			transaction.commit();

			
	}
	catch (const exception& e)
	{
		cout << "Exception happened: " << e.what() << endl;
	}

	return 0;
}

void findShop(dbo::Session& s, string NPublisher) 
{
	dbo::ptr<Publisher> findPublisher = s.find<Publisher>().where("name = ?").bind(NPublisher);
	dbo::collection<dbo::ptr<Book>> books = s.find<Book>().where("publisher_id = ?").bind(findPublisher);
	vector<dbo::collection<dbo::ptr<Stock>>> stocks;
	for (const auto& id : books) 
	{
		stocks.push_back(s.find<Stock>().where("book_id = ?").bind(id.id()));
	}
	vector<dbo::collection<dbo::ptr<Shop>>> shops;
	for (const auto& col : stocks) 
	{
		for (const auto& id : col) 
		{
			shops.push_back(s.find<Shop>().where("id = ?").bind(id->shop));
		}
	}
	cout << "Магазины: " << NPublisher << ": \n";
	set<string> names;
	for (const auto& col : shops) 
	{
		for (const auto& id : col) 
		{
			names.insert(id->name);
		}
	}
	for (const auto& name : names) 
	{
		cout << name << endl;
	}
}
