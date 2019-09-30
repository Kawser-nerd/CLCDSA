import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        long[]h=new long[n],s=new long[n];
        for(int i=0;i<n;++i){
            h[i]=sc.nextInt();
            s[i]=sc.nextInt();
        }
        long p=1L<<50,f=0;
        while(p-f>1){
            long x=(p+f)/2;
            long[]a=new long[n];
            for(int i=0;i<n;++i)
                a[i]=x<h[i]?-1:(x-h[i])/s[i];
            Arrays.sort(a);
            boolean ok=true;
            for(int i=0;i<n;++i)
                if(a[i]<i){
                    ok=false;
                    break;
                }
            if(ok)
                p=x;
            else
                f=x;
        }
        out.println(p);
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