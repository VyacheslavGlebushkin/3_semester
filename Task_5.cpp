#include <iostream>

using namespace std;

class Image {
    int* img;
    int mx;
    int my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy) {

        img = new int[mx * my]();
    }
    ~Image() {};
    int get(int x, int y) {
        if (x < 0 || y < 0 || x >= mx || y >= my) throw - 1;
        return img[y * my + x];
    }
    int set(int x, int y, int colour) {
        if (x < 0 || y < 0 || x >= mx || y >= my) throw - 1;
        img[y * my + x] = colour;
    }
    friend bool operator ==(Image& arrInt, Image& arrInt2);
};

bool operator ==(Image& arrInt, Image& arrInt2) {
    if ((arrInt.mx != arrInt2.mx) || (arrInt.my != arrInt2.my)) {
        return false;
    }
    for (int i = 0; i < (arrInt.mx) * (arrInt.my); i++) {
        if (arrInt.img[i] != arrInt2.img[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    try
    {
        Image image_1(3, 3);
        image_1.set(0, 0, 1);
        image_1.set(1, 1, 2);
        image_1.set(2, 2, 4);

        Image image_2(3, 3);
        image_2.set(0, 0, 1);
        image_2.set(1, 1, 2);
        image_2.set(2, 2, 4);

        Image image_3(3, 3);
        image_3.set(2, 0, 1);
        image_3.set(1, 1, 2);
        image_3.set(0, 2, 4);

        cout << "image_1 1: (0;1) colour is " << image_1.get(1, 1) << endl;

        if (image_1 == image_2) {
            cout << "The images 1 and 2 are the same." << endl;
        }
        else cout << "The images 1 and 2 are not the same." << endl;

        if (image_1 == image_3) {
            cout << "The images 1 and 3 are the same." << endl;
        }
        else cout << "The images 1 and 3 are not the same." << endl;
    }
    catch (int e)
    {
        if (e == -1) cout << "Error. Out of range" << endl;
    }
    return 0;
}