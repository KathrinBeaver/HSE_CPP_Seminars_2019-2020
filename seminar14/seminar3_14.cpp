#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>

#include "FileWrapper.cpp"

class TwoFilesWrapper {

private:
    FileWrapper fileFrom;
    FileWrapper fileTo;
	int* test;

public:

    // Может ли быть утечка памяти в этом коде?
    TwoFilesWrapper(const char* file1, const char* file2) {
        fileFrom = FileWrapper(file1);
		test = new int[100];
        fileTo = FileWrapper(file2);
		std::cout << "TwoFilesWrapper was created, files were opened\n";
    }
	

    // И что будет при такой релизации?
    TwoFilesWrapper(const char* file1, const char* file2) :
		TwoFilesWrapper(file1) {			
    	fileTo = FileWrapper(file2);
    }

    TwoFilesWrapper(const char* file1) {	
		fileFrom = FileWrapper(file1);
		test = new int[100];
    }

    void copy() {
        size_t size = fileFrom.getFileSize();
        char* buff = new char[size + 1];
        fileFrom.readAll(buff, size);
        fileTo.writeToFile(buff, size);
    }

    ~TwoFilesWrapper() {
		delete[] test;
        std::cout << "Destroying TwoFilesWrapper\n";
    }
};


int old_school() {

    FILE* pFile;
    char* buffer;
    size_t result;

    pFile = fopen("1.txt", "r");
    if(pFile == nullptr) {
        std::cerr << "File error\n";
        return 1;
    }

    // Получаем размер файла
    fseek(pFile, 0, SEEK_END);
    long fSize = ftell(pFile);
    rewind(pFile);

    // Выделяем память
    buffer = new char[fSize + 1];
    if(buffer == nullptr) {
        std::cerr << "Memory error";
        return 2;
    }

    // Читаем файл в массив char
    result = fread(buffer, 1, fSize, pFile);
    buffer[fSize] = '\0';

    if(result != fSize) {
        std::cerr << "Reading error";
        return 3;
    }

    // Закрытие и очистка
    fclose(pFile);

    std::cout << buffer << "\n";

    delete[] buffer;
    return 0;
}

void fileWrapperExample() {
    {
        std::cout << "File Wrapper Example(1)\n\n";
        FileWrapper file = FileWrapper("1.txt");
        size_t fileSize = file.getFileSize();

        char* buffer = new char[fileSize + 1]; // +1 для \0  в конце!
        if(buffer == nullptr) {
            std::cerr << "Memory error\n\n";
        }

        file.readAll(buffer, fileSize);
        std::cout << buffer << "\n\n";
        delete[] buffer;
        //FileWrapper is destroyed automatically
    }
    {
        std::cout << "\n\n\n";

        try {
            std::cout << "File Wrapper Example(2)\n";
            FileWrapper file2("1.txt", 999);
        }
        catch(std::exception& ex) {
            std::cout << ex.what() << "\n";
        }
        std::cout << "\n";
        // Is FileWrapper destroyed automatically?
    }
}

void twoFilesExample() {
    std::cout << "2 Files wrapper example\n";
    try {
        TwoFilesWrapper twoFiles("1.txt", "C:\\Windows\\2.txt");
        std::cout << "After ctor \n";
        twoFiles.copy();
    }
    catch(std::exception& ex) {
        std::cout << ex.what();
    }
}

void exampleCpp11() {
    std::fstream file("1.txt");
    std::string str;	
	while (file >> str) {
		std::cout << str << " ";
	}
	file.close();
}

int main() {

    //old_school();
    fileWrapperExample();
    //twoFilesExample();
    //exampleCpp11();

    system("pause");

    return 0;
}

