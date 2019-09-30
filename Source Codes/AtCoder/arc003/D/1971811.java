import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        int k=sc.nextInt();
        int[]g=new int[n];
        for(int i=0;i<m;++i){
            int a=sc.nextInt();
            int b=sc.nextInt();
            g[a]|=1<<b;
            g[b]|=1<<a;
        }
        final int I=1000000;
        int iter=I;
        int[]seat=new int[n];
        double p=0;
        Random rnd=new Random("taplis".hashCode());
        while(iter-->0){
            for(int i=0;i<n;++i)seat[i]=i;
            for(int i=0;i<k;++i){
                int x=-1;
                int y=-1;
                if(n==2){
                    x=0;
                    y=1;
                }else
                    do{
                        x=rnd.nextInt(n);
                        y=rnd.nextInt(n);
                    }while(x==y);
                int t=seat[x];
                seat[x]=seat[y];
                seat[y]=t;
            }
            boolean ok=true;
            for(int i=0;i<n;++i){
                int x=seat[i];
                int y=seat[(i+1)%n];
                if((g[x]&1<<y)!=0){
                    ok=false;
                    break;
                }
            }
            if(ok)p+=1;
        }
        out.println(p/I);
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
        int[] nextIntArray(int n){
            int[]r=new int[n];
            for(int i=0;i<n;++i)r[i]=nextInt();
            return r;
        }
    }
}