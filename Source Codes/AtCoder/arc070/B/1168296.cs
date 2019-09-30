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
        int K = int.Parse(str[1]);
        int[] A = new int[N];
        str = Console.ReadLine().Split(' ');
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        Array.Sort(A);
        int bf = 0;
        int bl = N;
        while(bf != bl){
            int bc = (bf+bl)/2;
            bool OK;
            if(bc == N || K <= A[bc]){
                OK = true;
            }
            else{
                bool[] b = new bool[K];
                b[0] = true;
                for(int i=0;i<N;i++){
                    if(i != bc){
                        for(int j=K-1;j>=A[i];j--){
                            if(b[j-A[i]]){
                                b[j] = true;
                            }
                        }
                    }
                }
                OK = false;
                for(int i=K-A[bc];i<K;i++){
                    OK |= b[i];
                }
            }
            if(OK){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        sb.Append(bf+"\n");
    }
}