#include <stdio.h>
#include <string.h>
#include <termios.h>  /* 与终端有关的函数声明*/ 
/* Linux, not Windowns. 大家可以查看一下 man stty 命令*/
int  main()
{
    char buf[20];
    int num,i;
    struct termios new;  /* 控制终端状态的数据结构，可 man termios 查看*/
    struct termios old;
 
    tcgetattr(0,&old);   /* 得到当前的终端状态 */
    new = old;
    /* ICANON取反，表示关闭输入行编辑模式，这样我们可以直接read字符，不用等着瞧回车.
     * ISIG取反，表示禁止信号，这样Crtl+c Crtl+s 就不会产生信号了，当你发现用户键入
     * Crtl+c后，你可以自定义一个动作
     */
    new.c_lflag &= ~(ICANON | ISIG);
    tcsetattr(0,TCSANOW,&new);  /* 应用新的设置*/ 
    num = read(0,buf,sizeof buf);  /* 从标准输入读取字符*/
    buf[num] = '\0';
    printf("\n");
    printf("buf:%s\n",buf);  /* 控制字符打印不出来，所以不要相信printf函数*/
    printf("debug_> we get %d chars [",num);
    for(i = 0; i < num; i++) {  /* ASCII值才是我们想要的，就是用它来比较是那个键按下了*/
        printf("%d ",buf[i]);
    }
    printf("]\n");
     
    /*
     * your codes  ,你可以试试Crtl+f ,  Alt+a 上下左右键的字符编码
     */
      
    tcsetattr(0,TCSANOW,&old);  /* 如果要推出程序，恢复旧的设置 */

    return 0; 
}
