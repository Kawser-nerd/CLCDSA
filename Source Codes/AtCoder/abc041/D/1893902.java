import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]g=new int[n];
        for(int i=0;i<m;++i){
            int x=sc.nextInt()-1;
            int y=sc.nextInt()-1;
            g[x]|=1<<y;
        }
        long[]dp=new long[1<<n];
        dp[0]=1;
        for(int b=1;b<1<<n;++b){
            for(int i=0;i<n;++i){
                if((b&1<<i)==0)continue;
                if(((b^1<<i)&g[i])==0)
                    dp[b]+=dp[b^1<<i];
            }
        }
        out.println(dp[(1<<n)-1]);
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