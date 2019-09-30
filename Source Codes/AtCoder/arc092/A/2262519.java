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

    void solve(){
        int n = ni();
        int[][] red = new int[n][2];
        int[][] blue = new int[n][2];
        for(int i = 0; i < n; i++){
            red[i][0] = ni();
            red[i][1] = ni();
        }
        for(int i = 0; i < n; i++){
            blue[i][0] = ni();
            blue[i][1] = ni();
        }
        MaxFlowDinic flow = new MaxFlowDinic();
        flow.init(2*n+2);

        int source = 2*n;
        int sink = 2*n+1;
        for(int i = 0; i < n; i++){
            flow.edge(source,i,1);
            flow.edge(n+i,sink,1);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(red[i][0]<blue[j][0] && red[i][1]<blue[j][1]){
                    flow.edge(i, j+n, 1);
                }
            }
        }
        out.println(flow.max_flow(source,sink));
    }

    public static class MaxFlowDinic {
        public List<int[]>[] graph;
        public int[] deg;

        public int[] level;
        public int[] itr;

        public int[] que;

        @SuppressWarnings("unchecked")
        public void init(int size) {
            graph = new List[size];
            for (int i = 0; i < size ; i++) {
                graph[i] = new ArrayList<int[]>();
            }
            deg = new int[size];
            level = new int[size];
            itr = new int[size];
            que = new int[size+10];
        }
        public void edge(int from, int to, int cap) {
            int fdeg = deg[from];
            int tdeg = deg[to];
            graph[from].add(new int[]{to, cap, tdeg});
            graph[to].add(new int[]{from, 0, fdeg});
            deg[from]++;
            deg[to]++;
        }

        public int dfs(int v, int t, int f) {
            if (v == t) return f;
            for (int i = itr[v] ; i < graph[v].size() ; i++) {
                itr[v] = i;
                int[] e = graph[v].get(i);
                if (e[1] > 0 && level[v] < level[e[0]]) {
                    int d = dfs(e[0], t, Math.min(f, e[1]));
                    if (d > 0) {
                        e[1] -= d;
                        graph[e[0]].get(e[2])[1] += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        public void bfs(int s) {
            Arrays.fill(level, -1);
            int qh = 0;
            int qt = 0;
            level[s] = 0;
            que[qh++] = s;
            while (qt < qh) {
                int v = que[qt++];
                for (int i = 0; i < graph[v].size() ; i++) {
                    int[] e = graph[v].get(i);
                    if (e[1] > 0 && level[e[0]] < 0) {
                        level[e[0]] = level[v] + 1;
                        que[qh++] = e[0];
                    }
                }
            }
        }

        public int max_flow(int s, int t) {
            int flow = 0;
            while (true) {
                bfs(s);
                if (level[t] < 0) {
                    return flow;
                }
                Arrays.fill(itr, 0);
                while (true) {
                    int f = dfs(s, t, Integer.MAX_VALUE);
                    if (f <= 0) {
                        break;
                    }
                    flow += f;
                }
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
 
}