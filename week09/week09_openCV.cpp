#include <opencv/highgui.h>
int main()
{ /// Ipl �O Intel performance library ���Y�g

	IplImage * img = cvLoadImage("di.jpg"); ///Ū��
	cvShowImage("week09", img); ///�q��
	cvWaitKey(0); ///�����N���~��

}
