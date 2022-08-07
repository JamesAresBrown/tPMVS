//
// Created by hzx on 2022/8/3.
//

#ifndef PMVS3_OPENCVSHOW_H
#define PMVS3_OPENCVSHOW_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
//#include <eigen3/Eigen/Dense>
//#include <eigen3/Eigen/Geometry>
using namespace std;
//using namespace cv;
namespace PMVS3 {
    class CfindMatch;

    class OShow {
    public:
        OShow(CfindMatch& findMatch);

        ~OShow();

        static cv::Mat show(vector<unsigned char> image, int height, int width, int isShow = 1);
        static cv::Mat show(const CfindMatch& fm, int index, int level = 0, int isShow = 1);
        static void showAll(const CfindMatch& fm, int level = 1);


    protected:
        CfindMatch &m_fm;

    };
};

#endif //PMVS3_OPENCVSHOW_H
