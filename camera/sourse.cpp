#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <filesystem>

using namespace std;

int main()
{
   vector<cv::Rect> info;
   cv::Mat image;
   cv::Mat gray_image;
   cv::VideoCapture cap(0);
   int key;
   cv::CascadeClassifier faseclassifier;
   faseclassifier.load((filesystem::current_path() / "klasificatori" / "haarcascade_frontalface_default.xml").string());
   cv::namedWindow("Camera", cv::WINDOW_GUI_NORMAL);
   while(true)
   {
   //                                            заполнение
   cap >> image;
   cv::flip(image, image, 1);
   //                                            заполнение

   //                                            детект
   cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);
   faseclassifier.detectMultiScale(gray_image, info, 1.1, 9, 0, cv::Size(100,100));
   //                                            детект

   //                                            отрисовка
   for(int i = 0; i<info.size(); i++)
   {
   cv::rectangle(image, info[0], cv::Scalar(0, 255, 0), 1);
   }
   cv::imshow("Camera", image);
   key = cv::waitKey(10) & 0b11111111;
   //                                            отрисовка
   
   //                                            выход из проги
   if(key == 27)
   {
      break;
   }
   //                                            выход из проги
   }
}