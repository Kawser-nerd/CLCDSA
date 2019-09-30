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
        string S = re.s();
        if(S.Length <= 4){
            sb.Append(SolveSimple(S)+"\n");
            return;
        }
        {
            bool AllSame = true;
            for(int i=0;i<S.Length-1;i++){
                AllSame &= S[i] == S[i+1];
            }
            if(AllSame){
                sb.Append("1\n");
                return;
            }
        }
        long[,,,] DP = new long[S.Length,3,3,2];
        DP[0,0,0,0] = 1;
        DP[0,1,1,0] = 1;
        DP[0,2,2,0] = 1;
        for(int i=0;i<S.Length-1;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        DP[i+1,l,(k+l) % 3,j == l ? 1 : 0] = (DP[i+1,l,(k+l) % 3,j == l ? 1 : 0] + DP[i,j,k,0]) % Define.mod;
                        DP[i+1,l,(k+l) % 3,1] = (DP[i+1,l,(k+l) % 3,1] + DP[i,j,k,1]) % Define.mod; 
                    }
                }
            }
        }
        bool alldiff = true;
        int c = 0;
        for(int i=0;i<S.Length-1;i++){
            alldiff &= S[i] != S[i+1];
        }
        for(int i=0;i<S.Length;i++){
            c += S[i] - 'a';
        }
        c %= 3;
        long count = DP[S.Length-1,0,c,1] + DP[S.Length-1,1,c,1] + DP[S.Length-1,2,c,1];
        if(alldiff){
            count++;
        }
        count %= Define.mod;
        sb.Append(count+"\n");
    }
    int SolveSimple(string s){
        int N = s.Length;
        int pow = 1;
        int c = 0;
        for(int i=0;i<N;i++){
            c *= 3;
            if(s[i] == 'a'){
            }
            else if(s[i] == 'b'){
                c++;
            }
            else{
                c += 2;
            }
            pow *= 3;
        }
        bool[] OK = new bool[pow];
        dfs(OK,c,N);
        int count = 0;
        for(int i=0;i<pow;i++){
            if(OK[i]){
                count++;
                // string ans = "";
                // int d = i;
                // for(int j=0;j<N;j++){
                //     char ax = (char)('a' + d % 3);
                //     d /= 3;
                //     ans = ax + ans;
                // }
                // Console.WriteLine(ans);
            }
        }
        return count;
    }
    void dfs(bool[] OK,int c,int N){
        if(OK[c]){
            return;
        }
        OK[c] = true;
        int[] S = new int[N];
        int cc = c;
        for(int i=N-1;i>=0;i--){
            S[i] = cc % 3;
            cc /= 3;
        }
        int pow = 1;
        for(int i=N-1;i>0;i--){
            if(S[i] != S[i-1]){
                bool[] used = new bool[3];
                used[S[i]] = true;
                used[S[i-1]] = true;
                int a = -1;
                for(int j=0;j<3;j++){
                    if(!used[j]){
                        a = j;
                    }
                }
                int newc = c - pow*S[i] - pow*3*S[i-1] + pow*4*a;
                dfs(OK,newc,N);
            }
            pow *= 3;
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
public static class Define{
    public const long mod = 998244353;
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