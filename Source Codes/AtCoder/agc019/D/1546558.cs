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
        string A = Console.ReadLine();
        string B = Console.ReadLine();
        {
            bool b = false;
            for(int i=0;i<B.Length;i++){
                b |= B[i] == '1';
            }
            if(!b){
                if(A == B){
                    sb.Append("0\n");
                }
                else{
                    sb.Append("-1\n");
                }
                return;
            }
        }
        int N = B.Length;
        int[] Left = new int[N];
        int[] Right = new int[N];
        for(int i=0;i<N;i++){
            Left[i] = B[i] == '1' ? 0 : N;
            Right[i] = B[i] == '1' ? 0 : N;
        }
        for(int i=0;i<N;i++){
            Left[i] = Math.Min(Left[i],i == 0 ? Left[N-1]+1 : Left[i-1]+1); 
        }
        for(int i=0;i<N;i++){
            Left[i] = Math.Min(Left[i],i == 0 ? Left[N-1]+1 : Left[i-1]+1); 
        }
        for(int i=N-1;i>=0;i--){
            Right[i] = Math.Min(Right[i],i == N-1 ? Right[0]+1 : Right[i+1]+1); 
        }
        for(int i=N-1;i>=0;i--){
            Right[i] = Math.Min(Right[i],i == N-1 ? Right[0]+1 : Right[i+1]+1); 
        }
        int count = 4*N;
        for(int i=0;i<N;i++){
            int c = 0;
            int[] DL;
            int[] DR;
            {
                int[] L = new int[N];
                int[] R = new int[N];
                for(int j=0;j<N;j++){
                    if((i + j < N ? A[i+j] : A[i+j-N]) != B[j]){
                        L[j] = (i + j < N ? Left[i+j] : Left[i+j-N]);
                        R[j] = (i + j < N ? Right[i+j] : Right[i+j-N]);
                        c++;
                    }
                }
                Array.Sort(L,R);
                List<int> bL = new List<int>();
                List<int> bR = new List<int>();
                bL.Add(L[N-1]);
                bR.Add(R[N-1]);
                for(int j=N-2;j>=0;j--){
                    if(R[j] > bR[bR.Count-1]){
                        bL.Add(L[j]);
                        bR.Add(R[j]);
                    }
                }
                DL = bL.ToArray();
                DR = bR.ToArray();
            }
            int d = 4*N;
            int n = DL.Length;
            {
                int d1 = DL[0];
                int d2 = Math.Max(DL[0] - i,i - DL[0]);
                d = Math.Min(d,d1 + d2);
            }
            {
                int d1 = DL[0];
                int d2 = DL[0] + N - i;
                d = Math.Min(d,d1 + d2);
            }
            {
                int d1 = DR[n-1];
                int d2 = Math.Max(DR[n-1] - (N - i),(N - i) - DR[n-1]);
                d = Math.Min(d,d1 + d2);
            }
            {
                int d1 = DR[n-1];
                int d2 = DR[n-1] + i;
                d = Math.Min(d,d1 + d2);
            }
            for(int j=0;j<n-1;j++){
                {
                    int d1 = DR[j];
                    int d2 = DR[j] + DL[j+1];
                    int d3 = Math.Max(DL[j+1]-i,i-DL[j+1]);
                    d = Math.Min(d,d1 + d2 + d3);
                }
                {
                    int d1 = DL[j+1];
                    int d2 = DL[j+1] + DR[j];
                    int d3 = Math.Max(DR[j]-(N-i),(N-i)-DR[j]);
                    d = Math.Min(d,d1 + d2 + d3);
                }
            }
            count = Math.Min(count,d + c);
        }
        sb.Append(count+"\n");
    }
}