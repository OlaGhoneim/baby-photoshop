// ==========================================================================================================
// Purpose: The program is dedicated to image processing Demo , and contains 5 types of filters programs
// ==========================================================================================================
// Author1: Mariem Refaey Abd El-Manaf Ahmed __ ID: 20231163
// Filter 3: Invert Image __ Filter 6: Rotate Image 
// Email: refaeymariem@gmail.com __ Section 26
// ==========================================================================================================
// Author2: Salma Ashraf Hassan Mostafa __ ID:20231073
//  Filter 1: Grayscale Conversion 
// Email: salmaashrafdiab11@gmail.com  __ Section 26
// ==========================================================================================================
// Author3: Ola Ghoneim Hammad Ahmed Salama __ ID: 20231232
//  Filter 2: Black and White __ Filter 5:Flip Image
//Filter 9:make boarder __ Filter 12:blurring __ Filter(bonus):purple
// Email: olaghoneim38@gmail.com __ Section 26
// ==========================================================================================================

#include <iostream>
#include <algorithm>
#include <limits>
#include "Image_Class.h"
using namespace std;
void purple();
void blur();
void simple();
void fancy();
void boarder_colour();
void boarder();
void Grayscale_Conversion();
void invertImage();
void rotate();
void Black_white();
void flipH();
void flipv();

int main()
{
    bool validInput = false;
    int choice;
    int close;

    while (true)
    {
        cout << "Welcome to Image processing  programs" << endl;
        cout << "Please select an option" << endl;
        cout << "1 > Grey scale filter" << endl;
        cout << "2 > Black and white " << endl;
        cout << "3 > Invert image " << endl;
        cout << "4 > flipping Horizontally" << endl;
        cout << "5 > flipping vertically" << endl;
        cout << "6 > Rotating the image" << endl;
        cout << "7 > assign border to the image" << endl;
        cout << "8 > blurring the image" << endl;
        cout << "9> make the image purple" << endl;
        cout << "0 > End" << endl;

        while (!validInput)
        {
            try
            {
                cin >> choice;
                if (cin.fail() || choice < 0 || choice > 10)
                {
                    throw invalid_argument("Invalid input: Please choose a valid option");
                }
                validInput = true;
            }

            catch (const invalid_argument& e)
            {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        validInput = false;

        if (choice == 1)
        {
            Grayscale_Conversion();
        }
        else if (choice == 2)
        {
            Black_white();
        }
        else if (choice == 3)
        {
            invertImage();
        }
        else if (choice == 4)
        {
            flipH();
        }
        else if (choice == 5)
        {
            flipv();;
        }
        else if (choice == 6)
        {
            rotate();
        }
        else if (choice == 7) {
            boarder();
        }
        else if (choice == 8) {
            blur();
        }
        else if (choice == 9) {
            purple();
        }
        else if (choice == 0)
        {
            cout << "----------END PROGRAM----------" << endl;
            break;
        }

        cout << "Do you want to end image processing programs?" << endl;
        cout << "1 > End" << endl;
        cout << "2 > continue" << endl;

        while (!validInput)
        {
            try
            {
                cin >> close;
                if (cin.fail() || close < 1 || close > 2)
                {
                    throw invalid_argument("Invalid input: Please choose a valid option");
                }
                validInput = true;
            }

            catch (const invalid_argument& e)
            {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        validInput = false;

        if (close == 1)
        {
            cout << "----------END PROGRAM----------" << endl;
            break;
        }
        else
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
        }
    }

    return 0;
}

void Grayscale_Conversion()
{
    string imagename;
    cout << "Please enter colored image name to turn to gray scale image : ";
    cin >> imagename;
    Image image(imagename); // Creating an Image object with the specified image name

    // Looping through each pixel in the image
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned  int avg = 0;
            // Calculating the average of pixel values
            for (int k = 0; k < image.channels; ++k)
            {
                avg += image(i, j, k);

            }

            avg /= 3;
            for (int x = 0; x < image.channels; ++x)
            {
                image(i, j, x) = avg;

            }


        }
    }
    cout << "Successfully modified.\n";
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imagename;
    // Saving the modified image with the specified name
    image.saveImage(imagename);
}

void invertImage()
{
    string filename;
    cout << "Please enter colored image name to turn to invert image: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            unsigned  int R = 0, G = 0, B = 0;

            for (int k = 0; k < 3; ++k)
            {
                if (k == 0)
                {
                    R = image(i, j, k);
                }
                else if (k == 1)
                {
                    G = image(i, j, k);
                }
                else if (k == 2)
                {
                    B = image(i, j, k);
                }
            }

            image(i, j, 0) = 255 - R;
            image(i, j, 1) = 255 - G;
            image(i, j, 2) = 255 - B;
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

}

void rotate_90()
{
    string filename;
    cout << "Please enter image name to rotate it by 90 degree: ";
    cin >> filename;

    Image image(filename);
    Image image2(image.height, image.width);

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(j, i, k) = image(i, image.height - 1 - j, k);
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image2.saveImage(filename);

}

void rotate_180()
{
    string filename;
    cout << "Please enter image name to rotate it by 180 degree: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width / 2; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                unsigned  int temp = image(i, j, k);
                image(i, j, k) = image((image.width - 1) - i, (image.height - 1) - j, k);
                image((image.width - 1) - i, (image.height - 1) - j, k) = temp;
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);

}

void rotate_270()
{
    string filename;
    cout << "Please enter image name to rotate it by 270 degree: ";
    cin >> filename;

    Image image(filename);
    Image image2(image.height, image.width);

    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image2(j, i, k) = image(image.width - 1 - i, j, k);
            }
        }
    }

    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image2.saveImage(filename);

}

void rotate()
{
    int option;
    bool validInput = false;

    cout << "1 > rotate image by 90 degree" << endl;
    cout << "2 > rotate image by 180 degree" << endl;
    cout << "3 > rotate image by 270 degree" << endl;

    while (!validInput)
    {
        try
        {
            cin >> option;
            if (cin.fail() || option < 1 || option > 3)
            {
                throw invalid_argument("Invalid input: Please choose a valid option");
            }
            validInput = true;
        }

        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (option == 1)
    {
        rotate_90();
    }
    else if (option == 2)
    {
        rotate_180();
    }
    else if (option == 3)
    {
        rotate_270();
    }

}

void Black_white() {
    string filename;
    cout << "Please enter colored image name to turn to black and white: ";
    cin >> filename;

    Image image(filename);

    unsigned int avg = 0;
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {

            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg /= 3;

            for (int k = 0; k < image.channels; k++) {

                if (avg > 128)
                    image(i, j, k) = 255;
                else
                    image(i, j, k) = 0;

            }


        }
    }
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}

void flipH() {
    string filename;
    cout << "Please enter colored image name to flip Horizontally: ";
    cin >> filename;

    Image image(filename);

    int l = image.width - 1;
    for (int i = 0; i < image.width / 2; i++, l--) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                std::swap(image(i, j, k), image(l, j, k));
            }
        }
    }

    cout << "Please enter image name to store new image";
    cout << "and specify extension .jpg, .bmp, .png, .tga: " << "\n";

    cin >> filename;
    image.saveImage(filename);
}

void flipv() {
    string filename;
    cout << "Please enter colored image name to flip vertically : ";
    cin >> filename;
    Image image(filename);
    for (int i = 0; i < image.width; i++) {
        int l = image.height - 1;
        for (int j = 0; j < image.height / 2; j++, l--) {

            for (int k = 0; k < image.channels; k++) {
                std::swap(image(i, j, k), image(i, l, k));
            }
        }

    }

    cout << "Please enter image name to store new image";
    cout << "and specify extension .jpg, .bmp, .png, .tga: " << "\n";

    cin >> filename;
    image.saveImage(filename);
}
int boarder_colour(){
    int colour;
    bool validInput = false;
    cout << "choose boarder colour" << endl;

    cout << "1 > white" << endl;
    cout << "2 > black" << endl;
    cout << "3 > blue" << endl;



    while (!validInput)
    {
        try
        {
            cin >> colour;
            if (cin.fail() || colour< 1 || colour > 3)
            {
                throw invalid_argument("Invalid input: Please choose a valid option");
            }
            validInput = true;
        }

        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return colour;

}
void simple(){
    string imagename;
    cout << "Please enter image name to make boarder : ";
    cin >> imagename;
    Image image(imagename); // Creating an Image object with the specified image name


    int minBorder = 40; // Minimum border size
    int maxBorder = 40; // Maximum border size

    int colour =boarder_colour(); // Get the border color from user input


    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (i <= maxBorder || i >= image.width - maxBorder - 1 || j <= maxBorder ||
                j >= image.height - maxBorder - 1) {
                if (i <= maxBorder || i >= image.width - maxBorder - 1 || j <= maxBorder ||
                    j >= image.height - maxBorder - 1) {
                    if (colour == 2) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 0;
                        image(i, j, 2) = 0;

                    } else if (colour == 1) {
                        image(i, j, 0) = 255; // Set red component to 255(black)
                        image(i, j, 1) = 255; // Set green component to 255(black)
                        image(i, j, 2) = 255; // Set blue component to 255 (blue

                    } else if (colour == 3) {
                        image(i, j, 0) = 0; // Set red component to 0 (black)
                        image(i, j, 1) = 255; // Set green component to 0 (black)
                        image(i, j, 2) = 255; // Set blue component to 255 (blue


                    }
                }
            }
        }
    }

    cout << "Successfully modified.\n";
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imagename;
    // Saving the modified image with the specified name
    image.saveImage(imagename);
}
void fancy(){
    string imagename;
    cout << "Please enter image name to make boarder : ";
    cin >> imagename;
    Image image(imagename); // Creating an Image object with the specified image name

    int colour =boarder_colour(); // Get the border color from user input

    int outerBorder = 40; // Outer border size
    int spaceSize = 20; // Size of the space between borders
    int innerBorder = 80; // Inner border size

    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if ((i <= outerBorder || i >= image.width - outerBorder - 1 || j <= outerBorder || j >= image.height - outerBorder - 1)
                && !(i <= innerBorder || i >= image.width - innerBorder - 1 || j <= innerBorder || j >= image.height - innerBorder - 1)) {
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = 250; // Set RGB values to 250 (white) for the outer border
                }
            }
            else if ((i <= outerBorder + spaceSize || i >= image.width - outerBorder - spaceSize - 1 || j <= outerBorder + spaceSize || j >= image.height - outerBorder - spaceSize - 1)
                     && !(i <= outerBorder || i >= image.width - outerBorder - 1 || j <= outerBorder || j >= image.height - outerBorder - 1)) {
                for (int k = 0; k < 3; k++) {
                    image(i, j, k) = 0; // Set RGB values to 0 (black) for the space between borders
                }
            }
            else if (i <= innerBorder || i >= image.width - innerBorder - 1 || j <= innerBorder || j >= image.height - innerBorder - 1) {
                if (colour == 2) {
                    image(i, j, 0) = 0;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 0;

                } else if (colour == 1) {
                    image(i, j, 0) = 255; // Set red component to 255(black)
                    image(i, j, 1) = 255; // Set green component to 255(black)
                    image(i, j, 2) = 255; // Set blue component to 255 (blue

                } else if (colour == 3) {
                    image(i, j, 0) = 0; // Set red component to 0 (black)
                    image(i, j, 1) = 255;
                    image(i, j, 2) = 255;


                }
            }
        }
    }

    cout << "Successfully modified.\n";
    cout << "Please enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imagename;
    // Saving the modified image with the specified name
    image.saveImage(imagename);
}
void boarder()
{
    int option;
    bool validInput = false;

    cout << "1 > simple boarder" << endl;
    cout << "2 > fancy boarder" << endl;


    while (!validInput)
    {
        try
        {
            cin >> option;
            if (cin.fail() || option < 1 || option > 3)
            {
                throw invalid_argument("Invalid input: Please choose a valid option");
            }
            validInput = true;
        }

        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (option == 1)
    {
        simple();
    }
    else if (option == 2)
    {
        fancy();
    }


}
void blur(){
    string imagename;
    cout << "Please enter image name for blurring : ";
    cin >> imagename;
    Image image(imagename); // Creating an Image object with the specified image name
    // Loop through each pixel in the image
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;
            if (x > 0 && x < image.width - 1 && y > 0 && y < image.height - 1) {
                // Loop through the 10x10 matrix around the pixel (x, y)
                for (int i = x - 15; i <= x + 15; ++i) {
                    for (int j = y - 15; j <= y + 15; ++j) {
                        if (i >= 0 && i < image.width && j >= 0 && j < image.height) {
                            // Accumulate RGB values and count valid pixels
                            sumRed += image(i, j, 0);
                            sumGreen += image(i, j, 1);
                            sumBlue += image(i, j, 2);
                            ++count;
                        }
                    }
                }

                if (count > 0) {
                    // Calculate average RGB values
                    int avgRed = sumRed / count;
                    int avgGreen = sumGreen / count;
                    int avgBlue = sumBlue / count;

                    // Assign the average values to the center pixel
                    image(x, y, 0) = avgRed;
                    image(x, y, 1) = avgGreen;
                    image(x, y, 2) = avgBlue;
                }
            }
        }
    }
    // Save the blurred image
    cout << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    string filename;
    cin >> filename;
    image.saveImage(filename);

}
void purple() {
    string imageName;
    cout << "Please enter image name to make it purple: ";
    cin >> imageName;

    Image image(imageName); // Create an Image object with the specified image name

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {

            unsigned int r = image(i, j, 0);
            unsigned int g = image(i, j, 1);
            unsigned int b = image(i, j, 2);

            image(i, j, 0) = r;
            image(i, j, 1) = g * 0.69;
            image(i, j, 2) = b; // Clamp to maximum of 255

        }
    }

    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    string fileName;
    cin >> fileName;

    image.saveImage(fileName);


}