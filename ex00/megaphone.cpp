#include <iostream>

int main(int ac, char *av[]) {
  int i;
  int j;

  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  i = 1;
  while (av[i]) {
    j = 0;
    while (av[i][j]) {
      if (std::islower(av[i][j]))
        std::cout << (char)std::toupper(av[i][j]);
      else
        std::cout << av[i][j];
      j++;
    }
    if (i + 1 != ac)
      std::cout << " ";
    else
      std::cout << std::endl;
    i++;
  }
  return 0;
}
