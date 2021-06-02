#include <iostream>
#include <string>
#include "header.h"

using namespace std;

//����, ������� ��������� ������������ ������������ �� �������� ���������
void Methods::Menu(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	int number;

	cout << "���� ������������" << endl;
	cout << "���������� ���������: 1" << endl;
	cout << "����������: 2" << endl;
	cout << "����������: 3" << endl;
	cout << "�������: 4" << endl;
	cout << "�������: 5" << endl;
	cout << "����� �� ���������: 6" << endl;

	cout << endl;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number) //�� ������ �������� ����������� �������
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
		cout << "�� ������ �� ����������." << endl << endl;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
		break;
	}
}
void Methods::Sports_buildings(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "������� ������ ���������� ������������� ����: 1" << endl;
	cout << "������� ������ ���������� � ���� ���������� ������������ � ������� ������������� ���������� �������: 2" << endl << endl;

	string building_name;
	int number, start_of_competitions, end_of_competitions, count = 0;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������� ��� ����������(stadium, gym ��� court): ";
		cin >> building_name;
		cout << endl;

		if (building_name == "stadium") //� ������ ��� ���������� ���� ���������� ������� �������� ����������
		{
			cout << "�������� ���������:" << endl;
			for (int i = 0; i < stadium_quantity; i++)
				cout << i + 1 << ". " << stadium[i].infrastructure_name << endl;
			cout << endl;
		}
		else if (building_name == "gym")
		{
			cout << "�������� ����������:" << endl;
			for (int i = 0; i < gym_quantity; i++)
				cout << i + 1 << ". " << gym[i].infrastructure_name << endl;
			cout << endl;
		}
		else if (building_name == "court")
		{
			cout << "�������� ������:" << endl;
			for (int i = 0; i < court_quantity; i++)
				cout << i + 1 << ". " << court[i].infrastructure_name << endl;
			cout << endl;
		}
		else
			cout << "��� ��������� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	case 2:
		cout << "������� ��� ������ ������������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "������� ��� ��������� ������������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "������������ �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*���� ��� ������ � ��������� ������������ ������ � �������� ���������� - ������� ���������� �� �����.
					���������� �������� �� ����������� � �������.*/
					if (stadium[i].sponsor[j].competitions[m].competitions_start_year >= start_of_competitions)
					{
						if (stadium[i].sponsor[j].competitions[m].competitions_end_year <= end_of_competitions)
						{
							cout << "������� ����� " << i + 1 << ": " << stadium[i].infrastructure_name << endl;
							cout << "�������� ������������: " << stadium[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "��� ������ ������������: " << stadium[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "��� ��������� ������������: " << stadium[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "��� ���������, �� ������� ����������� ������������ � ������� ��������� ���������� ����������." << endl << endl;
		count = 0;

		cout << "������������ � ����������:" << endl;
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
							cout << "�������� ����� " << i + 1 << ": " << gym[i].infrastructure_name << endl;
							cout << "�������� ������������: " << gym[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "��� ������ ������������: " << gym[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "��� ��������� ������������: " << gym[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "��� ����������, �� ������� ����������� ������������ � ������� ��������� ���������� ����������." << endl << endl;
		count = 0;

		cout << "������������ �� ������:" << endl;
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
							cout << "���� ����� " << i + 1 << ": " << court[i].infrastructure_name << endl;
							cout << "�������� ������������: " << court[i].sponsor[j].competitions[m].competitions_name << endl;
							cout << "��� ������ ������������: " << court[i].sponsor[j].competitions[m].competitions_start_year << endl;
							cout << "��� ��������� ������������: " << court[i].sponsor[j].competitions[m].competitions_end_year << endl << endl;
							count++;
						}
					}
				}
			}
		}
		if (count == 0)
			cout << "��� ������, �� ������� ����������� ������������ � ������� ��������� ���������� ����������." << endl << endl;
		count = 0;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Competitions(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "�������� ������ ������������, ����������� � ������� ��������� ���������� �������: 1" << endl;
	cout << "�������� ������ ������������, ����������� � ��������� ���������� ����������: 2" << endl << endl;

	string infrastructure_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������� ��� ������ ������������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "������� ��� ��������� ������������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "������������ �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*���� ��� ������ � ��������� ������������ ������ � �������� ���������� - ������� ���������� �� �����.
					���������� �������� �� ����������� � �������.*/
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
			cout << "��� ������������, ������� ����������� � �������� ���������� ������� �� ���������." << endl;
		cout << endl;
		count = 0;

		cout << "������������ � ����������:" << endl;
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
			cout << "��� ������������, ������� ����������� � �������� ���������� ������� � ����������." << endl;
		cout << endl;
		count = 0;

		cout << "������������ �� ������:" << endl;
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
			cout << "��� ������������, ������� ����������� � �������� ���������� ������� �� ������." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "������� �������� ����������: ";
		cin >> infrastructure_name;
		cout << endl;

		cout << "������������ �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			/*���� �������� ���������� ������� � ������������ - ������� ���������� �� �����.
			���������� �������� �� ����������� � �������.*/
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
			cout << "��� ������������, ������� ���������� �� ������ ��������." << endl;
		cout << endl;
		count = 0;

		cout << "������������ � ����������:" << endl;
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
			cout << "��� ������������, ������� ���������� � ������ ���������." << endl;
		cout << endl;
		count = 0;

		cout << "������������ �� ������:" << endl;
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
			cout << "��� ������������, ������� ���������� �� ������ �����." << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Sportsmans(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "������ �����������, ������� ���������� ��������� ����� ������: 1" << endl;
	cout << "������ �����������, ��� ����������� � ������-���� ������� � �����: 2" << endl;
	cout << "������ �����������, ������� ���������� ����� ��� ����� ����� ������: 3" << endl << endl;

	string sport_type, trainer_name;
	int number, count = 0;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������� ��� ������: ";
		cin >> sport_type;
		cout << endl;

		cout << "����������, ������� ����������� �� ���������:" << endl;
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
							/*���� �������� ���� ������ ������� � ������������ - ������� ���������� �� �����.
							���������� �������� �� ����������� � �������.*/
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
			cout << "��� �����������, ������� ���������� ������ ����� ������ �� ���������." << endl;
		cout << endl;
		count = 0;

		cout << "����������, ������� ����������� � ����������:" << endl;
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
			cout << "��� �����������, ������� ���������� ������ ����� ������ � ����������." << endl;
		cout << endl;
		count = 0;

		cout << "����������, ������� ����������� �� ������:" << endl;
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
			cout << "��� �����������, ������� ���������� ������ ����� ������ �� ������." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "������� ��� �������: ";
		cin >> trainer_name;
		cout << endl;

		cout << "����������, ������� ����������� �� ���������:" << endl;
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
								/*���� ��� ������� ������� � ������������ - ������� ���������� �� �����.
								���������� �������� �� ����������� � �������.*/
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
			cout << "��� �����������, ������� ���������� � ������� ������� �� ���������." << endl;
		cout << endl;
		count = 0;

		cout << "����������, ������� ����������� � ����������:" << endl;
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
			cout << "��� �����������, ������� ���������� � ������� ������� � ����������." << endl;
		cout << endl;
		count = 0;

		cout << "����������, ������� ����������� �� ������:" << endl;
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
			cout << "��� �����������, ������� ���������� � ������� ������� �� ������." << endl;
		cout << endl;
		count = 0;
		break;
	case 3:
		cout << "����������, ������� ����������� �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						/*���� ��������� ���������� ����� ��� ����� ����� ������ - ������� ���������� �� �����.
						���������� �������� �� ����������� � �������.*/
						if (stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity > 1)
						{
							cout << "- " << stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name << endl;
							cout << "���� ������: " << endl;
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
			cout << "��� �����������, ������� ���������� ����� ��� ����� ����� ������ �� ���������." << endl << endl;
		count = 0;

		cout << "����������, ������� ����������� � ����������:" << endl;
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
							cout << "���� ������: " << endl;
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
			cout << "��� �����������, ������� ���������� ����� ��� ����� ����� ������ � ����������." << endl << endl;
		count = 0;

		cout << "����������, ������� ����������� �� ������:" << endl;
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
							cout << "���� ������: " << endl;
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
			cout << "��� �����������, ������� ���������� ����� ��� ����� ����� ������ �� ������." << endl << endl;
		count = 0;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Trainers(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "�������� ������ �������� ���������� ����������: 1" << endl;
	cout << "�������� ������ �������� �� ���������� ���� ������: 2" << endl << endl;

	string sportsman_name, sport_name;
	int number, count = 0;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������� ��� ����������: ";
		cin >> sportsman_name;
		cout << endl;

		cout << "�������, ������� �������� ������� �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					for (int n = 0; n < stadium[i].sponsor[j].competitions[m].sportsman_quantity; n++)
					{
						/*���� ��� ���������� ������� � ������������ - ������� ���������� �� �����.
						���������� �������� �� ����������� � �������.*/
						if (sportsman_name == stadium[i].sponsor[j].competitions[m].sportsman[n].sportsman_name)
						{
							for (int a = 0; a < stadium[i].sponsor[j].competitions[m].sportsman[n].sport_quantity; a++)
							{
								cout << "��� ������: " << stadium[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "��� ��������, ������� �������� ������� � ������� ���������� �� ���������." << endl << endl;
		count = 0;

		cout << "�������, ������� �������� ������� � ����������:" << endl;
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
								cout << "��� ������: " << gym[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "��� ��������, ������� �������� ������� � ������� ���������� � ����������." << endl << endl;
		count = 0;

		cout << "�������, ������� �������� ������� �� ������:" << endl;
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
								cout << "��� ������: " << court[i].sponsor[j].competitions[m].sportsman[n].sport[a].sport_name << endl;
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
			cout << "��� ��������, ������� �������� ������� � ������� ���������� �� ������." << endl << endl;
		count = 0;
		break;
	case 2:
		cout << "������� ��� ������: ";
		cin >> sport_name;
		cout << endl;

		cout << "�������, ������� �������� ������� �� ���������:" << endl;
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
							/*���� ��� ������ ������ � ������������ - ������� ���������� �� �����.
							���������� �������� �� ����������� � �������.*/
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
			cout << "��� ��������, ������� �������� �� ������ ��� ������ �� ���������." << endl;
		cout << endl;
		count = 0;

		cout << "�������, ������� �������� ������� � ����������:" << endl;
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
			cout << "��� ��������, ������� �������� �� ������ ��� ������ � ����������." << endl;
		cout << endl;
		count = 0;

		cout << "�������, ������� �������� ������� �� ������:" << endl;
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
			cout << "��� ��������, ������� �������� �� ������ ��� ������ �� ������." << endl;
		cout << endl;
		count = 0;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}
void Methods::Awardees(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity)
{
	cout << "�������� ������ �������� ���������� ������������: 1" << endl;
	cout << "�������� ������ ������������� ������������ � ����� ����������� ���� ������������ � ������� ������������� �������: 2" << endl << endl;

	string competition_name;
	int start_of_competitions, end_of_competitions, number, count = 0;
	cout << "������� �����: ";
	cin >> number;
	cout << endl;

	switch (number)
	{
	case 1:
		cout << "������� �������� ������������: ";
		cin >> competition_name;
		cout << endl;

		cout << "���������� �� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				for (int m = 0; m < stadium[i].sponsor[j].competitions_quantity; m++)
				{
					/*���� �������� ������������ ������� � ������������ - ������� �������� �� �����(1 - 3 �����).
					���������� �������� �� ����������� � �������.*/
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
			cout << "������� ������������, ����������� �� ���������, �� ����������, ���� ������� �����������." << endl;
		cout << endl;
		count = 0;

		cout << "���������� � ����������:" << endl;
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
			cout << "������� ������������, ����������� � ����������, �� ����������, ���� ������� �����������." << endl;
		cout << endl;
		count = 0;

		cout << "���������� �� ������:" << endl;
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
			cout << "������� ������������, ����������� �� ������, �� ����������, ���� ������� �����������." << endl;
		cout << endl;
		count = 0;
		break;
	case 2:
		cout << "������� ��� ������ ������������: ";
		cin >> start_of_competitions;
		cout << endl;

		cout << "������� ��� ��������� ������������: ";
		cin >> end_of_competitions;
		cout << endl;

		cout << "�������� ���������:" << endl;
		for (int i = 0; i < stadium_quantity; i++)
		{
			for (int j = 0; j < stadium[i].sponsor_quantity; j++)
			{
				/*���� ����� ���������� ������������ ������ � ���������� - ������� ���������� �� �����.
				���������� �������� �� ����������� � �������.*/
				cout << "�������: " << stadium[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������� �������� ����������� ������������, ���������� � ������ ������ �������." << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "�������� ����������:" << endl;
		for (int i = 0; i < gym_quantity; i++)
		{
			for (int j = 0; j < gym[i].sponsor_quantity; j++)
			{
				cout << "�������: " << gym[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������� �������� ����������� ������������, ���������� � ������ ������ �������." << endl;
				cout << endl;
			}
		}
		count = 0;

		cout << "�������� ������:" << endl;
		for (int i = 0; i < court_quantity; i++)
		{
			for (int j = 0; j < court[i].sponsor_quantity; j++)
			{
				cout << "�������: " << court[i].sponsor[j].sponsor_name << endl;
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
					cout << "� ������� �������� ����������� ������������, ���������� � ������ ������ �������." << endl;
				cout << endl;
			}
		}
		count = 0;
		break;
	default:
		cout << "����� ������ �����������, ���������� ��� ���." << endl << endl;
		break;
	}

	Methods::Menu(stadium, stadium_quantity, gym, gym_quantity, court, court_quantity);
}