import java.io.*;
import java.util.*;


class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        long[][]ab=new long[n][2];
        for(int i=0;i<n;++i){
            ab[i][0]=sc.nextLong();
            ab[i][1]=sc.nextLong();
        }
        Arrays.sort(ab,(x,y)->{
                long fst=Math.max(x[0],x[0]-x[1]+y[0]);
                long snd=Math.max(y[0],y[0]-y[1]+x[0]);
                int res=Long.compare(fst,snd);
                if(res!=0)return res;
                return Long.compare(x[0]-x[1],y[0]-y[1]);
            });
        long ans=0;
        long cur=0;
        for(int i=0;i<n;++i){
            cur+=ab[i][0];
            ans=Math.max(ans,cur);
            cur-=ab[i][1];
        }
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
        int[] nextIntArray(int n){
            int[]r=new int[n];
            for(int i=0;i<n;++i)r[i]=nextInt();
            return r;
        }
    }
}