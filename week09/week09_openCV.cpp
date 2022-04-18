#include <opencv/highgui.h>
int main()
{ /// Ipl 是 Intel performance library 的縮寫

	IplImage * img = cvLoadImage("di.jpg"); ///讀圖
	cvShowImage("week09", img); ///秀圖
	cvWaitKey(0); ///等任意鍵繼續

}
