import java.io.*;
import java.util.*;


class Main {
    static ArrayList<Integer>[]g;
    static boolean dfs(int v,List<Integer>l,boolean[]vis){
        if(vis[v])return false;
        l.add(v);
        vis[v]=true;
        for(int w:g[v]){
            boolean sub=dfs(w,l,vis);
            if(sub)break;
        }
        return true;
    }
    @SuppressWarnings("unchecked")
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
        List<Integer>ans=new ArrayList<Integer>();
        boolean[]vis=new boolean[n];
        dfs(0,ans,vis);
        vis[0]=false;
        Collections.reverse(ans);
        ans.remove(ans.size()-1);
        dfs(0,ans,vis);
        out.println(ans.size());
        for(int i=0;i<ans.size();++i)
            out.print((ans.get(i)+1)+(i==ans.size()-1?"\n":" "));
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