
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Hero  /*: public Entity*/ {
protected:

    std::string nickname;
    std::string weapon_of_choice;

    double health_player;
    int level_player;
    double player_health_on_lvl;
    double potion_amount;
    double player_damage;
    

    std::vector <std::string> weapons_container;
    std::vector <std::vector <std::string >> player_nick_and_weapon;

    bool player_atack_sword1 = false;
    bool player_atack_sword2 = false;
    bool player_atack_bow1 = false;
    bool player_atack_bow2 = false;
    bool player_atack_wand1 = false;
    bool player_atack_wand2 = false;
    bool player_atack_sword_crit = false;
    bool player_atack_bow_crit = false;
    bool player_atack_wand_crit = false;
    bool player_shield = false;

    bool using_potion = false;
    bool weapons_in_file = false;

public:

    Hero() {
        nickname = "Steve";
        health_player = 100.00;
        level_player = 1;
    }
    Hero(std::string a, double health, int lvl) {
        nickname = a;
        health_player = health;
        level_player = lvl;
    }

    std::string SetNickname() {
        std::string login;
        std::cout << "Hello Hero, welcome to the game. Please give me your nickname in which to address you: ";
        std::cin >> login;
        nickname = login;
        std::cout << "Ok, hello " << nickname << " welcome to the world of Eonia\n" << std::endl;
        return this->nickname;
    }

    std::string WeaponOfChoice() {
        std::string weapons;
        std::ifstream weapons_file;
        int answer;


        weapons_file.open("weapons.txt", std::ios::in);
        if (weapons_file.is_open()) {
            std::string temp;
            while (getline(weapons_file, temp)) {

                if (temp.empty()) {
                    break;
                }
                else {
                    this->weapons_container.push_back(temp);
                }
            }

        }
        else {
            std::cout << "There was a problem with getting the weapons list\n";
        }
        std::cout << "Which weapon would you like to choose?: (1/2/3)\n";
        for (int i = 0; i < this->weapons_container.size(); i++) {
            std::cout << i << ". " << this->weapons_container[i] << std::endl;
        }

        std::cin >> answer;
        //WYBRANA BRON DO VECTORA KTORY BEDZIE TRZYMAL JA RAZEM Z NAZWA
        if (answer == 0) {
            weapon_of_choice = weapons_container[0];
            std::cout << "New item unlocked: " << weapon_of_choice << ".\n";
            return this->weapon_of_choice;
        }
        else if (answer == 1) {
            weapon_of_choice = weapons_container[1];
            std::cout << "New item unlocked: " << weapon_of_choice << ".\n";
            return this->weapon_of_choice;
        }
        else if (answer == 2) {
            weapon_of_choice = weapons_container[2];
            std::cout << "New item unlocked: " << weapon_of_choice << ".\n";
            return this->weapon_of_choice;
        }
        else {
            std::cout << "Hello Hero, your choice was somehow not part of the game, my bad, please take this magic sword of greatnes \n :p";
            weapon_of_choice = weapons_container[0];
            std::cout << "New item unlocked: " << weapon_of_choice << ".\n";
            return this->weapon_of_choice;
        }
    }

    void Hero_Summation() {
        SetNickname();

        std::cout << "Hello " << this->nickname << ". Welcome to the world of Eonia. My name is Geraldo. You probably wonder how did you find yourself here.\n Let me tell you the story.";
        //... STORY
        /*std::cout << "\n Please let me introduce you to the weapons that you can choose from. ";
        std::cout << " The Sword of Valor In the heart of Eldoria, deep within the treacherous Forest of Whispers, lies a hidden glade where an ancient sword known as the Sword of Valor rests";
        std::cout << "Legend has it that this blade was forged by the first blacksmith of Eldoria, a master craftsman whose devotion to justice was unparalleled.The sword is said to be imbued with the essence of bravery itself.";
        std::cout << "To wield the Sword of Valor is to embrace the spirit of a true hero.Its blade gleams with an ethereal light that can dispel darkness and cut through any obstacle, physical or spiritual.";
        std::cout << "Those who choose this sword as their weapon are destined for greatness, but they must be prepared to face the most challenging trials and protect the innocent from harm. \n";*/
        //std::cout <<
        WeaponOfChoice();
        std::cout << "Ok " << this->nickname << ". I see you have just decided which weapon you would like to fight with. Very good choice " << "\n";
        //player_nick_and_weapon.push_back({ weapons_container });
        //std::vector<std::vector<std::string>>::iterator it = player_nick_and_weapon.begin();
        //player_nick_and_weapon.insert(it + 1, { SetNickname() });
    }
};
class Enemy /*: public Entity*/ {
protected:

    std::string enemy_name;
    std::string enemydif;

    double health_enemy;
    int level_enemy;
    double enemy_damage;

    std::vector <std::string> enemy_list_container;
    std::vector <std::string> enemy_difficulty;

    bool enemy_shield = false;
    bool enemy_atack1 = false;
    bool enemy_atack2 = false;
    bool enemy_crit_atack = false;

    bool enemy_choose = false;
    bool difficulty_in_file = false;

public:

    void Enemy_container_file() {
        std::string enemy_type;

        std::ifstream enemy_file;
        enemy_file.open("enemy.txt", std::ios::in);
        if (enemy_file.is_open()) {
            //https://stackoverflow.com/questions/6942273/how-to-get-a-random-element-from-a-c-container
            //randomowy element z vectora do ktorym znajduja sie wszyscy dostepni enemy;
            std::string temp;
            while (getline(enemy_file, temp)) {

                if (temp.empty()) {
                    break;
                }
                else {

                    this->enemy_list_container.push_back(temp);
                    /*for (int i = 0; i < this->enemy_list_container.size(); i++) {

                        std::cout << this->enemy_list_container[i] << std::endl;;

                    }*/
                    enemy_choose = true;

                }

            }

        }
        else {
            std::cout << "problem occured while the enemy file!\n";
        }

    }

    //LOSOWANIE ENEMY Z PLIKU \/ 
    std::string Enemy_random() {

        Enemy_container_file();

        return this->enemy_name;
    }

    void Difficulty_From_File() {
        if (enemy_choose == true) {
            std::string difficulty;
            std::ifstream difficulty_file;
            std::string answer;
            difficulty_file.open("difficulty.txt", std::ios::in);
            if (difficulty_file.is_open()) {

                std::string temp;
                while (getline(difficulty_file, temp)) {

                    if (temp.empty()) {
                        break;
                    }
                    else {

                        this->enemy_difficulty.push_back(temp);
                        difficulty_in_file = true;
                        //RANDOM DIFFICULTY Z PLIKU
                    }
                }

            }
            else {
                std::cout << "problem occured while the enemy file!\n";
            }

        }
        else {

            std::cout << "There was a problem with getting the enemies list\n";

        }
        if (difficulty_in_file == true) {
            std::string answer;
            std::cout << " Choose difficulty : (0/1/2) " << std::endl;
            for (int i = 0; i < enemy_difficulty.size(); i++) {
                std::cout << i << " . " << enemy_difficulty[i] << std::endl;
            }
            std::cin >> answer;
            if (answer == "0") {
                enemydif = "easy";
            }
            else if (answer == "1") {
                enemydif = "medium";
            }
            else {
                enemydif = "hard";
            }

        }
        else {
            std::cout << "There was a problem with getting the difficulty list" << std::endl;
        }
    }

    void Enemy_lvl_hp_random() {

        if (enemydif == "easy") {

            this->health_enemy = 80;
            
            std::cout << "Difficulty saved to easy";
        }
        else if (enemydif == "medium") {

            this->health_enemy = 100;
            std::cout << "Difficulty saved to medium";
        }
        else {
                
            this->health_enemy = 150;
            std::cout << "Difficulty saved to hard";
        }

    }


};
class FightClass : public Hero, public Enemy {
public:
    
    void HealingPotion() {
        std::string answer;
        double default_healing = 50;
        
        std::cout << "You have " << this->health_player << " health points,\n would you like to heal? : (Y/N) \n" << std::endl;
        std::cin >> answer;
        if (answer == "Y" && potion_amount > 0) {


            if (this->health_player >= this->player_health_on_lvl - 50 ) {

                this->health_player = player_health_on_lvl;
                potion_amount = potion_amount - 1;
                std::cout << "Ok, would you like to fight further?: (Y/N)\n";
                std::cin >> answer;
                if (answer == "Y") {

                    using_potion = true;
                    RandomEnemyEncounter();

                }
                else {
                    std::cout << "Ok, that was a good attempt, thank you for playing!";
                }
            }
            else {

                this->health_player += 50;
                potion_amount = potion_amount - 1;
                std::cout << "Ok, would you like to fight further?: (Y/N)\n";
                std::cin >> answer;
                if (answer == "Y") {
                    using_potion = true;
                    RandomEnemyEncounter();
                }
                else {
                    std::cout << "Ok, that was a good attempt, thank you for playing!";
                }

            }

        }


        else if (answer == "N") {
            std::cout << "Ok, would you like to fight further?: (Y/N)\n";
            std::cin >> answer;
            if (answer == "Y") {
                RandomEnemyEncounter();
            }
            else {
                std::cout << "Ok, that was a good attempt, thank you for playing!";
            }
        }
        else {

            std::cout << "You dont have any more potions" << std::endl;
        }

    }

    void RandomEnemyEncounter() {
        Enemy_random();

        std::string answer;
        std::cout << "Look Out " << this->nickname << " a wild " << this->enemy_name << " , it has got " << this->level_enemy << " level and has got " << health_enemy << " health points\n, would you like ti fight it? (Y/N)";
        std::cin >> answer;
        if (answer == "Y") {
            EnemyAttack();
        }
        else {
            std::cout << "OK, I understand, your journey ends here my Hero :C" << std::endl;
        }

    }

    //JAK TO WPLESC W SYSTEM WALKI
    void HealingDuringFight() {
        std::cout << "would you like to heal while using the barrier? (Y/N)" << std::endl;
        std::string answer;
        if (answer == "Y" && potion_amount > 0) {

            if (this->health_player >= this->player_health_on_lvl - 50) {

                this->health_player = player_health_on_lvl;
                std::cout << "Potion used. " << std::endl;
                potion_amount = potion_amount - 1;
                EnemyAttack(); // <- na starcie wybieramy losowy atack enemy a dopiero pozniej HeroAttack()
            }
            else {

                this->health_player += 50;
                std::cout << "Potion used. " << std::endl;
                potion_amount = potion_amount - 1;
                EnemyAttack();
            }
        }
        else if (answer == "N") {

            std::cout << "ok, fight further. " << std::endl;
            EnemyAttack();
        }
        else {
            std::cout << "not enough potions, good luck"; 
            EnemyAttack();
        }
    }

    void EnemyAttack() {

        //DODAC JAKOS TEN ELEMENT LOSOWOSCI
        // atack1 lub atack2 lub bariera losowo i tyle

        HeroAttack();
    }

    void HeroAttack() {

        if (this->Hero::weapon_of_choice == "sword") {
            std::string answer;

            std::cout << "choose you atack: (1/2)" << std::endl;
            std::cout << "1. Sword Thrust (25 dmg, 100% hit chance)" << std::endl;
            std::cout << "2. Heavy Sword Stroke (40 dmg, 65% hit chance)" << std::endl;
            std::cout << "3. Use Shield (blocks next enemy attack, you can use potion while blocking)" << std::endl;

            std::cin >> answer;

            if (answer == "1")
            {
                player_atack_sword1 = true;
            }
            else  if (answer == "2") {
                player_atack_sword2 = true;
            }
            else {
                player_shield = true;
                //HealingDuringFight();
            }

        }
        else if (this->Hero::weapon_of_choice == "wand") {
            std::string answer;
            std::cout << "choose you atack: " << std::endl;
            std::cout << "1. Fireball (25 dmg, 100% hit chance)" << std::endl;
            std::cout << "2. Cloud Of Fire (40 dmg, 65% hit chance)" << std::endl;
            std::cout << "3. Use Shield (blocks next enemy attack, you can use potion while blocking)" << std::endl;

            std::cin >> answer;

            if (answer == "1")
            {
                player_atack_wand1 = true;
            }
            else  if (answer == "2") {
                player_atack_wand2 = true;
            }
            else {
                player_shield = true;
                //HealingDuringFight();
            }
        }
        else if (this->Hero::weapon_of_choice == "bow") {
            std::string answer;
            std::cout << "choose you atack: " << std::endl;
            std::cout << "1. Quick Shot (25 dmg, 100% hit chance)" << std::endl;
            std::cout << "2. Power Shot (40 dmg, 65% hit chance)" << std::endl;
            std::cout << "3. Use Shield (blocks 85% of the damage of the enemy's next attack, you can use potion while blocking)" << std::endl;

            std::cin >> answer;

            if (answer == "1")
            {
                player_atack_bow1 = true;
            }
            else  if (answer == "2") {
                player_atack_bow2 = true;
            }
            else {
                player_shield = true;
            }
        }
        else
        {
            std::cout << " 123 hero attack 123 " << std::endl;
        }

        if (player_atack_sword1 == true) {
            player_damage = 40;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " << health_enemy - player_damage * 0.15;

            }
            else if (enemy_atack1 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else if (enemy_atack2 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();
            
            }
            else {

                std::cout << " 123 " << std::endl;
                
            
            }
        }
        //DODAC JAKOS TEN ELEMENT LOSOWOSCI
        else if (player_atack_sword2 == true) {

            player_damage = 60;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " << player_damage * 0.15;

            }
            else if (enemy_atack1 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else if (enemy_atack2 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else {

                std::cout << " 123 " << std::endl;
             
            }
        }
        else if (player_atack_bow1 == true) {
            player_damage = 40;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " <<  player_damage * 0.15 << std::endl;

            }
            else if (enemy_atack1 == true) {

                EnemyHealthChecker();
                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else if (enemy_atack2 == true) {

                EnemyHealthChecker();
                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else {
                std::cout << " 123 " << std::endl;
           
            }
        }
        //DODAC JAKOS TEN ELEMENT LOSOWOSCI
        else if (player_atack_bow2 == true) {
            player_damage = 60;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " << player_damage * 0.15;

            }
            else if (enemy_atack1 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage<< " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();
            }
            else if (enemy_atack2 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();
            }   
            else {

                std::cout << " 123 " << std::endl;
                
            }
        }
        else if (player_atack_wand1 == true) {
            player_damage = 40;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " << player_damage << " damage" << std::endl;

            }
            else if (enemy_atack1 == true) {

                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else if (enemy_atack2 == true) {

                EnemyHealthChecker();
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();
            }
            else {

                std::cout << "123" << std::endl;
            }
        }
        //DODAC JAKOS TEN ELEMENT LOSOWOSCI
        else if (player_atack_wand2 == true) {
            player_damage = 60;
            if (enemy_shield == true) {

                std::cout << "enemy used barrier, your atack delt " << player_damage << " damage" << std::endl;

            }
            else if (enemy_atack1 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();

            }
            else if (enemy_atack2 == true) {

                std::cout << "enemy has taken " << player_damage << "damage" << std::endl;
                std::cout << " you have just taken " << enemy_damage << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage;
                HeroHealthChecker();
            }
            else {

                std::cout << "123" << std::endl;
            }

        }
        else if (player_shield == true) {
            if (enemy_atack1 == true) {
                std::cout << " you have just taken " << enemy_damage * 0.15 << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage * 0.15;
                HeroHealthChecker();
                HealingDuringFight();
            }
            else if (enemy_atack2 == true) {
                std::cout << " you have just taken " << enemy_damage * 0.15 << " amount of damage, ouch" << std::endl;
                health_player = health_player - enemy_damage * 0.15;
                HeroHealthChecker();
                HealingDuringFight();
            }
            else {
                std::cout << " enemy has just used barrier" << std::endl;
                HealingDuringFight();
            }
        }
        else {
            std::cout << " 123 haha 123" << std::endl;
        }
        //Wubierasz atak
        //PAMIETAC O ZWIEKSZENIU HP PO WALCE

    }

    void HeroHealthChecker() {

        if (health_player <= 0) {

            std::cout << "You have been slain" << std::endl;

        }
        else {

            EnemyAttack();

        }
    }
    void EnemyHealthChecker() {

        if (health_enemy <= 0) {

            std::cout << "enemy has been slain. " << std::endl;
            std::string answer;
            std::cout << " Fight further ? " << std::endl;
            std::cin >> answer;
            if (answer == "Y") {
                RandomEnemyEncounter();
            }
            else {
                std::cout << "Ok, that was a great adventure My Hero" << std::endl;
            }
        }
        else {

            EnemyAttack();

        }
       

    }

  /*  void Fight() {

        RandomEnemyEncounter();

    }*/
    
    

    void WholeFightEnd() {

        Hero_Summation();
        Difficulty_From_File();
        Enemy_lvl_hp_random();
        RandomEnemyEncounter();
        HealingPotion();
        
    }

};




int main()
{
    std::cout << "Hello World!\n";

    FightClass Hero2;

    Hero Hero3;
    //Hero3.SetNickname();

    Enemy enemy;
    enemy.Enemy_lvl_hp_random();
}

