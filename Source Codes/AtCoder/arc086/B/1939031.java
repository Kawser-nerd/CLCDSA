import java.io.*;
import java.util.*;


class Main {
    static int p=0;
    static int[]ops;
    static long[]a;
    static int n;
    static void add(int x,int y){
        a[y]+=a[x];
        ops[p++]=x*n+y;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        n=sc.nextInt();
        a=new long[n];
        ops=new int[2*n];
        for(int i=0;i<n;++i)a[i]=sc.nextLong();
        long max=Math.abs(a[0]);
        int maxind=0;
        for(int i=1;i<n;++i){
            if(max<Math.abs(a[i])){
                max=Math.abs(a[i]);
                maxind=i;
            }
        }
        if(max!=0){
            for(int i=0;i<n;++i)
                if(i!=maxind)
                    add(maxind,i);
            if(a[maxind]<0)
                for(int i=n-2;i>=0;--i)
                    add(i+1,i);
            else
                for(int i=0;i<n-1;++i)
                    add(i,i+1);
        }
        out.println(p);
        for(int i=0;i<p;++i){
            int x=ops[i]/n+1;
            int y=ops[i]%n+1;
            out.println(x+" "+y);
        }
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