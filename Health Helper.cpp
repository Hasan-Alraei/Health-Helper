#include <iostream>
using namespace std;

int main()
{
    int service, sexType, activityLevel, calories, packets;
    float weight, age, height, bmr, AF, waterAmount, money, cost, bmi;

    cout << "\n\t\t\t\t\tWELCOME TO HEALTH HELPER\n\n";
    cout << "   IN THIS PROGRAM, WE OFFER YOU THE FOLLOWING SERVICES:\n\n";
    cout << "1 - Calculate your daily calorie needs\n";
    cout << "2 - Calculate the amount of water in your body\n";
    cout << "3 - Calculate the cost of your smoking habit\n";
    cout << "4 - Check if your weight is healthy for your height\n";
    cout << "\nEnter the service number:\n";
    cin >> service;

    switch (service)
    {
    case 1:
        cout << "\nPLEASE ENTER 1 FOR MALE OR 2 FOR FEMALE:\n";
        cin >> sexType;
        while (sexType != 1 && sexType != 2)
        {
            cout << "ERROR... Please enter 1 for male or 2 for female:\n";
            cin >> sexType;
        }

        cout << "Enter your age:\n";
        cin >> age;
        while (age <= 0 || age >= 130)
        {
            cout << "Please enter a valid age:\n";
            cin >> age;
        }

        cout << "Enter your weight (kg):\n";
        cin >> weight;
        while (weight <= 2 || weight >= 200)
        {
            cout << "Please enter a valid weight:\n";
            cin >> weight;
        }

        cout << "Enter your height (cm):\n";
        cin >> height;
        while (height <= 40 || height >= 220)
        {
            cout << "Please enter a valid height:\n";
            cin >> height;
        }

        bmr = (sexType == 1)
            ? ((weight * 10) + (6.25 * height) - (5 * age) + 5)
            : ((weight * 10) + (6.25 * height) - (5 * age) - 161);

        cout << "Choose your activity level:\n";
        cout << "1 - Sedentary\n";
        cout << "2 - Lightly active\n";
        cout << "3 - Moderately active\n";
        cout << "4 - Very active\n";
        cout << "5 - Super active\n";
        cin >> activityLevel;
        while (activityLevel < 1 || activityLevel > 5)
        {
            cout << "ERROR... Please enter a number from 1 to 5:\n";
            cin >> activityLevel;
        }

        if (activityLevel == 1) AF = 1.2;
        else if (activityLevel == 2) AF = 1.375;
        else if (activityLevel == 3) AF = 1.55;
        else if (activityLevel == 4) AF = 1.725;
        else if (activityLevel == 5) AF = 1.9;

        calories = AF * bmr;
        cout << "\nYour daily calorie needs are: " << calories << "\n";
        break;

    case 2:
        cout << "Enter your weight (kg):\n";
        cin >> weight;
        while (weight <= 2 || weight >= 200)
        {
            cout << "Please enter a valid weight:\n";
            cin >> weight;
        }
        waterAmount = weight * 0.6;
        cout << "Your body contains approximately " << waterAmount << " liters of water.\n";
        break;

    case 3:
        cout << "How many packets of cigarettes do you smoke per day?\n";
        cin >> packets;
        while (packets <= 0 || packets > 25)
        {
            if (packets == 0)
                cout << "Then why calculate the smoking cost? 😄\n";
            else if (packets > 25)
                cout << "That's too high! Please enter a realistic number:\n";
            cin >> packets;
        }

        cout << "How much does one packet cost?\n";
        cin >> money;
        cost = packets * money;
        cout << "Daily smoking cost: " << cost << "\n";
        cout << "Weekly cost: " << cost * 7 << "\n";
        cout << "Monthly cost: " << cost * 30 << "\n";
        cout << "Annual cost: " << cost * 365 << "\n";
        cout << "\nTake care of your health and consider quitting. 😊\n";
        break;

    case 4:
        cout << "Enter your weight (kg):\n";
        cin >> weight;
        while (weight <= 2 || weight >= 200)
        {
            cout << "Please enter a valid weight:\n";
            cin >> weight;
        }

        cout << "Enter your height (cm):\n";
        cin >> height;
        while (height <= 40 || height >= 220)
        {
            cout << "Please enter a valid height:\n";
            cin >> height;
        }

        height = height / 100;
        bmi = weight / (height * height);

        if (bmi < 18.5)
            cout << "You are underweight. Consider eating more.\n";
        else if (bmi >= 18.5 && bmi <= 24.9)
            cout << "Your weight is healthy. Keep it up!\n";
        else if (bmi > 24.9 && bmi <= 29.9)
            cout << "You're slightly overweight. Consider a light diet.\n";
        else if (bmi >= 30)
            cout << "You're very overweight. A strong diet is recommended.\n";
        break;

    default:
        cout << "ERROR... Please enter a number from 1 to 4\n";
        break;
    }

    cout << "\n\tThank you for using Health Helper.\n\n";
}
