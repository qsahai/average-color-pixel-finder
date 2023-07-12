#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


// Find average of the image
unsigned int getAvg (Mat &image) {

    unsigned int x, y;
    unsigned int avgR, avgG, avgB, avg;
    int pixelCount = 0; // used for debug purposes
    int i = 0;
    string fileName;

    for (y; y < image.rows; y++) {

        for (x; x < image.cols; x++) {

            avgR += image.at<Vec3b>(y, x)[2];
            avgG += image.at<Vec3b>(y, x)[1];
            avgB += image.at<Vec3b>(y, x)[0];

        }

        x = 0;

    }

    avgR /= (image.rows * image.cols);
    avgG /= (image.rows * image.cols);
    avgB /= (image.rows * image.cols);

    avg = (avgR << 16) | (avgG << 8) | avgB;

    /*
    cout << "Width: " << image.cols << endl;
    cout << "Height: " << image.rows  << endl;
    cout << "Pixels: " << (image.rows * image.cols) << endl;
    */

   return avg;

}


// Find the target pixel by traversing the image
unsigned int findTarget (Mat &image) {       

    unsigned int pixelColor = 0;
    unsigned int targetPixel = 0;
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int pixelCount = 1;

    unsigned int avg = getAvg(image);

    if (avg > (image.rows * image.cols)) {
        targetPixel = (avg % (image.rows * image.cols));
    } else {
        targetPixel = (avg % (image.rows * image.cols));
    }


    if (!(targetPixel % 2)) {       // if average is even, read pixels normally

        while (pixelCount < targetPixel) {

            //cout << x << ", " << y << "; Pixels: " << pixelCount << endl;

            x++;
            
            if (x == (image.cols)) {

                y++;
                x = 0;

                if (y == image.rows) {
                    y = 0;
                }

            }

            pixelCount++;

        }

    } else {

        while (pixelCount < targetPixel) {

            //cout << x << ", " << y << "; Pixels: " << pixelCount << endl;

            y++;
            
            if (y == (image.rows)) {

                x++;
                y = 0;

                if (x == image.cols) {      // loop back around image
                    x = 0;
                }

            }

            pixelCount++;

        }

    }

    // r | g | b
    pixelColor = ((image.at<Vec3b>(y, x)[2])<< 16) | ((image.at<Vec3b>(y, x)[1]) << 8) | image.at<Vec3b>(y, x)[0];
    return pixelColor;

}


int main (int argc, char *argv[]) {

    // read image name in command line argument
    string picture;
    for (int j = 1; j < argc; j++) {
        picture += argv[j];
    }

    Mat image = imread(picture);

    // get and print average
    unsigned int avg = getAvg(image);
    cout << "Image average is " << hex << avg << dec << endl;

    unsigned int targetPixel = findTarget(image);
    cout << "Target pixel color is: " << hex << targetPixel << dec << endl;

}

