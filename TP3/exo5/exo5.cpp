/*
Galaad Martineaux:

IMPORTANT PLEASE READ
- If you want to debug (know the number in advance), add #define DEBUG. There are some #ifdef for you.
- I added code to check for unfair numbers (check function Init()).

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#define MAX 100
#define MIN 1
#define DEBUG

const std::string GAME_INTRO = "Try guessing the randomly generated number!\nAttempts left: ";
const std::string ERROR_INVALID_NUMBER = "Please enter valid stricly positive number between ";
const std::string AND = " and ";
const std::string DOT = ".";
const std::string YOU_WON = "Congratulations, you guessed the right number!";
const std::string YOU_LOSE = "You lost... How sad! The number to guess was ";
const std::string INPUT_NUMBER_IS_MULTIPLE = "The inputted number is a multiple of the randomly generated number!";
const std::string INPUT_NUMBER_IS_DIVIDER = "The inputted number is a divider of the randomly generated number!";
const std::string INPUT_NUMBER_IS_NEITHER = "The inputted number has nothing to do with the randomly generated one.";

uint8_t Init();

int main() {
	uint8_t numberToGuess = Init();
	bool hasWon = false;

	#ifdef DEBUG
	std::cout << "DEBUG: Randomly generated number is " << (int)numberToGuess << std::endl;
	#endif //DEBUG

	for (uint8_t i = 10; i > 0; --i)
	{
		uint8_t input;
		std::cout << GAME_INTRO << (int)i << std::endl;
		

		{
			int temp;
			std::cin >> temp;
			while (temp <= 0 || temp > MAX) {
				//Clear std::cin so that the program does not loop indefinitely.
				std::cin.clear();
				fflush(stdin);

				std::cout << ERROR_INVALID_NUMBER << MIN << AND << MAX << DOT << std::endl;
				std::cin >> temp;
			}
			input = static_cast<uint8_t>(temp);
		}

		#ifdef DEBUG
		std::cout << "DEBUG: You entered: " << (int)input << std::endl;
		#endif //DEBUG
		
		if (input == numberToGuess) {
			std::cout << YOU_WON << std::endl;
			hasWon = true;
			break;
		}
		else if (input % numberToGuess == 0)
			std::cout << INPUT_NUMBER_IS_MULTIPLE << std::endl;
		else if (numberToGuess % input == 0)
			std::cout << INPUT_NUMBER_IS_DIVIDER << std::endl;
		else
			std::cout << INPUT_NUMBER_IS_NEITHER << std::endl;
	}
	
	if (!hasWon)
		std::cout << YOU_LOSE << (int)numberToGuess << DOT << std::endl;
	return 0;
}

uint8_t Init() {
	/*
		Since it would not be fair to allow numbers with no dividers or multiplicators
		within the MIN to MAX range, we find all of them, then compare it to the
		randomly generated number. If they match, we add 1 to the random number.
	*/
	std::vector<uint8_t> output;

	//Checks all numbers that have no dividers or multiplicators within the MIN to MAX range.
	for (uint8_t i = MIN; i < MAX; ++i) {
		uint8_t sum = 0;
		for (uint8_t j = MIN; j < MAX; ++j)
		{
			if (i % j != 0 && j % i != 0)
				++sum;
		}

		if (sum > MAX - 4) {
			output.push_back(i);
		}
	}

	//Assign a randomly generated number within the MIN MAX range.
	std::srand(time(NULL));
	uint8_t randomNumber = rand() % MAX + MIN;

	//Checks if the random number is an unfair one and adds 1 to it if yes.
	for (int i = MIN; i < output.size(); ++i) {

		if (randomNumber == output[i])
		{
			#ifdef DEBUG
			std::cout << "DEBUG: Unfair number checked has been triggered! Number " << randomNumber-1 << " is now " << 
			++randomNumber << std::endl;
			#else
			++randomNumber;
			#endif //DEBUG

		}
	}

	return randomNumber;
}

/*
JEU D'ESSAI
___________

ENTRÉE	NOMBRE_à_TROUVER	ESSAIS_RESTANTS	RÉPONSE_DU_PROGRAMME
22		44					10				The inputted number is a divider of the randomly generated number!
88		44					10				The inputted number is a multiple of the randomly generated number!
54		44					10				The inputted number has nothing to do with the randomly generated one.
104		44					10				Please enter valid stricly positive number between 1 and 100.
256		44					10				Please enter valid stricly positive number between 1 and 100.
-2		44					10				Please enter valid stricly positive number between 1 and 100.
0		44					10				Please enter valid stricly positive number between 1 and 100.
Hoi		44					10				Please enter valid stricly positive number between 1 and 100.
44		44					10				Congratulations, you guessed the right number!
4		44					0				You lost... How sad! The number to guess was 44.

*/