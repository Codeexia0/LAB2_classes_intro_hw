#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class Complex {
   public:
   float real, img;
      Complex() {
         //default constructor to initialize complex number to 0+0i
         real = 0; img = 0;
      }
      Complex(float r, float i) {
         //parameterized constructor to initialize complex number.
         real = r; img = i;
      }
      void set_im(float i) {
          img = i;
      }
      Complex (float r) {
          real=r;
      }
};
Complex add(Complex n1, Complex n2) {
    Complex res;
    res.real=n1.real + n2.real;  // adding real part of complex numbers
   res.img =n1.img + n2.img;
   return res;
}


class Student {
    std::string name;
    std::string surname;
    std::vector<float> album_number;
    std::vector<float> grades;
public:
    Student();
    Student(std::string n, std::string s, std::vector<float> an, std::vector<float> g) {
        name = n;
        surname = s;
        album_number = an;
        grades = g;
    }

    void set_name(std::string n) {
        name = n;
    }
    std::string get_name() {
        return name;
    }

    float calculate_grade() {
        std::cout << name + " " + surname  + ": " ;
//        for(auto &it : grades) {
//            std::cout << it << " ";
//        }
//        std::cout << "\nAverage of grades: ";
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    bool add_grade(float grade) {
        if(grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

};


int main()
{
//    Student student3;

//    student3.set_name("Alex");
//    Student student2("Emin", "Shirinov", {153910},{0.0, 1.1});
//    std::cout << "Student name is :" << student3.get_name() << std::endl;

    Complex a(1.0, -2.0);
    std::cout << "First given Complex Number is : " << a.real << " " << a.img << "i" << std::endl;
    Complex b(3.14);
    b.set_im(-5);
    std::cout << "Second given Complex NUmber is : " << b.real << " " << b.img << "i" << std::endl;
    Complex c= add(a,b);
    std::cout << c.real << " " << c.img << std::endl;
    return 0;
}
