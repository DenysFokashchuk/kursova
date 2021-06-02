#include <iostream>
#include <string>
#include "header.h"

using namespace std;

//меню, которое позволяет пользователю перемещатьмя по функциям программы
void Methods::Menu(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	int number;

	cout << "Меню пользователя" << endl;
	cout << "Спортивные постройки: 1" << endl;
	cout << "Состязания: 2" << endl;
	cout << "Спортсмены: 3" << endl;
	cout << "Тренеры: 4" << endl;
	cout << "Призеры: 5" << endl;
	cout << "Выйти из программы: 6" << endl;

	cout << endl;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number) //по номеру вызываем необходимую функцию
	{
	case 1:
		Methods::Sports_buildings(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	case 2:
		Methods::Competitions(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	case 3:
		Methods::Sportsmans(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	case 4:
		Methods::Trainers(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	case 5:
		Methods::Awardees(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	case 6:
		cout << "Вы решили не продолжать." << endl << endl;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	}
}
void Methods::Sports_buildings(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "Вывести список сооружения определенного типа: 1" << endl;
	cout << "Вывести список сооружений и даты проведения соревнований в течении определенного промежутка времени: 2" << endl << endl;

	string building_name;
	int number, start_of_competitions, end_of_competitions, count = 0;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введите тип сооружения(stadium, gym или court): ";
		cin >> building_name;
		cout << endl;

		if (building_name == "stadium") //в циклах при совпадении типа сооружения выводим названия сооружений
		{
			cout << "Название стадионов:" << endl;
			for (int i = 0; i < stadium_quantity; i++)
				cout << i + 1 << ". " << stadium[i].infrastructure_name << endl;
			cout << endl;
		}
		else if (building_name == "gym")
		{
			cout << "Название спортзалов:" << endl;
			for (int i = 0; i < gym_quantity; i++)
				cout << i + 1 << ". " << gym[i].infrastructure_name << endl;
			cout << endl;
		}
		else if (building_name == "court")
		{
			cout << "Название кортов:" << endl;
			for (int i = 0; i < court_quantity; i++)
				cout << i + 1 << ". " << court[i].infrastructure_name << endl;
			cout << endl;
		}
		else
			cout << "Тип постройки введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	case 2:
		cout << "Введите год начала соревнований: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Введите год окончания соревнований: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Соревнования на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*Если год начала и окончания соревнования входит в заданный промежуток - выводим информацию на экран.
					Аналогично работаем со спортзалами и кортами.*/
					if (stadium[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (stadium[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "Стадион номер " << i + 1 << ": " << stadium[i].infrastructure_name << endl;
							cout << "Название соревнования: " << stadium[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Год начала соревнования: " << stadium[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "Год окончания соревнования: " << stadium[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет стадионов, на которых проводились соревнования в течении заданного временного промежутка." << endl << endl;
		count = 0;

		cout << "Соревнования в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "Спортзал номер " << i + 1 << ": " << gym[i].infrastructure_name << endl;
							cout << "Название соревнования: " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Год начала соревнования: " << gym[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "Год окончания соревнования: " << gym[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортзалов, на которых проводились соревнования в течении заданного временного промежутка." << endl << endl;
		count = 0;

		cout << "Соревнования на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "Корт номер " << i + 1 << ": " << court[i].infrastructure_name << endl;
							cout << "Название соревнования: " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "Год начала соревнования: " << court[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "Год окончания соревнования: " << court[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет кортов, на которых проводились соревнования в течении заданного временного промежутка." << endl << endl;
		count = 0;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Competitions(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "Получить список соревнований, проведенных в течении заданного промежутка времени: 1" << endl;
	cout << "Получить список соревнований, проведенных в указанном спортивном сооружении: 2" << endl << endl;

	string infrastructure_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введите год начала соревнований: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Введите год окончания соревнований: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Соревнования на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*Если год начала и окончания соревнования входит в заданный промежуток - выводим информацию на экран.
					Аналогично работаем со спортзалами и кортами.*/
					if (stadium[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (stadium[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << stadium[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводились в заданный промежуток времени на стадионах." << endl;
		cout << endl;
		count = 0;

		cout << "Соревнования в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводились в заданный промежуток времени в спортзалах." << endl;
		cout << endl;
		count = 0;

		cout << "Соревнования на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводились в заданный промежуток времени на кортах." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "Введите название сооружения: ";
		cin >> infrastructure_name;
		cout << endl;

		cout << "Соревнования на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			/*Если название сооружения совпало с существующим - выводим информацию на экран.
			Аналогично работаем со спортзалами и кортами.*/
			if (infrastructure_name == stadium[i].infrastructure_name)
			{
				for (int j = 0; j < stadium[i].sponsor_quantity; j++)
				{
					for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << stadium[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводятся на данном стадионе." << endl;
		cout << endl;
		count = 0;

		cout << "Соревнования в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			if (infrastructure_name == gym[i].infrastructure_name)
			{
				for (int j = 0; j < gym[i].sponsor_quantity; j++)
				{
					for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводятся в данном спортзале." << endl;
		cout << endl;
		count = 0;

		cout << "Соревнования на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			if (infrastructure_name == court[i].infrastructure_name)
			{
				for (int j = 0; j < court[i].sponsor_quantity; j++)
				{
					for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
						cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
				}
				count++;
			}
		}
		if (count == 0)
			cout << "Нет соревнований, которые проводятся на данном корте." << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Sportsmans(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "Список спортсменов, которые занимаются указанным видом спорта: 1" << endl;
	cout << "Список спортсменов, что тренируются у какого-либо тренера в целом: 2" << endl;
	cout << "Список спортсменов, которые занимаются более чем одним видом спорта: 3" << endl << endl;

	string sport_type, trainer_name;
	int number, count = 0;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введите вид спорта: ";
		cin >> sport_type;
		cout << endl;

		cout << "Спортсмены, которые тренируются на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							/*Если название вида спорта совпало с существующим - выводим информацию на экран.
							Аналогично работаем со спортзалами и кортами.*/
							if (sport_type == stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются данным видом спорта на стадионах." << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							if (sport_type == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются данным видом спорта в спортзалах." << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							if (sport_type == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются данным видом спорта на кортах." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "Введите имя тренера: ";
		cin >> trainer_name;
		cout << endl;

		cout << "Спортсмены, которые тренируются на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							for (int b = 0; b < stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
							{
								/*Если имя тренера совпало с существующим - выводим информацию на экран.
								Аналогично работаем со спортзалами и кортами.*/
								if (trainer_name == stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются у данного тренера на стадионах." << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
							{
								if (trainer_name == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются у данного тренера в спортзалах." << endl;
		cout << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
							{
								if (trainer_name == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name)
								{
									cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
									count++;
								}
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются у данного тренера на кортах." << endl;
		cout << endl;
		count = 0;
		break;
	case 3:
		cout << "Спортсмены, которые тренируются на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						/*Если спортсмен занимается более чем одним видом спорта - выводим информацию на экран.
						Аналогично работаем со спортзалами и кортами.*/
						if (stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity > 1)
						{
							cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Виды спорта: " << endl;
							for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
								cout << a + 1 << "; " << stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются более чем одним видом спорта на стадионах." << endl << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity > 1)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Виды спорта: " << endl;
							for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
								cout << a + 1 << "; " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются более чем одним видом спорта в спортзалах." << endl << endl;
		count = 0;

		cout << "Спортсмены, которые тренируются на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity > 1)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "Виды спорта: " << endl;
							for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
								cout << a + 1 << "; " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
							cout << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет спортсменов, которые занимаются более чем одним видом спорта на кортах." << endl << endl;
		count = 0;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Trainers(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "Получить список тренеров указанного спортсмена: 1" << endl;
	cout << "Получить список тренеров по указанному виду спорта: 2" << endl << endl;

	string sportsman_name, sport_name;
	int number, count = 0;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введите имя спортсмена: ";
		cin >> sportsman_name;
		cout << endl;

		cout << "Тренеры, которые проводят занятия на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						/*Если имя спортсмена совпало с существующим - выводим информацию на экран.
						Аналогично работаем со спортзалами и кортами.*/
						if (sportsman_name == stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
							{
								cout << "Вид спорта: " << stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << b + 1 << ". " << stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые проводят занятия у данного спортсмена на стадионах." << endl << endl;
		count = 0;

		cout << "Тренеры, которые проводят занятия в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (sportsman_name == gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
							{
								cout << "Вид спорта: " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << b + 1 << ". " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые проводят занятия у данного спортсмена в спортзалах." << endl << endl;
		count = 0;

		cout << "Тренеры, которые проводят занятия на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						if (sportsman_name == court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
							{
								cout << "Вид спорта: " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
								for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << b + 1 << ". " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								cout << endl;
							}
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые проводят занятия у данного спортсмена на кортах." << endl << endl;
		count = 0;
		break;
	case 2:
		cout << "Введите вид спорта: ";
		cin >> sport_name;
		cout << endl;

		cout << "Тренеры, которые проводят занятия на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							/*Если вид спорта совпал с существующим - выводим информацию на экран.
							Аналогично работаем со спортзалами и кортами.*/
							if (sport_name == stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые отвечают за данный вид спорта на стадионах." << endl;
		cout << endl;
		count = 0;

		cout << "Тренеры, которые проводят занятия в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < gym[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							if (sport_name == gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые отвечают за данный вид спорта в спортзалах." << endl;
		cout << endl;
		count = 0;

		cout << "Тренеры, которые проводят занятия на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						for (int a = 0; a < court[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
						{
							if (sport_name == court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name)
							{
								for (int b = 0; b < court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer_quantity; b++)
									cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].trainer[b].trainer_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Нет тренеров, которые отвечают за данный вид спорта на кортах." << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Awardees(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "Получить список призеров указанного соревнования: 1" << endl;
	cout << "Получить список организаторов соревнований и число проведенных ними соревнований в течении определенного времени: 2" << endl << endl;

	string competition_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "Введите номер: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "Введите название соревнования: ";
		cin >> competition_name;
		cout << endl;

		cout << "Тренировки на стадионах:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*Если название соревнования совпало с существующим - выводим призеров на экран(1 - 3 места).
					Аналогично работаем со спортзалами и кортами.*/
					if (competition_name == stadium[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (stadium[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Данного соревнования, проводимого на стадионах, не существует, либо призеры отсутствуют." << endl;
		cout << endl;
		count = 0;

		cout << "Тренировки в спортзалах:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (competition_name == gym[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < gym[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (gym[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << gym[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Данного соревнования, проводимого в спортзалах, не существует, либо призеры отсутствуют." << endl;
		cout << endl;
		count = 0;

		cout << "Тренировки на кортах:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (competition_name == court[i].sponsor[j].competitions[m].competitions_name)
					{
						for (int n = 0; n < court[i].sponsor[j].competitions[m].sportsman_quantity; n++)
						{
							if (court[i].sponsor[j].competitions[m].sportsman[n].place < 4)
							{
								cout << "- " << court[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
								count++;
							}
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "Данного соревнования, проводимого на кортах, не существует, либо призеры отсутствуют." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "Введите год начала соревнований: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "Введите год окончания соревнований: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "Спонсоры стадионов:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				/*Если время проведения соревнования попало в промежуток - выводим информацию на экран.
				Аналогично работаем со спортзалами и кортами.*/
				cout << "Спонсор: " << stadium[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					if (stadium[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (stadium[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << stadium[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У данного спонсора отсутствуют соревнования, проводимые в данный период времени." << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "Спонсоры спортзалов:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				cout << "Спонсор: " << gym[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < gym[i].sponsor[j].competitions_quantity; m++)
				{
					if (gym[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (gym[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У данного спонсора отсутствуют соревнования, проводимые в данный период времени." << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "Спонсоры кортов:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				cout << "Спонсор: " << court[i].sponsor[j].sponsor_name << endl;
				for (int m = 0; m < court[i].sponsor[j].competitions_quantity; m++)
				{
					if (court[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (court[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "- " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							count++;
						}
					}
				}
				if (count == 0)
					cout << "У данного спонсора отсутствуют соревнования, проводимые в данный период времени." << endl;
				cout << endl;
			}
		}
		count = 0;
		break;
	default:
		cout << "Номер введен некорректно, попробуйте еще раз." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}