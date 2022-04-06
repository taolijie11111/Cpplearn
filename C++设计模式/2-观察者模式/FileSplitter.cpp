class FileSplitter{
    string m_filePath;
    int m_fileNumber;

    //做一个进度条
    ProgressBar* m_progreeBar;

    public:
    FileSplitter(const string& filePath,int fileNumber):
    m_filePath(filePath),m_fileNumber(fileNumber){

    }

    void split(){
        //1. 读取文件

        //2. 分批次向小文件中写入
        for(int i=0;i<m_fileNumber;i++){

        }
    }

    
};