#include <iostream>
#include <string>
#include "header.h" //подключаем заголовочный файл, в котором хранятся наши классы

using namespace std;


//в dataInput буде записане значення вводу з консолі
//textInCout - текст, який має вивестися на консоль
void checkExceptionForPositiveNumbers(int& dataInput, string textInCout)// тільки для додатніх чисел
{
	bool stopLoop = false;
	int tempNumber;
	do
	{
		cout << textInCout;
		cin >> tempNumber;
		if (std::cin.fail() || tempNumber < 0) // якщо не змогли записати дані з консолі в змінну або число було від'ємне
		{
			std::cin.clear(); // забирання "помилки" з cin 

			// видалення з буферу  до 10000 символів разом з переходом 
			//на новий рядок(припускаємо, що користувач більше символів не введе)
			std::cin.ignore(10000, '\n');
			std::cout << "Введено неправильнi данi!\n";

		}
		else
		{
			std::cin.ignore(10000, '\n'); // видалення зайвих значень з буфера
			dataInput = tempNumber;
			stopLoop = true;
		}
	}
	while(!stopLoop);
}
//то саме що і попередня функція, але від'ємні число з консолі теж може бути від'ємне
void checkExceptionForNumbers(int& dataInput, string textInCout)// тільки для додатніх чисел
{
	bool stopLoop = false;
	int tempNumber;
	do
	{
		cout << textInCout;
		cin >> tempNumber;
		if (std::cin.fail()) // якщо не змогли записати дані з консолі в змінну або число було від'ємне
		{
			std::cin.clear(); // забирання "помилки" з cin 

			// видалення з буферу  до 10000 символів разом з переходом 
			//на новий рядок(припускаємо, що користувач більше символів не введе)
			std::cin.ignore(10000, '\n');
			std::cout << "Введено неправильнi данi!\n";

		}
		else
		{
			std::cin.ignore(10000, '\n'); // видалення зайвих значень з буфера
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

	/*Ниже мы вводим количество стадионов, спортзалов и кортов. Желательно вводить небольшое количество(1 - 2 штуки),
	иначе ввод данных окажется весьма длительным.*/
	//do {
	//cout << "Введите количество стадионов(> 0): ";
	//cin >> stadium_quantity;
	checkExceptionForPositiveNumbers(stadium_quantity, "Введите количество стадионов(> 0): ");
	cout << endl;
	//} while (stadium_quantity <= 0);
	do {
		cout << "Введите количество спортзалов(> 0): ";
		cin >> gym_quantity;
		cout << endl;
	} while (gym_quantity <= 0);
	do {
		cout << "Введите количество кортов(> 0): ";
		cin >> court_quantity;
		cout << endl;
	} while (court_quantity <= 0);

	stadium = new Stadium[stadium_quantity]; //выделяем память под массивы
	gym = new Gym[gym_quantity];
	court = new Court[court_quantity];

	for (int i = 0; i < stadium_quantity; i++) //ниже в циклах вводим все необходимые данные(опять же, лучше вводить небольшое количество)
	{
		cout << "Введите название стадиона номер " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(stadium[i].infrastructure_name, 30);
		cout << endl;
		
		do {
			cout << "Введите площадь стадиона(> 0): ";
			cin >> stadium[i].area;
			cout << endl;
		} while (stadium[i].area <= 0);

		do {
			cout << "Введите вместимость стадиона(> 0): ";
			cin >> stadium[i].capacity;
			cout << endl;
		} while (stadium[i].capacity <= 0);

		do {
			cout << "Введите количество спонсоров стадиона(> 0): "; //вводим количество спонсоров стадиона
			cin >> stadium[i].sponsor_quantity;
			cout << endl;
		} while (stadium[i].sponsor_quantity <= 0);

		stadium[i].sponsor = new Sponsor[stadium[i].sponsor_quantity];
		for (int j = 0; j < stadium[i].sponsor_quantity; j++) //вводим информацию о каждом спонсоре
		{
			cout << "Введите имя спонсора номер " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(stadium[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "Введите количество соревнований, за которые отвечает спонсор(> 0): ";
				cin >> stadium[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (stadium[i].sponsor[j].competitions_quantity <= 0);

			stadium[i].sponsor[j].competitions = new Competitions[stadium[i].sponsor[j].competitions_quantity];

			//каждый спонсор отвечает за некоторое количество соревнований - вводим соответствующую информацию
			for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "Введите название соревнования номер " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(stadium[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "Введите год начала соревнования: ";
				cin >> stadium[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "Введите год окончания соревнования: ";
					cin >> stadium[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (stadium[i].sponsor[j].competitions[m].competitions_start_year > stadium[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "Введите количество спортсменов, которые учавствовали в соревновании: ";
					cin >> stadium[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (stadium[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				stadium[i].sponsor[j].competitions[m].sportsman = new Sportsman[stadium[i].sponsor[j].competitions[m].sportsman_quantity];

				//в каждом соревновании может принимать участие некоторое количество спортсменов - вводим соответствующую информацию
				for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "Введите имя спортсмена номер " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "Введите место, которое занял спортсмен в соревновании: ";
						cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (stadium[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "Введите количество видов спорта, которыми занимается спортсмен: ";
						cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					stadium[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];

					//каждый спортсмен может заниматься несколькими видами спорта - вводим соответствующую информацию
					for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "Введите название вида спорта номер " << a + 1 << ", которым занимается спортсмен: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "Введите количество тренеров, у которых занимается спортсмен данным видом спорта: ";
							cin >> stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];

						//за каждый вид спорта может отвечать несколько тренеров - вводим соответствующую информацию
						for (int b = 0; b < stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "Введите имя тренера номер " << b + 1 << ": ";
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

	//ниже все также, как и со стадионами, только работаем со спортзалами и кортами
	for (int i = 0; i < gym_quantity; i++)
	{
		cout << "Введите название спортзала номер " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(gym[i].infrastructure_name, 30);
		cout << endl;

		do {
			cout << "Введите площадь спортзала(> 0): ";
			cin >> gym[i].area;
			cout << endl;
		} while (gym[i].area <= 0);

		do {
			cout << "Введите количество тренажеров спортзала(> 0): ";
			cin >> gym[i].number_of_simulators;
			cout << endl;
		} while (gym[i].number_of_simulators <= 0);

		do {
			cout << "Введите количество спонсоров спортзала(> 0): ";
			cin >> gym[i].sponsor_quantity;
			cout << endl;
		} while (gym[i].sponsor_quantity <= 0);

		gym[i].sponsor = new Sponsor[gym[i].sponsor_quantity];
		for (int j = 0; j < gym[i].sponsor_quantity; j++)
		{
			cout << "Введите имя спонсора номер " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(gym[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "Введите количество соревнований, за которые отвечает спонсор(> 0): ";
				cin >> gym[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (gym[i].sponsor[j].competitions_quantity <= 0);

			gym[i].sponsor[j].competitions = new Competitions[gym[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "Введите название соревнования номер " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(gym[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "Введите год начала соревнования: ";
				cin >> gym[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "Введите год окончания соревнования: ";
					cin >> gym[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (gym[i].sponsor[j].competitions[m].competitions_start_year > gym[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "Введите количество спортсменов, которые учавствовали в соревновании: ";
					cin >> gym[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (gym[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				gym[i].sponsor[j].competitions[m].sportsman = new Sportsman[gym[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "Введите имя спортсмена номер " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "Введите место, которое занял спортсмен в соревновании: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "Введите количество видов спорта, которыми занимается спортсмен: ";
						cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					gym[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];
					for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "Введите название вида спорта номер " << a + 1 << ", которым занимается спортсмен: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "Введите количество тренеров, у которых занимается спортсмен данным видом спорта: ";
							cin >> gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];
						for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "Введите имя тренера номер " << b + 1 << ": ";
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
		cout << "Введите название корта номер " << i + 1 << ": ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(court[i].infrastructure_name, 30);
		cout << endl;

		do {
			cout << "Введите площадь корта(> 0): ";
			cin >> court[i].area;
			cout << endl;
		} while (court[i].area <= 0);

		cout << "Введите тип покрытия корта: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(court[i].type_of_coverage, 30);
		cout << endl;

		do {
			cout << "Введите количество спонсоров корта(> 0): ";
			cin >> court[i].sponsor_quantity;
			cout << endl;
		} while (court[i].sponsor_quantity <= 0);

		court[i].sponsor = new Sponsor[court[i].sponsor_quantity];
		for (int j = 0; j < court[i].sponsor_quantity; j++)
		{
			cout << "Введите имя спонсора номер " << j + 1 << ": ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(court[i].sponsor[j].sponsor_name, 30);
			cout << endl;

			do {
				cout << "Введите количество соревнований, за которые отвечает спонсор(> 0): ";
				cin >> court[i].sponsor[j].competitions_quantity;
				cout << endl;
			} while (court[i].sponsor[j].competitions_quantity <= 0);

			court[i].sponsor[j].competitions = new Competitions[court[i].sponsor[j].competitions_quantity];
			for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
			{
				cout << "Введите название соревнования номер " << m + 1 << ": ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin.getline(court[i].sponsor[j].competitions[m].competitions_name, 30);
				cout << endl;

				cout << "Введите год начала соревнования: ";
				cin >> court[i].sponsor[j].competitions[m].competitions_start_year;
				cout << endl;

				do {
					cout << "Введите год окончания соревнования: ";
					cin >> court[i].sponsor[j].competitions[m].competitions_end_year;
					cout << endl;
				} while (court[i].sponsor[j].competitions[m].competitions_start_year > court[i].sponsor[j].competitions[m].competitions_end_year);

				do {
					cout << "Введите количество спортсменов, которые учавствовали в соревновании: ";
					cin >> court[i].sponsor[j].competitions[m].sportsman_quantity;
					cout << endl;
				} while (court[i].sponsor[j].competitions[m].sportsman_quantity <= 0);

				court[i].sponsor[j].competitions[m].sportsman = new Sportsman[court[i].sponsor[j].competitions[m].sportsman_quantity];
				for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
				{
					cout << "Введите имя спортсмена номер " << n + 1 << ": ";
					cin.ignore(cin.rdbuf()->in_avail());
					cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name, 30);
					cout << endl;

					do {
						cout << "Введите место, которое занял спортсмен в соревновании: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].place;
						cout << endl;
					} while (court[i].sponsor[j].competitions[m].sportsman[n].place <= 0);

					do {
						cout << "Введите количество видов спорта, которыми занимается спортсмен: ";
						cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity;
						cout << endl;
					} while (court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity <= 0);

					court[i].sponsor[j].competitions[m].sportsman[n].sport = new Kind_of_Sport[court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity];
					for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
					{
						cout << "Введите название вида спорта номер " << a + 1 << ", которым занимается спортсмен: ";
						cin.ignore(cin.rdbuf()->in_avail());
						cin.getline(court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name, 30);
						cout << endl;

						do {
							cout << "Введите количество тренеров, у которых занимается спортсмен данным видом спорта: ";
							cin >> court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity;
							cout << endl;
						} while (court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity <= 0);

						court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer = new Trainer[court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity];
						for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
						{
							cout << "Введите имя тренера номер " << b + 1 << ": ";
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

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity); //вызываем меню пользователя
}