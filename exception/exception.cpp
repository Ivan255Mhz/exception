#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "ru");
    // Задание 1
    int N = 15; // Последняя цифра номера паспорта плюс 5
    int k = 10; // Верхняя граница диапазона
    std::vector<double> f(k + 1);

    try {
        for (int x = 0; x <= k; ++x) {
            if (x - N == 0) {
                throw std::runtime_error("Деление на ноль");
            }
            f[x] = 1.0 / (x - N);
        }

        for (double value : f) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    // Задание 2
    try {
        double a, b;
        std::cout << "Введите два числа: ";
        std::cin >> a >> b;

        if (b == 0) {
            throw std::runtime_error("Деление на ноль");
        }

        double result = a / b;
        std::cout << "Результат: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        int matrix[2][2] = { {1, 2}, {3, 4} };
        int result = matrix[3][3]; // Выход за границы массива
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        int x = 42;
        double y = x; // Неверный тип входных параметров
    }
    catch (const std::bad_cast& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
