//Шахниязов Ботир М8О-201Б
//Вариант 8. 8-миугольник, треугольник, квадрат
/*
Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
1. Вычисление геометрического центра фигуры;
2. Вывод в стандартный поток вывода std::cout координат вершин фигуры;
3. Вычисление площади фигуры;
Разработать шаблоны классов согласно варианту задания.
Параметром шаблона должен являться скалярный тип данных
задающий тип данных для оси координат. Классы должны иметь
публичные поля. Фигуры являются фигурами вращения.
Для хранения координат фигур необходимо использовать шаблон std::pair.
*/
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include "figure.hpp"

void printMenu();
void inputPoints(std::vector<coordinate<double>> &points, int countPoints);

int main()
{
    std::vector<figure<double>*> figures;
    std::vector<coordinate<double>> points;
    bool again = true;
    char variant = '1';

    printMenu();
    while(again){
        std::cout << "> ";
        std::cin >> variant;
        if(variant >= '0' && variant <= '9'){
            if(variant == '1'){ //меню
                printMenu();
            }else if(variant == '2'){ //треугольник
                std::cout << "Введите 3 координаты вершин треугольника.\n";
                points.clear();
                inputPoints(points, 3);
                figures.push_back(new triangle<double>(points));
            }else if(variant == '3'){ //квадрат
                std::cout << "Введите центр квадрата и длину его стороны.\n";
                points.clear();
                inputPoints(points, 1);
                double N;
                std::cout << "Длина = "; std::cin >> N;
                figures.push_back(new squary<double>(points[0], N));
            }else if(variant == '4'){ //восьмиугольник
                std::cout << "Введите центр 8-ми угольника и длину его стороны.\n";
                points.clear();
                inputPoints(points, 1);
                double N;
                std::cout << "Длина = "; std::cin >> N;
                figures.push_back(new angle8<double>(points[0], N));
            }else if(variant == '5'){ //площадь
                for(int i = 0; i < figures.size(); i++)
                {
                    std::cout << "Фигура №" << i + 1 << std::endl;
                    figures[i]->printCoord();
                    std::cout << std::endl;
                }
                std::cout << "Площадь какой фигуры вы хотите найти?"
                          << "Введите номер. N = ";
                int N; std::cin >> N;
                if(N >= 0 && N <= figures.size())
                    figures[N - 1]->printArea();
                else std::cout << "Пока не существует фигуры с указанным номером\n";
            }else if(variant == '6'){ //площади
                for(int i = 0; i < figures.size(); i++)
                {
                    std::cout << "Фигура №" << i + 1 << std::endl;
                    figures[i]->printArea();
                    std::cout << std::endl;
                }
            }else if(variant == '7'){ //центр
                for(int i = 0; i < figures.size(); i++)
                {
                    std::cout << "Фигура №" << i + 1 << std::endl;
                    figures[i]->printCoord();
                    std::cout << std::endl;
                }
                std::cout << "Площадь какой фигуры вы хотите найти?"
                          << "Введите номер. N = ";
                int N; std::cin >> N;
                if(N >= 0 && N <= figures.size())
                    figures[N - 1]->printCenter();
                else std::cout << "Пока не существует фигуры с указанным номером\n";
            }else if(variant == '8'){ //центры
                for(int i = 0; i < figures.size(); i++)
                {
                    std::cout << "Фигура №" << i + 1 << std::endl;
                    figures[i]->printCenter();
                    std::cout << std::endl;
                }
            }else if(variant == '9'){ //координаты
                for(int i = 0; i < figures.size(); i++)
                {
                    std::cout << "Фигура №" << i + 1 << std::endl;
                    figures[i]->printCoord();
                    std::cout << std::endl;
                }
            }else if(variant == '0') again = false;
        }else{
            std::cout << "Введёный знак не является цифрой\n";
        }
    }
    return 0;
}

void printMenu()
{
    std::cout << "1. Вывести меню\n"
              << "2. Создать треугольник\n"
              << "3. Создать квадрат\n"
              << "4. Создать восьмиугольник\n"
              << "5. Посчитать площадь фигуры\n"
              << "6. Посчитать площади всех фигур\n"
              << "7. Посчитать центр фигуры\n"
              << "8. Посчитать центры всех фигур\n"
              << "9. Вывести координаты фигур\n"
              << "0. Выход\n";
}

void inputPoints(std::vector<coordinate<double>> &points, int countPoints)
{
    coordinate<double> value;
    char trash;
    std::cout << "Вводите кооридинаты в формате x;y" << std::endl;
    for(int i = 0; i < countPoints; i++)
    {
        std::cout << "Точка №" << i + 1 << ": ";
        std::cin >> value.x >> trash >> value.y;
        points.push_back(value);
        std::cout << "\n";
    }
}