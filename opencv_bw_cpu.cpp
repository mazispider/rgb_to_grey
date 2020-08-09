#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
void rgb_to_grey(cv::Mat& in, cv::Mat& out) {
	//For Better Performance using Pointers for Accessing Image Data
	unsigned char* im_in_ptr = in.ptr();
	unsigned char* im_out_ptr = out.ptr();
	for (int y = 0; y < in.rows; y++) {
		for (int x = 0; x < in.cols; x++) {
			im_out_ptr[x + y * in.cols] = (im_in_ptr[3 * (x + y * in.cols)] * 0.11f + im_in_ptr[3 * (x + y * in.cols) + 1] * 0.59f + im_in_ptr[3 * (x + y * in.cols) + 2] * 0.3f);
		}
	}
}

int main( int argc, char** argv )
{   
	std::string imagePath = "./image.jpg";
	
    if(argc>1){
		imagePath = std::string(argv[1]);
	}
    
	cv::Mat input = cv::imread(imagePath, cv::IMREAD_COLOR);

	if (input.empty()) {
		std::cout << "File \"" << imagePath << "\" not found!" << std::endl;
		std::cin.get();
		return -1;
	}
	
	cv::Mat output(input.rows, input.cols, CV_8UC1);
	//Passing Mat as Reference
	rgb_to_grey(input, output);
	//Show Input Image and Generated Gray Scale Image
	cv::imshow("Input", input);
	cv::imshow("Output", output);
	//Save Image
	cv::imwrite("./image_bw.jpg",output);
	cv::waitKey();

    return 0;
}
