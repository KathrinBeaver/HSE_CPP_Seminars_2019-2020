#define _CRT_SECURE_NO_WARNINGS

#include <exception>
#include <iostream>

class FileWrapper {

private:
    FILE* pFile;
    size_t lSize;

public:
    FileWrapper(const char* fileName = "1.txt") {		
        pFile = fopen(fileName, "r");
        if(pFile == nullptr) {
            throw std::invalid_argument("Can't open a file\n\n");
        }
        std::cout << "Object was created, file " << fileName << " was opened\n\n";
    }

    // Например, нужен другой конструктор с дополнительными действиями
/*    FileWrapper(const char* fileName, int expSize) {
        pFile = fopen(fileName, "r");
        if(pFile == nullptr) {
            throw std::invalid_argument("Can't open a file\n\n");
        }
        std::cout << "Object was created, file was opened\n";
        if(getFileSize() != expSize) {
            // Тут может возникнуть исключение
            // Тогда файл останется открытым, как быть?..
            throw std::length_error("File has unexpected size!");
        }
    }
	*/

    // Делегирующий конструктор:
    // Объект создается, когда выполнился самый первый в цепочке
    FileWrapper(const char* fileName, int expSize) 
		: FileWrapper(fileName) {
        if(getFileSize() != expSize) {
            throw std::length_error("File has unexpected size!\n\n");
        }
    }


    ~FileWrapper() {
        if(pFile != nullptr) {
            fclose(pFile);
            pFile = nullptr;
        }
        std::cout << "Object was destroyed, file was closed\n\n";
    }

    // Конструктор перемещения
    FileWrapper(FileWrapper&& other) {
        if(this->pFile != nullptr) fclose(this->pFile);
        this->pFile = other.pFile;
        other.pFile = nullptr;
    }

    FileWrapper& operator = (FileWrapper&& other) {
        std::cout << "Moving data to new object\n";
        if(this->pFile != nullptr) fclose(this->pFile);
        this->pFile = other.pFile;
        other.pFile = nullptr;
        return *this;
    }

    size_t getFileSize() {
        fseek(pFile, 0, SEEK_END);
        this->lSize = ftell(pFile);
        rewind(pFile);
        return this->lSize;
    }

    void readAll(char* const buffer, const size_t size) const {
        rewind(pFile);
        if(size != lSize) {
            throw std::length_error("Buffer size is not OK");
        }
        // Чтение файла
        size_t result = fread(buffer, 1, lSize, pFile);
        buffer[lSize] = '\0';

        if(result != lSize) {
            throw std::runtime_error("Error reading the file\n\n");
        }
    }

    void writeToFile(const char* const buffer, size_t size) const {
        if(pFile != nullptr) {
            fwrite(buffer, sizeof(*buffer), size, pFile);
        }
    }
};