#include "gameclasses.h"

int main() {
	srand(time(NULL));
	puts("Enter number of players");
	int n;
	scanf("%d", &n);
	unit *player[n];
	char *name[n];
	bool alive[n];
	int c;
	puts("Available classes:\n1\tRogue\n2\tReaper\n3\tPaladin\n4\tBerserk\n5\tFire mage\n6\tArcane mage");
	for (int i(0); i < n; ++i) {
		printf("Player #%d: [CLASS_ID] [NAME]\n", i + 1);
		name[i] = new char[100];
		scanf("%d%s", &c, name[i]), alive[i] = true;
		switch(c) {
			case 1:
				player[i] = new rogue(250, 15, 2.5, 30);
				break;
			case 2:
				player[i] = new reaper(250, 15, 3, 15);
				break;
			case 3:
				player[i] = new paladin(500, 20, 0.5);
				break;
			case 4:
				player[i] = new berserk(500, 20, 0.5, 0);
				break;
			case 5:
				player[i] = new firemage(200, 15, 60);
				break;
			case 6:
				player[i] = new arcanemage(200, 20, 40);
		}
		player[i]->print_stat(name[i]);
	}
	int target;
	for (int k(0);; k = (k + 1) % n) {
		if (!alive[k])
			continue;
		printf("Move player #%d\nWhom are attacking?\n", k + 1);
		scanf("%d", &target);
		player[target - 1]->take_damage(player[k]->get_damage());
		if (!player[target - 1]->print_stat(name[target - 1]))
			printf("Player #%d is death\n", target), alive[target - 1] = false;
		player[k]->print_stat(name[k]);
		puts("------------------------------");
	}
	return 0;
}