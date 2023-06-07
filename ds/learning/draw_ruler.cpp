#include <iostream>
#include <vector>

using namespace std;

void draw_one_tick(int tick_length, int tick_label = -1);
void draw_one_tick(int tick_length, int tick_label = -1);
void draw_ruler(int n_inches, int major_length);

int main()
{
    cout << "Enter number of inches ";
    int n;
    cin >> n;
    draw_ruler(n, 3);
}

void draw_one_tick(int tick_length, int tick_label = -1)
{
    for (int i = 0; i < tick_length; i++)
        cout << "-";
    if (tick_label >= 0)
        cout << " " << tick_label;
    cout << "\n";
}

void draw_ticks(int tick_length)
{
    if (tick_length > 0)
    {
        draw_ticks(tick_length - 1);
        draw_one_tick(tick_length);
        draw_ticks(tick_length - 1);
    }
}

void draw_ruler(int n_inches, int major_length)
{
    draw_one_tick(major_length, 0);
    for (int i = 0; i <= n_inches; i++)
    {
        draw_ticks(major_length - 1);
        draw_one_tick(major_length, i);
    }
}