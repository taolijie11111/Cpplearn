#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
private:
    double re,im;
public:
    complex(double r=0,double i=0):re(r),im(i){}//构造函数
    complex& operator += (const complex&);//声明
    double real(){return re;}
    double imag(){return im;}
friend complex& __doapl(complex*,const complex&);//这些地方的声明是都没有写具体的东西的

    //~complex();这个不是指针类型，所以可以不需要析构函数
};

inline complex& __doapl(complex* ths,const complex& r){
    ths->re +=r.re;//这里调用的是标准库里面的double浮点数相加
    ths->im +=r.im;
    return *ths;
}

inline complex&//建议一个inline部分
complex::operator += (const complex& r)//这里实际上有两个参数，只是前面一个为隐式的
{
    return __doapl(this,r);
}

//加法
inline complex operator + (const complex& x,const complex& y)
{
    return complex(real(x)+real(y),imag(x)+imag(y));
}
inline complex operator + (const double x,const complex& y)
{
    return complex(x+real(y),imag(y));
}
inline complex operator + (const complex& x,const double y)
{
    return complex(real(x)+y,imag(x));
}

//操作符重载
#include <iostream>
ostream&
operator << (ostreams& os,const complex& x)
{
   return  os<<'('<<real(x)<<','<<imag(x)<<')';
}


#endif