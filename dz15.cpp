#include <iostream>
#include <algorithm> 
//
//
//int findMax(int* array, int size) {
//    return *std::max_element(array, array + size);
//}
//
//
//int findMin(int* array, int size) {
//    return *std::min_element(array, array + size);
//}
//
//
//double findAvg(int* array, int size) {
//    int sum = 0;
//    for (int i = 0; i < size; ++i) {
//        sum += array[i];
//    }
//    return static_cast<double>(sum) / size;
//}
//
//
//using FuncPtr = double(*)(int*, int);
//
//
//double Action(int* array, int size, FuncPtr func) {
//    return func(array, size); 
//}
//
//int main() {
//    int array[] = { 1, 2, 3, 4, 5 };
//    int size = sizeof(array) / sizeof(array[0]);
//
//    int choice;
//    std::cout << "Оберіть дію:\n1 - max\n2 - min\n3 - avg\n";
//    std::cin >> choice;
//
//    double result;
//    switch (choice) {
//    case 1:
//        result = Action(array, size, findMax);
//        break;
//    case 2:
//        result = Action(array, size, findMin);
//        break;
//    case 3:
//        result = Action(array, size, findAvg);
//        break;
//    default:
//        std::cout << "Неправильний вибір!\n";
//        return 1;
//    }
//
//    std::cout << "Результат: " << result << std::endl;
//    return 0;
//}











#include <string>
#include <cctype> 


void removeCharAt(std::string& str, int pos) {
    if (pos >= 0 && pos < str.size()) {
        str.erase(pos, 1);
    }
}


void removeAllOccurrences(std::string& str, char ch) {
    str.erase(std::remove(str.begin(), str.end(), ch), str.end());
}

void insertCharAt(std::string& str, int pos, char ch) {
    if (pos >= 0 && pos <= str.size()) {
        str.insert(str.begin() + pos, ch);
    }
}


void replaceDotsWithExclamations(std::string& str) {
    std::replace(str.begin(), str.end(), '.', '!');
}


int countOccurrences(const std::string& str, char ch) {
    return std::count(str.begin(), str.end(), ch);
}

void countCharacterTypes(const std::string& str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (char ch : str) {
        if (std::isalpha(ch))
            ++letters;
        else if (std::isdigit(ch))
            ++digits;
        else
            ++others;
    }
}

int main() {
    std::string str;
    int choice;

    std::cout << "Введіть рядок: ";
    std::getline(std::cin, str);

    std::cout << "Оберіть дію:\n1 - Видалити символ за позицією\n2 - Видалити всі входження символу\n";
    std::cout << "3 - Вставити символ у позицію\n4 - Замінити '.' на '!'\n5 - Порахувати входження символу\n";
    std::cout << "6 - Порахувати літери, цифри та інші символи\n";
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice == 1) {
        int pos;
        std::cout << "Введіть позицію для видалення: ";
        std::cin >> pos;
        removeCharAt(str, pos);
        std::cout << "Результат: " << str << std::endl;

    }
    else if (choice == 2) {
        char ch;
        std::cout << "Введіть символ для видалення: ";
        std::cin >> ch;
        removeAllOccurrences(str, ch);
        std::cout << "Результат: " << str << std::endl;

    }
    else if (choice == 3) {
        int pos;
        char ch;
        std::cout << "Введіть позицію для вставки: ";
        std::cin >> pos;
        std::cout << "Введіть символ для вставки: ";
        std::cin >> ch;
        insertCharAt(str, pos, ch);
        std::cout << "Результат: " << str << std::endl;

    }
    else if (choice == 4) {
        replaceDotsWithExclamations(str);
        std::cout << "Результат: " << str << std::endl;

    }
    else if (choice == 5) {
        char ch;
        std::cout << "Введіть символ для підрахунку: ";
        std::cin >> ch;
        int count = countOccurrences(str, ch);
        std::cout << "Кількість входжень символу '" << ch << "': " << count << std::endl;

    }
    else if (choice == 6) {
        int letters, digits, others;
        countCharacterTypes(str, letters, digits, others);
        std::cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших символів: " << others << std::endl;

    }
    else {
        std::cout << "Неправильний вибір!" << std::endl;
    }

    return 0;
}
