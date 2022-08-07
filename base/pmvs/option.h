#ifndef PMVS3_OPTION_H
#define PMVS3_OPTION_H

#include <string>
#include <vector>
#include <map>

namespace PMVS3 {
  
struct Soption{
  public:
  int m_level; // 图像金字塔中用于计算的级别
  int m_csize; // 控制重建的密度
  float m_threshold; // 	如果其相关的光度一致性测量高于此阈值，则补丁重建被视为成功并被保留
  int m_wsize; // 从每个图像中采样wsize x wsize像素颜色以计算光度一致性分数。例如，当wsize =7 时，在每张图像中采样 7x7=49 像素颜色。增加该值会导致更稳定的重建，但程序会变慢。
  int m_minImageNum; // 每个 3D 点必须至少在minImageNum 图像中可见才能重建
  int m_CPU; // 该软件支持线程，您可以指定机器中（虚拟）CPU 的数量
  float m_setEdge;
  int m_useBound;
  int m_useVisData; // PMVS 可以通过在root下创建名为“vis.dat”的文件并设置useVisData =1 来利用此类信息
  int m_sequence; // 有时，图像是按顺序给出的，在这种情况下，您可以强制软件仅使用具有相似索引的图像来重建一个点。序列给出了重建中使用的图像索引差异的上限。更具体地说，如果sequence = 3，图像5可以与图像2、3、4、6、7和8一起使用来重建点。
  
  float m_maxAngleThreshold; // 立体算法需要一定数量的基线才能进行准确的 3D 重建。我们通过每个 3D 点的可见相机方向之间的角度来测量基线。更具体地说，如果 2 个可见相机的方向之间的最大角度低于此阈值，则不会重建 3D 点。单位不是弧度，而是度数。降低此阈值可以对远离相机的场景进行更多重建，但在这些地方，结果往往会非常嘈杂。
  float m_quadThreshold; // 该软件通过查看其空间一致性来消除虚假的 3D 点。换言之，如果面向 3D 的点与其许多相邻的 3D 点一致，则该点不太可能被过滤掉。您可以使用quad控制此过滤步骤的阈值。增加阈值等同于降低阈值并允许更多噪声的重建。通常，无需调整此参数。
  
  std::string m_prefix;
  std::string m_option;
  int m_tflag; // 事实上是图像的数量-1
  std::vector<int> m_timages; // 目标图像
  int m_oflag;
  std::vector<int> m_oimages; // oimages 指的是其他图像，它还指定用于重建的图像索引

  std::map<int, int> m_dict;
  
  std::vector<int> m_bindexes;
  std::vector<std::vector<int> > m_visdata;
  std::vector<std::vector<int> > m_visdata2;
  
  Soption(void);
  
  void init(const std::string prefix, const std::string option);
  
  protected:
  void initOimages(void);
  void initBindexes(const std::string sbimages);
  void initVisdata(void);
  void initVisdata2(void);
};
};

#endif // PMVS3_OPTION_H
