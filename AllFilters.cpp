// FCAI – Programming 1 – 2022 - Assignment 3
// Program Name: AllFilters.cpp
// Program Description: Program to do filters on images.
// Last Modification Date: 21/4/2022
// Author and ID and Group: Rawan Hesham, 20211040, Group A, S1/S2.
// Author and ID and Group: Nourhan Mahmoud, 20211107, Group A, S1/S2.
// Author and ID and Group: Mai Mohamed, 20211098, Group A, S1/S2.
// Purpose: Get a Gray Scale image and produce a filtered image (any filter the user choose).

#include <iostream>
#include "bmplib.cpp"
#include <cstring>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];

void loadImage ();
void loadImage1 ();
void loadImage2 ();
void saveImage ();
void saveImage2();
void saveImage3 ();
void saveImage4 ();
void savenewImage();
void blackandWhite();
void flipImage();
void mirrorFilter();
void MergeFunc();
void lightenFunc();
void darkenFunc();
void detectImageEdges();
void shrinkFunc();
void blurFun();
void InvertImage();
void RotateImage_90();
void RotateImage_180();
void RotateImage_270();
void EnlargePart1 ();
void EnlargePart2 ();
void EnlargePart3 ();
void EnlargePart4 ();
void ImagePart1_1 ();
void ImagePart2_1 ();
void ImagePart3_1 ();
void ImagePart4_1 ();
void ImagePart1_2 ();
void ImagePart2_2 ();
void ImagePart3_2 ();
void ImagePart4_2 ();
void ImagePart1_3 ();
void ImagePart2_3 ();
void ImagePart3_3 ();
void ImagePart4_3 ();
void ImagePart1_4 ();
void ImagePart2_4 ();
void ImagePart3_4 ();
void ImagePart4_4 ();



int main()
{
    int filternum;
    cout << "Ahlan ya user ya habibi :)  \nPlease select the filter to apply or 0 to Exit:"<<endl;
    cout << "1-Black & White Filter \n2-Invert Filter \n3-Merge Filter \n4-Flip Image \n5-Rotate Image \n6-Darken and lighten Image\n7-Detect Edges Filter\n8-Enlarge Image \n9-Shrink image\n10-Mirror Filter\n11-Shuffle Filter\n12-Blur Filter\n0-Exit \nChoose number: ";
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
                InvertImage();
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
            case 5:
                loadImage();
                int choose;
                cout <<"1-Rotate 90.\n2-Rotate 180.\n3-Rotate 270." << endl;
                cout << "Enter 1,2 or 3:" << endl;
                cin >> choose;
                cin.ignore();
                if (choose ==1){
                    RotateImage_90();
                }
                else if (choose == 2){
                    RotateImage_180();
                }
                else if (choose == 3){
                    RotateImage_270();
                }
                else {
                    cout << "Wrong input enter again";
                    break;
                }
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
            case 8:
                loadImage();
                int Choose;
                cout <<"1-Enlarge Part 1.\n2-Enlarge Part 2.\n3-Enlarge Part 3.\n4-Enlarge Part 4." << endl;
                cout << "Enter Your Choice: " << endl;
                cin >> Choose;
                cin.ignore();
                if(Choose==1) {
                    EnlargePart1();
                    saveImage3();
                }
                else if (Choose==2) {
                    EnlargePart2();
                    saveImage4();
                }
                else if (Choose==3) {
                    EnlargePart3();
                    saveImage4();
                }
                else if (Choose==4){
                    EnlargePart4();
                    saveImage4();
                }
                else {
                    cout << "Wrong input enter again.";
                    break;
                }
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
            case 11:
                loadImage();
                int choose1;
                int choose2;
                int choose3;
                int choose4;
                cout<<"Enter Part 1: ";
                cin>>choose1;
                cout<<"Enter Part 2: ";
                cin>>choose2;
                cout<<"Enter Part 3: ";
                cin>>choose3;
                cout<<"Enter Part 4: ";
                cin>>choose4;
                if(choose1==1){
                    ImagePart1_1();
                }
                else if(choose1==2){
                    ImagePart2_1();
                }
                else if(choose1==3){
                    ImagePart3_1();
                }
                else if (choose1==4){
                    ImagePart4_1();
                }
                else{
                    cout<<"Wrong input enter again.";
                    return 0;
                }
                if(choose2==1){
                    ImagePart1_2();
                }
                else if(choose2==2){
                    ImagePart2_2();
                }
                else if(choose2==3){
                    ImagePart3_2();
                }
                else if (choose2==4){
                    ImagePart4_2();
                }
                else{
                    cout<<"Wrong input enter again.";
                    return 0;
                }
                if(choose3==1){
                    ImagePart1_3();
                }
                else if(choose3==2){
                    ImagePart2_3();
                }
                else if(choose3==3){
                    ImagePart3_3();
                }
                else if (choose3==4){
                    ImagePart4_3();
                }
                else{
                    cout<<"Wrong input enter again.";
                    return 0;
                }
                if(choose4==1){
                    ImagePart1_4();
                }
                else if(choose4==2){
                    ImagePart2_4();
                }
                else if(choose4==3){
                    ImagePart3_4();
                }
                else if (choose4==4){
                    ImagePart4_4();
                }
                else{
                    cout<<"Wrong input enter again.";
                    return 0;
                }
                saveImage3();
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
        cout << "Ahlan ya user ya habibi :)  \nPlease select the filter to apply or 0 to Exit:"<<endl;
        cout << "1-Black & White Filter \n2-Invert Filter \n3-Merge Filter \n4-Flip Image \n5-Rotate Image \n6-Darken and lighten Image\n7-Detect Edges Filter\n8-Enlarge Image \n9-Shrink image\n10-Mirror Filter\n11-Shuffle Filter\n12-Blur Filter\n0-Exit \nChoose number: ";
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
void saveImage4() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Please enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image4);
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
            image[i][j]=(image[i][j-1]+image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i][j+1]+image[i+1][j+1]+image[i+1][j]+image[i+1][j-1]+image[i-2][j]+image[i-2][j-2]+image[i][j-2]+image[i+2][j-1]+image[i+2][j-1]+image[i+2][j]+image[i][j+2]+image[i-1][j+2]+image[i+2][j+2]+image[i][j])/18;
        }
    }
}

//_________________________________________
void InvertImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = 255- image[i][j];
        }
    }
}

//_________________________________________
void RotateImage_90(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i > j)
                swap(image[i][j], image[j][i]);

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            swap(image[i][j],image[i][256-j]);

        }
    }
}

//_________________________________________
void RotateImage_180() {
    for (int i = 0; i < SIZE/2 ; i++) {
        for (int j = 0; j < SIZE; j++) {
            swap(image[255-i][j], image[i][255-j]);
        }
    }
}

//_________________________________________
void RotateImage_270(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i > j)
                swap(image[i][j], image[j][i]);
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            swap(image[i][j], image[256-i][j]);

        }
    }
}

//_________________________________________
void EnlargePart1() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j]=image[i][j];
            image2[i][j]=image[i+1][j];
            image2[i][j]=image[i][j+1];
            image2[i][j]=image[i+1][j+1];
        }
    }
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j < SIZE; j+=2,l++) {
            image3[i][j]=image2[k][l];
            image3[i+1][j]=image2[k][l];
            image3[i][j+1]=image2[k][l];
            image3[i+1][j+1]=image2[k][l];
        }
    }
}

//_________________________________________
void EnlargePart2(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i][j] = image2[i][j+SIZE/2];
        }
    }
    for (int i = 0, k = 0; i < SIZE; i += 2, k++) {
        for (int j = 0, l = 0; j < SIZE; j += 2, l++) {
            image4[i][j] = image3[k][l];
            image4[i + 1][j] = image3[k][l];
            image4[i][j + 1] = image3[k][l];
            image4[i + 1][j + 1] = image3[k][l];
        }
    }
}

//_________________________________________
void EnlargePart3(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i][j]=image2[i+SIZE/2][j];
        }
    }
    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j < SIZE; j+=2,l++) {
            image4[i][j]=image3[k][l];
            image4[i+1][j]=image3[k][l];
            image4[i][j+1]=image3[k][l];
            image4[i+1][j+1]=image3[k][l];
        }
    }
}

//_________________________________________
void EnlargePart4(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = SIZE/2; j < SIZE; j++) {
            image2[i][j]=image[i][j];
            image2[i][j]=image[i+1][j];
            image2[i][j]=image[i][j+1];
            image2[i][j]=image[i+1][j+1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i][j]=image2[i+SIZE/2][j+SIZE/2];
        }
    }

    for (int i = 0,k=0; i < SIZE; i+=2,k++) {
        for (int j = 0,l=0; j < SIZE; j+=2,l++) {
            image4[i][j]=image3[k][l];
            image4[i+1][j]=image3[k][l];
            image4[i][j+1]=image3[k][l];
            image4[i+1][j+1]=image3[k][l];
        }
    }
}

//_________________________________________
void ImagePart1_1() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
            image3[i][j]=image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart2_1(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i][j] = image2[i][j+SIZE/2];
        }
    }
}

//_________________________________________
void ImagePart3_1(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i][j]=image2[i+SIZE/2][j];
        }
    }
}

//_________________________________________
void ImagePart4_1() {
    for (int i = SIZE / 2; i < SIZE; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i][j]=image2[i+SIZE/2][j+SIZE/2];
        }
    }
}

//_________________________________________
void ImagePart1_2() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2 ; i++) {
        for (int j = 0; j < SIZE/2 ; j++) {
            image3[i][j+SIZE/2] = image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart2_2(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
            image3[i][j]=image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart3_2(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i][j+128]=image2[i+128][j];
        }
    }
}

//_________________________________________
void ImagePart4_2() {
    for (int i = SIZE / 2; i < SIZE; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE; j++) {
            image3[i][j+128]=image2[i+128][j+128];
        }
    }
}

//_________________________________________
void ImagePart1_3() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i+128][j]=image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart2_3(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i+128][j] = image2[i][j+128];
        }
    }
}

//_________________________________________
void ImagePart3_3(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
            image3[i][j]=image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart4_3(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = SIZE/2; j < SIZE; j++) {
            image2[i][j]=image[i][j];
            image2[i][j]=image[i+1][j];
            image2[i][j]=image[i][j+1];
            image2[i][j]=image[i+1][j+1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i+128][j] = image2[i+128][j+128];
        }
    }
}

//_________________________________________
void ImagePart1_4() {
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i+128][j+128] = image2[i][j];
        }
    }
}

//_________________________________________
void ImagePart2_4(){
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE / 2; j++) {
            image3[i+128][j+128] = image2[i][j+128];
        }
    }
}

//_________________________________________
void ImagePart3_4(){
    for (int i = SIZE/2; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
        }
    }
    for (int i = 0; i < SIZE/2; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            image3[i+128][j+128]=image2[i+128][j];
        }
    }
}

//_________________________________________
void ImagePart4_4() {
    for (int i = SIZE / 2; i < SIZE; i++) {
        for (int j = SIZE / 2; j < SIZE; j++) {
            image2[i][j] = image[i][j];
            image2[i][j] = image[i + 1][j];
            image2[i][j] = image[i][j + 1];
            image2[i][j] = image[i + 1][j + 1];
            image3[i][j]=image2[i][j];
        }
    }
}