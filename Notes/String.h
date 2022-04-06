#ifndef __STRING__
#define __STRING__

class String
{
private:
    char* m_data;
public:
    String(const char* cstr=0);//构造函数
    String(const String& str);//拷贝构造函数
    String& operator=(const String& str);//拷贝赋值函数
    ~String();//析构函数
    char* get_c_str()const{return m_data;}//调用数据函数
};

inline
String::String(const char* cstr=0)
{
    if(cstr){
        m_data=new char[strlen(cstr)+1];//这里是array new,所以对应的释放应该是delete[]
        strcpy(m_data,cstr);
    }   
    else{
        m_data=new char[1];
        *m_data='\0';
    }
}

inline
String::~String()
{
    delete[] m_data;
}

inline //inline只是一种建议
String::String(const String& str)
{
    m_data=new char [strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}

inline String& String::operator=(const String& str)//这里表示reference，在typename后面
{
    if (this== &str){return *this}//这里的&表示取地址的一个东西，两个指针相同
    delete[] m_data;
    m_data=new char[strlen(str.m_data)];
    strcpy(m_data,str.m_data);
    return  *this;//*this这个是一个“东西”,this是一个指针，*this就是表示它所指的那个对象
}
#endif