#include <iostream>
#include <cmath>
using namespace std;

struct location
{
    double x;
    double y;
};

double square(double a)
{
    return a*a;
}

double distance(location people1, location people2)
{
    double distance = fabs(sqrt(square(people1.x-people2.x)+square(people1.y-people2.y)));
    return distance;
}

int next_move(int now, int number, int threshold, location* people)
{
    int next_pos = -1;
    double min_distance = 0;
    for (int i = now; i < number-1; i++)
    {
        min_distance += distance(people[i], people[i+1]);
    }
    double new_distance = 0;
    for (int i = now + 1; i < number; i++)
    {
        new_distance = distance(people[now], people[i]) + distance(people[i], people[number-1]);
        if ((new_distance <= min_distance) && ( distance(people[now], people[i]) <= threshold))
        {
            next_pos = i;
        }
    }
    
    return next_pos;
}

int main()
{
    int number, threshold;
    cin >> number >> threshold;
    location *people = new location [number];
    
    
    for (int i = 0; i < number; i++)
    {
        cin >> people[i].x >> people[i].y;
    }
    
    int now = 0;
    int next_pos = 0;
    int check = 1;
    
    while (next_pos != number-1)
    {
        next_pos = next_move(now, number, threshold, people);
        if (next_pos == -1)
        {
            cout << "n" << endl;
            check = 0;
            break;
        }
        else
        {
            now = next_pos;
        }
    }
    
    
    if ( check )
    {
        cout << "y" << endl;
    }
    
    delete [] people;
    return 0;
}
