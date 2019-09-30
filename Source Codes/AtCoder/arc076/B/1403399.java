import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.util.Map.Entry;
import java.util.stream.IntStream;

public class Main {
    static ContestScanner in;
    static Writer out;
    public static void main(String[] args) {
        Main main = new Main();
        try {
            in = new ContestScanner();
            out = new Writer();
            main.solve();
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        Pos[] xo = new Pos[n];
        Pos[] yo = new Pos[n];
        for(int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            xo[i] = new Pos(i, x, y);
            yo[i] = new Pos(i, y, x);
        }
        Arrays.sort(xo);
        Arrays.sort(yo);
        List<Edge> edge = new ArrayList<>();
        for(int i = 1; i < n; i++) {
            int from1 = xo[i].id;
            int to1 = xo[i - 1].id;
            int cost1 = xo[i].x - xo[i - 1].x;
            int from2 = yo[i].id;
            int to2 = yo[i - 1].id;
            int cost2 = yo[i].x - yo[i - 1].x;
            edge.add(new Edge(from1, to1, cost1));
            edge.add(new Edge(from2, to2, cost2));
        }
        Collections.sort(edge);
        Kruskal.getMst(edge, n);
        System.out.println(Kruskal.cost);
    }
}

class Kruskal{
    static long cost;
    static List<Edge>[] getMst(List<Edge> edge, int n){
        Collections.sort(edge);
        UnionFind uf = new UnionFind(n);
        List<Edge>[] node = new List[n];
        for(int i=0; i<n; i++){
            node[i] = new ArrayList<>();
        }
        for(Edge e: edge){
            if(uf.same(e.from, e.to)) continue;
            uf.unite(e.from, e.to);
            cost += e.cost;
            node[e.from].add(e);
            node[e.to].add(new Edge(e.to, e.from, e.cost));
        }
        return node;
    }
}

class UnionFind{
    int[] par;
    int[] rank;
    UnionFind(int n){
        par = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y) return;
        if(rank[x] > rank[y]) par[x] = y;
        else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    boolean same(int x, int y){
        return find(x) == find(y);
    }
}


class Edge implements Comparable<Edge> {
    int from, to, cost;
    public Edge(int from, int to, int cost) {
        this.to = to;
        this.from = from;
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return cost - o.cost;
    }
}

class Pos implements Comparable<Pos> {
    int x, y, id;
    public Pos(int id, int x, int y) {
        this.x = x;
        this.y = y;
        this.id = id;
    }

    @Override
    public int compareTo(Pos o) {
        if(x != o.x) return x - o.x;
        return y - o.y;
    }
}

class Writer extends PrintWriter{
    public Writer(String filename)throws IOException
    {super(new BufferedWriter(new FileWriter(filename)));}
    public Writer()throws IOException{super(System.out);}
}
class ContestScanner implements Closeable{
    private BufferedReader in;private int c=-2;
    public ContestScanner()throws IOException
    {in=new BufferedReader(new InputStreamReader(System.in));}
    public ContestScanner(String filename)throws IOException
    {in=new BufferedReader(new InputStreamReader(new FileInputStream(filename)));}
    public String nextToken()throws IOException {
        StringBuilder sb=new StringBuilder();
        while((c=in.read())!=-1&&Character.isWhitespace(c));
        while(c!=-1&&!Character.isWhitespace(c)){sb.append((char)c);c=in.read();}
        return sb.toString();
    }
    public String readLine()throws IOException{
        StringBuilder sb=new StringBuilder();if(c==-2)c=in.read();
        while(c!=-1&&c!='\n'&&c!='\r'){sb.append((char)c);c=in.read();}
        return sb.toString();
    }
    public long nextLong()throws IOException,NumberFormatException
    {return Long.parseLong(nextToken());}
    public int nextInt()throws NumberFormatException,IOException
    {return(int)nextLong();}
    public double nextDouble()throws NumberFormatException,IOException
    {return Double.parseDouble(nextToken());}
    public void close() throws IOException {in.close();}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.