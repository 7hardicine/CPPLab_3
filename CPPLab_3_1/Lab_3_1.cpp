#include <iostream>
#include <locale>
#include <math.h>
#include <iomanip>

using namespace std;
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

    cout << setw(10) << "x" << setw(16) << "Arth(x)" << setw(21) << "Итеративная сумма" \
        << setw(21) << "Рекурсивная сумма" << setw(10) << "Вызовы" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    cout.setf(ios::fixed);
    for (double x = start_x; x <= end_x; x += step) 
    {
        recursive_calls = 0; 
        double math_val = math_arth(x);
        double iter_val = iterative_sum(x, epsilon);
        double rec_val = recursive_sum(x, epsilon, 0, 0);
        cout << setprecision(4) << setw(10) << x << setw(16) << setprecision(8) << math_val \
            << setprecision(8) << setw(21) << iter_val << setprecision(8) << setw(21) << rec_val \
            << setw(10) << recursive_calls << endl;
    }
    cout.unsetf(ios::fixed);

    system("pause");
    return 1;
}