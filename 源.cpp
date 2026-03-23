#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Position
{
	double x;
	double y;
	double z;
	Position(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0)
		: x(x_), y(y_), z(z_) {}
}currentPosition;

class Drone
{
public:
	string id;
	double speed;
	Position currentPosition;

	Drone(string i, double spe)
		: id(i), speed(spe), currentPosition(Position(0.0, 0.0, 0.0)) {}
	
	//moveto
	void moveTo(const Position& target) {
		double dx = target.x - currentPosition.x;
		double dy = target.y - currentPosition.y;
		double dz = target.z - currentPosition.z;
		double distance = sqrt(dx * dx + dy * dy + dz * dz);

		double flightTime =  distance / speed ;

		cout << "无人机：" << id << endl;
		cout << "起始位置：(" << currentPosition.x << ", " << currentPosition.y << ", " << currentPosition.z << ")" << endl;
		cout << "目标位置：(" << target.x << ", " << target.y << ", " << target.z << ")" << endl;
		cout << "飞行距离：" << distance << endl;
		cout << "飞行速度：" << speed << endl;
		cout << "飞行时间：" << flightTime << endl << endl;

		currentPosition = target;
	}
	

	//显示无人机的当前位置
	void displayPosition() {
		cout << "无人机:" << id << "当前位置：("
			<< currentPosition.x << ", " << currentPosition.y << ", " << currentPosition.z << ")" << endl;
	}
};


class DroneFormation
{
public:
	vector<Drone*>drones;


	//将无人机添加到编队中
	void addDrone(Drone* drone) {
			drones.push_back(drone);
			cout << "无人机:" << drone->id << "已加入编队" << endl;
		}

	//让编队中的所有无人机移动到目标位置
	void moveFormationTo(const Position& target) {
		cout << "\n移动到目标位置(" << target.x << ", " << target.y << ", " << target.z << ")" << endl << endl;
		for (Drone* drone : drones) {
			drone->moveTo(target);
		}
	}

	//显示编队中所有无人机的当前位置
	void displayFormationPositions() {
		cout << "\n编队所有无人机最终位置:" << endl;
		for (Drone* drone : drones) {
			drone->displayPosition();
		}

	}
};

int main() {
     //1.创建一个无人机编队对象，并将上述无人机添加到编队中
	DroneFormation formation;

	Drone drone1("001", 5.0); 
	Drone drone2("002", 8.0); 
	Drone drone3("003", 10.0); 

	formation.addDrone(&drone1);
	formation.addDrone(&drone2);
	formation.addDrone(&drone3);


	//2.让编队移动到一个新的位置
	Position targetPos(100.0, 50.0, 20.0);
	formation.moveFormationTo(targetPos);


	//3.显示编队中所有无人机的最终位置
	formation.displayFormationPositions();

	return 0;

}