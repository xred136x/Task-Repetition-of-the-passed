#include<iostream>
#include<vector>


class IVehicle {
public:
	virtual void printName() const = 0;
	virtual ~IVehicle() {}
};
class Car : public IVehicle {
public:
	void printName() const override {
		std::cout << "Car class" << std::endl;
	}
};
void foo(const std::vector<const IVehicle*>& vec) {// const IVehicle* не правильно, должно быть IVehicle*
	//(не правильная передача данных) 
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i]->printName();
	}
}
int main() {
	//IVehicle* vehicle = new IVehicle();//использование чистой виртуальной функции не допускается. 
	//Абстрактные классы не могут использоваться для создания объектов и служат только как интерфейс .
	IVehicle* vehicle2 = new Car();
	std::vector<IVehicle*> vec{ vehicle2 };
	foo(vec);

	//delete vehicle2; удаление объекта из кучи

	return 0;
}