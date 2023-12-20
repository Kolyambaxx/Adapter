// Adapter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


class OldInterface {
public:
    virtual std::string request() const {
        return "Old Interface Request";
    }
};


class NewInterface {
public:
    virtual std::string specificRequest() const {
        return "New Interface Specific Request";
    }
};


class Adapter : public OldInterface {
public:
    Adapter(NewInterface* newInterface) : newInterface(newInterface) {}

    std::string request() const override {
        return newInterface->specificRequest();
    }

private:
    NewInterface* newInterface;
};

int main() {
  
    NewInterface newObject;
    Adapter adapter(&newObject);


    std::cout << "Using old interface through adapter: " << adapter.request() << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
