#include <string>

using namespace std;

class Writer
{
    private:
		unsigned char* createFileHeader(int fileSize);
		unsigned char* createSizeHeader(int, int);

    public:
		int write(unsigned char***, int, int, string path);
};