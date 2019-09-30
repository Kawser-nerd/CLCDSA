import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.TreeSet;
public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int N = sc.nextInt();
		Pair[] X = new Pair[N];
		Pair[] Y = new Pair[N];
		for(int i=0;i<N;i++){
			X[i] = new Pair(sc.nextInt(),i);
			Y[i] = new Pair(sc.nextInt(),i);
		}
		
		Arrays.sort(X,new SampleComparator());
		Arrays.sort(Y,new SampleComparator());
		Graph G = new Graph(N);
		
		for(int i=0;i<N-1;i++){
			G.Edges.add(new LinkEdge(X[i+1].a-X[i].a,X[i].b,X[i+1].b));
		}
		for(int i=0;i<N-1;i++){
			G.Edges.add(new LinkEdge(Y[i+1].a-Y[i].a,Y[i].b,Y[i+1].b));
		}
		
		long ans = G.Kruskal();
		System.out.println(ans);
	}
}


class Graph {
	ArrayList<Edge>[] list;
	int size;
	@SuppressWarnings("unchecked")
	Graph(int N){
		size = N;
		list = new ArrayList[N];
		for(int i=0;i<N;i++){
			list[i] = new ArrayList<Edge>();
		}
	}
	
	void addEdge(int a,int b){
		list[a].add(new Edge(b,1));
	}
	
	void addWeightedEdge(int b,int b2,long l){
		list[b].add(new Edge(b2,l));
	}
	
	void addEgdes(int[] a,int[] b){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],1));
		}
	}
	
	void addWeighterEdges(int[] a ,int[] b ,int[] c){
		int size = a.length;
		for(int i=0;i<size;i++){
			list[a[i]].add(new Edge(b[i],c[1]));
		}
	}
	
	long[] bfs(int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		L[s] = 0;
		ArrayDeque<Integer> Q = new ArrayDeque<Integer>();
		Q.add(s);
		
		while(!Q.isEmpty()){
			int v = Q.poll();
			for(Edge e:list[v]){
				int w = e.to;
				long c = e.cost;
				if(L[w]==-1){
					L[w] = L[v] + c;
					Q.add(w);
				}
			}
		}
		
		return L;
	}
	
	long[] dijkstra(int s){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] visited = new int[size];
		L[s] = 0;
		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(0,s));
		
		while(!Q.isEmpty()){
			
			Pair C = Q.poll();
			if(visited[(int)C.b]==0){
				L[(int)C.b] = C.a;
				visited[(int) C.b] = 1;
				for(Edge D:list[(int) C.b]){
					Q.add(new Pair(L[(int)C.b]+D.cost,D.to));
				}
			}
		}
		
		return L;
	}
	TreeSet<LinkEdge> Edges = new TreeSet<LinkEdge>(new LinkEdgeComparator());
	
	long Kruskal(){
		long ans = 0;
		
		UnionFindTree UF = new UnionFindTree(size);
		
		for(LinkEdge e:Edges){
			if(!UF.same(e.a,e.b)){
				ans += e.L;
				UF.unite(e.a,e.b);
			}
		}
			
		
		return ans;
	}
}


class UnionFindTree {
	int[] root;
	int[] rank;
	
	UnionFindTree(int N){
		root = new int[N];
		rank = new int[N];
		for(int i=0;i<N;i++){
			root[i] = i;
		}
	}
	
	public int find(int x){
		if(root[x]==x){
			return x;
		}else{
			return root[x] = find(root[x]);
		}
	}
	
	public void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y){
			return;
		}else{
			if(rank[x]<rank[y]){
				root[x] = y;
			}else{
				root[y] = x;
				if(rank[x]==rank[y]){
					rank[x]++;
				}
			}
		}
	}
	
	public boolean same(int x,int y){
		return find(x)==find(y);
	}
}

class Edge{
	int to;
	long cost;
	
	Edge(int a,long b){
		to = a;
		cost = b;
	}
	
}

class LinkEdge{
	long L;
	int a ;
	int b;
	LinkEdge(long l,int A,int B){
		L = l;
		a = A;
		b = B;
	}
	public boolean equals(Object o){
		LinkEdge O = (LinkEdge) o;
		if(O.a==this.a&&O.b==this.b&&O.L==this.L){
			return true;
		}else{
			return false;
		}
		
		
	}
	
	public int hashCode(){
		return Objects.hash(L,a,b);
	}
	
}
class LinkEdgeComparator implements Comparator<LinkEdge>{
	public int compare(LinkEdge P, LinkEdge Q) {
		long temp = P.L-Q.L;
		if(temp==0){
			if(P.a>Q.a){
				return 1;
			}else{
				if(P.b>Q.b){
					return 1;
				}else{
					return -1;
				}
			}
			
		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
	}
 
}
class Pair{
	long a;
	int b;
	
	Pair(long p,int q){
		this.a = p;
		this.b = q;
	}
	
	public boolean equals(Object o){
		Pair O = (Pair) o;
		if(O.a==this.a&&O.b==this.b){
			return true;
		}else{
			return false;
		}
		
		
	}
	
	public int hashCode(){
		return Objects.hash(a,b);
	}
	
}


 
class SampleComparator implements Comparator<Pair>{
	public int compare(Pair P, Pair Q) {
		long temp = P.a-Q.a;
		if(temp==0){
			if(P.b>Q.b){
				return 1;
			}else{
				return -1;
			}
			
		}
		if(temp>=0){
			return 1;
		}else{
			return -1;
		}
	}
 
}
class FastScanner {
    private final java.io.InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return (int) (minus ? -n : n);
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}