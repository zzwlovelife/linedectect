#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

#define g_nGaussianBlurValue 13 //��˹�˲�����

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
	imshow("�Ҷ�ͼ", srcImage);

	//ƽ���˲�

	GaussianBlur(srcImage,midImage, Size(g_nGaussianBlurValue, g_nGaussianBlurValue), 2, 2);
	imshow("ƽ��ͼ",midImage);


	//��Ե���
	Canny(midImage,midImage,10,250,5);
	imshow("��Ե���ͼ",midImage);

	//Houghline���ֱ��
	vector<Vec4i> lines;//����һ��ʸ���ṹlines���ڴ�ŵõ����߶�ʸ������
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 80, 400,50);

	cout << "ֱ����Ŀ��" << lines.size() << endl;

	//������ͼ�л��Ƴ�ÿ���߶�
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		Point pt1 = Point(l[0], l[1]);
		Point pt2= Point(l[2], l[3]);
		cout<<"����"<<pt1 << pt2 << endl;
		line(desImage, pt1, pt2, Scalar(0,255,0), 1, LINE_AA,0);
	}
	imshow("Ŀ��ͼ",desImage);

	cv::waitKey(0);
	return 0;
}