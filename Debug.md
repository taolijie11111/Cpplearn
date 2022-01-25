# Debug record

1. **warning**:control reaches end of non-void function [-Wreturn-type]
    ```C++
    Image *Image::findAndClone(imageType type){
    for(int i=0;i<_nextSlot;i++)
      if(_prototypes[i]->returnType()==type)
        return _prototypes[i]->clone();
    }//control reaches end of non-void function [-Wreturn-type]
    ```
  