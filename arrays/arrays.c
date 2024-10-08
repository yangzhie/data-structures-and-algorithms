#include <stdio.h>

void traversal();
void insertion();
void deletion();

int main()
{
    deletion();
}

/*
 * Traversal:
 * Visiting every element of the array at least once
 */

void traversal()
{
    // Initialization & Declaration
    // 50 * 4 bytes = 200 bytes this array takes up
    int a[50];
    int size;

    // User input: size of array
    printf("Enter the size of the array: \n");
    scanf("%d", &size); // The value that the user provides should be stored in memory

    // User input: elements of array
    printf("Enter the elements of the array: \n");
    // i < size so if input size was 5, it would be i < 4
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    // Print output array
    printf("Elements in the array are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

/*
 * Insertion:
 * Insert data at any position in an array
 */

void insertion()
{
    int a[50];
    int size;

    int number;
    int position;

    // User input: size of array
    printf("Enter the size of the array: \n");
    scanf("%d", &size);

    // User input: elements of array
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    /*
     * Start the loop from the last position of the array, at index: size - 1
     * because we need to shift all elements to the right to insert or else other elements will get overwritten.
     * When it has found the index for the new element to be inserted into, we stop there
     * because at that point the duplication of that index is completed
     * and overwriting of new number at that index can begin.
     */

    printf("Enter the number you want to insert: \n");
    scanf("%d", &number);

    printf("Enter the position you want to insert %d at: \n", number);
    scanf("%d", &position);

    /*
     * Let's say the array size inputted is 5, number is 10 and position is 3.
     * This makes the index for the loop to be stopped at 2 (3 - 1)
     * [1, 2, 3, 4, 5]
     *  0  1  2  3  4
     *        pos-1 size - 1
     */
    for (int i = size - 1; i >= position - 1; i--) // Decrement as we are traversing right-to-left
    {
        /*
         * a[i] would be shifted to a[i + 1]
         * At the start, size - 1 = 5 - 1 => i = 4
         * Then 4 >= position - 1 = 3 - 1 = 2 => true, continue
         * Thus, a[5] = a[4]
         * So a[4]'s element would be transferred to a[5], a newly created (not really) slot in the array
         */
        a[i + 1] = a[i];
    }

    a[position - 1] = number; // Now we insert the number
    size++;                   // Now array size becomes 6

    /*
     * In arrays it is not possible to insert data into non-continuous indicies. (position > size + 1)
     * i.e if for this array if you wanted to store a number at a[20], this is not possible
     * as the data in arrays is stored in continuous locations.
     */

    // Print output array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

/*
 * Deletion: Delete data at any position in an array
 */

void deletion()
{
    int a[50];
    int size;
    int position;

    // User input: size of array
    printf("Enter the size of the array: \n");
    scanf("%d", &size);

    // User input: elements of array
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    // User input: position
    printf("What position do you want to delete the element from?: \n");
    scanf("%d", &position);

    /*
     * I want to delete the data present at position 2.
     * [1, 2, 3, 4, 5]
     *  0  1  2  3  4
     * p-1 p
     * What needs to happen is when the deletion occurs, we need to shift all existing elements
     * one to the left and fill up the array so that it is continuous.
     * We start the loop from pos - 1, the index until size - 1.
     * This time, we start from position - 1 => 0
     * The loop ends at the end of the array, size - 1 => 4
     */

    /*
     * Delete the first element in the array: i = 0; i < size - 1; i++
     * Remove the last element by reducing the logical size
     * if (size > 0) {
     *    size--;  Decrease the logical size by 1
     * }
     */
    for (int i = position - 1; i < size - 1; i++)
    {
        /*
         * a[i + 1] would be shifted to a[i]
         * At the start, i = position - 1 = 2 - 1 => i = 1
         * Then i < size = 1 < 5 - 1 = 4 => true, continue
         * Thus, a[1] = a[2]
         * So a[2]'s element would be transferred to a[1]
         */

        a[i] = a[i + 1];
    }
    size--; // Size of the array has been decremented due to deletion

    // Print output array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}