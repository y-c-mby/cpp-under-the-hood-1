#include <stdio.h>
#include "cpp2c_encapsulation_defs.h"

//// Box ////////////


void box_init_ddd(boxptr b, double length, double width, double highet){
    b->length =length;
    b->height = highet;
    b->width =width;
    box_print_vC(b);

}
void box_init_d(boxptr b, double dim){
    b->length =dim;
    b->height = dim;
    b->width =dim;
    box_print_vC(b);
}
//inline//double  box_get_width_C(const boxptr b)
//{
//    return b->width;
//}
//
//double  box_get_length_C(const boxptr b)
//{
//    return b->length;
//}
//
//double  box_get_height_C(const boxptr b)
//{
//    return b->height;
//}
double box_get_volume_C(const boxptr b)
{
    return b->width * b->length * b->height;
}
box g_mult_box_d(const boxptr b, double mult){
    box ans=*b;
//    box_init_d(ans);
    box_mult_eq_d(&ans,mult);
    return ans;
}
box g_mult_d_box(double mult,const boxptr box){
    return g_mult_box_d(box,mult);
}
bool g_eq_box_box(const boxptr lhs ,  const boxptr rhs){
    return (lhs->width==rhs->width) && (lhs->height == rhs->height) && (lhs->length==rhs->length);
}
bool g_neq_box_box(const boxptr lhs ,  const boxptr rhs){
    return !g_eq_box_box(lhs,rhs);
}
//Box::~Box()
//{
//    std::printf("Box destructor, %f x %f x %f\n", width, height, length);
//}
boxptr box_mult_eq_d(boxptr b , double mult){
    b->width *=mult;
    b->length *=mult;
    b->height*=mult;
    return b;
}
void box_print_vC(const boxptr const b){
    printf("Box: %f x %f x %f\n", b->length,b->width, b->height);
}

//// Shelf ////////////

//const char* const Shelf::DEF_MSG = "The total volume held on the shelf is";
//const char* Shelf::message = Shelf::DEF_MSG;
boxptr shelf_get_box(shelfptr s , int index){
    return s->boxes[index];
}
int shelf_get_num_books(shelfptr s){
    return NUM_BOXES;
}

//void Shelf::setBox(int index, const Box& dims)
//{
//    boxes[index] = dims;
//}
void shelf_set_box(shelfptr s, int index, const boxptr dim){
    s->boxes[index] = dim;
}
void shelf_print_C(shelfptr s){
    printf("%s %f\n","fdf",shelf_get_volume_C(s));
}
double shelf_get_volume_C(shelfptr s){
    double vol = 0;
    for (size_t i = 0; i < NUM_BOXES; ++i)
        vol += box_get_volume_C(s->boxes[i]);

    return vol;
}

//double Shelf::getVolume() const
//{
//    double vol = 0;
//    for (size_t i = 0; i < NUM_BOXES; ++i)
//        vol += boxes[i].getVolume();
//
//    return vol;
//}
//
//void Shelf::print() const
//{
//    std::printf("%s %f\n", message, getVolume());
//}



