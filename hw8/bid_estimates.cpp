#include <iostream>

using namespace std;

void get_sqr_ft(int& wall_sqr_ft, int& ceiling_sqr_ft)
{
    // Get the square feet for the walls
    cout << "Type in the number of square feet for the walls: ";
    cin >> wall_sqr_ft;

    // Get the square feet for the ceiling
    cout << "Type in the number of square feet for the ceilings: ";
    cin >> ceiling_sqr_ft;

    return;
}

double calculate_painting_labor(int& wall_sqr_ft, int& ceiling_sqr_ft, double& total_labor)
{
    // Dollars per hour for walls and ceilings
    int dol_per_hr = 40;

    // Hours per 200 Square Feet
    const float ceiling_hr_per_sqft = 3.2;

    // Hours per 200 Square Feet
    const float wall_hr_per_sqft = 2.5;

    double wall_hours = 0;
    double wall_labor = 0;
    double ceiling_labor = ((ceiling_sqr_ft / 200) * ceiling_hr_per_sqft) * dol_per_hr;

    if (wall_sqr_ft > 1400)
    {
        wall_sqr_ft -= 1400;
        wall_hours += (wall_sqr_ft / 200) * wall_hr_per_sqft;
        wall_labor = (dol_per_hr * 17.5) + (34 * wall_hours);
    }

    else
    {
        wall_hours += (wall_sqr_ft / 200) * wall_hr_per_sqft;
        wall_labor = dol_per_hr * wall_hours;
    }

    cout << "Ceiling Labor: " << ceiling_labor << endl << "Wall Labor: "
         << wall_labor << endl;

    total_labor += ceiling_labor + wall_labor;

    return total_labor;
}

void painting_cost()
{

    double total_labor = 0;
    int wall_sqr_ft = 0;
    int ceiling_sqr_ft = 0;

    get_sqr_ft(wall_sqr_ft, ceiling_sqr_ft);
    total_labor = calculate_painting_labor(wall_sqr_ft, ceiling_sqr_ft, total_labor);

    cout << "Total expenses for the walls and ceilings: " << total_labor
         << endl;

    return;
}

string get_fm()
{
    string floor_material;

    cout << "Type in the type of material your floors are (Wood, Tile, Other): ";
    cin >> floor_material;

    return floor_material;
}

void get_sqft(int& sqft)
{
    cout << "Type in the number of square foot to replace: ";
    cin >> sqft;

    return;
}

double calculate_flooring_labor(double dol_per_hr, double hr_per_sqft, int sq_ft)
{
    return (((sq_ft / 100) * hr_per_sqft) * dol_per_hr);
}

void flooring_cost()
{
    int sq_ft = 0;
    double total_labor = 0;
    string floor_material = get_fm();

    double dol_per_hr = 0;

    // Hours per 100 Square Feet
    double hr_per_sqft = 0;

    while (true)
    {
        if (floor_material == "Wood")
        {
            dol_per_hr = 48;
            hr_per_sqft = 2;
            break;
        }

        if (floor_material == "Tile")
        {
            dol_per_hr = 52;
            hr_per_sqft = 2.8;
            break;
        }

        if (floor_material == "Other")
        {
            dol_per_hr = 30;
            hr_per_sqft = 1.7;
            break;
        }

        cout << "Your input did not match \"Wood\", \"Tile\", or \"Other\"."
             << endl;
        floor_material = get_fm();
    }

    get_sqft(sq_ft);
    total_labor = calculate_flooring_labor(dol_per_hr, hr_per_sqft, sq_ft);

    cout << "Total expenses for replacing the flooring: " << total_labor
         << endl;
}

int main()
{
    /* painting_cost(); */
    flooring_cost();
}