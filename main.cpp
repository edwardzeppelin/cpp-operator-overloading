#include <iostream>
#include <random>
#include "coords.h"
#include "stack.h"

using namespace std;

void mainmenu() {
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Menu:" << endl;
    cout << "1 - Coords Menu" << endl;
    cout << "2 - Stack Menu" << endl;
    cout << "3 - Exit" << endl;
    cout << "Choose an action: ";
}

void coordsmenu() {
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Coords Menu:" << endl;
    cout << "1 - Print coords" << endl;
    cout << "2 - ! - Negative coords" << endl;
    cout << "3 - ++Prefix - Increase all coords by min coord" << endl;
    cout << "4 - --Prefix - Decrease all coords by max coord" << endl;
    cout << "5 - ++Postfix - Increase one coord by user number" << endl;
    cout << "6 - --Postfix - Decrease one coord by user number" << endl;
    cout << "7 - Exit" << endl;
    cout << "Choose an action: ";
}

void stackmenu() {
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Stack Menu:" << endl;
    cout << "1 - Print Stack1 and Stack2" << endl;
    cout << "2 - Stack1 - Stack2" << endl;
    cout << "3 - Stack1 -= Stack2" << endl;
    cout << "4 - Stack1 /= Stack2" << endl;
    cout << "5 - Stack1 / Stack2" << endl;
    cout << "6 - Compare Stack1 and Stack2" << endl;
    cout << "7 - Check if Stack1 and Stack2 empty" << endl;
    cout << "8 - Exit" << endl;
    cout << "Choose an action: ";
}

int main() {

    coords coords1;
    coords coords2(20, 17, 31);
    coords negative;

    stack stack1;
    stack stack2;
    stack result_minus;
    stack result_div;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randsize(5, 10);

    int stacksize = randsize(gen);

    uniform_int_distribution<> randnum(1, 100);

    for (int i = 0; i < stacksize; ++i) {
        int randnumb = randnum(gen);
        stack1.add(randnumb);
    }

    uniform_int_distribution<> randsize1(5, 10);

    int stacksize1 = randsize1(gen);

    for (int i = 0; i < stacksize1; ++i) {
        int randnumb1 = randnum(gen);
        stack2.add(randnumb1);
    }

    int choice;
    int coordschoice;
    int stackchoice;

    do {
        mainmenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            do {
                coordsmenu();
                cin >> coordschoice;

                switch (coordschoice) {
                case 1:
                    cout << "Coords: " << endl;
                    coords1.printcoords();
                    break;
                case 2:
                    cout << "Negative coords: " << endl;
                    negative = !coords1;
                    negative.printcoords();
                    break;
                case 3:
                    ++coords1;
                    cout << "++Coords: " << endl;
                    coords1.printcoords();
                    break;
                case 4:
                    --coords1;
                    cout << "--Coords: " << endl;
                    coords1.printcoords();
                    break;
                case 5:
                    coords1++;
                    cout << "Coords++: " << endl;
                    coords1.printcoords();
                    break;
                case 6:
                    coords1--;
                    cout << "Coords--: " << endl;
                    coords1.printcoords();
                    break;
                case 7:
                    cout << "Exit" << endl;
                    break;
                default:
                    cout << "Try again" << endl;
                }
            } while (coordschoice != 7);
            break;
        }
        case 2:
            do {
                stackmenu();
                cin >> stackchoice;

                switch (stackchoice) {
                case 1:
                    cout << "Stack1: " << stack1 << endl;
                    cout << "Stack2: " << stack2 << endl;
                    break;
                case 2:
                    //result_minus = stack1 - stack2;
                    result_minus = stack1 - 10;
                    cout << "Stack1 - Stack2 = " << result_minus << endl;

                    break;
                case 3:
                    stack1 -= stack2;
                    cout << "Stack1 -= Stack2 = " << stack1 << endl;
                    break;
                case 4:
                    stack1 /= stack2;
                    cout << "Stack1 /= Stack2 = " << stack1 << endl;
                    break;
                case 5:
                    //result_div = stack1 / stack2;
                    result_div = stack1 / 10;
                    cout << "Stack1 / Stack2 = " << result_div <<endl;
                    break;
                case 6:
                    cout << "Are stacks1 and stack2 equal? " << (stack1 == stack2) << endl;
                    cout << "Is stack1 shorter than stack2? " << (stack1 < stack2) << endl;
                    cout << "Is stack1 longer than stack2? " << (stack1 > stack2) << endl;
                    break;
                case 7:
                    cout << "Is stack1 empty? " << !stack1 << endl;
                    cout << "Is stack2 empty? " << !stack2 << endl;
                    break;
                case 8:
                    cout << "Exit" << endl;
                    break;
                default:
                    cout << "Try again" << endl;
                }
            } while (stackchoice != 8);
            break;
        case 3: {
            cout << "Exit" << endl;
            break;
        }
        default:
            cout << "Try again" << endl;
        }
    } while (choice != 3);

    return 0;
}

