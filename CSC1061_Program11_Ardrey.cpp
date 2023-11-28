  Mark Ardrey

  Computer Science II CSC 1061 2H1 (C++)

  Programming Project 11

  This program uses quicksort three times, with the pivot point in the center, first, and last of the array. Next, it uses quicksort three more times, but with insertion as well. Finally, the program outputs the times the cpu needed to sort them

  Inputs: None.
  Outputs: A success for starting and finishing the program, and 6 cpu times that the processer needed to sort the array each time.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//the six functions to sort the array the six different ways
void quickSortFirst(int *unsortedArray, int lowerValue, int higherValue);
void quickSortCenter(int *unsortedArray, int lowerValue, int higherValue);
void quickSortLast(int *unsortedArray, int lowerValue, int higherValue);
void quickInsertionSortFirst(int *unsortedArray, int lowerValuer, int higherValue);
void quickInsertionSortCenter(int *unsortedArray, int lowerValuer, int higherValue);
void quickInsertionSortLast(int *unsortedArray, int lowerValuer, int higherValue);

//other functions needed, such as initializing the array, or partitioning it
void generateArray(int *unsortedArray, int size, int seed);
void insertionSort(int *unsortedArray, int lowerValue, int higherValue);
int partition(int *unsortedArray, int lowerValue, int higherValue, int pivot);

int main()
{
  //the seed, size, and array are all set
  //the seed is defined because the array needs to be the same each sort
  int seed = std::time(NULL);
  int unsortedArray[10000];
  int size = 10000;

  //the clocks are set
  clock_t startTime;
  clock_t endTime;

  //output to ensure the program is running
  cout << "Starting...\n";

  //each of the six times the program sorts an array, it generates an array with the same seed
  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickSortFirst(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort, pivot first: " << endTime - startTime << '\n';

  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickSortCenter(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort, pivot middle: " << endTime - startTime << '\n';

  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickSortLast(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort, pivot last: " << endTime - startTime << '\n';

  cout << '\n';

  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickInsertionSortFirst(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort with insertion, pivot first: " << endTime - startTime << '\n';

  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickInsertionSortCenter(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort with insertion, pivot middle: " << endTime - startTime << '\n';

  generateArray(unsortedArray, size, seed);

  startTime = clock();
  quickInsertionSortLast(unsortedArray, 0, size - 1);
  endTime = clock();

  cout << "Quicksort with insertion, pivot last: " << endTime - startTime << '\n';

  //output to ensure the program finishes
  cout << "Program successfully ran.\n";

  return 0;
}

//initializes the array
void generateArray(int *unsortedArray, int size, int seed)
{
  int randomNumber;
  srand(seed);

  for (int i = 0; i < size; i++)
    {
      randomNumber = 1 + std::rand() / ((RAND_MAX + 1u) / 3000);
      unsortedArray[i] = randomNumber;
    }
}

//the next three functions are indetical, however the pivot is different
void quickSortLast(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the last index here
  int pivot = higherValue;

  //recursively loops through the function swapping each index
  if (lowerValue < higherValue)
  {
    int index = partition(unsortedArray, lowerValue, higherValue, pivot);
    quickSortFirst(unsortedArray, lowerValue, index - 1);
    quickSortFirst(unsortedArray, index + 1, higherValue);
  }
}

void quickSortFirst(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the first index here
  int pivot = lowerValue;

  if (lowerValue < higherValue)
  {
    int index = partition(unsortedArray, lowerValue, higherValue, pivot);
    quickSortFirst(unsortedArray, lowerValue, index - 1);
    quickSortFirst(unsortedArray, index + 1, higherValue);
  }
}

void quickSortCenter(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the middle index here
  int pivot = higherValue / 2;

  if (lowerValue < higherValue)
  {
    int index = partition(unsortedArray, lowerValue, higherValue, pivot);
    quickSortFirst(unsortedArray, lowerValue, index - 1);
    quickSortFirst(unsortedArray, index + 1, higherValue);
  }
}
//end of the standard quicksorts

//the next three functions are indentical, however the the pivot is different
void quickInsertionSortFirst(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the first index here
  int pivot = lowerValue;

  if (lowerValue < higherValue)
    {
      //if there are less than 20 elements left in the index, the program uses insertion sort
      if ((higherValue - lowerValue) < 20)
        {
          insertionSort(unsortedArray, lowerValue, higherValue);
        }
      //otherwise, the program uses quick sort as usual
      else
        {
          int index = partition(unsortedArray, lowerValue, higherValue, pivot);
          quickSortFirst(unsortedArray, lowerValue, index - 1);
          quickSortFirst(unsortedArray, index + 1, higherValue);
        }
    }
}

void quickInsertionSortLast(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the last element here
  int pivot = higherValue;

  if (lowerValue < higherValue)
    {
      if ((higherValue - lowerValue) < 20)
        {
          insertionSort(unsortedArray, lowerValue, higherValue);
        }
      else
        {
          int index = partition(unsortedArray, lowerValue, higherValue, pivot);
          quickSortFirst(unsortedArray, lowerValue, index - 1);
          quickSortFirst(unsortedArray, index + 1, higherValue);
        }
    }
}

void quickInsertionSortCenter(int *unsortedArray, int lowerValue, int higherValue)
{
  //pivot is the center index here
  int pivot = higherValue / 2;

  if (lowerValue < higherValue)
    {
      if ((higherValue - lowerValue) < 20)
        {
          insertionSort(unsortedArray, lowerValue, higherValue);
        }
      else
        {
          int index = partition(unsortedArray, lowerValue, higherValue, pivot);
          quickSortFirst(unsortedArray, lowerValue, index - 1);
          quickSortFirst(unsortedArray, index + 1, higherValue);
        }
    }
}
//end of the quick sorts with insertion

//partitions the array for quicksort
int partition(int *unsortedArray, int lowerValue, int higherValue, int pivot)
{
  //x is the element in the array at the pivot index
  int i = (lowerValue - 1);
  int x = unsortedArray[pivot];

  //the for loops checks each index for a value higher than the pivot index
  for (int j = lowerValue; j < higherValue; j++)
    {
      if (unsortedArray[j] <= x)
        {
          //if one is found, the program swaps the two elements
          i++;
          int temp = unsortedArray[i];
          unsortedArray[i] = unsortedArray[j];
          unsortedArray[j] = temp;
        }
    }

  //the program also swaps the new partition with the pivot
  int temp = unsortedArray[pivot];
  unsortedArray[pivot] = unsortedArray[i + 1];
  unsortedArray[i + 1] = temp;

  return (i + 1);
}

//standard insertion sort
void insertionSort(int *unsortedArray, int lowerValue, int higherValue)
{
  //loops through each element
  for (int j = lowerValue + 1; j <= higherValue; j++)
    {
      int insert = unsortedArray[j];
      int i = j - 1;
      while (i > 0 && unsortedArray[i] > insert)
        {
          //swaps the two if one is greater than the other
          unsortedArray[i + 1] = unsortedArray[i];
          i = i - 1;
        }
      unsortedArray[i + 1] = insert;
    }
}
