# include <iostream>
using namespace std;

enum imageType //枚举类型
{
  LAST,SPOT
};
class Image
{
private:
  //addPrototype()saves each registered prototype here
  static Image* _prototypes[10];
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
//这里有一个warning: control reaches end of non-void function [-Wreturn-type]
//因为return没有定义完，如果if这一块else就没有返回值
Image *Image::findAndClone(imageType type){
  for(int i=0;i<_nextSlot;i++)
    if(_prototypes[i]->returnType()==type)
      return _prototypes[i]->clone();
  return 0;//这里暂时不知道需要些什么，先添加上吧
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
const int NUM_IMAGES=8;
imageType input[NUM_IMAGES]={
  LAST,LAST,LAST,SPOT,LAST,SPOT,SPOT,LAST
};
int main(){
  Image* images[NUM_IMAGES];
  //Given an image type,find the right prototype,and return a clone 
  for (int i=0;i<NUM_IMAGES;i++)
    images[i]=Image::findAndClone(input[i]);
  //Demonstrate that correct image objects have been cloned
  for(int i=0;i<NUM_IMAGES;i++)
    images[i]->draw();
  //Free the dynamic menmory
  for(int i=0;i<NUM_IMAGES;i++)
    delete images[i];
}
