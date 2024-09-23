#include <bits/stdc++.h>
using namespace std;

struct Student {
    string studentID;
    string name;
};

struct Wheel {
    string model; // 公路轮 or 麦克纳姆轮
    string size;  // 175mm
};

struct Chassis {
    string chassisID; //
    string model;     // SCOUT MINI
    string wheelbase; // 451mm
    string trackWidth; // 490mm
    string minGroundClearance; // 115mm
    string minTurningRadius; // 0m
    string driveType; // 四轮四驱
    string maxTravel; // 10KM
    vector<Wheel> wheels; // 4 wheels
};

struct AGX {
    string model; // AGX Xavier
    string AI; // 32 TOPS
    string CUDA_core; // 512
    string Tensor_CORE; // 64
    string VRAM; // 32G
    string storage; //32G
};

struct Camera {
    string model; // RealSense D435i
    string cameraModel; // D430
    string RGB_resolution; // 1920*1080
    string RGB_frameRate; // 30
    string FOV; //87*58
    string depth_frameRate; //90
};

struct Lidar {
    string model; // RS-Helios-16p
    int channels; //16
    string range; //100m
    string power; //8W
};

struct Gyroscope {
    string model; // CH110
    string manufacturer; //NXP
};

struct Display {
    string size; //11.6
    string model; //super
};

struct Battery {
    string parameters; //24V/15Ah
    string externalPower; //24V
    string chargingTime; //2H
};

struct Car {
    string carID; //
    Chassis chassis;
    AGX agx;
    Camera camera;
    Lidar lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
    Student assignedStudent;
};

string generateCarID(int index) {
    string digits = "";
    stringstream ss;
    ss << setw(16) << setfill('0') << index;
    digits = ss.str();
    char letter = 'A' + (index % 26);
    return "Carnum" + digits + string(1, letter);
}

string generateChassisID(int index) {

    string digits = "";
    stringstream ss;
    ss << setw(8) << setfill('0') << index;
    digits = ss.str();
    char letter = 'A' + (index % 26);
    return "Chasislnum" + digits + string(1, letter);
}

string generateRandomChineseName() {
    vector<string> surnames = {
            "王", "李", "张", "刘", "陈", "杨", "赵", "黄", "周", "吴",
            "徐", "孙", "胡", "朱", "高", "林", "何", "郭", "马", "罗"
    };
    vector<string> givenNamesSingle = {
            "伟", "芳", "娜", "敏", "静", "丽", "强", "磊", "洋", "勇",
            "艳", "杰", "娟", "涛", "明", "超", "秀英", "霞", "平", "刚"
    };
    vector<string> givenNamesDouble = {
            "佳", "玲", "静", "丽", "敏", "艳", "强", "磊", "洋", "勇",
            "刚", "平", "辉", "娜", "俊", "华", "丽", "军", "翔", "杰"
    };
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<> nameLengthDist(0, 1);
    int nameLength = nameLengthDist(gen); // 0: single, 1: double

    uniform_int_distribution<> surnameDist(0, surnames.size() - 1);
    string surname = surnames[surnameDist(gen)];

    string givenName;
    if(nameLength == 0) {
        uniform_int_distribution<> givenDist(0, givenNamesSingle.size() -1);
        givenName = givenNamesSingle[givenDist(gen)];
    }
    else {
        uniform_int_distribution<> givenDist(0, givenNamesDouble.size() -1);
        givenName = givenNamesDouble[givenDist(gen)] + givenNamesDouble[givenDist(gen)];
    }

    return surname + givenName;
}

Student generateStudent(int index) {
    Student s;
    stringstream ss;
    ss << "Stu" << setw(4) << setfill('0') << index;
    s.studentID = ss.str();
    s.name = generateRandomChineseName();
    return s;
}

vector<Car> generateCars(int numCars) {
    vector<Car> cars;
    // Wheels: 公路轮 和 麦克纳姆轮
    vector<Wheel> wheels;
    for(int i=0;i<4;i++) {
        Wheel w;
        if(i %2 ==0) w.model = "公路轮";
        else w.model = "麦克纳姆轮";
        w.size = "175mm";
        wheels.push_back(w);
    }
    // AGX
    AGX agx;
    agx.model = "AGX Xavier";
    agx.AI = "32 TOPS";
    agx.CUDA_core = "512";
    agx.Tensor_CORE = "64";
    agx.VRAM = "32G";
    agx.storage = "32G";
    // Camera
    Camera camera;
    camera.model = "RealSense D435i";
    camera.cameraModel = "D430";
    camera.RGB_resolution = "1920*1080";
    camera.RGB_frameRate = "30";
    camera.FOV = "87*58";
    camera.depth_frameRate = "90";
    // Lidar
    Lidar lidar;
    lidar.model = "RS-Helios-16p";
    lidar.channels = 16;
    lidar.range = "100m";
    lidar.power = "8W";
    // Gyroscope
    Gyroscope gyro;
    gyro.model = "CH110";
    gyro.manufacturer = "NXP";
    // Display
    Display display;
    display.size = "11.6";
    display.model = "super";
    // Battery
    Battery battery;
    battery.parameters = "24V/15Ah";
    battery.externalPower = "24V";
    battery.chargingTime = "2H";

    for(int i=1;i<=numCars;i++) {
        Car car;
        car.carID = generateCarID(i);
        car.chassis.chassisID = generateChassisID(i);
        car.chassis.model = "SCOUT MINI";
        car.chassis.wheelbase = "451mm";
        car.chassis.trackWidth = "490mm";
        car.chassis.minGroundClearance = "115mm";
        car.chassis.minTurningRadius = "0m";
        car.chassis.driveType = "四轮四驱";
        car.chassis.maxTravel = "10KM";
        car.chassis.wheels = wheels;
        car.agx = agx;
        car.camera = camera;
        car.lidar = lidar;
        car.gyro = gyro;
        car.display = display;
        car.battery = battery;
        car.assignedStudent = generateStudent(i);
        cars.push_back(car);
    }
    return cars;
}

void saveCarsToFile(const vector<Car>& cars, const string& filename) {
    ofstream ofs(filename, ios::out | ios::trunc);
    if(!ofs) {
        cout << "Error opening file for writing." << endl;
        return;
    }
    for(const auto& car : cars) {
        ofs << "CarID: " << car.carID << endl;
        ofs << "ChassisID: " << car.chassis.chassisID << endl;
        ofs << "Chassis Model: " << car.chassis.model << endl;
        ofs << "Wheelbase: " << car.chassis.wheelbase << endl;
        ofs << "Track Width: " << car.chassis.trackWidth << endl;
        ofs << "Min Ground Clearance: " << car.chassis.minGroundClearance << endl;
        ofs << "Min Turning Radius: " << car.chassis.minTurningRadius << endl;
        ofs << "Drive Type: " << car.chassis.driveType << endl;
        ofs << "Max Travel: " << car.chassis.maxTravel << endl;
        // Wheels
        for(int i=0;i<car.chassis.wheels.size();i++) {
            ofs << "Wheel" << (i+1) << " Model: " << car.chassis.wheels[i].model << endl;
            ofs << "Wheel" << (i+1) << " Size: " << car.chassis.wheels[i].size << endl;
        }
        // AGX
        ofs << "AGX Model: " << car.agx.model << endl;
        ofs << "AI: " << car.agx.AI << endl;
        ofs << "CUDA Core: " << car.agx.CUDA_core << endl;
        ofs << "Tensor CORE: " << car.agx.Tensor_CORE << endl;
        ofs << "VRAM: " << car.agx.VRAM << endl;
        ofs << "Storage: " << car.agx.storage << endl;
        // Camera
        ofs << "Camera Model: " << car.camera.model << endl;
        ofs << "Camera: " << car.camera.cameraModel << endl;
        ofs << "RGB Resolution: " << car.camera.RGB_resolution << endl;
        ofs << "RGB Frame Rate: " << car.camera.RGB_frameRate << endl;
        ofs << "FOV: " << car.camera.FOV << endl;
        ofs << "Depth Frame Rate: " << car.camera.depth_frameRate << endl;
        // Lidar
        ofs << "Lidar Model: " << car.lidar.model << endl;
        ofs << "Channels: " << car.lidar.channels << endl;
        ofs << "Range: " << car.lidar.range << endl;
        ofs << "Power: " << car.lidar.power << endl;
        // Gyroscope
        ofs << "Gyroscope Model: " << car.gyro.model << endl;
        ofs << "Gyroscope Manufacturer: " << car.gyro.manufacturer << endl;
        // Display
        ofs << "Display Size: " << car.display.size << endl;
        ofs << "Display Model: " << car.display.model << endl;
        // Battery
        ofs << "Battery Parameters: " << car.battery.parameters << endl;
        ofs << "Battery External Power: " << car.battery.externalPower << endl;
        ofs << "Battery Charging Time: " << car.battery.chargingTime << endl;
        // Assigned Student
        ofs << "Assigned Student ID: " << car.assignedStudent.studentID << endl;
        ofs << "Assigned Student Name: " << car.assignedStudent.name << endl;
        // Delimiter
        ofs << "---" << endl;
    }
    ofs.close();
    cout << "Data saved to " << filename << " successfully." << endl;
}

vector<Car> loadCarsFromFile(const string& filename) {
    vector<Car> cars;
    ifstream ifs(filename);
    if(!ifs) {
        cout << "Error opening file for reading." << endl;
        return cars;
    }
    string line;
    Car car;
    while(getline(ifs, line)) {
        if(line == "---") {
            cars.push_back(car);
            car = Car();
            continue;
        }
        size_t pos = line.find(": ");
        if(pos == string::npos) continue;
        string key = line.substr(0, pos);
        string value = line.substr(pos + 2);
        if(key == "CarID") {
            car.carID = value;
        }
        else if(key == "ChassisID") {
            car.chassis.chassisID = value;
        }
        else if(key == "Chassis Model") {
            car.chassis.model = value;
        }
        else if(key == "Wheelbase") {
            car.chassis.wheelbase = value;
        }
        else if(key == "Track Width") {
            car.chassis.trackWidth = value;
        }
        else if(key == "Min Ground Clearance") {
            car.chassis.minGroundClearance = value;
        }
        else if(key == "Min Turning Radius") {
            car.chassis.minTurningRadius = value;
        }
        else if(key == "Drive Type") {
            car.chassis.driveType = value;
        }
        else if(key == "Max Travel") {
            car.chassis.maxTravel = value;
        }
        else if(key.find("Wheel") != string::npos && key.find(" Model") != string::npos) {
            // Wheel model
            int wheelNum = stoi(key.substr(5,1)); // e.g., Wheel1 Model
            if(car.chassis.wheels.size() < wheelNum) {
                // Add wheels up to wheelNum
                while(car.chassis.wheels.size() < wheelNum) {
                    Wheel w;
                    car.chassis.wheels.push_back(w);
                }
            }
            car.chassis.wheels[wheelNum-1].model = value;
        }
        else if(key.find("Wheel") != string::npos && key.find(" Size") != string::npos) {
            // Wheel size
            int wheelNum = stoi(key.substr(5,1));
            if(car.chassis.wheels.size() < wheelNum) {
                // Add wheels up to wheelNum
                while(car.chassis.wheels.size() < wheelNum) {
                    Wheel w;
                    car.chassis.wheels.push_back(w);
                }
            }
            car.chassis.wheels[wheelNum-1].size = value;
        }
        else if(key == "AGX Model") {
            car.agx.model = value;
        }
        else if(key == "AI") {
            car.agx.AI = value;
        }
        else if(key == "CUDA Core") {
            car.agx.CUDA_core = value;
        }
        else if(key == "Tensor CORE") {
            car.agx.Tensor_CORE = value;
        }
        else if(key == "VRAM") {
            car.agx.VRAM = value;
        }
        else if(key == "Storage") {
            car.agx.storage = value;
        }
        else if(key == "Camera Model") {
            car.camera.model = value;
        }
        else if(key == "Camera") {
            car.camera.cameraModel = value;
        }
        else if(key == "RGB Resolution") {
            car.camera.RGB_resolution = value;
        }
        else if(key == "RGB Frame Rate") {
            car.camera.RGB_frameRate = value;
        }
        else if(key == "FOV") {
            car.camera.FOV = value;
        }
        else if(key == "Depth Frame Rate") {
            car.camera.depth_frameRate = value;
        }
        else if(key == "Lidar Model") {
            car.lidar.model = value;
        }
        else if(key == "Channels") {
            car.lidar.channels = stoi(value);
        }
        else if(key == "Range") {
            car.lidar.range = value;
        }
        else if(key == "Power") {
            car.lidar.power = value;
        }
        else if(key == "Gyroscope Model") {
            car.gyro.model = value;
        }
        else if(key == "Gyroscope Manufacturer") {
            car.gyro.manufacturer = value;
        }
        else if(key == "Display Size") {
            car.display.size = value;
        }
        else if(key == "Display Model") {
            car.display.model = value;
        }
        else if(key == "Battery Parameters") {
            car.battery.parameters = value;
        }
        else if(key == "Battery External Power") {
            car.battery.externalPower = value;
        }
        else if(key == "Battery Charging Time") {
            car.battery.chargingTime = value;
        }
        else if(key == "Assigned Student ID") {
            car.assignedStudent.studentID = value;
        }
        else if(key == "Assigned Student Name") {
            car.assignedStudent.name = value;
        }
    }
    if(!car.carID.empty()) {
        cars.push_back(car);
    }
    ifs.close();
    return cars;
}

void displayCars(const vector<Car>& cars) {
    if(cars.empty()) {
        cout << "No cars to display." << endl;
        return;
    }
    int current = 0;
    while(true) {
        system("cls");
        cout << "----------------------------------------" << endl;
        cout << "Displaying Car " << (current +1) << " of " << cars.size() << endl;
        cout << "CarID: " << cars[current].carID << endl;
        cout << "ChassisID: " << cars[current].chassis.chassisID << endl;
        cout << "Chassis Model: " << cars[current].chassis.model << endl;
        cout << "Wheelbase: " << cars[current].chassis.wheelbase << endl;
        cout << "Track Width: " << cars[current].chassis.trackWidth << endl;
        cout << "Min Ground Clearance: " << cars[current].chassis.minGroundClearance << endl;
        cout << "Min Turning Radius: " << cars[current].chassis.minTurningRadius << endl;
        cout << "Drive Type: " << cars[current].chassis.driveType << endl;
        cout << "Max Travel: " << cars[current].chassis.maxTravel << endl;
        // Wheels
        for(int i=0;i<cars[current].chassis.wheels.size();i++) {
            cout << "Wheel" << (i+1) << " Model: " << cars[current].chassis.wheels[i].model << endl;
            cout << "Wheel" << (i+1) << " Size: " << cars[current].chassis.wheels[i].size << endl;
        }
        // AGX
        cout << "AGX Model: " << cars[current].agx.model << endl;
        cout << "AI: " << cars[current].agx.AI << endl;
        cout << "CUDA Core: " << cars[current].agx.CUDA_core << endl;
        cout << "Tensor CORE: " << cars[current].agx.Tensor_CORE << endl;
        cout << "VRAM: " << cars[current].agx.VRAM << endl;
        cout << "Storage: " << cars[current].agx.storage << endl;
        // Camera
        cout << "Camera Model: " << cars[current].camera.model << endl;
        cout << "Camera: " << cars[current].camera.cameraModel << endl;
        cout << "RGB Resolution: " << cars[current].camera.RGB_resolution << endl;
        cout << "RGB Frame Rate: " << cars[current].camera.RGB_frameRate << endl;
        cout << "FOV: " << cars[current].camera.FOV << endl;
        cout << "Depth Frame Rate: " << cars[current].camera.depth_frameRate << endl;
        // Lidar
        cout << "Lidar Model: " << cars[current].lidar.model << endl;
        cout << "Channels: " << cars[current].lidar.channels << endl;
        cout << "Range: " << cars[current].lidar.range << endl;
        cout << "Power: " << cars[current].lidar.power << endl;
        // Gyroscope
        cout << "Gyroscope Model: " << cars[current].gyro.model << endl;
        cout << "Gyroscope Manufacturer: " << cars[current].gyro.manufacturer << endl;
        // Display
        cout << "Display Size: " << cars[current].display.size << endl;
        cout << "Display Model: " << cars[current].display.model << endl;
        // Battery
        cout << "Battery Parameters: " << cars[current].battery.parameters << endl;
        cout << "Battery External Power: " << cars[current].battery.externalPower << endl;
        cout << "Battery Charging Time: " << cars[current].battery.chargingTime << endl;
        // Assigned Student
        cout << "Assigned Student ID: " << cars[current].assignedStudent.studentID << endl;
        cout << "Assigned Student Name: " << cars[current].assignedStudent.name << endl;
        cout << "----------------------------------------" << endl;
        // 导航提示
        cout << "\n 按下p显示下一辆小车,按n则显示上一里辆小车: ";
        char choice;
        cin >> choice;
        if(choice == 'n' || choice == 'N') {
            if(current < static_cast<int>(cars.size())-1) {
                current++;
            }
            else {
                cout << "已经是最后一辆小车。" << endl;
                cout << "按回车键继续...";
                cin.ignore();
                cin.get();
            }
        }
        else if(choice == 'p' || choice == 'P') {
            if(current >0) {
                current--;
            }
            else {
                cout << "已经是第一辆小车。" << endl;
                cout << "按回车键继续...";
                cin.ignore();
                cin.get();
            }
        }
        else if(choice == 'q' || choice == 'Q') {
            break;
        }
    }
}

int main(){
    // Step 1: 生成小车和学生信息
    int numCars = 10;
    vector<Car> cars = generateCars(numCars);

    // Step 2: 保存到文件里
    string filename = "car_data.txt";
    saveCarsToFile(cars, filename);

    // Step 3: 从文件里读取信息
    vector<Car> loadedCars = loadCarsFromFile(filename);

    // Step 4: 在屏幕上进行提示
    displayCars(loadedCars);

    return 0;
}



//
// Coded by SinianDragon on 24-9-23. https://github.com/SinianDragon/
//
