import java.io.*;
import java.util.*;


class Main {
    static ArrayList<Integer>[]g;
    static boolean[]vis;
    static int p;
    static int[]ans;
    static boolean dfs(int v){
        if(vis[v])return false;
        vis[v]=true;
        ans[p++]=v;
        for(int w:g[v]){
            boolean r=dfs(w);
            if(r)return true;
        }
        return true;
    }
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        int m=sc.nextInt();
        g=new ArrayList[n];
        Arrays.setAll(g,x->new ArrayList<Integer>());
        for(int i=0;i<m;++i){
            int a=sc.nextInt()-1;
            int b=sc.nextInt()-1;
            g[a].add(b);
            g[b].add(a);
        }
        vis=new boolean[n];
        ans=new int[n];
        dfs(0);
        int[]ans2=Arrays.copyOf(ans,p);
        vis[0]=false;
        ans=new int[n];
        p=0;
        dfs(0);
        int[]ans3=Arrays.copyOf(ans,p);
        int[]outa=new int[ans2.length+ans3.length-1];
        for(int i=0;i<ans3.length;++i){
            outa[ans3.length-1-i]=ans3[i];
        }
        for(int i=1;i<ans2.length;++i)
            outa[ans3.length+i-1]=ans2[i];
        out.println(outa.length);
        for(int i=0;i<outa.length;++i)
            out.print((outa[i]+1)+(i==outa.length-1?"\n":" "));
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