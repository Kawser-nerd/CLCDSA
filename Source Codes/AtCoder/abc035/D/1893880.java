import java.io.*;
import java.util.*;


class Main {
    static ArrayList<Long>[]g,rev;
    static long[]solve(ArrayList<Long>[]g){
        int n=g.length;
        long[]d=new long[n];
        Arrays.fill(d,1L<<52);
        Queue<Long>q=new PriorityQueue<Long>();
        q.add((long)0<<17|0);
        while(q.size()>0){
            long top=q.poll();
            int v=(int)top&0x1ffff;
            long dist=top>>>17;
            if(d[v]<=dist)continue;
            d[v]=dist;
            for(long e:g[v]){
                int w=(int)(e>>>32);
                int c=(int)e;
                if(d[w]<=dist+c)continue;
                d[w]=dist+c+1;
                q.add((dist+c)<<17|w);
            }
        }
        return d;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        long t=sc.nextInt();
        long[]a=new long[n];
        for(int i=0;i<n;++i)a[i]=sc.nextInt();
        g=new ArrayList[n];
        rev=new ArrayList[n];
        Arrays.setAll(g,x->new ArrayList<Long>());
        Arrays.setAll(rev,x->new ArrayList<Long>());
        for(int i=0;i<m;++i){
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            int c=sc.nextInt();
            g[u].add((long)v<<32|c);
            rev[v].add((long)u<<32|c);
        }
        long[]d1=solve(g),d2=solve(rev);
        long ans=0;
        for(int i=0;i<n;++i){
            long total=d1[i]+d2[i];
            if(total>t)continue;
            ans=Math.max(ans,(t-total)*a[i]);
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
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.