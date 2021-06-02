#include <iostream>
#include <string>
#include "header.h" //���������� ������������ ����, � ������� �������� ���� ������

using namespace std;


//� dataInput ���� �������� �������� ����� � ������
//textInCout - �����, ���� �� ��������� �� �������
void checkExceptionForPositiveNumbers(int& dataInput, string textInCout)// ����� ��� ������� �����
{
	bool stopLoop = false;
	int tempNumber;
	do
	{
		cout << textInCout;
		cin >> tempNumber;
		if (std::cin.fail() || tempNumber < 0) // ���� �� ������ �������� ��� � ������ � ����� ��� ����� ���� ��'����
		{
			std::cin.clear(); // ��������� "�������" � cin 

			// ��������� � ������  �� 10000 ������� ����� � ��������� 
			//�� ����� �����(����������, �� ���������� ����� ������� �� �����)
			std::cin.ignore(10000, '\n');
			std::cout << "������� ����������i ���i!\n";

		}
		else
		{
			std::cin.ignore(10000, '\n'); // ��������� ������ ������� � ������
			dataInput = tempNumber;
			stopLoop = true;
		}
	}
	while(!stopLoop);
}
//�� ���� �� � ��������� �������, ��� ��'��� ����� � ������ ��� ���� ���� ��'����
void checkExceptionForNumbers(int& dataInput, string textInCout)// ����� ��� ������� �����
{
	bool stopLoop = false;
	int tempNumber;
	do
	{
		cout << textInCout;
		cin >> tempNumber;
		if (std::cin.fail()) // ���� �� ������ �������� ��� � ������ � ����� ��� ����� ���� ��'����
		{
			std::cin.clear(); // ��������� "�������" � cin 

			// ��������� � ������  �� 10000 ������� ����� � ��������� 
			//�� ����� �����(����������, �� ���������� ����� ������� �� �����)
			std::cin.ignore(10000, '\n');
			std::cout << "������� ����������i ���i!\n";

		}
		else
		{
			std::cin.ignore(10000, '\n'); // ��������� ������ ������� � ������
			dataInput = tempNumber;
			stopLoop = true;
		}
	} while (!stopLoop);
}

int main()
{
	setlocale(LC_ALL, "");

	int stadium_quantity = -1, gym_quantity, court_quantity;
	Stadium* stadium;
	Gym* gym;
	Court* court;

	/*���� �� ������ ���������� ���������, ���������� � ������. ���������� ������� ��������� ����������(1 - 2 �����),
	����� ���� ������ �������� ������ ����������.*/
	//do {
	//cout << "������� ���������� ���������(> 0): ";
	//cin >> stadium_quantity;
	checkExceptionForPositiveNumbers(stadium_quantity, "������� ���������� ���������(> 0): ");
	cout << endl;
	//} while (stadium_quantity <= 0);
	do {
		cout << "������� ���������� ����������(> 0): ";
		cin >> gym_quantity;
		cout << endl;
	} while (gym_quantity <= 0);
	do {
		cout << "������� ���������� ������(> 0): ";
		cin >> court_quantity;
		cout << endl;
	} while (court_quantity <= 0);

	stadium = new Stadium[stadium_quantity]; //�������� ������ ��� �������
	gym = new Gym[gym_quantity];
	court = new Court[court_quantity];

	for (int i = 0; i < stadium_quantity; i++) //���� � ������ ������ ��� ����������� ������(����� ��, ����� ������� ��������� ����������)
	{
		cout << "������� �������� �������� ����� " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(stadium[i].infrastructure_name, 30);
		cout << endl;
		
		do {
			cout << "������� ������� ��������(> 0): ";
			cin >> stadium[i].area;
			cout << endl;
		} while (stadium[i].area <= 0);

		do {
			cout << "������� ����������� ��������(> 0): ";
			cin >> stadium[i].capacity;
			cout << endl;
		} while (stadium[i].capacity <= 0);

		do {
			cout << "������� ���������� ��������� ��������(> 0): "; //������ ���������� ��������� ��������
			cin >> stadium[i].sponsor_quantity;
			cout << endl;
		} while (stadium[i].sponsor_quantity <= 0);

		stadium[i].sponsor = new Sponsor[stadium[i].sponsor_quantity];
		for (int j = 0; j < stadium[i].sponsor_quantity; j++) //������ ���������� � ������ ��������
		{
			cout << "������� ��� �������� ����� " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(stadium[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "������� ���������� ������������, �� ������� �������� �������(> 0): ";
				cin >> stadium[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (stadium[i].sponsor[j].competitions_quantity <= 0);

			stadium[i].sponsor[j].competitions = new Competitions[stadium[i].sponsor[j].competitions_quantity];

			//������ ������� �������� �� ��������� ���������� ������������ - ������ ��������������� ����������
			for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "������� �������� ������������ ����� " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(stadium[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "������� ��� ������ ������������: ";
				cin >> stadium[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "������� ��� ��������� ������������: ";
					cin >> stadium[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (stadium[i].sponsor[j].competitions[m].competitions_start_year > stadium[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "������� ���������� �����������, ������� ������������ � ������������: ";
					cin >> stadium[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (stadium[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				stadium[i].sponsor[j].competitions[m].sportsman = new Sportsman[stadium[i].sponsor[j].competitions[m].sportsman_quantity];

				//� ������ ������������ ����� ��������� ������� ��������� ���������� ����������� - ������ ��������������� ����������
				for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "������� ��� ���������� ����� " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "������� �����, ������� ����� ��������� � ������������: ";
						cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (stadium[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "������� ���������� ����� ������, �������� ���������� ���������: ";
						cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					stadium[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];

					//������ ��������� ����� ���������� ����������� ������ ������ - ������ ��������������� ����������
					for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "������� �������� ���� ������ ����� " << a + 1 << ", ������� ���������� ���������: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "������� ���������� ��������, � ������� ���������� ��������� ������ ����� ������: ";
							cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];

						//�� ������ ��� ������ ����� �������� ��������� �������� - ������ ��������������� ����������
						for (int b = 0; b < stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "������� ��� ������� ����� " << b + 1 << ": ";
							cin.ignore(cin.rdbuf()->in_avail());
							cin.getline(stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
						}
					}
				}
			}
		}
	}
	cout << endl;

	//���� ��� �����, ��� � �� ����������, ������ �������� �� ����������� � �������
	for (int i = 0; i < gym_quantity; i++)
	{
		cout << "������� �������� ��������� ����� " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(gym[i].infrastructure_name, 30);
		cout << endl;

		do {
			cout << "������� ������� ���������(> 0): ";
			cin >> gym[i].area;
			cout << endl;
		} while (gym[i].area <= 0);

		do {
			cout << "������� ���������� ���������� ���������(> 0): ";
			cin >> gym[i].number_of_simulators;
			cout << endl;
		} while (gym[i].number_of_simulators <= 0);

		do {
			cout << "������� ���������� ��������� ���������(> 0): ";
			cin >> gym[i].sponsor_quantity;
			cout << endl;
		} while (gym[i].sponsor_quantity <= 0);

		gym[i].sponsor = new Sponsor[gym[i].sponsor_quantity];
		for (int j = 0; j < gym[i].sponsor_quantity; j++)
		{
			cout << "������� ��� �������� ����� " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(gym[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "������� ���������� ������������, �� ������� �������� �������(> 0): ";
				cin >> gym[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (gym[i].sponsor[j].competitions_quantity <= 0);

			gym[i].sponsor[j].competitions = new Competitions[gym[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "������� �������� ������������ ����� " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(gym[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "������� ��� ������ ������������: ";
				cin >> gym[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "������� ��� ��������� ������������: ";
					cin >> gym[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (gym[i].sponsor[j].competitions[m].competitions_start_year > gym[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "������� ���������� �����������, ������� ������������ � ������������: ";
					cin >> gym[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (gym[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				gym[i].sponsor[j].competitions[m].sportsman = new Sportsman[gym[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "������� ��� ���������� ����� " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "������� �����, ������� ����� ��������� � ������������: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "������� ���������� ����� ������, �������� ���������� ���������: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					gym[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];
					for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "������� �������� ���� ������ ����� " << a + 1 << ", ������� ���������� ���������: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "������� ���������� ��������, � ������� ���������� ��������� ������ ����� ������: ";
							cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];
						for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "������� ��� ������� ����� " << b + 1 << ": ";
							cin.ignore(cin.rdbuf()->in_avail());
							cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
						}
					}
				}
			}
		}
	}
	cout << endl;

	for (int i = 0; i < court_quantity; i++)
	{
		cout << "������� �������� ����� ����� " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(court[i].infrastructure_name, 30);
		cout << endl;

		do {
			cout << "������� ������� �����(> 0): ";
			cin >> court[i].area;
			cout << endl;
		} while (court[i].area <= 0);

		cout << "������� ��� �������� �����: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(court[i].type_of_coverage, 30);
		cout << endl;

		do {
			cout << "������� ���������� ��������� �����(> 0): ";
			cin >> court[i].sponsor_quantity;
			cout << endl;
		} while (court[i].sponsor_quantity <= 0);

		court[i].sponsor = new Sponsor[court[i].sponsor_quantity];
		for (int j = 0; j < court[i].sponsor_quantity; j++)
		{
			cout << "������� ��� �������� ����� " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(court[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "������� ���������� ������������, �� ������� �������� �������(> 0): ";
				cin >> court[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (court[i].sponsor[j].competitions_quantity <= 0);

			court[i].sponsor[j].competitions = new Competitions[court[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "������� �������� ������������ ����� " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(court[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "������� ��� ������ ������������: ";
				cin >> court[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "������� ��� ��������� ������������: ";
					cin >> court[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (court[i].sponsor[j].competitions[m].competitions_start_year > court[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "������� ���������� �����������, ������� ������������ � ������������: ";
					cin >> court[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (court[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				court[i].sponsor[j].competitions[m].sportsman = new Sportsman[court[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "������� ��� ���������� ����� " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "������� �����, ������� ����� ��������� � ������������: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (court[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "������� ���������� ����� ������, �������� ���������� ���������: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					court[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];
					for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "������� �������� ���� ������ ����� " << a + 1 << ", ������� ���������� ���������: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "������� ���������� ��������, � ������� ���������� ��������� ������ ����� ������: ";
							cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];
						for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "������� ��� ������� ����� " << b + 1 << ": ";
							cin.ignore(cin.rdbuf()->in_avail());
							cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name, 30);
							cout << endl;
						}
					}
				}
			}
		}
	}
	cout << endl;

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity); //�������� ���� ������������
}