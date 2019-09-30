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
        int[] A = new int[N];
        bool[] R = new bool[N];
        {
            string[] str0 = Console.ReadLine().Split(' ');
            string[] str1 = Console.ReadLine().Split(' ');
            string[] str2 = Console.ReadLine().Split(' ');
            for(int i=0;i<N;i++){
                int x = int.Parse(str0[i]);
                int y = int.Parse(str1[i]);
                int z = int.Parse(str2[i]);
                if(x+1 == y && y+1 == z && z%3 == 0){
                    A[i] = y/3;
                    R[i] = true;
                }
                else if(x-1 == y && y-1 == z && x%3 == 0){
                    A[i] = y/3;
                    R[i] = false;
                }
                else{
                    sb.Append("No\n");
                    return;
                }
                if((A[i] - i) % 2 != 0){
                    sb.Append("No\n");
                    return;
                }
            }
        }
        {
            int[] P = new int[(N+1)/2];
            int[] E = new int[(N+1)/2];
            bool b = true;
            for(int i=0;i<(N+1)/2;i++){
                P[A[i*2]/2] = i;
                E[i] = A[i*2]/2;
            }
            for(int i=0;i<(N+1)/2;i++){
                if(P[i] != i){
                    b = !b;
                    int temp = E[i];
                    P[E[i]] = P[i];
                    E[i] = E[P[i]];
                    E[P[i]] = temp;
                    P[i] = i;
                }
            }
            for(int i=0;i<N/2;i++){
                if(!R[i*2+1]){
                    b = !b;
                }
            }
            if(!b){
                sb.Append("No\n");
                return;
            }
        }
        {
            int[] P = new int[N/2];
            int[] E = new int[N/2];
            bool b = true;
            for(int i=0;i<N/2;i++){
                P[A[i*2+1]/2] = i;
                E[i] = A[i*2+1]/2;
            }
            for(int i=0;i<N/2;i++){
                if(P[i] != i){
                    b = !b;
                    int temp = E[i];
                    P[E[i]] = P[i];
                    E[i] = E[P[i]];
                    E[P[i]] = temp;
                    P[i] = i;
                }
            }
            for(int i=0;i<(N+1)/2;i++){
                if(!R[i*2]){
                    b = !b;
                }
            }
            if(!b){
                sb.Append("No\n");
                return;
            }
        }
        sb.Append("Yes\n");
    }
}