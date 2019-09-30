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
        int N = int.Parse(str[0]);
        long W = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        long w1 = int.Parse(str[0]);
        List<long>[] v = new List<long>[4];
        for(int i=0;i<4;i++){
            v[i] = new List<long>();
        }
        v[0].Add(int.Parse(str[1]));
        for(int i=1;i<N;i++){
            str = Console.ReadLine().Split(' ');
            v[int.Parse(str[0])-w1].Add(int.Parse(str[1]));
        }
        long[][] V = new long[4][];
        for(int i=0;i<4;i++){
            V[i] = v[i].ToArray();
            Array.Sort(V[i],(a,b)=>(a>b ? -1 : (a<b ? 1 : 0)));
        }
        long count = 0;
        long sum1 = 0;
        long nw1 = 0;
        for(int i=0;i<=V[0].Length;i++){
            if(nw1 > W){
                break;
            }
            long sum2 = sum1;
            long nw2 = nw1;
            for(int j=0;j<=V[1].Length;j++){
                if(nw2 > W){
                    break;
                }
                long sum3 = sum2;
                long nw3 = nw2;
                for(int k=0;k<=V[2].Length;k++){
                    if(nw3 > W){
                        break;
                    }
                    long sum4 = sum3;
                    long nw4 = nw3;
                    for(int l=0;l<=V[3].Length;l++){
                        if(nw4 > W){
                            break;
                        }
                        count = Math.Max(count,sum4);
                        if(l != V[3].Length){
                            sum4 += V[3][l];
                            nw4 += w1+3;
                        }
                    }
                    if(k != V[2].Length){
                        sum3 += V[2][k];
                        nw3 += w1+2;
                    }
                }
                if(j != V[1].Length){
                    sum2 += V[1][j];
                    nw2 += w1+1;
                }
            }
            if(i != V[0].Length){
                sum1 += V[0][i];
                nw1 += w1;
            }
        }
        sb.Append(count+"\n");
    }
}