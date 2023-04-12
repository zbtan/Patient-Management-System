#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection()
{
	sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
	connection = driver->connect("tcp://localhost", "root", "");

	connection->setSchema("patient_management_system_w1");
}

DatabaseConnection::~DatabaseConnection()
{
	connection->close();

	delete connection;
}

sql::PreparedStatement* DatabaseConnection::prepareStatement(std::string query)
{
	return connection->prepareStatement(query);
}