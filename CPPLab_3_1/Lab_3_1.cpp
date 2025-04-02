#include <iostream>
#include <locale>
#include <math.h>

using namespace std;

int recursive_calls = 0;

double math_arth(double x) 
{
    return atanh(x);
}

double term(double x, int n) 
{
    return pow(x, 2 * n + 1) / (2 * n + 1);
}

double iterative_sum(double x, double epsilon) 
{
    double sum = 0;
    double current_term;
    int n = 0;
    do 
    {
        current_term = term(x, n);
        sum += current_term;
        n++;
    } while (fabs(math_arth(x) - sum) >= epsilon);
    return sum;
}

double recursive_sum(double x, double epsilon, int n, double current_sum) 
{
    recursive_calls++;
    double current_term = term(x, n);
    double new_sum = current_sum + current_term;
    if (fabs(math_arth(x) - new_sum) < epsilon) 
    {
        return new_sum;
    }
    return recursive_sum(x, epsilon, n + 1, new_sum);
}

int main() {
    setlocale(LC_ALL, "rus");
    double start_x, end_x, step, epsilon;

    cout << "Введите начальное значение x (-1 < x < 1):";
    cin >> start_x;
    cout << "Введите конечное значение x (-1 < x < 1): ";
    cin >> end_x;
    cout << "Введите шаг изменения x: ";
    cin >> step;
    cout << "Введите точность epsilon: ";
    cin >> epsilon;

    double (*math_func)(double) = &math_arth;
    double (*iter_func)(double, double) = &iterative_sum;
    double (*rec_func)(double, double, int, double) = &recursive_sum;
    cout.width(10);
    cout << right << "x" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    for (double x = start_x; x <= end_x; x += step) 
    {
        recursive_calls = 0; 
        double math_val = math_func(x);
        double iter_val = iter_func(x, epsilon);
        double rec_val = rec_func(x, epsilon, 0, 0.0);
        printf("%10.4f %15.8f %20.8f %20.8f %15d\n",
            x, math_val, iter_val, rec_val, recursive_calls);
    }

    system("pause");
    return 1;
}