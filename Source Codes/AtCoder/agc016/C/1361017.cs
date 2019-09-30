using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int H = int.Parse(str[0]);
        int W = int.Parse(str[1]);
        int h = int.Parse(str[2]);
        int w = int.Parse(str[3]);
        if(H % h == 0 && W % w == 0){
            sb.Append("No\n");
            return;
        }
        int[,] A = new int[H,W];
        if(H % h != 0){
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    A[i,j] = i % h == h - 1 ? - 1 - 10000*(h - 1) : 10000; 
                }
            }
        }
        else{
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    A[i,j] = j % w == w - 1 ? - 1 - 10000*(w - 1) : 10000; 
                }
            }
        }
        sb.Append("Yes\n");
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                sb.Append(A[i,j]+" ");
            }
            sb.Append("\n");
        }
    }
}