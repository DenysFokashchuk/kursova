/*Ќа каждом стадионе, спортзале и корте присутствуют спонсоры, которые отвечают за некоторое количество соревнований.
¬ каждом соревновании может участвовать некоторое количество спортсменов, каждый из которых занимаетс€ некоторым количеством видов спорта.
ѕри этом за один вид спорта может отвечать некоторое количество тренеров.*/

class Trainer //класс тренер, который содержит соответствующие пол€
{
public:
	char trainer_name[30];
};
class Kind_of_Sport //класс "тип спорта", который содержит соответствующие пол€ и объект типа тренер
{
public:
	char sport_name[30];
	int trainer_quantity;
	Trainer* trainer;
};
class Sportsman //класс спортсмен, который содержит соответствующие пол€ и объект типа "вид спорта"
{
public:
	char sportsman_name[30];
	int place;
	int sport_quantity;
	Kind_of_Sport* sport;
};
class Competitions //класс соревновани€, который содержит соответствующие пол€ и объект типа спортсмен
{
public:
	char competitions_name[30];
	int competitions_start_year;
	int competitions_end_year;
	int sportsman_quantity;
	Sportsman* sportsman;
};
class Sponsor //класс спонсор, который содержит соответствующие пол€ и объект типа соревновани€
{
public:
	char sponsor_name[30];
	int competitions_quantity;
	Competitions* competitions;
};
class Infrastructure //класс инфраструктура, который содержит соответствующие пол€ и объекта типа спонсор
{
public:
	char infrastructure_name[30];
	int area;
	int sponsor_quantity;
	Sponsor* sponsor;
};
class Stadium : public Infrastructure //ниже представлены классы стадион, спортзал и корт, которые наследуютс€ от класса инфраструктура и содержат уникальные пол€
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

class Methods //класс методы, которые содержит все необходимые функции
{
public:
	static void Sports_buildings(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Competitions(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Sportsmans(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Trainers(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Awardees(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
	static void Menu(Stadium* stadium, int stadium_quantity, Gym* gym, int gym_quantity, Court* court, int court_quantity);
};