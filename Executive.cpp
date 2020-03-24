#include "Executive.h"

Executive::Executive(string file)
{
  fileName = file;
  bst = new BST;
  rootPtr = nullptr;
}

void Executive::Run()
{

  GetInputFromFile();

  int userChoice;
  int num;
  while(userChoice != 9)
  {
    PrintMenu();
    std::cout << "Your choice: ";
    WrongInputTypeCheck(userChoice);

    switch(userChoice)
    {
      case 1:
        std::cout << "Input an integer to add to the tree: ";
        WrongInputTypeCheck(num);
        if(rootPtr == nullptr)
          rootPtr = bst->AddItem(num, rootPtr);
        else
          bst->AddItem(num, rootPtr);
        break;

      case 2:
        std::cout << "Input an integer to remove from the tree: ";
        WrongInputTypeCheck(num);
        rootPtr = bst->DeleteItem(num, rootPtr);
        break;

      case 3:
        std::cout << "Input a key: ";
        WrongInputTypeCheck(num);
        if(bst->InorderSuccessor(num, rootPtr) != nullptr)
        {
          std::cout << "Your inorder successor is: " << bst->InorderSuccessor(num, rootPtr)->GetItem();
        }
        else
        {
          std::cout << "\nInorder successor for " << num << " does not exist in this current Binary Search Tree.\n";
        }
        break;

      case 4:
        std::cout << "LevelOrder: ";
        bst->LevelOrder(rootPtr);
        break;

      case 5:
        std::cout << bst->HeightOfTree(rootPtr);
        std::cout << "Spiral LevelOrder: ";
        bst->LevelOrderSpiral(rootPtr);
        break;

      case 6:
      {
        TreeNode* current = rootPtr;
        std::cout << "Left Side View: ";
        while(current != nullptr)
        {
          std::cout << current->GetItem() << " ";
          current = current->GetLeft();
        }
        break;
      }

      case 7:
      {
        TreeNode* current = rootPtr;
        std::cout << "Right Side View: ";
        while(current != nullptr)
        {
          std::cout << current->GetItem() << " ";
          current = current->GetRight();
        }
        break;
      }

      case 8:
      {
        std::cout << "Input an integer: ";
        WrongInputTypeCheck(num);

        if(num < 1)
          std::cout << "Number must be larger than 0\n";
        TreeNode* current = rootPtr;

        while(current->GetLeft() != nullptr)
          current = current->GetLeft();

        int i = 1;

        while(i < num)
        {
          if(current == nullptr)
            break;
          TreeNode* temp = current;
          current = bst->InorderSuccessor(current->GetItem(), rootPtr);
          if(current->GetRight() != nullptr)
          {
            if(current->GetItem() == current->GetRight()->GetItem())
            {

              current = current->GetRight();
            }
          }
          i++;
        }
        if(current != nullptr)
        {
          std::cout << "KthSmallestItem: " << current->GetItem();
        }
        else
        {
          std::cout << "Number too large.\n";
        }
        break;
      }

      case 9:
        std::cout << "\n\nGoodbye.\n";
        bst->ClearTree(rootPtr);
        delete bst;
        delete rootPtr;
        rootPtr = nullptr;
        bst = nullptr;
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
      rootPtr = bst->AddItem(item, rootPtr);
    inFile.close();
  }
  else
  {
    cout << "Unable to open file.\n\n";
  }
}
