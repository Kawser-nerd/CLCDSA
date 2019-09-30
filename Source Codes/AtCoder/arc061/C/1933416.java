import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE;

    void solve(){
        int n = ni();
        int m = ni();
        Dijkstra dijkstra = new Dijkstra(n+m*2+1);
        TreeMap<Long, Integer> reindex= new TreeMap<>();
        long res = 0;
        for(int i = 0; i < m; i++){
            long p = nl();
            long q = nl();
            long c = nl();
            long from = (p<<32)+c;
            long to = (q<<32)+c;
            long fromout = (p<<32)-1;
            long toout = (q<<32)-1;
            if(!reindex.containsKey(fromout))reindex.put(fromout, reindex.size());
            if(!reindex.containsKey(toout)) reindex.put(toout, reindex.size());
            if(!reindex.containsKey(from)){
                reindex.put(from, reindex.size());
                dijkstra.addDirectedEdge(reindex.get(from), reindex.get(fromout), 0);
                dijkstra.addDirectedEdge(reindex.get(fromout), reindex.get(from), 1);
                res+=2;
            }
            if(!reindex.containsKey(to)){
                reindex.put(to, reindex.size());
                dijkstra.addDirectedEdge(reindex.get(to), reindex.get(toout), 0);
                dijkstra.addDirectedEdge(reindex.get(toout), reindex.get(to), 1);
                res+=2;
            }
            dijkstra.addDirectedEdge(reindex.get(from), reindex.get(to), 0);
            dijkstra.addDirectedEdge(reindex.get(to), reindex.get(from), 0);
            res+=2;
        }
        // out.println(reindex.size());
        // out.println(res);
        long start = (1l<<32) - 1;
        long goal = ((long)n<<32) - 1;
        if(!reindex.containsKey(start) || !reindex.containsKey(goal)){
            out.println(-1);
            return;
        }
        int[] dist = dijkstra.getDist(reindex.get(start));
        int ans = dist[reindex.get(goal)];
        if(ans == Integer.MAX_VALUE / 3){
            out.println(-1);
            return;
        }
        out.println(ans);
    }

    static class Dijkstra {
        int n;
        ArrayList<Pair>[] G;
        int INF = Integer.MAX_VALUE / 3;

        public Dijkstra(int n) {
            this.n = n;
            G = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                G[i] = new ArrayList<>();
            }
        }

        public void addDirectedEdge(int from, int to, int cost) {
            G[from].add(new Pair(to, cost));
        }

        public int[] getDist(int s) {
            PriorityQueue<Pair> Q = new PriorityQueue<>();
            Q.add(new Pair(s, 0));
            int[] dist = new int[n];
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

        class Pair implements Comparable<Pair> {
            int x;
            int y;

            Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return Integer.compare(y, p.y);
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