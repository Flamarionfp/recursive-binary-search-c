#include <stdio.h>

int searchNumber(int *numbers, int number, int startAt, int endAt, int *count) {
  (*count)++;

  if (startAt > endAt) {
    return -1; // vou retornar -1 para quando não encontrado
  }

  int middleOfArray = (startAt + endAt) / 2;

  if (numbers[middleOfArray] == number) {
    return middleOfArray;
  }

  if (numbers[middleOfArray] > number) {
    return searchNumber(numbers, number, startAt, middleOfArray - 1, count);
  }

  return searchNumber(numbers, number, middleOfArray + 1, endAt, count);
}

int resetCount(int *count) {
  *count = 0;
}

int main() {
  #define QUANTITY_OF_NUMBER 5

  int number[QUANTITY_OF_NUMBER] = {1, 4, 8, 13, 27};
  int valueToSearch, searchedIndex;
  int searchAgain = 0;
  int count = 0;

  do {
    printf("Qual valor buscar? ");
    scanf("%d", &valueToSearch);

    printf("Buscando valor %d...\n", valueToSearch);

    searchedIndex = searchNumber(number, valueToSearch, 0, QUANTITY_OF_NUMBER, &count);

    if (searchedIndex == -1) {
      printf("Valor %d nao encontrado!\n", valueToSearch);
    } else {
      printf("Valor %d encontrado na posicao %d\n", valueToSearch, searchedIndex + 1);
    }

    printf("Foram feitas %d chamadas recursivas\n", count);

    printf("Buscar outro valor? (1 para Sim, 0 para Nao) \n");
    scanf("%d", &searchAgain);
    resetCount(&count);
  } while (searchAgain != 0);

  return 0;
}