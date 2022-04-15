#include <iostream>
#include "bmplib.cpp"
#include <cstring>

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void blackandWhite();
void flipImage();

int main()
{
    int filternum;
    cout << " Ahlan ya user ya habibi :)  \n Please select the filter to apply or 0 to Exit:"<<endl;
    cout << " 1-Black & White Filter\n2-Filp Filter\n0-Exit \nChoose number: ";
    cin >> filternum;
    while(filternum != 0){
        switch(filternum) {
            case 1:
                loadImage();
                blackandWhite();
                saveImage();
                break;
            case 2:
                loadImage();
                flipImage();
                saveImage();
                break;

            default:
                cout << "INVALID...";
                break;
        }
        cout << endl;
        cout << "THE FILTER APPLIED SUCCESSFULLY...\n";
        cout << " Ahlan ya user ya habibi :)  \n Please select the filter to apply or 0 to Exit:"<<endl;
        cout << " 1-Black & White Filter\n2-Filp Filter\n0-Exit\nChoose number: ";
        cin >> filternum;
    }
}

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void blackandWhite() {
    long average = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            average += image[i][j];
        }
    }
    //calculate the average of the pixels.
    average /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            //if the pixel is greater than the average convert this pixel to white color(255).
            if (image[i][j] > average)
                image[i][j] = 255;
                //if the pixel is smaller than the average convert this pixel to black color(0).
            else
                image[i][j] = 0;
        }
    }
}

void flipImage(){
    char choice;
    cout << "Choose 'h' for flipping horizontally or 'v' for flipping vertically: ";
    cin >> choice;
    if (choice == 'h' || choice == 'H'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < 127; j++) {
                //swap the pixels vertically.
                swap(image[i][j],image[i][256-j]);
            }
        }
    }
    else if (choice == 'v' || choice == 'V') {
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j < SIZE; j++) {
                //swap the pixels horizontally.
                swap(image[i][j],image[256-i][j]);
            }
        }
    }
}
