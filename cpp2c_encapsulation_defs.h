#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

#include <stdbool.h>
#define NUM_BOXES  3
//#define char[] DEF_MSG="The total volume held on the shelf is"
//#define GET_NUM_BOXES()
//// Box ////////////

//class Box
//{
//public:
//    Box(double dim = 1);
//    Box(double l, double w, double h);
//    ~Box();
//
//    double getWidth() const;
//    double getLength() const;
//    double getHeight() const;
//
//    double getVolume() const;
//
//    Box& operator*=(double mult);
//
//protected:
//    void print() const;
//
//private:
//    double length;
//    double width;
//    double height;
//};
struct b{
        double length;
        double width;
        double height;
}b;
typedef struct b box;
typedef box* boxptr;
void box_init_ddd(boxptr b, double length, double width, double highet);
void box_init_d(boxptr b, double dim);
void box_print_vC(const boxptr const b);
double box_get_width_C(const boxptr b);
double box_get_length_C(const boxptr b);
double box_get_hight_C(const boxptr b);
double box_get_volume_C(const boxptr b);
boxptr box_mult_eq_d(boxptr b , double mult);
box g_mult_box_d(const boxptr box, double mult);
box g_mult_d_box(double mult,const boxptr box);
bool g_eq_box_box(const boxptr lhs ,  const boxptr rhs);
bool g_neq_box_box(const boxptr lhs ,  const boxptr rhs);


//// Shelf ////////////
//
//class Shelf
//{
//public:
//    void setBox(int index, const Box& dims);
//    double getVolume() const;
//    Box& getBox(int index);
//    void print() const;
//
//    static int getNumBoxes();
//    static void setMessage(const char* msg);
//
//private:
//    static const unsigned int NUM_BOXES = 3;
//    static const char* const DEF_MSG;
//    static const char* message;
//
//    Box boxes[NUM_BOXES];
//};
struct s{
    boxptr boxes[NUM_BOXES];
};
typedef struct s shelf;
typedef const shelf* shelfptr;
void shelf_print_C(shelfptr s);
double shelf_get_volume_C();
boxptr shelf_get_box(shelfptr s , int index);
void shelf_set_box(shelfptr s, int index, const boxptr dim);
int shelf_get_num_books(shelfptr s);
//inline Box& Shelf::getBox(int index)
//{
//    return boxes[index];
//}

//inline int Shelf::getNumBoxes()
//{
//    return NUM_BOXES;
//}

//inline void Shelf::setMessage(const char* msg)
//{
//    message = msg;
//}

#endif // __CPP2C_ENCAPSULATION_DEFS_H__

