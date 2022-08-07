//
// Created by hzx on 2022/8/3.
//

#include "opencvShow.h"
#include "findMatch.h"
#include "opencv2/opencv.hpp"
#include <string>

using namespace PMVS3;
using namespace std;

OShow::OShow(CfindMatch &findMatch) : m_fm(findMatch){

}

OShow::~OShow() {

}

cv::Mat OShow::show(vector<unsigned char> image, int height, int width, int isShow) {
    cv::Mat img = cv::Mat::zeros(cv::Size(height, width), CV_8UC3);
//        if (width*height*3 != image.size()) {
//            cerr << "error" << endl;
//            return img;
//        }
    int i = 0;
    for (int col = 0; col < height; col++) {
        for (int row = 0; row < width; row++) {
            cv::Vec3b bgr = img.at<cv::Vec3b>(row, col);
            bgr[0] = (int) image[i++];
            bgr[1] = (int) image[i++];
            bgr[2] = (int) image[i++];
            img.at<cv::Vec3b>(row, col) = bgr;
        }
    }
    if (isShow == 1) {
        cv::imshow("image", img);
        cv::waitKey(0);
    }
    cv::imshow("image", img);
    cv::waitKey(10);
    return img;
}

cv::Mat OShow::show(const CfindMatch& fm, int index, int level, int isShow) {
    vector<unsigned char> image = fm.m_pss.m_photos[index].getImage(level);
    int height = fm.m_pss.m_photos[index].getHeight(level);
    int width = fm.m_pss.m_photos[index].getWidth(level);
    cv::Mat img(height, width, CV_8UC3, cv::Scalar(255, 0, 0));
//        if (width*height*3 != image.size()) {
//            cerr << "error" << endl;
//            return img;
//        }
    int i = 0;
    for (int col = 0; col < height; col++) {
        for (int row = 0; row < width; row++) {
            cv::Vec3b bgr = img.at<cv::Vec3b>(row, col);
            bgr[0] = (int) image[i++];
            bgr[1] = (int) image[i++];
            bgr[2] = (int) image[i++];
            img.at<cv::Vec3b>(row, col) = bgr;
        }
    }
    if (isShow == 1) {
        cv::imshow("image", img);
        cv::waitKey(0);
    }
    cv::imshow("image", img);
    cv::waitKey(10);
    return img;
}

void OShow::showAll(const CfindMatch &fm, int level) {
    vector<Image::Cphoto> photos = fm.m_pss.m_photos;
    for (auto index:fm.m_pss.m_images) {
        Image::Cphoto photo = fm.m_pss.m_photos[index];
        cv::Mat img(photo.getHeight(level), photo.getWidth(level), CV_8UC3, cv::Scalar(255, 255, 255));
        int i = 0;
        vector<unsigned char> image = photo.getImage(level);
        int scount = image.size();
        for (int row = 0; row < photo.getHeight(level); row++) {
            for (int col = 0; col < photo.getWidth(level); col++) {
                cv::Vec3b bgr = img.at<cv::Vec3b>(row, col);
                bgr[2] = (int) image[i++];
                bgr[1] = (int) image[i++];
                bgr[0] = (int) image[i++];
                img.at<cv::Vec3b>(row, col) = bgr;
            }
        }
        for (int row = 0; row < fm.m_pos.m_gheights[index]; row++) {
            cv::line(img, cv::Point(0, row*fm.m_csize), cv::Point(photo.getWidth(level), row*fm.m_csize), cv::Scalar(255, 255, 255), 1);
        }
        for (int col = 0; col < fm.m_pos.m_gwidths[index]; col++) {
            cv::line(img, cv::Point(col*fm.m_csize, 0), cv::Point(col*fm.m_csize, photo.getHeight(level)), cv::Scalar(255, 255, 255), 1);
        }
        for (auto ppoints:fm.m_seed.m_ppoints[index]) {
            if (ppoints.empty()) continue;
            for (auto point:ppoints) {
                cv::circle(img, cv::Point(point->m_icoord[0], point->m_icoord[1]), 2, cv::Scalar(255 * point->m_type, 0, -255*(point->m_type-1)), 1);
            }
        }
        cv::imshow(to_string(index), img);
//        cv::waitKey(0);
    }


}




