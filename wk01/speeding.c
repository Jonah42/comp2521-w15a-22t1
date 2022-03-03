// 2521 Jonah Meggs
// Why pointers are important

#include <stdio.h>
#include <math.h>

struct Person {
	char* name;
	int bank_account;
};

void print_person(struct Person p) {
	printf("%s:\n\tBank Account: %d\n\n", p.name, p.bank_account);
}

int calculate_fine(int diff) {
	if (diff < 0) return 0;
	else if (diff < 10) return 123;
	else if (diff < 20) return 285;
	else if (diff < 30) return 489;
	else if (diff < 45) return 935;
	else return 2520;
}

void usyd_cop_catch_speeding(struct Person p, int speed_limit, int speed) {
	int fine = calculate_fine(speed - speed_limit);
	p.bank_account -= fine;
}

void unsw_cop_catch_speeding(struct Person* p, int speed_limit, int speed) {
	int fine = calculate_fine(speed - speed_limit);
	p->bank_account -= fine;
}

int main(void) {
	// Jonah is a pretty cool kid
	struct Person Jonah;
	Jonah.name = "Jonah";
	Jonah.bank_account = 1000;
	print_person(Jonah);
	// One day Jonah gets caught speeding by a usyd cop
	int speed_limit = 80;
	int jonahs_speed = 120;
	printf("Jonah got caught speeding by a usyd cop :-(\n\n");
	usyd_cop_catch_speeding(Jonah, speed_limit, jonahs_speed);
	print_person(Jonah);
	// Jonah also gets caught speeding by a unsw cop
	printf("Jonah got caught speeding by a unsw cop :-(\n\n");
	unsw_cop_catch_speeding(&Jonah, speed_limit, jonahs_speed);
	print_person(Jonah);
	return 0;
}