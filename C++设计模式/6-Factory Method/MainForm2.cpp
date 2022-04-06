class MainForm : public Form
{
    SplitterFactory*  factory;//工厂
    //没有具体的类，依赖于一个抽象类
    //只需要创建一个工厂
    //和具体工厂并不相干

public:
    //一般写法是这样的
    MainForm(SplitterFactory*  factory){
        this->factory=factory;
    }
    
	void Button1_Click(){

        
		ISplitter * splitter=    //指针有一种多态性
            factory->CreateSplitter(); //多态new
        
        splitter->split();

	}
};



