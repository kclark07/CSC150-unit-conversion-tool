/** ***************************************************************************
 * @file
 *
 * @mainpage
 *
 * @section CSC_150 - MO1
 *
 * @author Kaeli Clark
 *
 * @date 11/08/2019
 * 
 * @par Professor:
 *         Daniel M. de Castro
 *
 * @par Course:
 *         CSC 150
 *
 * @par Location:
 *         McLaury - Room 306
 *
 * @section program_section Program Information
 *
 * @details This program is a unit conversion tool. Depending on the user
 * input it can convert temperature (celsius and fahrenheit), distance (miles,
 * meters, and kilometers), and volume (liters, quarts, and gallons). It is
 * designed to help people convert measures of units.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      Not a real program
 *
 * @par Usage:
   @verbatim
   c:\> d.exe
   d:\> c:\bin\d.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 *
 * @todo none
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date           Modification
   -------------  -------------------------------------------------------------
   Oct  20, 2019  Started writing program, added function prototypes  and
   documentation
   Oct  21, 2019  Started writing functions
   Oct  25, 2019  Started writing my int main() function
   Oct  27, 2019  Started testing the code in blocks to find bugs
   Oct  30, 2019  Started revising
   Nov  02, 2019  Started writing comments
   Nov  08, 2019  Finished documentation, then finished program


   @endverbatim
 *
 *************************************************************************** */
#include <iostream>
#include <ios>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//function prototypes (required)
void show_main_menu(char& user_input);
double celsius_to_fahrenheit(double celsius, double fahrenheit);
double fahrenheit_to_celsius(double fahrenheit, double celsius);
void miles_to_metric(double& miles, double& kilometers, double& meters);
void km_to_imperial(double& kilometers, double& miles, double& feet);
double convert_volume(double volume, string& symbol);

//additional funtion prototypes
void temperature_menu(char& temp_input);
void distance_menu(char& dist_input);
void volume_menu();

/*!
 * @brief the value of feet in a mile
 */
const int FEET_IN_MILE = 5280;
/*!
 * @brief the value of meters in a mile
 */
const double METERS_PER_MILE = 1609.34;
/*!
 * @brief the value of meters in a kilometer
 */
const int METERS_PER_KILOMETER = 1000;

int main()
{
    //declare variables
    char user_input;
    char temp_input;
    char dist_input;
    double meters;
    double volume = 0.0;
    double feet = 0.0;
    double kilometers = 0.0;
    double miles = 0.0;
    double gallon = 0.0;
    double liters = 0.0;
    double quarts = 0.0;
    int stop_program = 0;
    string symbol = "";
    double celsius = 0.0;
    double fahrenheit = 0.0;

    //call function to show the main menu
    show_main_menu(user_input);

    //while loop to run all parts of loop over and over
    while (stop_program == 0)
    {

        if (user_input == 'T' || user_input == 't')
        {
            cout << endl;
            //call temp memu
            temperature_menu(temp_input);

            if (temp_input == 'F' || temp_input == 'f')
            {
                //call celsius to fahrenheit conversion function
                celsius_to_fahrenheit(fahrenheit, celsius);

                cout << endl;
                //call main menu function after conversion
                show_main_menu(user_input);
            }

            else if (temp_input == 'C' || temp_input == 'c')
            {
                //call fahrenheit to celsius conversion function
                fahrenheit_to_celsius(celsius, fahrenheit);
                cout << endl;
                //call main menu function after fahrenheit conversion
                show_main_menu(user_input);
            }

            //if the user input is x, show main menu
            else if (temp_input == 'X' || temp_input == 'x')
            {
                cout << endl;
                show_main_menu(user_input);
            }
            //if the user input isnt one of the options, print invalid and 
            //loop again
            else
            {
                cout << "Invalid input!" << endl;
                cout << endl;
            }

        }

        else if (user_input == 'D' || user_input == 'd')
        {
            cout << endl;
            //print distance menu
            distance_menu(dist_input);


            if (dist_input == 'M' || dist_input == 'm')
            {
                //call function to convert miles to meters
                miles_to_metric(miles, kilometers, meters);

                show_main_menu(user_input);
            }
            else if (dist_input == 'I' || dist_input == 'i')
            {
                //call function to convert kilometers to miles
                km_to_imperial(kilometers, miles, feet);

                show_main_menu(user_input);
            }

            //if user input is x, loop main menu
            else if (dist_input == 'X' || dist_input == 'x')
            {
                cout << endl;
                show_main_menu(user_input);
            }
            //if the input is not one of the options, loop dist menu again
            else
            {
                cout << "Invalid input!" << endl;
                cout << endl;
                distance_menu(dist_input);
            }

        }
        else if (user_input == 'V' || user_input == 'v')
        {
            cout << endl;
            //call volume menu function
            volume_menu();
            //ask user to enter size of volume theyd like to convert
            cout << "Enter the volume to convert: ";
            cin >> volume;

            //call convert volume function
            convert_volume(volume, symbol);

            cout << endl;

            //call main menu function to loop after the convertion happened
            show_main_menu(user_input);
        }

        //if main menu input was x, print goodbye and exit program
        else if (user_input == 'X' || user_input == 'x')
        {
            cout << "Goodbye!" << endl;

            //return 1 to stop the while loop
            return 1;
        }

        //if the input is not one of the options, then print invalid and 
        // loop main menu again
        else
        {
            cout << "Invalid option" << endl << endl;

            show_main_menu(user_input);
        }

    }
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * Prints out the main menu and conversion options and asks the user for
 * what type of conversion they want.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void show_main_menu(char& user_input)
{
    cout << "Unit Conversion Tool" << endl << endl;

    cout << "Main Menu:" << endl;
    cout << setfill('-') << setw(20) << "" << endl;

    cout << "(T) Temperature" << endl;
    cout << "(D) Distance" << endl;
    cout << "(V) Volume" << endl;
    cout << "(X) Exit" << endl;

    cout << "Select the type of conversion: ";
    cin >> user_input;


}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description: This function takes in the user input for celsius and
 * converts it to fahrenheit.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
double celsius_to_fahrenheit(double fahrenheit, double celsius)
{
    cout << "Enter the temperature in celsius: ";
    cin >> celsius;

    fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;

    cout << fixed << setprecision(4) << celsius
        << " degrees Celsius is equivalent to " << fahrenheit <<
        " degrees Fahrenheit" << endl;

    return fahrenheit;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function takes in the user input for fahrenheit and converts it to
 * celsius.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
double fahrenheit_to_celsius(double celsius, double fahrenheit)
{
    cout << "Enter the temperature in fahrenheit: ";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32.0) * (5.0 / 9.0);


    cout << fixed << setprecision(4) << fahrenheit
        << " degrees Fahrenheit is equivalent to "
        << celsius << " degrees Celsius" << endl;

    return celsius;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function prints out the menu for the temperature selection, and prints
 * out the option for choosing whether you want to convert from celsius or
 * fahrenheit.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void temperature_menu(char& temp_input)
{
    cout << "Temperature conversion:" << endl;
    cout << setfill('-') << setw(20) << "" << endl;

    cout << "(F) From Celsius to Fahrenheit" << endl;
    cout << "(C) From Fahrenheit to Celsius" << endl;
    cout << "(X) Back to main menu" << endl;
    cout << "Select type of conversion: ";
    cin >> temp_input;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function prints out the distance option menu and asks what the user
 * would like to do from there.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void distance_menu(char& dist_input)
{
    cout << "Distance conversion:" << endl;
    cout << setfill('-') << setw(20) << "" << endl;

    cout << "(M) Miles to Metric" << endl;
    cout << "(I) Kilometers to Imperial" << endl;
    cout << "(X) Back to main menu" << endl;

    cout << "Select type of conversion: ";
    cin >> dist_input;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This asks the user for distance in miles and then converts it to
 * kilometers and meters.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void miles_to_metric(double& miles, double& kilometers, double& meters)
{
    cout << "Enter the distance in Miles: ";
    cin >> miles;

    meters = miles * METERS_PER_MILE;
    kilometers = meters / METERS_PER_KILOMETER;

    cout << fixed << setprecision(4) << miles << " mi is equivalent to "
        << kilometers << " km or " << meters << " m" << endl;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function takes in the user input for kilometers and then converts it
 * to miles and feet.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void km_to_imperial(double& kilometers, double& miles, double& feet)
{
    cout << "Enter distance in Kilometers: ";
    cin >> kilometers;

    miles = (kilometers * METERS_PER_KILOMETER) / METERS_PER_MILE;
    feet = miles * FEET_IN_MILE;

    cout << fixed << setprecision(4) << kilometers 
        << " Km is equivalent to " << miles << " mi or " << feet << " ft" 
        << endl;
}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function prints the volume menu.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
void volume_menu()
{
    cout << "Volume conversion:" << endl;
    cout << setfill('-') << setw(20) << "" << endl;

}


/** ***************************************************************************
 * @author Kaeli Clark
 *
 * @par Description:
 * This function asks the user how they would like to convert the volume input.
 * Asks for first input (liters, gallons, or quarts), and then asks for the
 * second input (liters, gallons, or quarts), and then converts accordingly.
 *
 * @param[n/a]
 *
 * @returns null
 *
 *****************************************************************************/
double convert_volume(double volume, string& symbol)
{
    char vol_input1;
    char vol_input2;

    //ask for first volume conversion input
    cout << "Select unit to convert from (L for liter, G for gallons,"
        << " or Q for quarts): ";
    cin >> vol_input1;

    //while loop to check if the vol1 input is not one of the options, if
    // so, then loop invalid and selection
    while (vol_input1 != 'L' && vol_input1 != 'l'
        && vol_input1 != 'G' && vol_input1 != 'g'
        && vol_input1 != 'Q' && vol_input1 != 'q')
    {
        cout << "Invalid option" << endl;

        cout << "Select unit to convert from (L for liter, G for gallons, "
            << "or Q for quarts): ";

        cin >> vol_input1;

    }

    if (vol_input1 == 'L' || vol_input1 == 'l')
    {

        cout << "Select unit to convert to (L for liter, G for gallons,"
            << " or Q for quarts): ";
        cin >> vol_input2;

        //while loop to check if the vol1 input is not one of the options, if
        // so, then loop invalid and selection
        while (vol_input2 != 'L' && vol_input2 != 'l'
            && vol_input2 != 'G' && vol_input2 != 'g'
            && vol_input2 != 'Q' && vol_input2 != 'q')
        {
            cout << "Invalid option" << endl;

            cout << "Select unit to convert to (L for liter, G for gallons, "
                << "or Q for quarts): ";

            cin >> vol_input2;
        }


        if (vol_input2 == 'L' || vol_input2 == 'l')
        {
            //same value, so return volume
            symbol = "l";

            cout << "You have approximately " << fixed << setprecision(4) 
                << volume << " " << symbol << endl;



        }
        else if (vol_input2 == 'G' || vol_input2 == 'g')
        {
            //convert liters to gallons, then print statement
            double liters_to_gallons = 0.0;

            liters_to_gallons = volume / 3.785;

            symbol = "g";

            cout << "You have approximately " << fixed << setprecision(4) 
                << liters_to_gallons << " " << symbol << endl;




        }
        else if (vol_input2 == 'Q' || vol_input2 == 'q')
        {
            //convert liters to quarts, then print statement
            double liters_to_quarts = 0.0;

            liters_to_quarts = volume * 1.05669;

            symbol = "Q";

            cout << "You have approximately " << fixed << setprecision(4)
                << liters_to_quarts << " " << symbol << endl;


        }

    }
    else if (vol_input1 == 'G' || vol_input1 == 'g')
    {
        cout << "Select unit to convert to (L for liter, G for gallons, "
            << "or Q for quarts): ";

        cin >> vol_input2;

        //while loop to check if the vol1 input is not one of the options, if
        // so, then loop invalid and selection
        while (vol_input2 != 'L' && vol_input2 != 'l'
            && vol_input2 != 'G' && vol_input2 != 'g'
            && vol_input2 != 'Q' && vol_input2 != 'q')
        {
            cout << "Invalid option" << endl;

            cout << "Select unit to convert to (L for liter, G for gallons, "
                << "or Q for quarts): ";

            cin >> vol_input2;
        }

        if (vol_input2 == 'L' || vol_input2 == 'l')
        {
            //convert gallons to liters, then print statement 
            double gallons_to_liters = 0.0;

            gallons_to_liters = volume * 3.78541;

            cout << "You have approximately " << fixed << setprecision(4)
                << gallons_to_liters << " l" << endl;

            return gallons_to_liters;
        }
        else if (vol_input2 == 'G' || vol_input2 == 'g')
        {
            //same, so print the volume input
            symbol = "G";

            cout << "You have approximately " << fixed << setprecision(4)
                << volume << " " << symbol << endl;

            return volume;
        }
        else if (vol_input2 == 'Q' || vol_input2 == 'q')
        {
            //convert gallons to quarts, then print statement 
            double gallons_to_quarts = 0.0;

            gallons_to_quarts = volume * 4;

            symbol = "Q";

            cout << "You have approximately " << fixed << setprecision(4)
                << gallons_to_quarts << " " << symbol << endl;

            
        }

    }
    else if (vol_input1 == 'Q' || vol_input1 == 'q')
    {
        cout << "Select unit to convert to (L for liter, G for gallons, "
            << "or Q for quarts): ";

        cin >> vol_input2;
        //while loop to check if the vol1 input is not one of the options, if
        // so, then loop invalid and selection
        while (vol_input2 != 'L' && vol_input2 != 'l'
            && vol_input2 != 'G' && vol_input2 != 'g'
            && vol_input2 != 'Q' && vol_input2 != 'q')
        {
            cout << "Invalid option" << endl;

            cout << "Select unit to convert to (L for liter, G for gallons, "
                << "or Q for quarts): ";

            cin >> vol_input2;
        }

        if (vol_input2 == 'L' || vol_input2 == 'l')
        {
            //convert quarts to liters, then print statement 
            double quarts_to_liters = 0.0;

            quarts_to_liters = volume / 1.057;

            symbol = "L";

            cout << "You have approximately " << fixed << setprecision(4)
                << quarts_to_liters << " " << symbol << endl;
            return quarts_to_liters;
        }
        else if (vol_input2 == 'G' || vol_input2 == 'g')
        {
            //convert quarts to gallons, then print statement 
            double quarts_to_gallons = 0.0;

            quarts_to_gallons = volume / 4;

            symbol = "G";

            cout << "You have approximately " << fixed << setprecision(4)
                << quarts_to_gallons << " " << symbol << endl;

            return quarts_to_gallons;

        }
        else if (vol_input2 == 'Q' || vol_input2 == 'q')
        {
            //same, so just print the user volume
            symbol = "Q";
            cout << "You have approximately " << fixed << setprecision(4)
                << volume << " " << symbol << endl;

            return volume;

        }
    }
    return 0.0;
}

