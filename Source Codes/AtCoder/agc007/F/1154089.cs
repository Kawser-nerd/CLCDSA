using System;
using System.Text;
using System.Collections.Generic;
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
        int N = int.Parse(Console.ReadLine());
        string s1 = Console.ReadLine();
        string s2 = Console.ReadLine();
        if(s1 == s2){
            sb.Append("0\n");
        }
        else{
            List<int> stacki = new List<int>();
            List<int> stacko = new List<int>();
            {
                char c = s2[N-1];
                int p = N-1;
                bool b = true;
                for(int i=N-1;i>=-1;i--){
                    if(i == -1 || s2[i] != c){
                        stacko.Add(i+1);
                        p = Math.Min(p,i+1);
                        while(p >= 0 && s1[p] != c){
                            p--;
                        }
                        if(p == -1){
                            b = false;
                            break;
                        }
                        stacki.Add(p);
                        if(i != -1){
                            c = s2[i];
                        }
                    }
                }
                if(!b){
                    sb.Append("-1\n");
                    return;
                }
            }
            int max = 0;
            int d = 0;
            int spi = stacki.Count-1;
            int spo = stacko.Count-1;
            for(int i=0;i<N;i++){
                if(spi >= 0 && i == stacki[spi]){
                    spi--;
                    d++;
                }
                while(spo >= 0 && i == stacko[spo] + d - 1){
                    spo--;
                    d--;
                }
                max = Math.Max(max,d);
            }
            sb.Append(max+1+"\n");
        }
    }
}