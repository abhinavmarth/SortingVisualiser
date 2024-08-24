
Sorting Visualizer
This program visualizes various sorting algorithms using SDL2 graphics. It provides a visual representation of the sorting process for different algorithms.

Features
Bubble Sort
Selection Sort
Insertion Sort
Merge Sort
Quick Sort
Requirements
SDL2 library
How to Run
Install SDL2: Make sure you have the SDL2 library installed on your system. You can download it from the SDL2 website.

Compile the Program: Use a C++ compiler to compile the source code. Make sure to link against SDL2.

bash
Copy code
g++ -o sorting_visualizer sorting_visualizer.cpp -lSDL2
Run the Program: Execute the compiled program.

bash
Copy code
./sorting_visualizer
Choose Sorting Algorithm:

After running, you’ll see a menu with sorting algorithms.
Enter the number corresponding to the sorting algorithm you want to visualize:
1 for Bubble Sort
2 for Selection Sort
3 for Insertion Sort
4 for Merge Sort
5 for Quick Sort
Watch the Visualization: The program will display a window with bars representing the elements of the array being sorted. The bars will change color to show the elements being compared and swapped.

Description
Bubble Sort: Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
Selection Sort: Repeatedly selects the smallest (or largest) element from the unsorted portion and moves it to the sorted portion.
Insertion Sort: Builds the final sorted array one item at a time by inserting elements into their correct position.
Merge Sort: Divides the array into halves, recursively sorts each half, and then merges the sorted halves.
Quick Sort: Picks an element as a pivot and partitions the array around the pivot. Recursively sorts the partitions.
Notes
The visualization scales the window based on the number of elements and their values.
Sorting animations are controlled by delays, which can be adjusted for faster or slower visualizations.
Troubleshooting
No window appears: Ensure SDL2 is correctly installed and linked.
Compilation errors: Verify that SDL2 development libraries are installed and correctly configured.
