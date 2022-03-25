/*
场景：
要做一个多国税收的体系
错误：
每次添加一个国家都需要到处改动
违背开闭原则，经可能用扩展，而不是改动源代码

改进：
使用虚函数和类的继承
*/

//工程上不要把多个类放在一个文件里面

class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){};                               //重要
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){

    };
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){

    };
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){

    };
};

//要有多态性
//这一块是稳定的，表示前面加上东西并不影响这一段
class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy=strategyFactory->NewStrategy();//加入一个策略
    }
    ~SalesOrder(){
        delete this ->strategy;
    }

    double CalculateTax(context){
        Context context();
        double val=strategy->Calculate(context);//多态调用
    }

};

/*
这一段代码具有良好的本地性，会缓解性能的问题

策略模式的好处：
1. 提供可重用算法
2. 消除条件判断语句
3. 共享一个strategy对象，从而节省对象开销
4. 写出来的代码，加载到高速缓存区的为有用代码，提高效率
*/