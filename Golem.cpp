#include <iostream>

class Sigma 
{
public:
    Sigma()
    {
        std::cout << this << " Sigma created by default constructor\n";
    }
    Sigma(int valt)
    {
        std::cout << this << " Sigma created by parametryc constructor\n";
    }
    Sigma(const Sigma& other)//обычная ссылка
    {
        std::cout << this << " Sigma created by copy constructor\n";
    }
    Sigma(const Sigma&& other)//Зарезервированная ссылка на временный объект
    {
        std::cout << this << " Sigma created by move constructor\n";
    }
    ~Sigma()
    {
        std::cout << this << " Sigma created by default destructor\n";
    }//Деструктор у класса может быть только один и должен быть без параметров





private:

};

void F00(Sigma zero)
{
    Sigma one;
    Sigma two(9);
}

Sigma F01()
{
    Sigma result;
    return std::move(result);
}

int main()
{
    Sigma one;
    Sigma two(9);
    auto pOne = new Sigma;
    F00(*pOne);
    Sigma three = F01();


    delete pOne;

    return 0;
}
