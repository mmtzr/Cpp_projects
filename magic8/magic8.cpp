#include <iostream>
#include <string>



void answers(int a){
    switch(a){
        case 0:
            std::cout << "It is certain.";
            break;
        case 1:
            std::cout << "Yes - definitely.";
            break;
        case 2:
            std::cout << "Most likely.";
            break;
        case 3:
            std::cout << " Without a doubt.";
            break;
        case 4:
            std::cout << "As I see it, yes.";
            break;
        case 5:
            std::cout << "You may rely on it.";
            break;
        case 6:
            std::cout << "It is decidedly so.";
            break;
        case 7:
            std::cout << " My sources say no.";
            break;
        case 8:
            std::cout << "My reply is no.";
            break;
        case 9:
            std::cout << "Don't count on it.";
            break;
        case 10:
            std::cout << "Concentrate and ask again.";
            break;
        case 11:
            std::cout << "Cannot predict now.";
            break;
        case 12:
            std::cout << "Better not tell you now.";
            break;
        case 13:
            std::cout << "Ask again later.";
            break;
        case 14:
            std::cout << "Reply hazy, try again.";
            break;
        case 15:
            std::cout << "Signs point to yes.";
            break;
        case 16:
            std::cout << "Yes.";
            break;
        case 17:
            std::cout << "Outlook good.";
            break;
        case 18:
            std::cout << "Outlook not so good.";
            break;
        case 19:
            std::cout << "Very doubtful.";
            break;
        default:
            std::cout << "Invalid question, try again later.";
            break;
    }
}

/**
 * The main function of the program. It prompts the user to enter a question,
 * generates a random number based on the length of the question, and calls
 * the `answers` function to print the corresponding answer.
 *
 * @return 0 indicating successful execution of the program
 *
 * @throws None
 */
int main(){
    std::string question="";
    std::cout << "*** MAGIC 8-BALL:*** \n\n";
    std::cout << "Enter your question: ";
    std::cin >> question;

    if ((question.find('?') == std::string::npos) == 1)
    {
        answers(22);
    }
    else{
        // This sets the “seed” of the random number generator.
        srand(time(NULL));
        answers(question.size()*std::rand() % 20);
    }
    
    return 0;
}

