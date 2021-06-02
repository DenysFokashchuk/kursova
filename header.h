/*�� ������ ��������, ��������� � ����� ������������ ��������, ������� �������� �� ��������� ���������� ������������.
� ������ ������������ ����� ����������� ��������� ���������� �����������, ������ �� ������� ���������� ��������� ����������� ����� ������.
��� ���� �� ���� ��� ������ ����� �������� ��������� ���������� ��������.*/

class Trainer //����� ������, ������� �������� ��������������� ����
{
public:
	char trainer_name[30];
};
class Kind_of_Sport //����� "��� ������", ������� �������� ��������������� ���� � ������ ���� ������
{
public:
	char sport_name[30];
	int trainer_quantity;
	Trainer* trainer;
};
class Sportsman //����� ���������, ������� �������� ��������������� ���� � ������ ���� "��� ������"
{
public:
	char sportsman_name[30];
	int place;
	int sport_quantity;
	Kind_of_Sport* sport;
};
class Competitions //����� ������������, ������� �������� ��������������� ���� � ������ ���� ���������
{
public:
	char competitions_name[30];
	int competitions_start_year;
	int competitions_end_year;
	int sportsman_quantity;
	Sportsman* sportsman;
};
class Sponsor //����� �������, ������� �������� ��������������� ���� � ������ ���� ������������
{
public:
	char sponsor_name[30];
	int competitions_quantity;
	Competitions* competitions;
};
class Infrastructure //����� ��������������, ������� �������� ��������������� ���� � ������� ���� �������
{
public:
	char infrastructure_name[30];
	int area;
	int sponsor_quantity;
	Sponsor* sponsor;
};
class Stadium : public Infrastructure //���� ������������ ������ �������, �������� � ����, ������� ����������� �� ������ �������������� � �������� ���������� ����
{
public:
	int capacity;
};
class Gym : public Infrastructure
{
public:
	int number_of_simulators;
};
class Court : public Infrastructure
{
public:
	char type_of_coverage[30];
};

class Methods //����� ������, ������� �������� ��� ����������� �������
{
public:
	static void Sports_buildings(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Competitions(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Sportsmans(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Trainers(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Awardees(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Menu(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
};