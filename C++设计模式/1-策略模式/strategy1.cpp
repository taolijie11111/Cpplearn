/*
场景：
要做一个多国税收的体系
错误：
每次添加一个国家都需要到处改动
违背开闭原则，经可能用扩展，而不是改动源代码

*/

enum TaxBase{
    CN_Tax,
    US_Tax,
    DE_Tax
};

class SalesOrder{
private:
    TaxBase tax;
public:
    double CalculateTax(){
        if(tax==CN_Tax){
            //CN
        }
        else if(tax == US_Tax){
            //US
        }
        else if(tax == DE_Tax){
            //DE
        }
    }

};