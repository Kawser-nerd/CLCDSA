import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE/2;


    void solve(){
        int h = ni();
        int w = ni();
        char[][] map = nm(h,w);
        Dinic dinic = new Dinic(h+w);
        int s = h+w;
        int t = h+w+1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j]=='S'){
                    dinic.addEdge(s,i,inf);
                    dinic.addEdge(s,j+h,inf);
                }
                if(map[i][j]=='T'){
                    dinic.addEdge(i,t,inf);
                    dinic.addEdge(j+h,t,inf);
                }
                if(map[i][j]=='o'){
                    dinic.addBiEdge(i,j+h,1);
                }
            }
        }
        long res = dinic.getMaxFlow(s,t);
        out.println((res>=inf ? -1 : res));


    }

    class Dinic {
        class Edge {
            int to, cap;
            int flow = 0;
            Edge rev;
            
            Edge(int to, int cap) {
                this.to = to;
                this.cap = cap;
            }
            
            void setRevEdge(Edge rev) {
                this.rev = rev;
            }
        }
        
        int N;
        int tank;
        int[] ptr, Q, dist;
        
        ArrayList<Edge>[] g;

        public Dinic(int N) {
            this.N = N;
            g = new ArrayList[N + 2];
            for (int i = 0; i < N + 2; i++)
                g[i] = new ArrayList<Edge>();
            
            ptr = new int[N + 2];
            Q = new int[N + 2];
            dist = new int[N + 2];
        }
        
        public void addEdge(int from, int to, int cap) {
            Edge e1 = new Edge(to, cap);
            Edge e2 = new Edge(from, 0);
            e1.setRevEdge(e2);
            e2.setRevEdge(e1);
            g[from].add(e1);
            g[to].add(e2);
        }
        
        boolean dinic_bfs(int src)  {
            Arrays.fill(dist, -1);
            dist[src] = 0;
            int sizeQ = 0;
            Q[sizeQ++] = src;
            for (int i = 0; i < sizeQ; i++) {
                int u = Q[i];
                for (Edge e : g[u]) {
                    if (dist[e.to] < 0 && e.flow < e.cap) {
                        dist[e.to] = dist[u] + 1;
                        Q[sizeQ++] = e.to;
                    }
                }
            }
            return dist[tank] >= 0;
        }
        
        int dinic_dfs(int u, int f) {
            if (u == tank) return f;
            for ( ; ptr[u] < g[u].size(); ptr[u]++) {
                Edge e = g[u].get(ptr[u]);
                if (dist[e.to] == dist[u] + 1 && e.flow < e.cap) {
                    int df = dinic_dfs(e.to, Math.min(f, e.cap - e.flow));
                    if (df > 0) {
                        e.flow += df;
                        e.rev.flow -= df;
                        return df;
                    }
                }
            }
            
            return 0;
        }
        
        public int getMaxFlow(int src, int tank) {
            this.tank = tank;
            
            int res = 0;
            while (dinic_bfs(src)) {
                Arrays.fill(ptr, 0);
                while (true) {
                    int df = dinic_dfs(src, Integer.MAX_VALUE);
                    if (df == 0) break;
                    res += df;
                }
            }
            
            return res;
        }

        public void addBiEdge(int from, int to, int cap) {
            Edge e1 = new Edge(to, cap);
            Edge e2 = new Edge(from, cap);
            e1.setRevEdge(e2);
            e2.setRevEdge(e1);
            g[from].add(e1);
            g[to].add(e2);
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