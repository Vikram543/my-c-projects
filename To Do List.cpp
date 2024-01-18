#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void showTasks(const std::vector<std::string> &tasks)
{
  std::cout << "To-Do List:" << std::endl;
  for (int i = 0; i < tasks.size(); ++i)
  {
      std::cout << i + 1 << ". " << tasks[i] << std::endl;
  }
}

int main()
{
  std::vector<std::string> tasks;
  std::string task;
  char choice;

  // Load existing tasks from file
  std::ifstream inputFile("tasks.txt");
  while (getline(inputFile, task))
  {
      tasks.push_back(task);
  }
  inputFile.close();

  do
  {
      std::cout << "A - Add a New task" << std::endl;
      std::cout << "V - View All tasks" << std::endl;
      std::cout << "E - To Exit the function" << std::endl;
      std::cout << "Enter your choice from the above List: ";
      std::cin >> choice;

      switch (choice)
      {
      case 'A':
      case 'a':
          std::cout << "Enter a task: ";
          std::cin.ignore(); // Clears the input buffer
          getline(std::cin, task);
          tasks.push_back(task);
          break;
      case 'V':
      case 'v':
          showTasks(tasks);
          break;
      }
  } while (choice != 'E' && choice != 'e');

  // Save tasks to file
  std::ofstream outputFile("tasks.txt");
  for (const auto &t : tasks)
  {
      outputFile << t << std::endl;
  }
  outputFile.close();

  return 0;
}
