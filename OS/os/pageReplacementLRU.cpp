#include <bits/stdc++.h>
using namespace std;

int main()
{
    int capacity = 4;
    int arr[] = {5, 0, 1, 2, 0, 1, 5, 10, 2, 7, 5, 3, 2};

    deque<int> q(capacity);
    int count = 0;
    int page_faults = 0;
    deque<int>::iterator itr;
    q.clear();
    for (int i : arr)
    {

        // Insert it into set if not present
        // already which represents page fault
        itr = find(q.begin(), q.end(), i);
        if ((itr == q.end()))
        {

            ++page_faults;

            // Check if the set can hold equal pages
            if (q.size() == capacity)
            {
                q.erase(q.begin());
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        else
        {
            // Remove the indexes page
            q.erase(itr);

            // insert the current page
            q.push_back(i);
        }
    }
    cout << page_faults;
}
