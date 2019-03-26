#include"Drawing.h"
#include<opencv2/highgui/highgui.hpp>

namespace Drawing
{
	void ViewPicture::View()
		{
			IplImage* img = cvLoadImage("C:\\Users\\Simon\\Desktop\\fun.png");
			cvNamedWindow("Game", 10);
			cvShowImage("Nothing", img);
			cvWaitKey(0);
			cvReleaseImage(&img);
			cvDestroyWindow("Example");
		}
}
