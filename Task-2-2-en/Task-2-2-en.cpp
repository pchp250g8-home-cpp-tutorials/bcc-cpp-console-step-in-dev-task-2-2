#include <iostream>
#include <tchar.h>
#include <locale>

int _tmain(int argc, _TCHAR* argv[])
{
    unsigned int prev; // first height
    unsigned int curr; // second height
    unsigned int next_val; // third height
    unsigned int peaks_count = 0; // peak counter
    bool b_done = false; // loop termination flag
    // Data input
    // Display prompt on screen
    std::cout << "Enter radar station data (0 to end input).\r\n";
    // Read the first two elements
    std::cin >> prev; // input first height
    std::cin >> curr; // input second height
    while (!b_done)
    {
        std::cin >> next_val; // input third height
        // If 0 is encountered, input is finished
        b_done = (next_val == 0); // loop termination condition
        // Check the peak condition for the current element
        if (!b_done && (curr > prev) && (curr > next_val))
        {
            peaks_count += 1; // increment peak counter by 1
        }
        // Shift the three-element "window" forward
        prev = curr;
        curr = next_val;
    }
    // Output to screen
    std::cout << "Number of peaks: " << peaks_count << "\r\n";
    // Delay screen output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
    return 0;
}
