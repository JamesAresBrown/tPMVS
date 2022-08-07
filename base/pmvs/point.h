#ifndef PMVS3_POINT_H
#define PMVS3_POINT_H

#include "../numeric/vec4.h"
#include "../numeric/mat3.h"

namespace PMVS3 {
class Cpoint {
 public:
  Cpoint(void);
  virtual ~Cpoint();
  
  Vec3f m_icoord; // 2D坐标
  float m_response; // 响应值

  // 0: Harris
  // 1: DoG
  int m_type; // 角点/斑点标识

  // tempporary variable, used to store original imageid in initial match
  // 临时变量，用于存储初始匹配时的原始图像id
  int m_itmp;

  // 3D coordinate
  Vec4f m_coord; // 3D坐标
  
  bool operator < (const Cpoint& rhs) const {
    return m_response < rhs.m_response;
  }

  friend std::istream& operator >>(std::istream& istr, Cpoint& rhs);
  friend std::ostream& operator <<(std::ostream& ostr, const Cpoint& rhs);
};

bool SortCpoint(const Cpoint& a, const Cpoint& b);

std::istream& operator >>(std::istream& istr, Cpoint& rhs);
std::ostream& operator <<(std::ostream& ostr, const Cpoint& rhs);
};

#endif //PMVS3_POINT_H
