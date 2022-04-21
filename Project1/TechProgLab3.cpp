// 1)добавить +
// 2)удалить +
// 3)редактировать
// 4)посчитать объём
// 5)сохранить +
//
#include "Parallelepiped.h"
#include "Pyramid.h"
#include "Tetrahedron.h"
#include "Sphere.h"
#include <iostream>
#include <locale>

void initData(int& listLength, Polyhedron**& list);
void addElement(int& listLength, Polyhedron**& list, Polyhedron* newElement);
void removeElement(int& listLength, Polyhedron**& list, Polyhedron* removedElement);
void saveList(int& listLength, Polyhedron**& list);
void showList(int& listLength, Polyhedron**& list);
Polyhedron* choiseElement(int& listLength, Polyhedron**& list);
Polyhedron* createElement();
void mainLoop(int& listLength, Polyhedron**& list);

int main()
{
    setlocale(LC_ALL, "Russian");


    Polyhedron** list=nullptr;
    int listLength=0;

    initData(listLength, list);
    mainLoop(listLength, list);
    if (list)
    {
        for (size_t i = 0; i < listLength; i++)
        {
            delete list[i];
        }
        delete[] list;
    }
}

void initData(int& listLength, Polyhedron**& list)
{
    std::ifstream in("data.txt");
    if (!in.is_open()||in.eof())
        return;
    int len;
    in >> len;
    if (len == 0)
        return;
    for (size_t i = 0; i < len; i++)
    {
        int type;
        in >> type;
        Polyhedron* tmp=nullptr;
        switch (type)
        {
        case PARALLELEPIPED:
            tmp = new Parallelepiped(in);
            break;
        case PYRAMID:
            tmp = new Pyramid(in);
            break;
        case TETRAHEDRON:
            tmp = new Tetrahedron(in);
            break;
        case SPHERE:
            tmp = new Sphere(in);
            break;
        default:
            break;
        }
        addElement(listLength,list,tmp);
    }
    in.close();
}
void saveList(int& listLength, Polyhedron**& list)
{
    std::ofstream out("data.txt");
    if (!out.is_open())
        return;
    out << listLength << std::endl;
    for (size_t i = 0; i < listLength; i++)
    {
        list[i]->save(out);
    }
    out.close();
}

void addElement(int& listLength, Polyhedron**& list,Polyhedron* newElement)
{
    if (!newElement)
        return;
    if (listLength == 0)
    {
        list = new Polyhedron* [1];
        list[0] = newElement;
        listLength++;
    }
    else
    {
        Polyhedron** newList = new Polyhedron * [listLength+1];
        for (size_t i = 0; i < listLength; i++)
        {
            newList[i] = list[i];
        }
        newList[listLength++] = newElement;
        delete[] list;
        list = newList;
    }
}
void removeElement(int& listLength, Polyhedron**& list, Polyhedron* removedElement)
{
    if (!removedElement)
        return;
    if (listLength==0)
    {
        return;
    }
    else if (listLength == 1)
    {
        listLength--;
        delete list[0];
        delete[] list;
        list = nullptr;
    }
    else
    {
        Polyhedron** newList = new Polyhedron * [listLength-1];
        Polyhedron** tmp = newList;
        for (size_t i = 0; i < listLength; i++)
        {
            if (!(list[i] == removedElement))
            {
                *(tmp++) = list[i];
            }
        }
        delete removedElement;
        delete[] list;
        list = newList;
        listLength--;
    }
}
Polyhedron* choiseElement(int& listLength, Polyhedron**& list)
{
    system("cls");
    showList(listLength, list);
    std::cout << "Выберите элемент:";
    int choise;
    std::cin >> choise;
    while (!std::cin.good() || choise < 0 || choise >= listLength)
    {
        std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choise;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return list[choise];
}
Polyhedron* createElement()
{
    system("cls");
    std::cout <<"1 - параллелепипед\n2 - пирамида\n3 - тетраэдр\n4 - Сфера"<<std::endl;
    int type;
    std::cin >> type;
    while (!std::cin.good() || type < 1 || type > 4)
    {
        std::cout << "Введено некоректное значение. Попробуйте ещё раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> type;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Polyhedron* tmp = nullptr;
    switch (type)
    {
    case PARALLELEPIPED:
        tmp = new Parallelepiped();
        break;
    case PYRAMID:
        tmp = new Pyramid();
        break;
    case TETRAHEDRON:
        tmp = new Tetrahedron();
        break;
    case SPHERE:
        tmp = new Sphere();
        break;
    default:
        break;
    }
    return tmp;
}

void showList(int& listLength, Polyhedron**& list)
{
    for (size_t i = 0; i < listLength; i++)
    {
        std::cout << i << ": ";
        list[i]->showData();
    }
}

void mainLoop(int &listLength,Polyhedron**& list)
{
    for (;;)
    {
        system("cls");
        showList(listLength, list);
        std::cout << std::endl << "1 - добавить элемент\n2 - удалить элемент\n3 - редактировать элемент\n4 - посчитать объём элемента\n5 - сохранить изменения\n6 - выйти" << std::endl << std::endl;
        int choise;
        std::cin >> choise;
        if (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choise)
        {
        case 1:
            addElement(listLength, list, createElement());
            break;
        case 2:
            if (listLength)
            removeElement(listLength,list,choiseElement(listLength,list));
            break;
        case 3:
            if (listLength)
            choiseElement(listLength, list)->edit();
            break;
        case 4:
            if (listLength)
            {
                auto tmp = choiseElement(listLength, list);
                system("cls");
                std::cout << "Объём фигуры равен: " << tmp->volume() << std::endl;
                system("pause");
            }
            break;
        case 5:
            saveList(listLength, list);
            break;
        case 6:
            return;
            break;
        }
    }
}
