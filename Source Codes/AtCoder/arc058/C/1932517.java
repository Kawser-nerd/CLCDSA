import java.io.*;
import java.util.*;


class Main {
    static final long MOD=1000000007;
    static int x,y,z;
    static int nextState(int state,int j){
        int ans=1;
        for(int i=0;i<x;++i){
            if((state&1<<i)!=0&&i+j<=x)
                ans|=1<<(i+j);
        }
        for(int i=x;i<x+y;++i){
            if((state&1<<i)!=0&&i+j<=x+y)
                ans|=1<<(i+j);
        }
        for(int i=x+y;i<x+y+z;++i){
            if((state&1<<i)!=0&&i+j<=x+y+z)
                ans|=1<<(i+j);
        }
        if((state&1<<(x+y+z))!=0)ans|=1<<(x+y+z);
        return ans;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        x=sc.nextInt();
        y=sc.nextInt();
        z=sc.nextInt();
        long[][]dp=new long[2][1<<18];
        int[][]ns=new int[18][1<<18];
        dp[0][1]=1;
        for(int b=0;b<1<<18;++b)
            for(int j=1;j<=10;++j)
                ns[j][b]=nextState(b,j);
        for(int i=0;i<n;++i){
            int u=i%2;
            int nxt=1-u;
            Arrays.fill(dp[nxt],0);
            for(int b=0;b<1<<18;++b){
                for(int a=1;a<=10;++a){
                    int nss=ns[a][b];
                    dp[nxt][nss]+=dp[u][b];
                    dp[nxt][nss]%=MOD;
                }
            }
        }
        long ans=0;
        for(int b=1<<(x+y+z);b<1<<(x+y+z+1);++b)
            ans=(ans+dp[n%2][b])%MOD;
        out.println(ans);
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