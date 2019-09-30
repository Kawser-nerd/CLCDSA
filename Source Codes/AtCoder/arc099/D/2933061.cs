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
        long[] X = new long[4];
        long[] reX = new long[4];
        X[0] = 118306800;
        X[1] = 686550364;
        X[2] = 218792700;
        X[3] = 202607072;
        for(int i=0;i<4;i++){
            reX[i] = Pow(X[i],Define.mod-2);
        }
        int N = re.i();
        string S = re.s();
        //Si H(0) = Sj(0)
        long[] Place = new long[4];
        long[,] SJ = new long[N+1,4];
        for(int i=0;i<4;i++){
            Place[i] = 1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<4;j++){
                if(S[i] == '+'){
                    SJ[i+1,j] = (SJ[i,j] + Place[j]) % Define.mod; 
                }
                if(S[i] == '-'){
                    SJ[i+1,j] = (SJ[i,j] - Place[j] + Define.mod) % Define.mod;
                }
                if(S[i] == '<'){
                    SJ[i+1,j] = SJ[i,j];
                    Place[j] = Place[j] * reX[j] % Define.mod;
                }
                if(S[i] == '>'){
                    SJ[i+1,j] = SJ[i,j];
                    Place[j] = Place[j] * X[j] % Define.mod;
                }
            }
        }
        long[,] SiH = new long[N+1,4];
        for(int i=0;i<4;i++){
            Place[i] = 1;
        }
        for(int i=0;i<=N;i++){
            for(int j=0;j<4;j++){
                if(i != 0){
                    if(S[i-1] == '<'){
                        Place[j] = Place[j] * reX[j] % Define.mod;
                    }
                    if(S[i-1] == '>'){
                        Place[j] = Place[j] * X[j] % Define.mod;
                    }
                }
                SiH[i,j] = (SJ[i,j] + Place[j] * SJ[N,j]) % Define.mod;
            }
        }
        int[] C = new int[N+1];
        for(int i=0;i<=N;i++){
            C[i] = i;
        }
        Array.Sort(C,(x,y)=>Compare(x,y,SJ));
        long count = 0;
        for(int i=0;i<N;i++){
            int bf = 0;
            int bl = N+1;
            while(bf != bl){
                int bc = (bf+bl)/2;
                if(bc == N+1 || OK1(i,C[bc],SiH,SJ)){
                    bl = bc;
                }
                else{
                    bf = bc+1;
                }
            }
            int min = bf;
            bf = -1;
            bl = N;
            while(bf != bl){
                int bc = (bf+bl+1)/2;
                if(bc == -1 || OK2(i,C[bc],SiH,SJ)){
                    bf = bc;
                }
                else{
                    bl = bc-1;
                }
            }
            int max = bf;
            count += max - min + 1;
        }
        sb.Append(count+"\n");
    }
    bool OK1(int i,int v,long[,] SiH,long[,] SJ){
        for(int j=0;j<4;j++){
            if(SiH[i,j] > SJ[v,j]){
                return false;
            }
            if(SiH[i,j] < SJ[v,j]){
                return true;
            }
        }
        return i < v;
    }
    bool OK2(int i,int v,long[,] SiH,long[,] SJ){
        for(int j=0;j<4;j++){
            if(SiH[i,j] > SJ[v,j]){
                return true;
            }
            if(SiH[i,j] < SJ[v,j]){
                return false;
            }
        }
        return true;
    }
    int Compare(int x,int y,long[,] S){
        for(int i=0;i<4;i++){
            if(S[x,i] > S[y,i]){
                return 1;
            }
            if(S[x,i] < S[y,i]){
                return -1;
            }
        }
        return x - y;
    }
    long Pow(long x,long r){
        if(r == 0){
            return 1;
        }
        if(r % 2 == 0){
            long t = Pow(x,r/2);
            return t*t%Define.mod;
        }
        return Pow(x,r-1)*x%Define.mod;
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