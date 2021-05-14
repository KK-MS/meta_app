
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

// Metainfo class
class CarDashAlgo
{
    string sMsg;

public:
    // default constructor
    CarDashAlgo()
    {
        sMsg = "";
    }

    // Getters

    // Algorithms

    // Methods
    int display(string sFilename)
    {

        return 1;
    }

    int test(string sFilename)
    {
        Mat img = imread(sFilename, IMREAD_COLOR);
        if (img.empty())
        {
            std::cout << "Could not read the image: " << sFilename << std::endl;
            return 1;
        }
        imshow("Display window", img);
        int k = waitKey(0); // Wait for a keystroke in the window
        if (k == 's')
        {
            imwrite("write_sample.png", img);
        }
    }
    // configure
};

main()
{
    CarDashAlgo carDashAlgo;
    carDashAlgo.test("sample.jpg");
}