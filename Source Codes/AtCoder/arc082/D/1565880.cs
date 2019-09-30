using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    ReadData re;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        re = new ReadData();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        int X = re.i();
        int K = re.i();
        int[] R = new int[K+1];
        for(int i=1;i<=K;i++){
            R[i] = re.i();
        }
        int Q = re.i();
        K++;
        int p = 0;
        int A1 = 0;
        int V1 = 0;
        int A2 = X;
        int V2 = X;
        for(int i=0;i<Q;i++){
            int T = re.i();
            int A = re.i();
            while(p < K-1 && R[p+1] < T){
                if(p % 2 == 0){
                    V1 -= R[p+1] - R[p];
                    if(V1 < 0){
                        A1 += -V1;
                        V1 = 0;
                    }
                    V2 -= R[p+1] - R[p];
                    if(V2 < 0){
                        A2 += -V2;
                        V2 = 0;
                    }
                }
                else{
                    V1 += R[p+1] - R[p];
                    if(V1 > X){
                        A1 -= V1-X;
                        V1 = X;
                    }
                    V2 += R[p+1] - R[p];
                    if(V2 > X){
                        A2 -= V2-X;
                        V2 = X;
                    }
                }
                p++;
            }
            int count = 0;
            if(A < A1){
                count = V1;
            }
            else if(A < A2){
                count = V1+A-A1;
            }
            else{
                count = V2;
            }
            if(p % 2 == 0){
                count = Math.Max(0,count-T+R[p]);
            }
            else{
                count = Math.Min(X,count+T-R[p]);
            }
            sb.Append(count+"\n");
        }
    }
}
class ReadData{
    string[] str;
    int counter;
    public ReadData(){
        counter = 0;
    }
    public string s(){
        if(counter == 0){
            str = Console.ReadLine().Split(' ');
            counter = str.Length;
        }
        counter--;
        return str[str.Length-counter-1];
    }
    public int i(){
        return int.Parse(s());
    }
    public long l(){
        return long.Parse(s());
    }
    public double d(){
        return double.Parse(s());
    }
    public int[] ia(int N){
        int[] ans = new int[N];
        for(int j=0;j<N;j++){
            ans[j] = i();
        }
        return ans;
    }
    public int[] ia(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        int[] ans = new int[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = int.Parse(str[j]);
        }
        return ans;
    }
    public long[] la(int N){
        long[] ans = new long[N];
        for(int j=0;j<N;j++){
            ans[j] = l();
        }
        return ans;
    }
    public long[] la(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        long[] ans = new long[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = long.Parse(str[j]);
        }
        return ans;
    }
    public double[] da(int N){
        double[] ans = new double[N];
        for(int j=0;j<N;j++){
            ans[j] = d();
        }
        return ans;
    }
    public double[] da(){
        str = Console.ReadLine().Split(' ');
        counter = 0;
        double[] ans = new double[str.Length];
        for(int j=0;j<str.Length;j++){
            ans[j] = double.Parse(str[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int[] f,int[] t){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<f.Length;j++){
            ans[f[j]].Add(t[j]);
            ans[t[j]].Add(f[j]);
        }
        return ans;
    }
    public List<int>[] g(int N,int M){
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
    public List<int>[] g(){
        int N = i();
        int M = i();
        List<int>[] ans = new List<int>[N];
        for(int j=0;j<N;j++){
            ans[j] = new List<int>();
        }
        for(int j=0;j<M;j++){
            int f = i()-1;
            int t = i()-1;
            ans[f].Add(t);
            ans[t].Add(f);
        }
        return ans;
    }
}