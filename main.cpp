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
      friend Complex add(Complex, Complex);
      void print();
};
Complex add(Complex n1, Complex n2) {
    Complex res;
    res.real=n1.real + n2.real;  // adding real part of complex numbers
   res.img =n1.img + n2.img;
   return res;
}

void Complex::print() {
    if(img < 0) {
        if(img == -1)
        std::cout << "The complex number is: " << real << "-i" << std::endl;
        else
            std::cout << "The complex number is: " << real << img << "i" << std::endl;
        } else
        if(img == 1)
            std::cout << "The complex number is: " << real << " + i" << std::endl;
    else std::cout << "The complex number is " << real << " + " << img << "i" << std::endl;
    }


class Student {
    std::string name;
    std::string surname;
    int album_number;
    std::vector<float> grades;
public:
    Student() {}
    Student(std::string n, std::string s, int an, std::vector<float> g) {
        name = n;
        surname = s;
        album_number = an;
        grades = g;
    }

    void set_name(std::string n) {
        name = n;
    }
    void set_surname(std::string s) {
        surname = s;
    }

    void set_album(int an) {
        if(an>=10000 && an<= 99999)
        album_number = an;
    }

    std::string get_name() {
        return name;
    }

    std::string get_surname() {
        return surname;
    }

    int get_album() {
        return album_number;
    }

    float calculate_grade() {
        std::cout << "Average grades of " << name + " " + surname  + ": " ;
        float ave;
//        for(auto &it : grades) {
//            std::cout << it << " ";
//        }
//        std::cout << "\nAverage of grades: ";
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return ave= sum / grades.size();
    }

    bool add_grade(float grade) {
        if(grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    bool passed(float ave) {
        if(ave >= 2.0 && ave <= 5.0) {
            std::cout << "Passed" << std::endl;
            return true;
        } else {
            std::cout << "FAILED" << std::endl;
            return false;
        }
    }

    void summary() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Surname: " << surname << std::endl;
        std::cout << "Album Number: " << album_number << std::endl;
        std::cout << "Grades: " << std::endl;
        for (int i=0;i<grades.size();i++)
            std::cout << "\t" << grades[i] << std::endl;
        std::cout << std::endl;
    }
};



int main()
{
//    Student student3;

//    student3.set_name("Alex");
//    Student student2("Emin", "Shirinov", 153910,{0.0, 1.1});
//    std::cout << "Student name is :" << student3.get_name() << std::endl;
//    Student student3;
Student student3("Emin", "Shirinov", 153910,{4.5,3.5,2.0, 1.1});
//        student3.set_name("Alex");
//        student3.set_surname("Jackson");
//        student3.set_album(12345);

//        std::cout << "student name is " << student3.get_name() << " and surname is " << student3.get_surname() <<
//                     "student album number: " << student3.get_album() << std::endl;
        student3.summary();
//        Student student2{"iman", "es", {0.0,1.1}};
        student3.add_grade(4.5);
        student3.add_grade(3.5);


        float ave = student3.calculate_grade();

        std::cout << ave << std::endl;
        student3.passed(ave);

        std::cout << "Part 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

//    Complex a(1.0, -2.0);
//    std::cout << "First given Complex Number is : " << a.real << " " << a.img << "i" << std::endl;
//    Complex b(3.14);
//    b.set_im(-5);
//    std::cout << "Second given Complex NUmber is : " << b.real << " " << b.img << "i" << std::endl;
//    Complex c= add(a,b);
//    std::cout << "Addition and result is : " << c.real << " " << c.img << std::endl;
        Complex a(1.0, -2.0),b(3.14);
        a.print();
        b.print();
        b.set_im(-5);
        b.print();
        Complex c = add(a,b);
        c.print();



    return 0;
}
