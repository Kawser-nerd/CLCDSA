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
        string S = re.s();
        Data[] D1 = new Data[1<<N];
        Data[] D2 = new Data[1<<N];
        for(int i=0;i<1<<N;i++){
            Hash s1 = new Hash();
            Hash s2 = new Hash();
            Hash s3 = new Hash();
            Hash s4 = new Hash();
            for(int j=0;j<N;j++){
                if(((1 << j) & i) != 0){
                    s1.Add(S[j]);
                    s3.Add(S[2*N-1-j]);
                }
                else{
                    s2.Add(S[j]);
                    s4.Add(S[2*N-1-j]);
                }
            }
            D1[i] = new Data(s1,s2);
            D2[i] = new Data(s3,s4);
        }
        Array.Sort(D2,(x,y)=>(Compare(x.H1,y.H1) == 0 ? Compare(x.H2,y.H2) : Compare(x.H1,y.H1)));
        long count = 0;
        for(int i=0;i<1<<N;i++){
            int bf = 0;
            int bl = 1<<N;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(bc == (1 << N) || Compare(D1[i],D2[bc]) <= 0){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            int min = bf;
            bf = -1;
            bl = (1<<N)-1;
            while(bf != bl){
                int bc = (bf+bl+1)/2;
                if(bc == -1 || Compare(D1[i],D2[bc]) >= 0){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            int max = bf;
            count += Math.Max(0,max-min+1);
        }
        sb.Append(count+"\n");
    }
    public int Compare(Data x,Data y){
        return (Compare(x.H1,y.H1) == 0 ? Compare(x.H2,y.H2) : Compare(x.H1,y.H1));
    }
    public int Compare(Hash x,Hash y){
        if(x.size != y.size){
            return x.size - y.size;
        }
        if(x.H1 > y.H1){
            return 1;
        }
        if(x.H1 < y.H1){
            return -1;
        }
        if(x.H2 > y.H2){
            return 1;
        }
        if(x.H2 < y.H2){
            return -1;
        }
        if(x.H3 > y.H3){
            return 1;
        }
        if(x.H3 < y.H3){
            return -1;
        }
        return 0;
    }
}
class Hash{
    const long mod1 = 1000000007;
    const long mod2 = 1000000009;
    const long mod3 = 924844033;
    const long D1 = 1009;
    const long D2 = 2690;
    const long D3 = 345;
    public long H1;
    public long H2;
    public long H3;
    public int size;
    public Hash(){
        H1 = 0;
        H2 = 0;
        H3 = 0;
        size = 0;
    }
    public void Add(char c){
        H1 *= D1;
        H1 += c;
        H1 %= mod1;
        H2 *= D2;
        H2 += c;
        H2 %= mod2;
        H3 *= D3;
        H3 += c;
        H3 %= mod3;
        size++;
    }
}
struct Data{
    public Hash H1;
    public Hash H2;
    public Data(Hash h1,Hash h2){
        H1 = h1;
        H2 = h2;
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
    public const long mod = 1000000007;
}
public static class Debug{
    public static void Print(double[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(double[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(long[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(long[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
    public static void Print(int[,,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                for(int l=0;l<k.GetLength(2);l++){
                    Console.Write(k[i,j,l]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[,] k){
        for(int i=0;i<k.GetLength(0);i++){
            for(int j=0;j<k.GetLength(1);j++){
                Console.Write(k[i,j]+" ");
            }
            Console.WriteLine();
        }
    }
    public static void Print(int[] k){
        for(int i=0;i<k.Length;i++){
            Console.WriteLine(k[i]);
        }
    }
}