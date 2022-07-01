#include<iostream>
#include<string>
using namespace std;

class UserInput {
protected:
	int input;
	int quantity;

public:
	//Set Input
	void setInput() {
		cout << "Enter desired item number or 0 to exit" << endl;
		cin >> input;
	}

	//Set Quantity
	void setQuantity() {
		cout << "Enter quantity of item" << endl;
		cin >> quantity;
	}
};

class InventoryManagement {
protected:

	int bill;
	string item[3] = { "Lays","Coke","Oreo" };
	int price[3] = { 50,80,20 };
	int stock[3] = { 10,10,10 };

	//Display Menu
	void displayMenu() {
		cout << "-----Menu-----" << endl;
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << item[i] << " " << price[i] << ".00 Rs" << endl;
		}
	}

	//Stock update
	void stockUpdate(int num, int quantity) {
		stock[num - 1] = stock[num - 1] - quantity;
	}

	//Billing
	void calculateBill(int num, int quantity) {
		bill = (price[num - 1] * quantity);
	}
};

class Balance {
protected:

	int balance;
	int addition;

public:
	//Set Balance
	void setBalance() {
		cout << "Enter your cash" << endl;
		cin >> balance;
	}

	//Addition in Balance
	void Addition() {
		cout << "Enter more cash" << endl;
		cin >> addition;
		balance = balance + addition;
	}
};

class VendingMachine :public InventoryManagement, UserInput, Balance {
public:

	VendingMachine() {

		//Menu Display
		displayMenu();

		//Set Input
		setInput();

		while (input != 0) {
			//Set Quantity
			setQuantity();

			while (quantity > stock[input - 1]) {
				cout << "Only " << stock[input - 1] << " items left in stock" << endl;
				setQuantity();
			}

			//Set Balance
			setBalance();

			//calculate Bill
			calculateBill(input, quantity);

			while (balance < bill) {
				Addition();
			}

			//Deduction from balance
			balance = balance - bill;

			//Deduction from stock
			stockUpdate(input, quantity);

			//Confirmation
			cout << "-----Thank You For Shoping-----" << endl;
			cout << "Remaining Balance = " << balance << endl;

			setInput();

			if (input == 0) {
				if (balance > 0) {
					cout << "Your Remaining balance is returned. Collect it!" << endl;
				}
			}
			else
			{
				continue;
			}
		}
	}
};

int main() {
	VendingMachine v1;
	return 0;
}