import java.io.*;
import java.util.*;


class Main {
    static final long MOD=1000000007;
    static final long solve(long[]x){
        int n=x.length;
        long ans=0;
        for(int i=0;i<n;++i)
            ans=(ans+(2*i-n+1+MOD)*((x[i]+MOD)%MOD))%MOD;
        return ans;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        long[]x=new long[n],y=new long[m];
        for(int i=0;i<n;++i)x[i]=sc.nextInt();
        for(int i=0;i<m;++i)y[i]=sc.nextInt();
        out.println(solve(x)*solve(y)%MOD);
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