#ifndef PMVS3_PATCH_H
#define PMVS3_PATCH_H

#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include "../numeric/vec4.h"

namespace Patch {

class Cpatch {
 public:
  Cpatch(void) {
    m_ncc = -1.0;
    m_timages = 0;
    m_fix = 0;
    // dflag is initialized only once. if failed in one direction, we
    // never try that.
    // dflag 只初始化一次。 如果在一个方向上失败了，我们永远不会尝试。
    m_dflag = 0;

    // All non-class member variables need to be initialized so that
    // they aren't just uninitialized memory.
    // 所有非类成员变量都需要初始化，这样它们就不仅仅是未初始化的内存。
    m_flag = 0;
    m_id = 0;
    m_dscale = 0;
    m_ascale = 0;
    m_tmp = 0;
  }
  
  //----------------------------------------------------------------------
  // saved information 保存信息
  // 3D coordinates of the center of the patch
  // patch出中心的3D坐标
  Vec4f m_coord;
  // patch outward normal vector
  // patch法向量
  Vec4f m_normal;
  
  // associated image ids. first image id is the reference one. images
  // can be non-targetting image.
  // 关联图像集。 第一个图像 id 是参考图像。 图像可以是非目标图像。
  std::vector<int> m_images;
  std::vector<TVec2<int> > m_grids;
  
  // visible images. m_vimages must be targetting images.
  // 可见图像集。 m_vimage 必须是目标图像。
  std::vector<int> m_vimages;
  std::vector<TVec2<int> > m_vgrids;
  
  //----------------------------------------------------------------------
  inline float score(const float threshold) const{
    return std::max(0.0f, m_ncc - threshold) * (int)m_images.size();
  }
  inline float score2(const float threshold) const{
    return std::max(0.0f, m_ncc - threshold) * m_timages;
  }

  // average ncc
  // 平均ncc
  float m_ncc;
  // number of targetting images in m_images
  // m_images中目标图像的数量
  int m_timages;

  // flat for expansion 扩展标志
  // 0: not yet tested 还未尝试
  // 1: done 完成尝试
  int m_flag;

  // for directional flag
  // 方向标志
  unsigned char m_dflag;

  // fixed patch or not
  // patch修复标志
  char m_fix;
  
  // id number in m_ppatches
  int m_id;

  // scaling factor corresponding to one pixel difference
  float m_dscale;
  float m_ascale;
  
  float m_tmp;
};

typedef boost::shared_ptr<Cpatch> Ppatch;

struct Spatchcmp {
  bool operator()(const Ppatch& lhs, const Ppatch& rhs) {
    if (lhs.get() < rhs.get())
      return true;
    else
      return false;
  }
};
 
std::istream& operator >>(std::istream& istr, Patch::Cpatch& rhs);
std::ostream& operator <<(std::ostream& ostr, const Patch::Cpatch& rhs);
 
};

#endif // PMVS3_PATCH_H
