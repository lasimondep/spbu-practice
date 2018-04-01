#include <cstdio>
#include <cstdlib>
#include <ctime>
#define COST_FIREBALL 25
#define COST_LIFESTEAL 10
#define LIFESTEAL_PERCENT 1.05
#define DAMAGE_FIREBALL 100
#define RATE_MANAREGEN 5
#define HEAL_HP 20
#define CRIT_MULTIPLE 10

class unit {
	protected:
	double hp, base_damage;
	unit(double _hp, double _base_damage) : hp(_hp), base_damage(_base_damage) {}
	public:
	virtual bool print_stat(const char *) = 0;
	virtual double get_damage() = 0;
	virtual void take_damage(double) = 0;
};

class hunter : public unit {
	protected:
	double agile;
	hunter(double _hp, double _bd, double _ag) : unit(_hp, _bd), agile(_ag) {}
};

class rogue : public hunter {
	private:
	int evasion_chance;
	bool evasion() {
		return rand() % 100 < evasion_chance;
	}
	public:
	bool print_stat(const char *name) {
		printf("Rogue %s HP: %.2lf\n", name, hp);
		return hp > 0;
	}
	rogue(double _hp, double _bd, double _ag, int _ec) : hunter(_hp, _bd, _ag), evasion_chance(_ec) {}
	double get_damage() {
		return base_damage * agile;
	}
	void take_damage(double damage) {
		if (evasion()) {
			puts("Evasion!");
		} else
			hp -= damage;
	}
};

class reaper : public hunter {
	private:
	int crit_chance;
	bool crit() {
		return rand() % 100 < crit_chance;
	}
	public:
	reaper(double _hp, double _bd, double _ag, int _cc) : hunter(_hp, _bd, _ag), crit_chance(_cc) {}
	bool print_stat(const char *name) {
		printf("Reaper %s HP: %.2lf\n", name, hp);
		return hp > 0;
	}
	double get_damage() {
		if (crit()) {
			puts("CRIT!");
			return base_damage * agile * CRIT_MULTIPLE;
		}
		return base_damage * agile;
	}
	void take_damage(double damage) {
		hp -= damage;
	}
};

class warrior : public unit {
	protected:
	double armor;
	warrior(double _hp, double _bd, double _ar) : unit(_hp, _bd), armor(_ar) {}
	void take_damage(double damage) {
		hp -= damage * armor;
	}
};

class paladin : public warrior {
	private:
	void healing() {
		hp += HEAL_HP;
	}
	public:
	paladin(double _hp, double _bd, double _ar) : warrior(_hp, _bd, _ar) {}
	bool print_stat(const char *name) {
		printf("Paladin %s HP: %.2lf\n", name, hp);
		return hp > 0;
	}
	double get_damage() {
		puts("[1]\tHeal\n[other]\tAttack");
		int c;
		scanf("%d", &c);
		switch (c) {
			case 1:
				healing();
				return 0;
			default:
				return base_damage;
		}
	}
};

class berserk : public warrior {
	private:
	int rage;
	public:
	berserk(double _hp, double _bd, double _ar, int _r) : warrior(_hp, _bd, _ar), rage(_r) {}
	bool print_stat(const char *name) {
		printf("Berserk %s HP: %.2lf\n", name, hp);
		return hp > 0;
	}
	double get_damage() {
		rage += 2;
		return base_damage + rage;
	}
};

class mage : public unit {
	protected:
	int mana;
	void regen_mana() {
		mana += RATE_MANAREGEN;
	}
	public:
	mage(double _hp, double _bd, int _m) : unit(_hp, _bd), mana(_m) {}
	void take_damage(double damage) {
		hp -= damage;
		regen_mana();
	}
};

class firemage : public mage {
	private:
	double fireball() {
		if (mana >= COST_FIREBALL) {
			mana -= COST_FIREBALL;
			return DAMAGE_FIREBALL;
		} else {
			puts("Not enought mana!");
			return 0;
		}
	}
	public:
	firemage(double _hp, double _bd, int _m) : mage(_hp, _bd, _m) {}
	bool print_stat(const char *name) {
		printf("Fire mage %s HP: %.2lf, mana: %d\n", name, hp, mana);
		return hp > 0;
	}
	double get_damage() {
		puts("[1]\tSpell fireball\n[other]\tnothing");
		int c;
		scanf("%d", &c);
		switch(c) {
			case 1:
				return base_damage + fireball();
			default:
				return base_damage;
		}
	}
};

class arcanemage : public mage {
	private:
	double lifesteal() {
		if (mana >= COST_LIFESTEAL) {
			mana -= COST_LIFESTEAL;
			return LIFESTEAL_PERCENT;
		} else
			return 1;
	}
	public:
	arcanemage(double _hp, double _bd, int _m) : mage(_hp, _bd, _m) {}
	bool print_stat(const char *name) {
		printf("Arcane mage %s HP: %.2lf, mana: %d\n", name, hp, mana);
		return hp > 0;
	}
	double get_damage() {
		hp += lifesteal();
		return base_damage;
	}
};
