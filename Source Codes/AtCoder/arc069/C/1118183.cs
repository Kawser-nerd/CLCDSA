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
        string[] str = Console.ReadLine().Split(' ');
        long[] A = new long[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        int[] a = new int[N];
        for(int i=0;i<N;i++){
            a[i] = i;
        }
        Array.Sort(a,(x,y)=>(A[x] < A[y] ? 1 : (A[x] == A[y] ? 0 : -1)));
        long count = A[a[0]];
        int nowp = a[0];
        long[] ans = new long[N];
        for(int i=1;i<N;i++){
            if(nowp > a[i]){
                ans[nowp] = count - i*A[a[i]];
                count = (i+1)*A[a[i]];
                nowp = a[i];
            }
            else{
                count += A[a[i]];
            }
        }
        ans[nowp] = count;
        for(int i=0;i<N;i++){
            sb.Append(ans[i]+"\n");
        }
    }
}