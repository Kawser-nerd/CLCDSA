using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    long[] Pow;
    int[] Normal;
    int[] NoZero;
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
        Pow = new long[19];
        Pow[0] = 1;
        for(int i=1;i<19;i++){
            Pow[i] = 10*Pow[i-1];
        }
        Normal = new int[19];
        NoZero = new int[19];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(i != 0){
                    NoZero[j-i+9]++;
                }
                Normal[j-i+9]++;
            }
        }
        long count = 0;
        long D = long.Parse(Console.ReadLine());
        for(int i=0;i<19;i++){
            count += Calc(D,i,true);
        }
        sb.Append(count+"\n");
    }
    long Calc(long N,int M,bool b){
        if(M == 0){
            return N == 0 ? 1 : 0;
        }
        if(M == 1){
            if(N == 0){
                return b ? 9 : 10;
            }
            else{
                return 0;
            }
        }
        long mo = Pow[M-1]-1;
        long count = 0;
        for(int i=-9;i<10;i++){
            if((N - mo*i) % 10 == 0){
                count += (b ? NoZero[i+9] : Normal[i+9])*Calc((N - mo*i) / 10,M-2,false);
            }
        }
        return count;
    }
}