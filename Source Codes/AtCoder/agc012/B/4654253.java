import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.TreeSet;
public class Main{
	static int[][] dp;
	static Graph G;
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		Mathplus mp = new Mathplus();
		int N = sc.nextInt();
		dp = new int[N][11];
		G = new Graph(N);
		int M = sc.nextInt();
		for(int i=0;i<M;i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			G.addEdge(a, b);
			G.addEdge(b, a);
		}
		int Q = sc.nextInt();
		int[] v = new int[Q];
		int[] d = new int[Q];
		int[] c = new int[Q];
		for(int i=0;i<Q;i++){
			v[i] = sc.nextInt()-1;
			d[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		for(int i=Q-1;i>=0;i--){
			paint(v[i],d[i],c[i]);
		}
		
		for(int i=0;i<N;i++){
			System.out.println(dp[i][0]);
		}
	}
	private static void paint(int v, int d, int c) {
		if(d==-1||dp[v][d]!=0)return;
		dp[v][d] = c;
		paint(v,d-1,c);
		for(Edge E:G.list[v]){
			int w = E.to;
			paint(w,d-1,c);
		}
		
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
			return find(root[x]);
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


class WeightedUnionFindTree extends UnionFindTree{
	int[] weight ;
	
	WeightedUnionFindTree(int N){
		super(N);
		weight = new int[N];
		for(int i=0;i<N;i++){
			weight[i] = 1;
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
				weight[y] += weight[x];
			}else{
				root[y] = x;
				weight[x] += weight[y];
				if(rank[x]==rank[y]){
					rank[x]++;
				}
			}
		}
	}
	
}

class Graph {
	ArrayList<Edge>[] list;
	int size;
	TreeSet<LinkEdge> Edges = new TreeSet<LinkEdge>(new LinkEdgeComparator());
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

	void addWeightedEdge(int a,int b,int c){
		list[a].add(new Edge(b,c));
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

class Edge{
	int to;
	long cost;

	Edge(int a,long b){
		to = a;
		cost = b;
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
	long b;

	Pair(long p,long q){
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

class Mathplus{
	int mod = 1000000007;
	long[] fac = new long[1000001];
	boolean isBuild = false;
	int mindex = -1;
	int maxdex = -1;


	void buildFac(){
		fac[0] = 1;
		for(int i=1;i<=1000000;i++){
			fac[i] = (fac[i-1] * i)%mod;
		}
		isBuild = true;
	}
	long max(long[] a){
		long max = 0;
		for(int i=0;i<a.length;i++){
			if(max<a[i]){
				max =a[i];
				maxdex = i;
			}
		}
		return max;
	}
	int max(int[] a){
		int max = 0;
		for(int i=0;i<a.length;i++){
			if(max<a[i]){
				max =a[i];
				maxdex = i;
			}
		}
		return max;
	}
	long min(long[] a){
		long min = Long.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(min>a[i]){
				min =a[i];
				mindex = i;
			}
		}
		return min;
	}
	int min(int[] a){
		int min = Integer.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(min>a[i]){
				min =a[i];
				mindex = i;
			}
		}
		return min;
	}
	long sum(long[] a){
		long sum = 0;
		for(int i=0;i<a.length;i++){
			sum += a[i];
		}
		return sum;
	}
	long sum(int[] a){
		long sum = 0;
		for(int i=0;i<a.length;i++){
			sum += a[i];
		}
		return sum;
	}

	long gcd(long a, long b){
		if(a<b){
			a^=b;
			b^=a;
			a^=b;
		}
		if(a%b==0){
			return b;
		}else{
			return gcd(b,a%b);
		}
	}

	long lcm(long a, long b){
		return a / gcd(a,b) * b;
	}

	public long comb(int a,int num){
		if(!isBuild){
			buildFac();
		}
		return fac[a] * (rev(fac[num])*rev(fac[a-num])%mod)%mod;
	}

	long rev(long l) {
		return pow(l,mod-2);
	}

	long pow(long l, int i) {
		if(i==0){
			return 1;
		}else{
			if(i%2==0){
				long val = pow(l,i/2);
				return val * val % mod;
			}else{
				return pow(l,i-1) * l % mod;
			}
		}
	}


}