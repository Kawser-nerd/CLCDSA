using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    int N;
    int[] p;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        int[] a = new int[N-1];
        int[] b = new int[N-1];
        for(int i=0;i<N;i++){
            if(p[i] == 1){
                b[0] = i+1;
            }
            else if(p[i] == N){
                a[N-2] = i+1;
            }
            else{
                a[p[i]-2] = i+1;
                b[p[i]-1] = i+1;
            }
        }
        int[] A = new int[N];
        int[] B = new int[N];
        for(int i=0;i<N;i++){
            if(i == 0){
                A[i] = 1; 
            }
            else{
                A[i] = A[i-1]+a[i-1];
            }
        }
        for(int i=N-1;i>=0;i--){
            if(i == N-1){
                B[i] = 1;
            }
            else{
                B[i] = B[i+1]+b[i];
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N-1;i++){
            sb.Append(A[i]+" ");
        }
        sb.Append(A[N-1]+"\n");
        for(int i=0;i<N-1;i++){
            sb.Append(B[i]+" ");
        }
        sb.Append(B[N-1]+"\n");
        Console.Write(sb.ToString());
    }
    void getinput(){
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        p = new int[N];
        for(int i=0;i<N;i++){
            p[i] = int.Parse(str[i]);
        }
    }    
}