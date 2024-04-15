// ==========================================================================================================
// Purpose: The program is dedicated to image processing Demo , and contains 5 types of filters programs
// ==========================================================================================================
// Author1: Mariem Refaey Abd El-Manaf Ahmed __ ID: 20231163
// Filter 3: Invert Image __ Filter 6: Rotate Image
// Filter 8: Crop Image __ Filter 11: Resize Image
// Bonus filter 17: Infrared 
// Email: refaeymariem@gmail.com __ Section 26
// ==========================================================================================================
// Author2: Salma Ashraf Hassan Mostafa __ ID:20231073
// Filter 1: Grayscale Conversion
// Filter 4: Merge Images
// Filter 7: Darken and lighten image
// Filter 10: detect image edges
// Bonus filter 13 : land of wano (sunlight)
// Email: salmaashrafdiab11@gmail.com  __ Section 26
// ==========================================================================================================
// Author3: Ola Ghoneim Hammad Ahmed Salama __ ID: 20231232
// Filter 2: Black and White __ Filter 5:Flip Image
// Filter 9:make boarder __ Filter 12:blurring __ Filter(bonus):purple
// Email: olaghoneim38@gmail.com __ Section 26
// ==========================================================================================================
 
#include <iostream>
#include <algorithm>
#include <limits>
#include "Image_Class.h"
using namespace std;

// Sobel kernel for horizontal edge detection
const int sobel_horizontal[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
};

// Sobel kernel for vertical edge detection
const int sobel_vertical[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
};
 
void save(Image& image);
void merge(Image& image);
void lighting (Image &image);
void darkening (Image &image);
void sobelEdgeDetection(Image &image) ;
void sunlight(Image &image);
void purple(Image& image);
void blur(Image& image);
void simple(Image& image);
void fancy(Image& image);
void boarder_colour(Image& image);
void boarder(Image& image);
void Grayscale_Conversion(Image& image);
void invertImage(Image& image);
void rotate(Image& image);
void Black_white(Image& image);
void flipH(Image& image);
void flipv(Image& image);
void crop(Image& image);
void resize(Image& image);
void infrared(Image& image);

int main()
{
 
    bool validInput = false;
    int choice;
    int close;
    Image image;
    string imageName, ext;
    cout << "Please enter image name: ";
    cin >> imageName;
    // Find the last occurrence of a period in imageName
    size_t pos = imageName.rfind('.');
    while (pos == string::npos || (ext = imageName.substr(pos), ext != ".jpg" && ext != ".bmp" && ext != ".png" && ext != ".tga")) {
        if (pos == string::npos) {
            cout << "No extension found. Please enter a valid image file name with extension (.jpg, .bmp, .png, .tga):\n";
        } else {
            cout << "Invalid extension. Please enter a valid image file name with extension (.jpg, .bmp, .png, .tga):\n";
        }
        cin >> imageName;
        pos = imageName.rfind('.');
    }
    image.loadNewImage(imageName);
    while (true)
    {
        cout << "Welcome to Image processing  programs" << endl;
        cout << "Please select an option" << endl;
        cout << "1 >load image" << endl;
        cout <<"2  > save image" << endl;
        cout << "3 > Grey scale filter" << endl;
        cout << "4 > Black and white " << endl;
        cout << "5 > Invert image " << endl;
        cout << "6 > flipping Horizontally" << endl;
        cout << "7 > flipping vertically" << endl;
        cout << "8 > Rotating the image" << endl;
        cout << "9 > assign border to the image" << endl;
        cout << "10 > blurring the image" << endl;
        cout << "11 > make the image purple" << endl;
        cout << "12 > merge two photos " << endl;
        cout << "13 > Darken and Lighten Image " << endl;
        cout << "14 > Detect Image Edges " << endl;
        cout << "15 > good natural sunlight to wano land " << endl;
        cout << "16 > Crop image " << endl;
        cout << "17 > Resize image " << endl;
        cout << "18 > Infrared " << endl;
        cout << "0 > End" << endl;
        while (!validInput)
        {
            try
            {
                cin >> choice;
                if (cin.fail() || choice < 0 || choice > 18)
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
            int c;
            cin>>c;
            cout<<"Do you want to save the current image before loading new image?\n"
                  "1)save.\n"
                  "2)Discard.\n";
 
            if (c == 1){
                save(image);
            }
            else
                continue;
            string imageName;
            cout << "Please enter image name: ";
            cin >> imageName;
            image.loadNewImage(imageName);
 
        }
        if (choice == 2)
        {
 
            save( image);
        }
        if (choice == 3)
        {
            Grayscale_Conversion(image);
        }
        else if (choice == 4)
        {
            Black_white(image);
        }
        else if (choice == 5)
        {
            invertImage( image);
        }
        else if (choice == 6)
        {
            flipH(image);
        }
        else if (choice == 7)
        {
            flipv( image);;
        }
        else if (choice == 8)
        {
            rotate( image);
        }
        else if (choice == 9) {
            boarder( image);
        }
        else if (choice == 10) {
            blur(image);
        }
        else if (choice == 11) {
            purple( image);
        }
        else if (choice == 12)
        {
            merge(image);
        }
        else if (choice == 13)
        {
            string choice_1;
            cout << "1 : lighting effect \n" ;
            cout << "2 : darkening effect \n" ;
            cout << "please choose 1 or 2 \n" ;
            while (true)
            {
 
                cin >> choice_1 ;
                if (choice_1 == "1")
                {
                    lighting (image);
                    break;
                }
                else if (choice_1 == "2")
                {
                    darkening (image);
                    break;
                }
                else
                {
                    cout << "invalid input , please choose 1 or 2 \n";
                }
            }
 
        }
        else if (choice == 14)
        {
            sobelEdgeDetection(image);
        }
        else if (choice == 15)
        {
            sunlight(image);
 
        }
        else if (choice == 16)
        {
            crop(image);
        }
        else if (choice == 17)
        {
            resize(image);
        }
        else if (choice == 18)
        {
            infrared(image);
        }
        else if (choice == 0)
        {
            int c;
 
            cout<<"Do you want to save the current image before closing the program?\n"
                  "1)save.\n"
                  "2)Discard.\n";
            cin>>c;
 
 
            if (c == 1){
                save(image);
            }
            cout << "----------END PROGRAM----------" << endl;
            break;
        }
    }
 
 
 
 
    return 0;
}
 
void Grayscale_Conversion(Image &image)
{
 
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
 
}
 
void invertImage(Image &image)
{
 
 
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
 
 
 
}
 
void rotate_90(Image &image)
{
 
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
 
    image=image2;
 
 
}
 
void rotate_180(Image &image)
{
 
 
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
 
 
 
}
 
void rotate_270(Image &image)
{
 
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
 
 
image=image2;
}
 
void rotate(Image &image)
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
        rotate_90(image );
    }
    else if (option == 2)
    {
        rotate_180(image);
    }
    else if (option == 3)
    {
        rotate_270(image);
    }
 
}
 
void Black_white(Image &image) {
 
 
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
 
}
 
void flipH(Image &image) {
 
 
    int l = image.width - 1;
    for (int i = 0; i < image.width / 2; i++, l--) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                std::swap(image(i, j, k), image(l, j, k));
            }
        }
    }
 
}
 
void flipv(Image &image) {
 
    for (int i = 0; i < image.width; i++) {
        int l = image.height - 1;
        for (int j = 0; j < image.height / 2; j++, l--) {
 
            for (int k = 0; k < image.channels; k++) {
                std::swap(image(i, j, k), image(i, l, k));
            }
        }
 
    }
 
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
void simple(Image &image){
 
 
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
 
 
}
void fancy(Image &image){
 
 
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
 
 
}
void boarder(Image &image)
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
        simple(image );
    }
    else if (option == 2)
    {
        fancy(image);
    }
 
 
}
void blur(Image &image){
 
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
 
 
}
void purple( Image &image) {
 
 
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
 
 
 
 
}
void merge(Image& image)
{
    string imagename_2 , ext = "";
    cout << "Please enter the two colored image name to modify :\n ";
    cin >> imagename_2;
    size_t pos = imagename_2.rfind('.');
    
    // Loop until a valid extension is provided
    while (pos == string::npos || (ext = imagename_2.substr(pos), ext != ".jpg" && ext != ".bmp" && ext != ".png" && ext != ".tga")) {
        if (pos == string::npos) {
            cout << "No extension found. Please enter a valid image file name with extension (.jpg, .bmp, .png, .tga):\n";
        } else {
            cout << "Invalid extension. Please enter a valid image file name with extension (.jpg, .bmp, .png, .tga):\n";
        }
        cin >> imagename_2;
        pos = imagename_2.rfind('.');
    }
    Image image_2(imagename_2);
    long long image_1_size = image.height * image.width;
    long long image_2_size = image_2.height * image_2.width;
    if (image_1_size == image_2_size)
    {
        Image new_image(image.width, image.height);
        for (int i = 0; i < new_image.width; i++)
        {
            for (int j = 0; j < new_image.height; j++)
            {
                for (int k = 0; k < new_image.channels; k++)
                {
                    new_image(i, j, k) = (image(i, j, k) + image_2(i, j, k)) / 2;
                    if (new_image(i, j, k) > 255)
                    {
                        new_image(i, j, k) = 255;
                    }
                }

            }


        }
        cout << "Successfully modified.\n";
        image = new_image;


    }
    else if (image_1_size != image_2_size)
    {
        cout << "the sizes of two photo are not equal \n";
        cout << "1 : resize the smaller image or both to the biggest height and the biggest width and then merge \n";
        cout << "2 : merge the common area of the smaller width and the smaller height \n";
        string choice;

        while (true)
        {
            cin >> choice;
            if (choice == "1")
            {
                double x_ratio = double(image_2.width) / image.width;
                double y_ratio = double(image_2.height) / image.height;
                Image resizedImage(image.width, image.height);
                for (int o = 0; o < image.width; o++)
                {
                    for (int p = 0; p < image.height; p++)
                    {
                        for (int q = 0; q < 3; q++)
                        {
                            resizedImage(o, p, q) = image_2(round(o * x_ratio), round(p * y_ratio), q);
                        }
                    }
                }
                Image new_image(image.width, image.height);
                for (int i = 0; i < new_image.width; i++)
                {
                    for (int j = 0; j < new_image.height; j++)
                    {
                        for (int k = 0; k < new_image.channels; k++)
                        {
                            new_image(i, j, k) = (image(i, j, k) + resizedImage(i, j, k)) / 2;
                            if (new_image(i, j, k) > 255)
                            {
                                new_image(i, j, k) = 255;
                            }
                        }
                    }
                }
                cout << "Successfully modified.\n";
                image = new_image;


                break;

            }
            else if (choice == "2")
            {
                int x = min(image.width, image_2.width);
                int y = min(image.height, image_2.height);

                Image cropedImage(x, y);
                for (int o = 0; o < x; o++) {
                    for (int p = 0; p < y; p++)
                    {
                        for (int q = 0; q < 3; q++)
                        {
                            if (x == image.width)
                            {
                                cropedImage(o, p, q) = image(o, p, q);
                            }
                            else
                            {
                                cropedImage(o, p, q) = image_2(o, p, q);
                            }
                        }
                    }

                }

                Image new_image(min(image.width, image_2.width), min(image.height, image_2.height));
                for (int i = 0; i < new_image.width; i++) {
                    for (int j = 0; j < new_image.height; j++) {
                        for (int k = 0; k < 3; k++) {
                            if (x == image.width)
                            {
                                new_image(i, j, k) = (cropedImage(i, j, k) + image_2(i, j, k)) / 2;
                            }
                            else
                            {
                                new_image(i, j, k) = (cropedImage(i, j, k) + image(i, j, k)) / 2;
                            }
                            if (new_image(i, j, k) > 255) {
                                new_image(i, j, k) = 255;
                            }
                        }
                    }
                }

                cout << "Successfully modified.\n";
                image = new_image;

                break;

            }
            else
            {
                cout << "invalid input , please choose 1 or 2 : ";
            }
        }


    }


}
void lighting (Image &image) {
 
    int rate = 50 ;
    // Looping through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int x = 0; x < image.channels; ++x) {
                int ratio = (image(i, j, x) * rate) / 100;
                image(i, j, x) = min(255, image(i, j, x) + ratio)  ;// Ensure that the channel value doesn't exceed 255
            }
        }
    }
    cout << "Successfully modified.\n";
 
}
void darkening (Image &image)
{
 
    int rate = 50;
 
    // Looping through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int x = 0; x < image.channels; ++x) {
                int ratio = (image(i, j, x) * rate) / 100;
                image(i, j, x) = min(255, image(i, j, x) - ratio)  ;// Ensure that the channel value doesn't exceed 255
            }
 
        }
    }
    cout << "Successfully modified.\n";
 
 
}
void sobelEdgeDetection(Image& image) {
    Image edge_Image(image.width, image.height);
    //convert image to grayscale 
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




    // Loop through pixels in the image
    for (int i = 1; i < image.width - 1; ++i) {
        for (int j = 1; j < image.height - 1; ++j) {
            int grad_X = 0;
            int grad_Y = 0;
            // Apply Sobel horizontal kernel
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    grad_X += image(i + k, j + l, 0) * sobel_horizontal[k + 1][l + 1];
                }
            }

            // Apply Sobel vertical kernel
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    grad_Y += image(i + k, j + l, 0) * sobel_vertical[k + 1][l + 1];
                }
            }


            // Combine gradients to get edge magnitude
            int edge_magnitude = abs(grad_X) + abs(grad_Y);

            // Set white color for edges
            for (int k = 0; k < image.channels; ++k) {
                if (edge_magnitude > 200)
                {
                    edge_Image(i, j, k) = 0;
                }
                else
                {
                    edge_Image(i, j, k) = 255;

                }

            }
        }
    }
    cout << "Successfully modified.\n";
    image = edge_Image;



}
void sunlight(Image &image)
{
 
 
    for (int  i = 0; i < image.width; i++)
    {
        for ( int j = 0; j < image.height ; j++)
        {
 
            // Retrieve the intensity values for the three color channels (RGB) of the current pixel
            double x = image(i, j, 0) * 1.1; // Increase intensity of red channel by 10%
            double y = image(i, j, 1) * 1.1; // Increase intensity of green channel by 10%
            double z = image(i, j, 2) * 0.5; // Decrease intensity of blue channel by 50%
 
            // Ensure that the intensity values are within the valid range [0, 255]
            image(i , j , 0) = min(x , 255.0) ;
            image(i , j , 1) = min(y, 255.0) ;
            image(i , j , 2) = max(z , 0.0) ;
 
        }
 
 
    }
    cout << "Successfully modified.\n";
}
 
void save(Image &image) 
{
    bool found = false;
    string fileName, ext = "";
    cout << "Please enter the image name to store the new image\n";
    cout << "and specify the extension (.jpg, .bmp, .png, .tga): ";
    cin >> fileName;

    size_t pos = fileName.find('.');
    if (pos != string::npos) {
        ext = fileName.substr(pos);
    }

    while (ext != ".jpg" && ext != ".bmp" && ext != ".png" && ext != ".tga") {
        cout << "Invalid extension. Please enter a valid image file name with extension (.jpg, .bmp, .png, .tga):\n";
        cin >> fileName;
        pos = fileName.find('.');
        if (pos != string::npos)
        {
            ext = fileName.substr(pos);
        } 
        else
        {
            ext = ""; // Reset ext if no period is found
        }
    }
    
    image.saveImage(fileName);
}

void crop(Image& image)
{
    int x, y, W, H;

    cout << "Please enter x, y, W, H : ";
    cin >> x >> y >> W >> H;

    Image cropedImage(W, H);

    for (int o = 0; o < W; o++) 
    {
        for (int p = 0; p < H; p++) 
        {   
            for (int q = 0; q < 3; q++) 
            {
                cropedImage(o, p, q) = image(o + x, p + y, q);
            }
        }
    }

    image = cropedImage;
}
void resize(Image& image)
{
    double W, H;
 
    cout << "Please enter new dimensions : ";
    cin >> W >> H;

    Image resizedImage(W, H);
 
    double x, y;
    x = image.width / W;
    y = image.height / H;

    for (int o = 0; o < W; o++) 
    {
        for (int p = 0; p < H; p++) 
        {   
            for (int q = 0; q < 3; q++) 
            {
                resizedImage(o, p, q) = image(round(o * x), round(p * y) , q);
            }
        }
    }

    image = resizedImage;
}
void infrared(Image& image)
{

    for (int o = 0; o < image.width; o++) 
    {
        for (int p = 0; p < image.height; p++) 
        {
            unsigned  int G = 0, B = 0;

            for (int q = 0; q < 3; q++) 
            {
                if (q == 1)
                {
                    G = image(o, p, q);
                }
                else if (q == 2)
                {
                    B = image(o, p, q);
                }
            }

            image(o, p, 0) = 255;
            image(o, p, 1) = 255 - G;
            image(o, p, 2) = 255 - B;
        }
    }

}
