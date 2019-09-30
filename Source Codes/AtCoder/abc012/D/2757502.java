import java.awt.font.GraphicAttribute;
import java.io.PrintWriter;
import java.util.*;
import java.io.*;
import java.util.function.*;
import java.util.stream.Stream;
import java.util.Map.Entry;

public class Main {

    public static void main(String[] args) { new Main().stream(); }

    final IO          io   = new IO();
    final PrintWriter out  = new PrintWriter(System.out);

    final int INF = Integer.MAX_VALUE/2;

    void stream(){ solve(); out.flush(); }

    /// ********** ?? ********** ///

    void solve() {
        int N=io.Int();
        int M=io.Int();
        int[] a=new int[M];
        int[] b=new int[M];
        long[] c=new long[M];
        REP(M,i->{
            a[i]=io.Int();
            b[i]=io.Int();
            c[i]=io.Long();
        });


        Dijkstra D = new Dijkstra(N);
        D.AddPath(a, b, c);

        long ans = INF;
        for(int i = 1; i <= N; ++i){
            long max = -INF;
            D.Run(i);
            for(int j = 1; j <= N; ++j)
                max = Math.max(max,D.MinCost(j));
            ans = Math.min(ans, max);
        }

        out.println(ans);

    }

    /// ********** __ ********** ///

    void FOR(int a, int b, Consumer<Integer>act) { for(int i = a; i < b; ++i) act.accept(i); }
    void REP(int a, Consumer<Integer>act) { FOR(0, a, act); }
    Integer  [] int2IntegerArr  (int[]  arr) { return Arrays.stream(arr).boxed().toArray(Integer[]::new); }
    Character[] str2CharacterArr(String str) { return str.chars().mapToObj(c->(char)c).toArray(Character[]::new); }
}
/// ********** ??? ********** ///

class Edge implements Comparable<Edge>{
    public int  To;
    public long Cost;
    public Edge(int to, long cost){
        To   = to;
        Cost = cost;
    }
    @Override
    public int compareTo(Edge e){
        return new Long(Cost).compareTo(e.Cost);
    }
}

class Path {
    public int VertexNum;
    public int EdgeNum;
    public boolean IsNonDir;
    public long INF = Long.MAX_VALUE/2;
    public long[] Cost;
    public ArrayList[] Adj;
    public Path(int n){ this(n,true); }
    public Path(int n,boolean isNonDir){
        VertexNum = n;
        IsNonDir  = isNonDir;
        Cost = new long     [VertexNum + 1];
        Adj  = new ArrayList[VertexNum + 1];
        for(int i = 0; i < Adj.length ; ++i) Adj[i] = new ArrayList<Edge>();
    }
    public void AddPath(int f, int t){ AddPath(f,t,1L); }
    public void AddPath(int f, int t, long c){
        EdgeNum++;
        Adj[f].add(new Edge(t, c));
        if(IsNonDir) Adj[t].add(new Edge(f, c));
    }
    public void AddPath(int[] f, int[] t){
        for(int i = 0; i < f.length; ++i) AddPath(f[i], t[i]);

    }
    public void AddPath(int[] f, int[] t, long[] c){
        for(int i = 0; i < f.length; ++i) AddPath(f[i], t[i], c[i]);
    }
}

class Dijkstra extends Path {
    public Dijkstra(int n){ super(n); }
    public Dijkstra(int n, boolean isNonDir){ super(n, isNonDir); }
    public void Run(int f){
        for(int i = 0; i < VertexNum + 1; ++i) Cost[i] = INF;
        Cost[f] = 0;
        Queue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(f,0L));
        while (pq.size() > 0){
            Edge cur = pq.poll();
            if(Cost[cur.To] < cur.Cost) continue;
            for(Edge adj : (ArrayList<Edge>) Adj[cur.To]){
                if(Cost[adj.To] > cur.Cost + adj.Cost){
                    Cost[adj.To] = cur.Cost + adj.Cost;
                    pq.add(new Edge(adj.To, Cost[adj.To]));
                }
            }
        }
    }
    public long MinCost(int t){ return Cost[t]; }
}

/// ********** __ ********** ///

class IO{
    private final InputStream in = System.in;
    private final byte[] buffer  = new byte[1<<12];
    private int   ptr = 0, buffLen = 0;
    private boolean hasNextByte     ()      {
        if(ptr < buffLen) return true;
        ptr = 0;
        try{ buffLen = in.read(buffer); } catch (IOException e){ e.printStackTrace(); }
        return buffLen > 0;
    }
    private int     readByte        ()      { return hasNextByte()? buffer[ptr++] : -1; }
    private boolean isPrintableChar (int c) { return 33 <= c && c <= 126; } //ASCII
    private void    skipUnprintable ()      { while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; }
    private boolean hasNext         ()      { skipUnprintable(); return hasNextByte();}
    private String  next            ()      {
        if(!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)){ sb.appendCodePoint(b); b = readByte(); }
        return sb.toString();
    }
    public String String () { return next(); }
    public char   Char   () { return next().charAt(0);}
    public int    Int    () { return Integer.parseInt(next());}
    public long   Long   () { return Long.parseLong(next());}
    public double Double () { return Double.parseDouble(next());}
    public String[] StringArr (final int n) { final String[] arr = new String[n]; for(int i = 0; i < n; ++i) arr[i] = String(); return arr; }
    public char  [] CharArr   (final int n) { final char  [] arr = new char  [n]; for(int i = 0; i < n; ++i) arr[i] = Char  (); return arr; }
    public int   [] IntArr    (final int n) { final int   [] arr = new int   [n]; for(int i = 0; i < n; ++i) arr[i] = Int   (); return arr; }
    public long  [] LongArr   (final int n) { final long  [] arr = new long  [n]; for(int i = 0; i < n; ++i) arr[i] = Long  (); return arr; }
    public double[] DoubleArr (final int n) { final double[] arr = new double[n]; for(int i = 0; i < n; ++i) arr[i] = Double(); return arr; }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.