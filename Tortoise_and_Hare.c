//Seth J Sutton
//Description:
/*This program is based off of the kid story the tortoise and the hare. The story is about a rabbit who is over confident and believes he can win a race against anyone.
So the tortoise races the rabbit. To summarize the tortoise wins because the rabbit felt so confident to take a nap during the race.
This program makes the path uses a path variable to make the area of the race using functions to move the hare and the tortise. There are also the main fuction which makes the race area with obstacles like rocks, streams, and carrots
and the print function prints the path along with when the rabbit sleeps or when there is a collision. This program uses pointers for the tortoise and the hare locations. 
The difference between this race and the kid story race is the rabbit might win or might not.*/

//libraries
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 60 //The max size of the path
char* moveTortoise(char *tortoise,char *hare, int* collision) {		//This function moves the Tortoise
	tortoise += (rand() % 3 + 2) ; // moves the tortoise random from 2-4 places 
	if (tortoise == hare) { //checks for collision cause by the tortoise
		*collision = 1; //sets collision to 1
		tortoise = tortoise - 1; //moves the tortoise back one
	}
	return tortoise;
}

char* moveHare(char *hare , char *tortoise, int* collision, int* nap, char *path) {
		if (rand() % 5 == 0) { // the 1 in 5 chance the hare takes a nap
			*nap = 1; // sets nap to 1
			return hare; // returns the napping hare
		}
		if (*hare == 'C') { //when the hare comes across a carrot
			*hare = ' '; //eats the carrot
			return hare; //keeps the hare in the same position
		}
		hare += (rand() % 9) + 1; //moves the hare randomly 1-9 places
		if (hare == tortoise) { //checks for collision cause by the hare
			*collision = 1; //sets collision to 1
			hare = hare - 1; //moves hare back 1
			return hare; //returns current position
		}
		while (*hare == 'S' || *hare == 'R' || hare == tortoise) { // runs until hare is not in a stream or on a rock
			hare = hare - 1; // moves hare back one position 
			if (hare == tortoise) { //checks while the hare is moving back from the rocks or stream, if he lands on the tortoise again
				*collision = 1; //sets collision 
			}
		}
		return hare;
}

void print(char path[], char *hare, char *tortoise, int turn, int collision, int nap) {
	char *Pp; //Path pointer
	printf("turn%3d",turn); // prints each turn
	for (Pp = path;  Pp < path + MAX; Pp++) {
		//For every character in path if tortoise print T and is hare print H OTW print &path
		if (Pp == tortoise) {
			printf("T"); //Prints tortoise's position
		}
		else if (Pp == hare) {
			printf("H");//Print hare's position
		}
		else {
			printf("%c", *Pp); //prints other path values like the rocks, streams, or spaces
		}
	}
	if (collision == 1) {
		printf("--Collision--"); //prints when a collision occurs
	}
	if (nap == 1) {
		printf("--Hare napping--"); //prints when the hare is napping
	}
	printf("\n");
}

void main() {
	char path[] = " R  R  R  SSSSS   R  R CCCC  R   R   CCCCCCCCCC  R  SSSS  R "; //The path of the race
	char* hare; char* tortoise; //The pointers for the hare and the tortoise positions
	hare = path; tortoise = path; //Starts the hare and tortoise at the beginning of the race
	int turn = 0; int collision = 0; int nap = 0; //Variables for which turn it is, when a collision occurs, and when the rabbit naps
	srand(time(NULL)); //for the random positions to move the hare and tortoise
	while (hare < path + MAX && tortoise < path + MAX) { //compares where the hare address is and where the tortoises address is along the path
		collision = 0; //set collision to 0
		nap = 0; //set nap to 0
		turn = turn + 1; //increments each turn
		tortoise = moveTortoise(tortoise, hare, &collision); //uses the function moveTortoise to move the tortoise
		hare = moveHare(hare, tortoise, &collision, &nap, path); //uses the function moveHare to move the hare
		print(path, hare, tortoise, turn, collision, nap); //prints the path each turn using the the print function
	}
	if (tortoise > hare) { 
		printf("Tortoise wins\n"); //prints if tortoise exceeds the finish line or is at the finish line first he wins other wise the hare wins
	}
	else{
		printf("Hare wins\n");
	}
}
