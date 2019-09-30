import java.io.*;
import java.util.*;


class Main {
    static ArrayList<Integer>[]g;
    static int maxMatching(int v,int p){
        int a=0;
        int o=0;
        for(int w:g[v]){
            if(w==p)continue;
            int r=maxMatching(w,v);
            a+=r/2;
            o+=r%2;
        }
        return 2*a+Math.min(1,o)+1;
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n=sc.nextInt();
        g=new ArrayList[n];
        Arrays.setAll(g,x->new ArrayList<Integer>());
        for(int i=0;i<n-1;++i){
            int a=sc.nextInt()-1;
            int b=sc.nextInt()-1;
            g[a].add(b);
            g[b].add(a);
        }
        int m=maxMatching(0,-1)/2;
        out.println(2*m==n?"Second":"First");
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