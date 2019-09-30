import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        long x=sc.nextLong();
        int k=sc.nextInt();
        long[]r=new long[k+1];
        r[0]=0;
        for(int i=0;i<k;++i)r[i+1]=sc.nextInt();
        //precomp
        long[]d=new long[k+1],e=new long[k+1],f=new long[k+1];
        // max(d,min(f,a+e))
        d[0]=0;e[0]=0;f[0]=x;
        for(int i=0;i<k;++i){
            if(i%2==0){
                d[i+1]=Math.max(0,d[i]-(r[i+1]-r[i]));
                e[i+1]=e[i]-(r[i+1]-r[i]);
                f[i+1]=Math.max(0,f[i]-(r[i+1]-r[i]));
            }else{
                d[i+1]=Math.min(x,d[i]+(r[i+1]-r[i]));
                e[i+1]=e[i]+(r[i+1]-r[i]);
                f[i+1]=Math.min(x,f[i]+(r[i+1]-r[i]));
            }
        }
        int q=sc.nextInt();
        int cpos=0;
        for(int i=0;i<q;++i){
            long t=sc.nextInt();
            long a=sc.nextInt();
            while(cpos<k+1&&r[cpos]<=t)cpos++;
            cpos--;
            long dif=t-r[cpos];
            long st=Math.max(d[cpos],Math.min(f[cpos],a+e[cpos]));
            //System.err.println("max("+d[cpos]+",min("+f[cpos]+",a+"+e[cpos]+"))");
            //System.err.println("dif="+dif+" st="+st);
            if(cpos%2==0)st-=dif;
            else st+=dif;
            st=Math.max(0,Math.min(x,st));
            out.println(st);
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