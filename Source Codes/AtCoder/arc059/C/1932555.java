import java.io.*;
import java.util.*;


class Main {
    static final long MOD=1000000007;
    static final int N=401;
    static long[][] tbl;
    static void init(){
        tbl=new long[N][N];
        for(int i=0;i<N;++i){
            tbl[0][i]=1;
            for(int j=1;j<N;++j)
                tbl[j][i]=tbl[j-1][i]*i%MOD;
        }
        for(int i=0;i<N;++i)
            for(int j=1;j<N;++j)
                tbl[i][j]=(tbl[i][j]+tbl[i][j-1])%MOD;
    }
    static long f(int a,int b,int d){
        return (tbl[d][b]-tbl[d][a-1]+MOD)%MOD;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        init();
        int n=sc.nextInt();
        int c=sc.nextInt();
        int[]a=new int[n],b=new int[n];
        for(int i=0;i<n;++i)a[i]=sc.nextInt();
        for(int i=0;i<n;++i)b[i]=sc.nextInt();
        long[][]dp=new long[n+1][c+1];
        dp[0][0]=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<=c;++j){
                for(int k=0;k<=j;++k){
                    dp[i+1][j]+=dp[i][j-k]*f(a[i],b[i],k);
                    dp[i+1][j]%=MOD;
                }
            }
        }
        out.println(dp[n][c]);
        out.close();
    }
    // http://codeforces.com/blog/entry/7018
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;
        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}