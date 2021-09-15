//工厂模式-简单工厂模式

//特点：需要在工厂类中做判断，从而创造相应的产品，当增加新产品时，需要修改工厂类。
//使用简单工厂模式，我们只需要知道具体的产品型号就可以创建一个产品。

//缺点：工厂类集中了所有产品类的创建逻辑，如果产品量较大，会使得工厂类变的非常臃肿。
#include <iostream>

enum tank_type {
    tank_64,
    tank_96
};

class Tank
{
public:
    virtual void print_tank() = 0;
};

class Tank_64 :public Tank
{
public:
    void print_tank() {
        std::cout << "tank_64" << std::endl;
    }
};

class Tank_96 :public Tank
{
public:
    void print_tank() {
        std::cout << "tank_96" << std::endl;
    }
};

class Tankfactory {
public:
    std::unique_ptr<Tank> createTank(tank_type type) {
        switch (type)
        {
        case tank_64:
            return std::make_unique<Tank_64>();
        case tank_96:
            return std::make_unique<Tank_96>();
        default:
            return nullptr;
        }
    }
};

int main()
{
    std::unique_ptr<Tankfactory> tankfactory = std::make_unique<Tankfactory>();

    auto tank1 = tankfactory->createTank(tank_64);
    tank1->print_tank();

    auto tank2 = tankfactory->createTank(tank_96);
    tank2->print_tank();
}
