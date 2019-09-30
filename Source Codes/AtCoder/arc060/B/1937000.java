import java.io.*;
import java.util.*;


class Main {
    static final long I=1L<<50;
    static long f(long b,long n){
        long s=0;
        while(n>0){
            s+=n%b;
            n/=b;
        }
        return s;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        long n=sc.nextLong();
        long s=sc.nextLong();
        // hitoketa
        if(n==s){
            out.println(n+1);
            out.close();
            return;
        }
        if(n<s){
            out.println(-1);
            out.close();
            return;
        }
        long min=I;
        for(long b=1;b*b<=n-s;++b){
            if((n-s)%b!=0)continue;
            if(f(b+1,n)==s)
                min=Math.min((long)b+1,min);
            if(f((n-s)/b+1,n)==s)
                min=Math.min(min,(n-s)/b+1);
        }
        if(min==I){
            out.println(-1);
            out.close();
            return;
        }
        out.println(min);
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