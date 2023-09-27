#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
enum UserChoice{odd, even, particular};
typedef struct player{
 char* name;
 int money;
}Player;
typedef struct enemy{
 char* name;
 int money;
}Enemy;
typedef enum UserChoice UserChoice;
int generateNum();
bool isWinOddAndEven(int systemNum, UserChoice userchoice);
bool isWinParticularNum(int systemNum,int userInput);
void printResult(bool result);
int calculateMoney(bool result, int money, Player* player, Enemy* enemy, UserChoice userchoice);
void printMoney(Player player,Enemy enemy);

int main(){
	srand(0);

	Player player1;
	player1.name = "Ming Liu";
	player1.money = 1000;

	Enemy enemy1;
	enemy1.name = "Du Chang";
	enemy1.money = 1000;

	while(true){
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
 		printf("start game!!!\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("current player is %s, current money is %i\n",player1.name,player1.money);
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		UserChoice userChoice;
		printf("you have three choices: (0) is betting odd, (1) is betting even, (2) is betting one particular number:");
		scanf("%i",&userChoice);
		int investmentMoney;
		printf("You currently have %i money, please enter your investment money:",player1.money);
		scanf("%i",&investmentMoney);
		player1.money -= investmentMoney;
		enemy1.money += investmentMoney;
		int particularNum;
		if(userChoice==particular){
			printf("please enter a number which is between 1 and 35:");
			scanf("%i",&particularNum);
			assert(particularNum>=1&&particularNum<=35);
		}
		bool result;
		int systemNum = generateNum();
		printf("systemNum is %i\n", systemNum);
	  	switch(userChoice){
		 case odd:
			result = isWinOddAndEven(systemNum,userChoice);
			break;
		 case even:
			result = isWinOddAndEven(systemNum,userChoice);
			break;
		 default:
			result = isWinParticularNum(systemNum,particularNum);
		}
		printResult(result);
		calculateMoney(result, investmentMoney, &player1, &enemy1, userChoice);
		printMoney(player1,enemy1);
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		printf("-----------------------------------------\n");
		if(player1.money==0){
			printf("you lost all your money!!!, game end!!!");
			break;
		}
		if(enemy1.money==0){
			printf("you win all duchang money!!!, game end!!!");
			break;
		}
		
	}
	


}

int generateNum(){
 return rand()%36;
}

bool isWinOddAndEven(int systemNum, UserChoice userchoice){
 assert(userchoice>=odd&&userchoice<=particular);
 return systemNum%2==0?userchoice==even:userchoice==odd;
}

bool isWinParticularNum(int systemNum,int userInput){
 return systemNum==userInput?true:false;
}

void printResult(bool result){
 if(result==false){
  printf("you lost the game!!!\n");
  return;
 }else{
  printf("you win the game!!!\n");
  return;
 }
}

int calculateMoney(bool result, int investMoney, Player* player, Enemy* enemy, UserChoice userchoice){
 switch(result){
  case true:
	if(userchoice==odd||userchoice==even){
		player->money+=investMoney*2;
		enemy->money-=2*investMoney;
		return investMoney*2;
   	}else{
		player->money+=investMoney*35;
		enemy->money-=investMoney*35;
		return investMoney*35;
	}
	break;
  default:
	break;
 }
}

void printMoney(Player player,Enemy enemy){
 printf("%s money is %i, %s money is %i, please keep fighting!!!",player.name,player.money,enemy.name,enemy.money);
}
