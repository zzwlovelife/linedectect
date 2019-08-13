Hough变换 线检测

https://blog.csdn.net/poem_qianmo/article/details/26977557

关键函数：
此函数在HoughLines的基础上末尾加了一个代表Probabilistic（概率）的P，表明它可以采用累计概率霍夫变换（PPHT）来找出二值图像中的直线。


C++: void HoughLinesP(InputArray image, OutputArray lines, double rho, double theta, int threshold, double minLineLength=0, double maxLineGap=0 )


第一个参数，InputArray类型的image，输入图像，即源图像，需为8位的单通道二进制图像，可以将任意的源图载入进来后由函数修改成此格式后，再填在这里。
第二个参数，InputArray类型的lines，经过调用HoughLinesP函数后后存储了检测到的线条的输出矢量，每一条线由具有四个元素的矢量(x_1,y_1, x_2, y_2）  表示，其中，(x_1, y_1)和(x_2, y_2) 是是每个检测到的线段的结束点。
第三个参数，double类型的rho，以像素为单位的距离精度。另一种形容方式是直线搜索时的进步尺寸的单位半径。
第四个参数，double类型的theta，以弧度为单位的角度精度。另一种形容方式是直线搜索时的进步尺寸的单位角度。
第五个参数，int类型的threshold，累加平面的阈值参数，即识别某部分为图中的一条直线时它在累加平面中必须达到的值。大于阈值threshold的线段才可以被检测通过并返回到结果中。
第六个参数，double类型的minLineLength，有默认值0，表示最低线段的长度，比这个设定参数短的线段就不能被显现出来。
第七个参数，double类型的maxLineGap，有默认值0，允许将同一行点与点之间连接起来的最大的距离。
