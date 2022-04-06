# Debug record


* @Author: taolijie
* @Date: 2022-01-25 13:58:45
* @Last Modified by: taolijie
* @Last Modified time: 2022-01-25 13:59:11


1. **warning**:control reaches end of non-void function [-Wreturn-type]
    ```C++
    Image *Image::findAndClone(imageType type){
    for(int i=0;i<_nextSlot;i++)
      if(_prototypes[i]->returnType()==type)
        return _prototypes[i]->clone();
    }//control reaches end of non-void function [-Wreturn-type]
    ```
