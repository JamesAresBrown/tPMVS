#ifndef PMVS3_FINDMATCH_H
#define PMVS3_FINDMATCH_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <mutex>
#include <queue>
#include "patch.h"
#include <boost/shared_ptr.hpp>
#include "tinycthread.h"
#include "rwmutex.h"

#include "../image/photoSetS.h"
#include "patchOrganizerS.h"
#include "seed.h"
#include "expand.h"
#include "filter.h"
#include "optim.h"
#include "option.h"

#include "opencvShow.h"

namespace PMVS3 {
  
class CfindMatch {
 public:
  CfindMatch(void);
  virtual ~CfindMatch();

  void init(const PMVS3::Soption& option);
  void run(void);
  void write(const std::string prefix, bool bExportPLY, bool bExportPatch, bool bExportPSet);
  
  int insideBimages(const Vec4f& coord) const;

  int isNeighborRadius(const Patch::Cpatch& lhs, const Patch::Cpatch& rhs,
                       const float hunit, const float neighborThreshold,
                       const float radius) const;
  
  int isNeighbor(const Patch::Cpatch& lhs, const Patch::Cpatch& rhs,
                 const float hunit, const float neighborThreshold) const;
  int isNeighbor(const Patch::Cpatch& lhs, const Patch::Cpatch& rhs,
                 const float neighborThreshold) const;
  
  //----------------------------------------------------------------------
  // num of target images 目标图像数目
  int m_tnum;
  // num of total images 总图像数量
  int m_num;
  // target images 目标图像
  std::vector<int> m_timages;
  // other images where patches are not computed 其他没有计算patch的图像
  std::vector<int> m_oimages;
  // total images 总图像
  std::vector<int> m_images;
  
  // prefix 字首
  std::string m_prefix;
  // level
  int m_level;
  // cellsize
  int m_csize;
  // nccThreshold NCC阈值
  float m_nccThreshold;  
  // windows size 窗口大小
  int m_wsize;
  // mininum image num threshold 最少图像阈值
  int m_minImageNumThreshold;
  // use edge detection or not 是否使用边缘检测
  float m_setEdge;
  // bounding images
  std::vector<int> m_bindexes;
  // visdata from SfM. m_num x m_num matrix
  std::vector<std::vector<int> > m_visdata;
  // an array of relavant images
  std::vector<std::vector<int> > m_visdata2;  
  // sequence Threshold
  int m_sequenceThreshold;
  // CPU
  int m_CPU;
  // Threshold on filterQuad
  float m_quadThreshold;
  
  // Maximum number of images used in the optimization 优化中使用的最大图像数量
  int m_tau; // 优化中使用的最大图像数量

  // If patches are dense or not, that is, if we use check(patch) after patch optimization 补丁是否密集，即补丁优化后是否使用check(patch)
  int m_depth; //补丁是否密集，即补丁优化后是否使用check(patch)
  
  //----------------------------------------------------------------------
  // Thresholds
  //----------------------------------------------------------------------
  // For first feature matching. Images within this angle are used in matching.
  // 对于第一个特征匹配。 该角度内的图像用于匹配。
  float m_angleThreshold0;
  // tigher angle
  float m_angleThreshold1;

  // Number of success generation from each seed point
  // 每个种子点的成功生成次数
  int m_countThreshold0;
  // Number of counts, expansion can be tried
  int m_countThreshold1;

  // Number of trials for each cell in seed 种子中每个细胞的试验次数
  int m_countThreshold2;
  
  // Parameter for isNeighbor in findemptyblocks
  // findemptyblocks 中 isNeighbor 的参数
  float m_neighborThreshold;
  // Parameter for isNeighbor in filterOutside
  // findemptyblocks 中 isNeighbor 的参数
  float m_neighborThreshold1;
  // Parameter for filterNeighbor
  // filterNeighbor 的参数
  float m_neighborThreshold2;

  // ncc threshold before optim
  // 优化前的 ncc 阈值
  float m_nccThresholdBefore;
  // Maximum angle of images must be at least as large as this
  // 图像的最大角度必须至少与此一样大
  float m_maxAngleThreshold;

  // visibility consistency threshold
  float m_visibleThreshold;
  float m_visibleThresholdLoose;
    
  // Epipolar distance in seed generation
  // 种子生成中的极距
  float m_epThreshold;
  
  //----------------------------------------------------------------------
  // For threads related
  //----------------------------------------------------------------------
  // General lock
  mtx_t m_lock;
  // For each image
  std::vector<std::mutex> m_imageLocks;
  std::vector<std::mutex> m_countLocks;
  // count
  int m_count;
  // jobs
  std::list<int> m_jobs;
  // job unit
  int m_junit;

  //----------------------------------------------------------------------
  // Core members
  //----------------------------------------------------------------------
  // Images 组织图片
  Image::CphotoSetS m_pss;
  // Patch organizer 组织面片
  CpatchOrganizerS m_pos;
  
  // Seed generator 生成种子
  Cseed m_seed;
  // Patch expansion 面片扩张
  Cexpand m_expand;
 public:
  // Patch filter 面片剔除
  Cfilter m_filter;
  // Patch optimizer 面片优化
  Coptim m_optim;

  int m_debug;
 protected:
  void init(void);
  void initTargets(void); // 临界点
  void updateThreshold(void);
  void initImages(void);
};
};

#endif // PMVS3_FINDMATCH_H
