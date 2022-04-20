#include <iostream>
#include "bmplib.cpp"
#include <cstring>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];

void loadImage ();
void loadImage1 ();
void loadImage2 ();
void saveImage ();
void saveImage2();
void saveImage3 ();
void savenewImage ();
void blackandWhite();
void flipImage();
void mirrorFilter();
void MergeFunc();
void lightenFunc();
void darkenFunc();
void detectImageEdges();
void shrinkFunc();
void blurFun();


int main()
{
    int filternum;
    cout << " Ahlan ya user ya habibi :)  \n Please select the filter to apply or 0 to Exit:"<<endl;
    cout << " 1-Black & White Filter \n 2-Invert Filter \n 3-Merge Filter \n 4-Flip Image \n 5-Rotate Image \n 6-Darken and lighten Image\n7-Detect Edges Filter\n 8-Enlarge Image \n9-Shrink image\n10-Mirror Filter\n11-Shuffle Filter\n12-Blur Filter\n0-Exit \nChoose number: ";
    cin >> filternum;
    while(filternum != 0){
        switch(filternum) {
            case 1:
                loadImage();
                blackandWhite();
                saveImage();
                break;
            case 3:
                loadImage1();
                loadImage2();
                MergeFunc();
                saveImage3();
                break;
            case 4:
                loadImage();
                flipImage();
                saveImage();
                break;
            case 6:
                char choice;
                cout << "Do you want darken or lighten?\n enter d for darken or l for lighten:";
                cin >> choice;
                if (choice == 'l') {
                    loadImage();
                    lightenFunc();
                    saveImage();
                } else if (choice == 'd') {
                    loadImage();
                    darkenFunc();
                    saveImage();
                } else
                    cout << "Invalid operation";
                break;
            case 7:
                loadImage();
                detectImageEdges();
                saveImage2();
                break;
            case 9:
                loadImage();
                shrinkFunc();
                savenewImage();
                break;
            case 10:
                loadImage();
                mirrorFilter();
                saveImage();
                break;
            case 12:
                loadImage();
                blurFun();
                saveImage();
                break;    
            default:
                cout << "INVALID...";
                break;
        }
        cout << endl;
        cout << "THE FILTER APPLIED SUCCESSFULLY...\n";
        cout << " Ahlan ya user ya habibi :)  \n Please select the filter to apply or 0 to Exit:"<<endl;
        cout << " 1-Black & White Filter \n 2-Invert Filter \n 3-Merge Filter \n 4-Flip Image \n 5-Rotate Image \n 6-Darken and lighten Image\n 7-Detect Edges Filter\n 8-Enlarge Image \n9-Shrink image\n10-Mirror Filter\n11-Shuffle Filter\n12-Blur Filter\n0-Exit \nChoose number: ";
        cin >> filternum;
    }
}

//_________________________________________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}
//_________________________________________
void saveImage2() {
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image2);
}

//____________________________________________
void loadImage1 () {
    char imageFileName1[100];

    // Get gray scale image file name
    cout << "Enter the first source image file name: ";
    cin >> imageFileName1;

    // Add to it .bmp extension and load image
    strcat (imageFileName1, ".bmp");
    readGSBMP(imageFileName1, image1);
}

//_________________________________________
void loadImage2 () {
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the second source image file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

//_________________________________________
void saveImage3() {
    char imageFileName3[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName3;

    // Add to it .bmp extension and load image
    strcat (imageFileName3, ".bmp");
    writeGSBMP(imageFileName3, image3);
}

//_________________________________________
void savenewImage() {
    char imageFileName3[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName3;

    // Add to it .bmp extension and load image
    strcat (imageFileName3, ".bmp");
    writeGSBMP(imageFileName3, newimage);
}

//_________________________________________
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

//_________________________________________
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

//_________________________________________
void mirrorFilter() {
    char letter;
    cout
            << "Do you want to mirror left, right, upper, down\nEnter 'l' for left, 'r' for right, 'u' for upper, 'd' for down:";
    cin >> letter;
    while(tolower(letter) != 'l' && tolower(letter) != 'r' && tolower(letter) != 'u' && tolower(letter) != 'd'){
        cout << "INVALID, Enter 'l' for left, 'r' for right, 'u' for upper, 'd' for down: ";
        cin >> letter;
    }
    if(tolower(letter) == 'l') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][256-j] = image[i][j];
            }
        }
    }
    else if(tolower(letter) == 'r') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[i][256 - j];
            }
        }
    }
    else if(tolower(letter) == 'u') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[256-i][j] = image[i][j];
            }
        }
    }
    else if(tolower(letter) == 'd') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[256-i][j];
            }
        }
    }
}

//_________________________________________
void MergeFunc() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image3[i][j] = (image1[i][j] + image2[i][j])/2 ;
        }
    }
}

//_________________________________________
void lightenFunc() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image[i][j] = (image[i][j]+255)/2;
        }
    }
}

//_________________________________________
void darkenFunc() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            image[i][j] = (image[i][j])/2;
        }
    }
}

//_________________________________________
void shrinkFunc() {
    int dim;
    int dimen;
    cout <<"Shrink to (1/2, 1/3 or 1/4)?\nPlease enter 2 for 1/2, 3 for 1/3 or 4 for 1/4 : ";
    cin >> dimen;
    dim = 2 * dimen;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            newimage[i/(dim/2)][j/(dim/2)]=(image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j])/dim;

        }
    }
}
//_________________________________________
void detectImageEdges() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] < 130 &&
                (image[i + 1][j] > 130 || image[i - 1][j] > 130 || image[i][j + 1] > 130 || image[i][j - 1] > 130))
                image2[i][j] = 0;
            else
                image2[i][j] = 255;
        }
    }
}
//_________________________________________
void blurFun() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
//            image[i][j]=(image[i][j-1]+image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1]+image[i+1][j]+image[i+1][j-1]+image[i][j])/9;

            image[i][j]=(image[i][j-1]+image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1]+image[i+1][j]+image[i+1][j-1]+image[i-2][j]+image[i-2][j-2]+image[i][j-2]+image[i+2][j-1]+image[i+2][j-1]+image[i+2][j]+image[i][j+2]+image[i-1][j+2]+image[i+2][j+2]+image[i][j])/18;
        }
    }
}
//_________________________________________