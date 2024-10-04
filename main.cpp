#include <iostream>
#include <locale>

using namespace std;

// Класс Mildew для моделирования роста плесени
class Mildew {
public:
    // Поля класса
    int speed; // Скорость прироста плесени в день
    int day; // Количество дней размножения
    int percentage; // Начальное количество плесени в процентах
    int death_speed; // Скорость отмирания плесени в день

    // Метод для установки начальных значений полей
    void SetInitialValues(int initialSpeed, int initialDay, int initialPercentage, int initialDeathSpeed) {
        speed = initialSpeed; // Установка скорости прироста
        day = initialDay; // Установка количества дней
        percentage = initialPercentage; // Установка начального количества плесени
        death_speed = initialDeathSpeed; // Установка скорости отмирания
    }

    // Метод для просмотра текущего состояния полей
    void ViewCurrentState() {
        cout << "Speed: " << speed << ", Day: " << day << ", Percentage: " << percentage << ", Death Speed: " << death_speed << endl;
    }

    // Метод для расчета количества плесени через заданное количество дней
    double CalculateMildewAmount() {
        double currentMildew = percentage; // Начальное количество плесени
        for (int i = 0; i < day; i++) {
            currentMildew += speed; // Прирост плесени
            currentMildew -= death_speed; // Отмирание плесени
        }
        return currentMildew; // Возвращаем итоговое количество плесени
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    // Создаем экземпляр класса Mildew
    Mildew mildew;

    // Устанавливаем начальные значения
    mildew.SetInitialValues(10, 5, 100, 2);

    // Просматриваем текущее состояние
    mildew.ViewCurrentState();

    // Рассчитываем количество плесени через заданное количество дней
    double finalMildewAmount = mildew.CalculateMildewAmount();
    cout << "Kolvo pleseni cherez " << mildew.day << " dney " << finalMildewAmount << endl;

    return 0;
}
