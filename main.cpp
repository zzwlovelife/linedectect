#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

#define g_nGaussianBlurValue 13 //高斯滤波参数

int main()
{
	Mat srcImage, midImage,desImage;

	desImage = imread("source\\014.jpg");

	cvtColor(desImage, srcImage,COLOR_BGR2GRAY,1);

	if (srcImage.empty())
	{
		cout << "can not open " << endl;
		return -1;
	}
	imshow("灰度图", srcImage);

	//平滑滤波

	GaussianBlur(srcImage,midImage, Size(g_nGaussianBlurValue, g_nGaussianBlurValue), 2, 2);
	imshow("平滑图",midImage);


	//边缘检测
	Canny(midImage,midImage,10,250,5);
	imshow("边缘检测图",midImage);

	//Houghline检测直线
	vector<Vec4i> lines;//定义一个矢量结构lines用于存放得到的线段矢量集合
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 400,50);

	cout << "直线数目：" << lines.size() << endl;

	//依次在图中绘制出每条线段
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		Point pt1 = Point(l[0], l[1]);
		Point pt2= Point(l[2], l[3]);
		cout<<"坐标"<<pt1 << pt2 << endl;
		line(desImage, pt1, pt2, Scalar(0,255,0), 1, LINE_AA,0);
	}
	imshow("目标图",desImage);

	cv::waitKey(0);
	return 0;
}