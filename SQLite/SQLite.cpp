#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum DataTypes {INTEGER, FLOAT, TEXT};

//Each command class will extend the validation class for itself which will be implemented by the **validate command class** that inheirts an abstract method
//(command type; Validate command)

class CreateTableCommand {
protected:
	string TableName = "";
	int nrCol = 0;
	int* columns = nullptr;
	DataTypes ColumnType = INTEGER;
public:
	void setTableName(string name)
	{
		if (name != "")
			this->TableName = name;
		else
			throw "Invalid Table Name";
	}
	void setColumns(int* columns, int nrCol)
	{
		if (nrCol > 0)
		{
			this->nrCol = nrCol;
			delete[] this->columns;
			this->columns = new int[nrCol];
			for (int i = 0; i < nrCol; i++)
				this->columns[i] = columns[i];
		}
		else
		{
			throw "Invalid Number of Columns";
		}
	}
	void setColumnType(DataTypes ColumnType)
	{
		this->ColumnType = ColumnType;
	}
	CreateTableCommand(string name, int nrCol, int* columns, DataTypes ColumnType)
	{
		this->setTableName(name);
		this->setColumns(columns, nrCol);
		this->setColumnType(ColumnType);
	}
	~CreateTableCommand() {
		delete[] this->columns;
	}

	CreateTableCommand()
	{

	}
};

class ValidateCommands {
public:
	virtual void CommandType() = 0;
	virtual void ValidateCommand() = 0;
};

class ValidateCommandCreateTable : public ValidateCommands, public CreateTableCommand
{
private:

public:
	void ValidateCommand() {

	}
	void CommandType() {
		if (this->ColumnType != INTEGER)		throw "Ceva";
		cout << this->ColumnType;
	}
};

int main()
{
	int vector1[2] = { 1, 2 };
	CreateTableCommand Employees("Employees", 2, vector1, INTEGER);
	ValidateCommandCreateTable table;
	table.CommandType();











}