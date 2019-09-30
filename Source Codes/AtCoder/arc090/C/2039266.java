import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long mod = 1_000_000_007;
    long inf = Long.MAX_VALUE;

    boolean[][] used;
    void solve(){
        int n = ni();
        int m = ni();
        int s = ni()-1;
        int t = ni()-1;
        Dijkstra dijk = new Dijkstra(n);
        long[][] edge = new long[2*m][3];
        for(int i = 0; i < m; i++){
            int from = ni()-1;
            int to = ni()-1;
            long d = nl();
            dijk.addDirectedEdge(from ,to, d);
            dijk.addDirectedEdge(to ,from, d);
            edge[2*i][0] = from;
            edge[2*i][1] = to;
            edge[2*i][2] = d;
            edge[2*i+1][0] = to;
            edge[2*i+1][1] = from;
            edge[2*i+1][2] = d;
        }
        long[][] dp1 = dijk.getDistMinPath(s);
        long[][] dp2 = dijk.getDistMinPath(t);
        long dist = dp1[t][0];
        //??
        long total = dp1[t][1]%mod*dp2[s][1]%mod;
        //?????????
        for(int i = 0; i < n; i++){
            if(2*dp1[i][0]==dist){
                total -= dp1[i][1]%mod*dp1[i][1]%mod*dp2[i][1]%mod*dp2[i][1]%mod;
                total = (total+mod)%mod;
            }
        }
        //????????
        for(int i = 0; i < 2*m; i++){
            int from = (int)edge[i][0];
            int to = (int)edge[i][1];
            long cost = edge[i][2];
            if(2*dp1[from][0]<dist && 2*dp1[to][0]>dist && dp1[from][0]+cost+dp2[to][0]==dist){
                total -= dp1[from][1]%mod*dp2[to][1]%mod*dp1[from][1]%mod*dp2[to][1]%mod;
                total = (total+mod)%mod;
            }
        }
        out.println(total);
    }

    static class Dijkstra {
        int n;
        ArrayList<Pair>[] G;
        long INF = Long.MAX_VALUE / 3;
        long mod = 1000000007;
        public Dijkstra(int n) {
            this.n = n;
            G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
        }

        public void addDirectedEdge(int from, int to, long cost) {
            G[from].add(new Pair(to, cost));
        }

        public long[] getDist(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            long[] dist = new long[n];
            Arrays.fill(dist, INF);
            boolean[] used = new boolean[n];
            while (!Q.isEmpty()) {
                Pair p = Q.poll();
                if (used[p.x]) continue;
                used[p.x] = true;
                dist[p.x] = p.y;

                for (Pair edge : G[p.x]) {
                    Q.add(new Pair(edge.x, p.y + edge.y));
                }
            }
            return dist;
        }
        // dp[i][0]:i???????
        // dp[i][1]:i????????????
        public long[][] getDistMinPath(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            long[][] dp = new long[n][2];
            for(int i = 0; i < n; i++){
                dp[i][0] = INF;
                dp[i][1] = 0;
            }
            dp[s][0] = 0;
            dp[s][1] = 1;
            boolean[] used = new boolean[n];
            while (!Q.isEmpty()) {
                Pair p = Q.poll();
                if (used[p.x]) continue;
                used[p.x] = true;
                // dp[p.x][0] = p.y%mod;
                for (Pair edge : G[p.x]) {
                    long dist = dp[p.x][0] + edge.y;
                    long root = dp[p.x][1];
                    if(dist==dp[edge.x][0]){
                        dp[edge.x][1] += root;
                        dp[edge.x][1] %= mod;
                    }
                    if(dist<dp[edge.x][0]){
                        dp[edge.x][0] = dist;
                        dp[edge.x][1] = root;
                        // dp[edge.x][0] %= mod;
                        dp[edge.x][1] %= mod;
                    }
                    Q.add(new Pair(edge.x, dp[edge.x][0]));
                }
            }
            return dp;
        }

        class Pair implements Comparable<Pair> {
            int x;
            long y;

            Pair(int x, long y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return Long.compare(y, p.y);
            }

        }
    }



    void run() throws Exception
    {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
    
    public static void main(String[] args) throws Exception { new Main().run(); }
    
    private byte[] inbuf = new byte[1024];
    private int lenbuf = 0, ptrbuf = 0;
    
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b) && b != ' ')){
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
 
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.