#include <iostream>
#include <tchar.h>
#include <locale>

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int prev; // первая высота
    unsigned int curr; // вторая высота
    unsigned int next_val; // третья высота
    unsigned int peaks_count = 0;  // счётчик пиков
    bool b_done = false;  // флаг окончания цикла
    // Установка русской локали для терминала Windows 11
    system("chcp 1251 >nul");// 1-й способ. Выплнить внешнюю команду.
    // 2 - й способ. Вызов библиотечной функции.
    setlocale(LC_ALL, "russian.1251");
    // 3 - й способ. Создать переменную типа локали
    std::locale rus_locale = std::locale("russian.1251");
    // 3 - й способ. Выбор кодировки(локали) терминала
    std::cout.imbue(std::locale::global(rus_locale));
    // Ввод данных
    // Вывод подсказки на экран
    std::cout << "Введите данные радарной станции (0 - конец ввода).\r\n";
    // Считываем первые два элемента
    std::cin >> prev;  // ввод первой высоты
    std::cin >> curr;  // ввод второй высоты
    while (!b_done)
    {
        std::cin >> next_val;  // ввод третьей высоты
        // Если встретили 0, ввод окончен
        b_done = (next_val == 0);  // условие окончания цикла
        // Проверяем условие пика для текущего элемента
        if (!b_done && (curr > prev) && (curr > next_val))
        {
            peaks_count += 1;  // счётчик пиков увеличили на 1
        }
        // Сдвигаем «окно» из трёх элементов вперед
        prev = curr;
        curr = next_val;
    }
    // вывод на экран
    std::cout << "Количество пиков: " << peaks_count << "\r\n";
    // Задержка вывода на экран до нажатия клавиши "Ввод"
    std::cin.ignore();
    std::cin.get();
    return 0;

}
