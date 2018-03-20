#include <iostream> // for standard I/O
#include <string>   // for std::strings

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>  // Video write

static void help()
{
	std::cout
		<< "------------------------------------------------------------------------------" << std::endl
		<< "This program creates a video out of a folder containing jpgs." << std::endl
		<< "Usage:" << std::endl
		<< "imageDir outputVideoName fps" << std::endl
		<< "Exmaple:" << std::endl
		<< "videoMaker_main.exe " << "./images " <<"\"jpgVideo.avi\" 10" << std::endl
		<< "------------------------------------------------------------------------------" << std::endl
		<< std::endl;
}

int main(int argc, char *argv[])
{
	
	if (argc != 4)
	{
		help();
		std::cout << "Not enough parameters" << std::endl;
		system("pause");
		return -1;
	}

	const std::string imageDir = argv[1]; //the location of jpg files
	const std::string outputVideoName = argv[2]; //the file name of the output vidoe of jpg files
	const int fps = std::stoi(argv[3]); //the file name of the output vidoe of jpg files
	
	cv::Size S;
	const std::string m_globPattern = imageDir + "\\*.jpg";           // the source file name
	std::vector<cv::String> result;
	
	cv::glob(m_globPattern, result);
	
	if (result.size() <= 0) {
		std::cout << "no jpgs found" << std::endl;
		return -1;
	}
	S = cv::imread(result.at(0)).size();
	
	cv::VideoWriter outputVideo; // Open the output
	outputVideo.open(outputVideoName, CV_FOURCC('M', 'J', 'P', 'G'), 1, S, true);

	for (auto imName : result)
	{
		outputVideo.write(cv::imread(imName));
	}
	outputVideo.release();
	std::cout << "Finished writing" << std::endl;
	return 0;
}