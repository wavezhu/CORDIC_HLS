# CORDIC_HLS

根据Xilinx提供的[教学课程](https://v.qq.com/x/page/u0516mz22q4.html)，建立相应的工程，添加HLS程序和测试数据。相关原理教程请查看[博客](https://github.com/wavezhu/CORDIC_HLS)。
  
实验程序存放在hls_code目录中。使用ViVado HLS运行run_hls.tcl脚本，就能建立工程进行仿真。工程中使用的测试数据存放在script目录中，使用Python语言编写。
  
顶层函数为cir_cordic，输入参数为目标角度(full_alpha)，输出参数为正弦值(sin_out)和余弦值(cos_out)。函数首先进行目标角度区间转换，将角度转换至$\left (-\pi,\pi  \right ) $区间。然后进行移位迭代计算正余弦值。最后将得到结果值转换至原始区间，得到最终结果。