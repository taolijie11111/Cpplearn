#include <iostream>
//导入标准库，使用<>和使用""是有区别的
//1、#include <> 编译器只会去系统文件目录中查找，找不到就报错。
//2、#include " "  编译器会先在用户目录中查找，再到编译器设定的目录中查找，最后到系统文件中目录中查找。
using namespace std;
//使用namespace，命名空间

enum imageType //枚举类型
{
  LAST,SPOT
};
//enum <类型名> {<枚举常量表>};
class Image
{
private:
  //addPrototype()saves each registered prototype here
  static Image* _prototypes[10]; //这里定义也是定义的原类型
  //指针数组
  //static 
  //https://blog.csdn.net/ypshowm/article/details/89030194
  //修饰类的数据成员，表明对该类所有对象这个数据成员都只有一个实例。即该实例归 所有对象共有。
  //static 不需要生成类对象就可以调用。
  static int _nextSlot;
public:
  virtual void draw()=0;
  static Image* findAndClone(imageType);
protected:
  virtual imageType returnType()=0;
  virtual Image * clone()=0;
  //as each subclass of Image is declared,it registers its prototype
  static void addPrototype(Image* image){
    _prototypes[_nextSlot++]=image;
  }
};
Image *Image::_prototypes[];
int Image::_nextSlot;

//Client calls this public static menmber function when it needs an instance 
//of an Image subclass
// Image *Image::findAndClone(imageType type){
//   for(int i=0;i<_nextSlot;i++)
//     if(_prototypes[i]->returnType()==type)
//       return _prototypes[i]->clone();
// }
//warning: control reaches end of non-void function [-Wreturn-type]
//这里表示return可能为null值
Image *Image::findAndClone(imageType type){
  for(int i=0;i<_nextSlot;i++)
    if(_prototypes[i]->returnType()==type)
      return _prototypes[i]->clone();
  return 0;//暂时不知道添加什么，这里先添加一个东西
}

class LandSatImage:public Image
{
private:
  //Mechanism for initializing an Image subclass -this causes the 
  //default ctor too be called,which registers the subclass's prototype
  static LandSatImage landSatImage;
  //This is only called when the private static data menber is inited
  LandSatImage(){
    addPrototype(this);
  }
  //Norminal"state" per instance mechanism
  int _id;
  static int _count;
public:
  imageType returnType(){
    return LAST;
  }
  void draw(){
    cout<<"LandSatImage::draw"<<_id <<endl;
  }
  //When clone() is called,call the one-argument ctor with a dummy arg
  Image* clone(){
    return new LandSatImage(1);
  }
protected:
  //This is only called from clone()
  LandSatImage(int dummy){
    _id=_count++;
  }
};
//Register the subclass's  prototype 
LandSatImage LandSatImage::landSatImage;
//Initialize the "state" per instance mechanism
int LandSatImage::_count=1;

class SpotImage:public Image
{
private:
  SpotImage(){
    addPrototype(this);
  }
  static SpotImage _spotImage;
  int _id;
  static int _count;
public:
  imageType returnType(){
    return SPOT;
  }
  void draw(){
    cout<<"SpotImage::draw"<<_id<<endl;
  }
  Image* clone(){
    return new SpotImage(1);
  }
protected:
  SpotImage(int dummy){
    _id=_count++;
  }
};
SpotImage SpotImage::_spotImage;
int SpotImage::_count=1;

//Simulated stream of creation requests
const int NUM_IMAGES=8;//这里定义了一个全局变量
imageType input[NUM_IMAGES]={//暂时还不是很理解前面的返回为imageType类型究竟表示什么意思
  LAST,LAST,LAST,SPOT,LAST,SPOT,SPOT,LAST
};
int main(){
  Image* images[NUM_IMAGES]; //image*类型，指针
  //这里就是弄了8个image类型
  //指针数组，images中的每一个元素都是指向一个image类型的指针
  //生成八个类对象？指向八个类对象？？
  //Given an image type,find the right prototype,and return a clone 
  for (int i=0;i<NUM_IMAGES;i++)
    images[i]=Image::findAndClone(input[i]);
  //Demonstrate that correct image objects have been cloned
  for(int i=0;i<NUM_IMAGES;i++)
    images[i]->draw();
  //Free the dynamic menmory
  for(int i=0;i<NUM_IMAGES;i++)
    delete images[i]; //删除指针
}
