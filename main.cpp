#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
#include "tables.h"


using namespace std;

namespace dbo = Wt::Dbo;

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
			"password=89617479237k ";

		auto postgres = make_unique<dbo::backend::Postgres>(connString);
		dbo::Session s;


		s.setConnection(std::move(postgres));
		s.mapClass<Book>("book");
		s.mapClass<Publisher>("publisher");
		s.mapClass<Shop>("shop");
		s.mapClass<Stock>("stock");
		s.mapClass<Sale>("sale");

		//s.dropTables();
		s.createTables();

		//Добавление издателя 
		dbo::Transaction transaction{ s };

		std::unique_ptr<Publisher> publisher{ new Publisher() };
		//publisher->name = "Joe";
		//publisher->name = "Hoe"
		//publisher->name = "Hoe";
		dbo::ptr<Publisher> publisherPtr = s.add(std::move(publisher));

		transaction.commit();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception happened: " << e.what() << std::endl;
	}

	return 0;
}