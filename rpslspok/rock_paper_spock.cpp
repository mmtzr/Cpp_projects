#include <iostream>

int choice_str_to_int(std::string choice){
    if (choice == "rock"){
        return 0;
    }
    else if (choice == "paper"){
        return 1;}
    else if (choice == "scissors"){
        return 2;}
    else if (choice == "lizard"){
        return 3;}
    else if (choice == "Spock"){
        return 4;}
    else {
        return -1;
    }
}

int user_choice() {
    // Prompts the user to select either Rock, Paper, Scissors, Lizard, or Spock.
    std::string user_choice;
    std::cout << "Select either rock ✊, paper ✋, scissors ✌, lizard 🫳, or Spock 🖖: ";
    std::cin >> user_choice;
    while (choice_str_to_int(user_choice)<0)
    {
        std::cout << "Invalid choice. Select either rock ✊, paper ✋, scissors ✌ , lizard 🫳 , or Spock 🖖: ";
        std::cin >> user_choice;
    }
    
    return choice_str_to_int(user_choice);
}

int computers_choice() {
    // Instructs the computer to randomly select either Rock, Paper, Scissors, Lizard, or Spock.
    srand (time(NULL));
    return rand() % 5;
}

void rules(int win, int lose){
    // Prints the rules of the game.
    if (win == 0){
        // rock (0) wins scissors (2) and lizard (3)
        if (lose == 2) {
            std::cout << "rock crushes scissors" << std::endl;
        }
        else if (lose == 3) {
            std::cout << "rock crushes lizard" << std::endl;
        }
    }
    else if (win == 1){
        // paper (1) wins rock (0) and Spock (4)
        if (lose == 0) {
            std::cout << "paper covers rock" << std::endl;
        }
        else if (lose == 4) {
            std::cout << "paper disproves Spock" << std::endl;
        }
    }
    else if (win == 2){
        // scissors (2) wins paper (1) and lizard (3)
        if (lose == 1) {
            std::cout << "scissors cuts paper" << std::endl;
        }
        else if (lose == 3) {
            std::cout << "scissors decapitates lizard" << std::endl;
        }
    }
    else if (win == 3){
        // lizard (3) wins paper (1) and Spock (4)
        if (lose == 1) {
            std::cout << "lizard eats paper" << std::endl;
        }
        else if (lose == 4) {
            std::cout << "lizard poisons Spock" << std::endl;
        }
    }
    else if (win == 4){
        // Spock (4) wins rock (0) and scissors (2)
        if (lose == 0) {
            std::cout << "Spock vaporizes rock" << std::endl;
        }
        else if (lose == 2) {
            std::cout << "Spock smashes scissors" << std::endl;
        }
    }
}

void print_winner(int computer, int user) {
    /* Compares the user’s choice and the computer’s choice and determine the winner.
     * scissors cuts paper, paper covers rock, rock crushes lizard, lizard poisons Spock, Spock smashes scissors, 
     * scissors decapitates lizard, lizard eats paper, paper disproves Spock, Spock vaporizes rock, and rock crushes scissors.
     */
    if (computer == user) {
        std::cout << "It's a tie!" << std::endl;
        return;
    }
    switch (user)
    {
    case 0: // 0: rock -- wins 2,3
        if (computer==2 || computer==3) {
            rules(user, computer);
            std::cout << "You win!" << std::endl;
        }
        else {
            rules(computer, user);
            std::cout << "I win!" << std::endl;
        }
        break;
    case 1: // 1: paper -- wins 0,4
        if (computer==0 || computer==4) {
            rules(user, computer);
            std::cout << "You win!" << std::endl;
        }
        else {
            rules(computer, user);
            std::cout << "I win!" << std::endl;
        }
        break;
    case 2: // 2: scissors -- wins 1,3
        if (computer==1 || computer==3) {
            rules(user, computer);
            std::cout << "You win!" << std::endl;
        }
        else {
            rules(computer, user);
            std::cout << "I win!" << std::endl;
        }
        break;
    case 3: // 3: lizard -- wins 1,4
        if (computer==3 || computer==4) {
            rules(user, computer);
            std::cout << "You win!" << std::endl;
        }
        else {
            rules(computer, user);
            std::cout << "I win!" << std::endl;
        }
        break;
    case 4: // 4: Spock -- wins 0,2
        if (computer==0 || computer==2) {
            rules(user, computer);
            std::cout << "You win!" << std::endl;
        }
        else {
            rules(computer, user);
            std::cout << "I win!" << std::endl;
        }
        break;
    default:
        std::cout << "Something horrible happened! Try again." << std::endl;
        break;
    }
}

int main() {
    int computer = computers_choice();
    int user = user_choice();
    std::string choices[] = {"✊", "✋", "✌", "🫳", "🖖"};
    std::cout << choices[user] << " vs. " << choices[computer] << std::endl;
    print_winner(computer, user);
}