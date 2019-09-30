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
        int Q = int.Parse(str[2]);
        bool[,] b = new bool[H,W];
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                b[i,j] = s[j] == '1';
            }
        }
        int[,] sum = new int[H,W];
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(i == 0 && j == 0){
                    sum[i,j] = b[i,j] ? 1 : 0;
                }
                else if(i == 0){
                    sum[i,j] = sum[i,j-1] + (b[i,j] ? 1 : 0);
                }
                else if(j == 0){
                    sum[i,j] = sum[i-1,j] + (b[i,j] ? 1 : 0);
                }
                else{
                    sum[i,j] = sum[i-1,j] + sum[i,j-1] - sum[i-1,j-1] + (b[i,j] ? 1 : 0);
                }
            }
        }
        int[,] Wsum = new int[H,W-1];
        for(int i=0;i<H;i++){
            for(int j=0;j<W-1;j++){
                if(i == 0 && j == 0){
                    Wsum[i,j] = (b[i,j] && b[i,j+1]) ? 1 : 0;
                }
                else if(i == 0){
                    Wsum[i,j] = Wsum[i,j-1] + ((b[i,j] && b[i,j+1]) ? 1 : 0);
                }
                else if(j == 0){
                    Wsum[i,j] = Wsum[i-1,j] + ((b[i,j] && b[i,j+1]) ? 1 : 0);
                }
                else{
                    Wsum[i,j] = Wsum[i-1,j] + Wsum[i,j-1] - Wsum[i-1,j-1] + ((b[i,j] && b[i,j+1]) ? 1 : 0);
                }
            }
        }
        int[,] Hsum = new int[H-1,W];
        for(int i=0;i<H-1;i++){
            for(int j=0;j<W;j++){
                if(i == 0 && j == 0){
                    Hsum[i,j] = (b[i,j] && b[i+1,j]) ? 1 : 0;
                }
                else if(i == 0){
                    Hsum[i,j] = Hsum[i,j-1] + ((b[i,j] && b[i+1,j]) ? 1 : 0);
                }
                else if(j == 0){
                    Hsum[i,j] = Hsum[i-1,j] + ((b[i,j] && b[i+1,j]) ? 1 : 0);
                }
                else{
                    Hsum[i,j] = Hsum[i-1,j] + Hsum[i,j-1] - Hsum[i-1,j-1] + ((b[i,j] && b[i+1,j]) ? 1 : 0);
                }
            }
        }
        for(int i=0;i<Q;i++){
            str = Console.ReadLine().Split(' ');
            int H1 = int.Parse(str[0])-1;
            int H2 = int.Parse(str[2])-1;
            int W1 = int.Parse(str[1])-1;
            int W2 = int.Parse(str[3])-1;
            long count = 0;
            count += sum[H2,W2];
            if(H1 != 0 && W1 != 0){
                count -= sum[H2,W1-1] + sum[H1-1,W2] - sum[H1-1,W1-1];
            }
            else if(H1 != 0){
                count -= sum[H1-1,W2];
            }
            else if(W1 != 0){
                count -= sum[H2,W1-1];
            }
            if(H1 != H2){
                count -= Hsum[H2-1,W2];
                if(H1 != 0 && W1 != 0){
                    count += Hsum[H2-1,W1-1] + Hsum[H1-1,W2] - Hsum[H1-1,W1-1];
                }
                else if(H1 != 0){
                    count += Hsum[H1-1,W2];
                }
                else if(W1 != 0){
                    count += Hsum[H2-1,W1-1];
                }
            }
            if(W1 != W2){
                count -= Wsum[H2,W2-1];
                if(H1 != 0 && W1 != 0){
                    count += Wsum[H2,W1-1] + Wsum[H1-1,W2-1] - Wsum[H1-1,W1-1];
                }
                else if(H1 != 0){
                    count += Wsum[H1-1,W2-1];
                }
                else if(W1 != 0){
                    count += Wsum[H2,W1-1];
                }
            }
            sb.Append(count+"\n");
        }
    }
}