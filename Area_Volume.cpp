//
//  main.cpp
//  oops
//
//  Created by Ragupathi on 16/08/2022.
//

/*  Write a C++ program with Area and Volume class. The Area class has side, length, breadth, and radius as private data members. It has a square, rectangle, and circle public function that calculates and returns the area of the respective shape. If the parameters of a shape are not given, it calculates the unit area of the respective shape.
 
 The Volume class has height as a private data member. It has cube, cuboid, sphere, compare cube, compare cuboid, and compare sphere public member functions. The compare volume function prints which among the two volumes is greater than the other.

 Utilize the concepts of this pointer, friend function, inline function, and default parameters wherever necessary (minimum 1 of each concept)

 Write a menu-driven program to calculate,
 Area of a Square
 Area of a Rectangle
 Area of a Circle
 Volume of a Cube
 Volume of a Cuboid
 Volume of a Sphere
 Compare Cube
 Compare Cuboids
 Compare Spheres

 */


#include <cstdio>
#include <iostream>
#include <numeric>

using namespace std;

class Area;
class Volume;

class Area{
private:
    float side;
    float length;
    float breadth;
    float radius;
    
public:
    //all mem func are inline and friend
    // unit
    void setSquare(float side =1){
        this->side = side;
    }
    void setRect(float length =1, float breadth =1){
        this->length = length;
        this->breadth = breadth;
    }
    void setCircle(float radius = 1){
        this->radius = radius;
    }
    
    friend float areaSquare(Area);
    friend float areaRect (Area);
    friend float areaCircle(Area);
    
    friend float volCube(Area);
    friend float volCuboid(Area, Volume);
    friend float volSphere(Area);
    
};
inline float areaSquare(Area a){
    return (a.side * a.side);
}
inline float areaRect(Area a){
    return(a.length*a.breadth);
}
inline float areaCircle(Area a){
    return(3.14*a.radius*a.radius);
}

class Volume{
private:
    int height;
    
public:
    void setHeight(int height =1){
        this->height = height;
    }
    friend float volCube(Area);
    friend float volCuboid(Area, Volume);
    friend float volSphere(Area);
    
    void compareCube(Area, Area);
    void compareCuboid(Area, Volume, Area, Volume);
    void compareSphere(Area, Area);
    
};

inline float volCube(Area a) {
        return areaSquare(a) * a.side;
}

inline float volCuboid(Area a, Volume v){
        return areaRect(a) * v.height;
}
                         
inline float volSphere(Area a) {
        return ((float)4/3)*areaCircle(a) * a.radius;
}
                         
inline void Volume::compareCube(Area obj1, Area obj2){
        float v1 = volCube(obj1);
        float v2 = volCube(obj2);
        if(v1 > v2){
            cout << "Cube with larger volume is the first cube with volume : "<< v1;
            cout << endl;
        }
        else{
            cout << "Cube with larger volume is the second cube with volume : "<< v2;
            cout << endl;
        }
}
inline void Volume::compareCuboid(Area a_obj1, Volume v_obj1, Area a_obj2, Volume v_obj2){
        float v1 = volCuboid(a_obj1, v_obj1);
        float v2 = volCuboid(a_obj2, v_obj2);
        if(v1 > v2){
            cout << "Cuboid with larger volume is the first cuboid with volume : "<< v1;
            cout << endl;
        }
        else{
            cout << "Cuboid with larger volume is the second cuboid with volume : "<< v2;
            cout << endl;
        }
}
inline void Volume::compareSphere(Area a_obj1, Area a_obj2){
        float v1 = volSphere(a_obj1);
        float v2 = volSphere(a_obj2);
        if(v1 > v2){
            cout << "Sphere with larger volume is the first sphere with volume : "<< v1;
            cout << endl;
        }
        else{
            cout << "Sphere with larger volume is the second sphere with volume : "<< v2;
            cout << endl;
         }
}
                         
int main() {
        Area a;
        Volume v;
        int option =10;
        int choice;
        while( option !=0){
            cout << "\nTo:\nCalculate the area of a square: press 1\nCalculate the area of a rectangle: press 2\nCalculate the area of a circle: press 3\nCalculate the volume of a cube: press 4\nCalculate the volume of a cuboid: press 5\nCalculate the volume of a sphere: press 6\nCompare two cubes: press 7\nCompare two cuboids: press 8\nCompare two spheres: press 9\nExit: press 0 \n";
            cin >> option;
            switch(option){
                case 1:
                    cout << "For finding the area of a square\nTo:\nuse default values: press 1\nprovide own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float s;
                        cout <<"enter the length of a side of the square: ";
                        cin >> s;
                        a.setSquare(s);
                    }
                    else{
                        a.setSquare();
                    }
                    cout << "area of the square is = " << areaSquare(a) << endl;
                    cout << endl;
                    break;
                case 2:
                    cout << "For finding the area of a rectangle\nTo:\nuse default values: press 1\nprovide own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float l, b;
                        cout << "enter the length of the rectangle: ";
                        cin >> l;
                        cout << "enter the breadth of the rectangle: ";
                        cin >> b;
                        a.setRect(l,b);
                    }
                    else{
                        a.setRect();
                    }
                    cout << "area of the rectangle is = "<< areaRect(a) << endl;
                    cout << endl;
                    break;
                
                case 3:
                    cout << "For finding the area of a circle\nTo:\nuse default values: press 1\nprovide own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float r;
                        cout << "enter the length of the radius: ";
                        cin >> r;
                        a.setCircle(r);
                    }
                    else{
                        a.setCircle();
                    }
                    cout << "area of the circle is = "<< areaCircle(a) << endl;
                    cout << endl;
                    break;
                
                case 4:
                    cout << "For finding the volume of a cube\nTo:\nuse default values: press 1\nprovide your own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float s;
                        cout << "enter the length of a side of the cube: ";
                        cin >> s;
                        a.setSquare(s);
                    }
                    else{
                        a.setSquare();
                    }
                    cout << "volume of the cube is = " << volCube(a) << endl;
                    cout << endl;
                    break;
                    
                case 5:
                    cout << "For finding the volume of a cuboid\nTo:\nuse default values: press 1\nprovide your own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float l,b,h;
                        cout << "enter the length of the cuboid: ";
                        cin >> l;
                        cout << "enter the breadth of the cuboid: ";
                        cin >> b;
                        cout << "enter the height of the cuboid: ";
                        cin >> h;
                        a.setRect(l,b);
                        v.setHeight(h);
                    }
                    else{
                        a.setRect();
                        v.setHeight();
                    }
                    cout << "volume of the cuboid is = " << volCuboid(a, v) << endl;
                    cout << endl;
                    break;
                    
                case 6:
                    cout << "For finding the volume of a sphere\nTo:\nuse default values: press 1\nprovide your own values: press 2 \n";
                    cin >> choice;
                    if(choice == 2){
                        float r;
                        cout << "enter the radius of the sphere: ";
                        cin >> r;
                        a.setCircle(r);
                    }
                    else{
                        a.setCircle();
                    }
                    cout << "volume of the sphere is = " << volSphere(a) << endl;
                    cout << endl;
                    break;
                    
                case 7:
                    Area cube_1, cube_2;
                    float s1, s2;
                    cout << "For comparing two cubes: \nEnter the side length for cube 1: ";
                    cin >> s1;
                    cout <<"Enter the side length for cube 2: ";
                    cin >> s2;
                    cube_1.setSquare(s1);
                    cube_2.setSquare(s2);
                    v.compareCube(cube_1, cube_2);
                    break;
                    
                case 8:
                    Area cuboid_1, cuboid_2;
                    Volume cub_1, cub_2;
                    float l1, l2, b1, b2, h1, h2;
                    cout << "For comparing two cuboids: \nFor cuboid 1: \nEnter the length : ";
                    cin >> l1;
                    cout << "Enter the breadth : ";
                    cin >> b1;
                    cout << "Enter the height: ";
                    cin >> h1;
                    cout << "\nFor cuboid 2: \nEnter the length: ";
                    cin >> l2;
                    cout<< "Enter the breadth: ";
                    cin >> b2;
                    cout << "Enter the height: ";
                    cin >> h2;
                    cuboid_1.setRect(l1, b1);
                    cuboid_2.setRect(l2, b2);
                    cub_1.setHeight(h1);
                    cub_2.setHeight(h2);
                    v.compareCuboid(cuboid_1, cub_1, cuboid_2, cub_2);
                    break;
                    
                case 9:
                    Area sphere_1, sphere_2;
                    float r1, r2;
                    cout << "For comparing two spheres: \nFor Sphere 1:\nEnter the radius: ";
                    cin >> r1;
                    cout << "\nFor Sphere 2:\nEnter the radius: ";
                    cin >> r2;
                    sphere_1.setCircle(r1);
                    sphere_2.setCircle(r2);
                    v.compareSphere(sphere_1, sphere_1);
                    break;
                    
                case 0:
                    cout << "you've successfully exited the program :)" <<endl;
                    cout << endl;
                    break;
                    
                default:
                    cout << "please enter a number between 0 and 9"<< endl;
                    cout << endl;
                    break;
            }
            
        }
    

    return 0;
}

