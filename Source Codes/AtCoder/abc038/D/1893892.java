import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        long[]hw=new long[n];
        for(int i=0;i<n;++i){
            long h=sc.nextInt();
            long w=sc.nextInt();
            hw[i]=h<<32|(1000000-w);
        }
        Arrays.sort(hw);
        int[] a=new int[n];
        for(int i=0;i<n;++i)a[i]=-(int)hw[i];
        // a no LIS
        int[]m=new int[n+1];
        int l=0;
        for(int i=0;i<n;++i){
            int p=0,f=l+1;
            while(f-p>1){
                int x=(p+f)/2;
                if(m[x]<a[i])
                    p=x;
                else
                    f=x;
            }
            m[p+1]=a[i];
            l=Math.max(l,p+1);
        }
        out.println(l);
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