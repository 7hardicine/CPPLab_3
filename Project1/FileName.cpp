#include <iostream>
#include <locale>

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ackermann(m - 1, 1);
    }
    else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int a, b;
    std::cout << "������� ��� ��������������� ����� ����� (m � n): ";
    std::cin >> a >> b;

    if (a < 0 || b < 0) {
        std::cout << "������: ����� ������ ���� ����������������." << std::endl;
        return 1;
    }

    std::cout << "��������� ������� ���������: " << ackermann(a, b) << std::endl;
    return 0;
}