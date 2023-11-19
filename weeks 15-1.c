/*
structure - a user-defined data type that combines existing data types
   a computer is represented by CPU (model), RAM size, SSD size
two using sturcture!
1,
struct tComputer{

};
2, batter than 1.
typedef struct{
    char CPU[64];
    int RAM;
    int SSD;
}tComputer

structure variable
   declare a structure variable 'comp'


structure pointer
   declare a structure pointer 'comp_ptr'
    Computer = comp_ptr = NULL;

set comp to ("Ryzen 5600", 16, 512) through comp
answer:  strcpy(comp.CPU,"Ryzen 5600"); 중요!! 구조체 사용시 strcpy를 사용해 변수에 값을 집어넣는다
         comp.RAM = 16;
         comp.SSD = 512;
set comp to ("Ryzen 5600G", 32, 1024) through comp_ptr
    strcpy(comp_ptr->CPU,"Ryzen 5600")
    comp_ptr->RAM = 32;
    comp_ptr->SSD = 1054;
answer:
Stamp.min      (INCORRECT)
Stamp.Time.min  (INCORRECT)
stamp.time.min  (correct)
*/