#include "Executive.h"

Executive::Executive(string file)
{
  fileName = file;
}

void Executive::Run()
{
  int userChoice;
  while(userChoice != 9)
  {
    PrintMenu();
    std::cout << "Your choice: ";
    WrongInputTypeCheck(userChoice);

    switch(userChoice)
    {
      case 1:
        break;

      case 2:
        break;

      case 3:
        break;

      case 4:
        break;

      case 5:
        break;

      case 6:
        break;

      case 7:
        break;

      case 8:
        break;

      case 9:
        break;

      default:
        cout << "Invalid choice. Try again.\n";
    }
  }
}

void Executive::PrintMenu()
{
  std::cout << "\nPlease select one of the following commands\n\n";

  std::cout << "\t1. AddItem\n"
            << "\t2. DeleteItem\n"
            << "\t3. InorderSuccessor\n"
            << "\t4. LevelOrder\n"
            << "\t5. SpiralLevelOrder\n"
            << "\t6. LeftSideView\n"
            << "\t7. RightSideView\n"
            << "\t8. KthSmallestItem\n"
            << "\t9. Exit\n\n";
}

void Executive::WrongInputTypeCheck(int &num)
{
  std::cin >> num;
  while(1)
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input a NUMBER please. \n\n";
        cout << "Your choice: ";
        cin >> num;
      }
      else
        break;
    }
}

void Executive::GetInputFromFile()
{
  ifstream inFile;
  int item;
  inFile.open(fileName);

  if(inFile.is_open())
  {
    while(inFile >> item)
      ;
      //bst.AddItem(item);
    inFile.close();
  }
  else
  {
    cout << "Unable to open file.\n\n";
  }
}
