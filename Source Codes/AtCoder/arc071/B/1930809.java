import java.io.*;
import java.util.*;


class Main {
    static final long MOD=1000000007;
    static long f(long[]a){
        int n=a.length;
        long ans=0;
        for(int i=0;i<n;++i){
            a[i]%=MOD;
            if(a[i]<0)a[i]+=MOD;
            long f=(2*i-n+1+MOD)%MOD;
            ans=(ans+f*a[i])%MOD;
        }
        return ans;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        long[]x=new long[n],y=new long[m];
        for(int i=0;i<n;++i)x[i]=sc.nextLong();
        for(int i=0;i<m;++i)y[i]=sc.nextLong();
        out.println(f(x)*f(y)%MOD);
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