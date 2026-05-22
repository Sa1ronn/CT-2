#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    //Массивы
    srand(time(0));

    int temp[365];

    for (int i = 0; i < 365; i++) {
        temp[i] = rand() % 61 - 30;
    }

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    string months[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

    double avg[12];

    int current_day = 0;

    for (int i = 0; i < 12; i++) {
        double sum = 0;
        for (int j = 0; j < days[i]; j++) {
            sum = sum + temp[current_day];
            current_day++;

            avg[i] = sum / days[i];
        }
    }

    cout << "Средняя температура по месяцам:" << endl;

    for (int i = 0; i < 12; i++) {
        cout << months[i] << ": " << avg[i] << endl;
    }

    double max_temp = -1000.0;
    double min_temp = 1000.0;
    int max_month = 0;
    int min_month = 0;

    for (int i = 0; i < 12; i++) {
        if (avg[i] > max_temp) {
            max_temp = avg[i];
            max_month = i;
        }
        if (avg[i] < min_temp) {
            min_temp = avg[i];
            min_month = i;
        }
    }

    cout << endl;

    cout << "Самый теплый месяц: " << months[max_month] << " (" << max_temp << ")" << endl;
    cout << "Самый холодный месяц: " << months[min_month] << " (" << min_temp << ")" << endl;

    //Строки
    string text = "Один два три четыре пять шесть семь восемь девять десять";
    string words[10];
    int word_count = 0;
    string current_word = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            if (current_word != "") {
                words[word_count] = current_word;
                word_count++;
                current_word = "";
            }
        }
        else {
            current_word = current_word + text[i];
        }
    }

    if (current_word != "") {
        words[word_count] = current_word;
        word_count++;
    }

    int m, n;
    cout <<"\n" << "Исходная строка: " << text << endl;
    cout << "Всего слов: " << word_count << endl << endl;
    cout << "С какого слова удалить? ";
    cin >> m;
    cout << "По какое слово удалить? ";
    cin >> n;

    cout << "Результат: ";

    for (int i = 0; i < word_count; i++) {
        int position = i + 1;
        if (position < m || position > n) {
            cout << words[i] << " ";
        }
    }

    cout << endl;

    return 0;
}