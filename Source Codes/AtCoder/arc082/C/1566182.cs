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
        int N = re.i();
        int[] X = new int[N];
        int[] Y = new int[N];
        for(int i=0;i<N;i++){
            X[i] = re.i();
            Y[i] = re.i();
        }
        long[] Po = new long[N+1];
        Po[0] = 1;
        for(int i=1;i<=N;i++){
            Po[i] = Po[i-1] * 2 % Define.mod;
        }
        long count = Po[N];
        count += Define.mod - (1 + N);
        count %= Define.mod;
        Data[] D = new Data[N*(N-1)/2];
        int c = 0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int x = X[i] - X[j];
                int y = Y[i] - Y[j];
                D[c] = new Data(x,y,i,j);
                c++;
            }
        }
        Array.Sort(D,(a,b)=>(a.x == 0 ? -100000000 : b.x*a.y) - (b.x == 0 ? -100000000 : a.x*b.y));
        int[] A = new int[N];
        int[] B = new int[N];
        for(int i=0;i<N;i++){
            A[i] = -1;
            B[i] = -1;
        }
        for(int i=0;i<c;i++){
            Data d = D[i];
            int p = d.p1;
            if(A[p] == -1){
                A[p] = i;
                B[p] = 1;
            }
            else if(SameR(d,D[A[p]])){
                if(B[p] != -1){
                    B[p]++;
                }
            }
            else{
                count += Define.mod - Po[B[p]+1] + (2 + B[p]);
                count %= Define.mod;
                A[p] = i;
                B[p] = 1;
            }
            p = d.p2;
            if(A[p] != -1 && !SameR(d,D[A[p]])){
                count += Define.mod - Po[B[p]+1] + (2 + B[p]);
                count %= Define.mod;
            }
            A[p] = i;
            B[p] = -1;
        }
        for(int i=0;i<N;i++){
            count += Define.mod - Po[B[i]+1] + (2 + B[i]);
            count %= Define.mod;
        }
        sb.Append(count+"\n");
    }
    bool SameR(Data a,Data b){
        return (a.x == 0 ? -100000000 : b.x*a.y) == (b.x == 0 ? -100000000 : a.x*b.y);
    }
}
class Data{
    public int x;
    public int y;
    public int p1;
    public int p2;
    public Data(int x0,int y0,int i,int j){
        if(x0 > 0){
            x = x0;
            y = y0;
        }
        else{
            x = -x0;
            y = -y0;
        }
        p1 = i;
        p2 = j;
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
public static class Define{
    public const long mod = 998244353;
}