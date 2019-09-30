import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.NoSuchElementException;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.TreeSet;
import java.util.function.BiFunction;

public class Main{
	
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		Mathplus mp = new Mathplus();
		PrintWriter out = new PrintWriter(System.out);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int Q = sc.nextInt();
		int min = 1000000007;
		int[] A = new int[N+1];
		for(int i=0;i<N;i++) {
			A[i] = sc.nextInt();
		}

		for(int i=0;i<N;i++) {
			int Y = A[i];
			ArrayList<Integer> list = new ArrayList<Integer>();
			ArrayList<Integer> listAll = new ArrayList<Integer>();
			for(int j=0;j<N;j++) {
				if(A[j]>=Y) {
					list.add(A[j]);
				}else {
					Collections.sort(list);
					if(list.size()>=K) {
						int take = list.size()-K+1;
						for(int k=0;k<take;k++) {
							listAll.add(list.get(k));
						}
					}
					list.clear();
				}
			}
			Collections.sort(list);
			if(list.size()>=K) {
				int take = list.size()-K+1;
				for(int k=0;k<take;k++) {
					listAll.add(list.get(k));
				}
			}
			if(listAll.size()>=Q) {
				Collections.sort(listAll);
				int X = listAll.get(Q-1);
				min = Math.min(min,X-Y);
			}
		}
		System.out.println(min);
	}

}

class SegmentTree<T,E>{
	int N;
	BiFunction<T,T,T> f;
	BiFunction<T,E,T> g;
	T d1;
	ArrayList<T> dat;
	SegmentTree(BiFunction<T,T,T> F,BiFunction<T,E,T> G,T D1,T[] v){
		int n = v.length;
		f = F;
		g = G;
		d1 = D1;
		init(n);
		build(v);
	}
	

	void init(int n) {
		N = 1;
		while(N<n)N*=2;
		dat = new ArrayList<T>();
	}
	
	void build(T[] v) {
		for(int i=0;i<2*N;i++) {
			dat.add(d1);
		}
		for(int i=0;i<v.length;i++) {
			dat.set(N+i-1,v[i]);
		}
		for(int i=N-2;i>=0;i--) {
			dat.set(i,f.apply(dat.get(i*2+1),dat.get(i*2+2)));
		}
	}
	
	void update(int k,E a) {
		k += N-1;
		dat.set(k,g.apply(dat.get(k),a));
		while(k>0){
			k = (k-1)/2;
			dat.set(k,f.apply(dat.get(k*2+1),dat.get(k*2+2)));
		}
	}
	
	T query(int a,int b, int k, int l ,int r) {
		if(r<=a||b<=l) return d1;
		if(a<=l&&r<=b) return dat.get(k);
		T vl = query(a,b,k*2+1,l,(l+r)/2);
		T vr = query(a,b,k*2+2,(l+r)/2,r);
		return f.apply(vl, vr);
	}
	T query(int a,int b){
		return query(a,b,0,0,N);
	}
	
}
	
class LazySegmentTree<T,E> extends SegmentTree<T,E>{
	BiFunction<E,E,E> h;
	BiFunction<E,Integer,E> p = (E a,Integer b) ->{return a;};
	E d0;
	ArrayList<E> laz;
	LazySegmentTree(BiFunction<T,T,T> F,BiFunction<T,E,T> G,BiFunction<E,E,E> H,T D1,E D0,T[] v){
		super(F,G,D1,v);
		int n = v.length;
		h = H;
		d0 = D0;
		Init(n);
	}
	void build() {
		
	}
	void Init(int n){
		laz = new ArrayList<E>();
		for(int i=0;i<2*N;i++) {
			laz.add(d0);
		}
	}
	
	void eval(int len,int k) {
		if(laz.get(k).equals(d0)) return;
		if(k*2+1<N*2-1) {
			laz.set(k*2+1,h.apply(laz.get(k*2+1),laz.get(k)));
			laz.set(k*2+2,h.apply(laz.get(k*2+2),laz.get(k)));
		}
		dat.set(k,g.apply(dat.get(k), p.apply(laz.get(k), len)));
		laz.set(k,d0);
	}
	
	T update(int a,int b,E x,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) {
			return dat.get(k);
		}
		if(a<=l&&r<=b) {
			laz.set(k,h.apply(laz.get(k),x));
			return g.apply(dat.get(k),p.apply(laz.get(k),r-l));
		}
		T vl = update(a,b,x,k*2+1,l,(l+r)/2);
		T vr = update(a,b,x,k*2+2,(l+r)/2,r);
		dat.set(k,f.apply(vl,vr));
		return dat.get(k);
		
	}
	
	T update(int a,int b,E x) {
		return update(a,b,x,0,0,N);
	}
	
	T query(int a,int b,int k,int l,int r) {
		eval(r-l,k);
		if(r<=a||b<=l) return d1;
		if(a<=l&&r<=b) return dat.get(k);
		T vl = query(a,b,k*2+1,l,(l+r)/2);
		T vr = query(a,b,k*2+2,(l+r)/2,r);
		return f.apply(vl, vr);
	}
	
	T query(int a,int b){
		return query(a,b,0,0,N);
	}
	
}
class UnionFindTree {
	int[] root;
	int[] rank;
	int[] size;
	UnionFindTree(int N){
		root = new int[N];
		rank = new int[N];
		size = new int[N];
		for(int i=0;i<N;i++){
			root[i] = i;
			size[i] = 1;
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
				size[y] += size[x];
			}else{
				root[y] = x;
				size[x] += size[y];
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
	long[] maxtra(int s,long l){
		long[] L = new long[size];
		for(int i=0;i<size;i++){
			L[i] = -1;
		}
		int[] visited = new int[size];
		L[s] = -1;
	;
		PriorityQueue<Pair> Q = new PriorityQueue<Pair>(new SampleComparator());
		Q.add(new Pair(l,s));

		while(!Q.isEmpty()){

			Pair C = Q.poll();
			if(visited[(int)C.b]==0){
				L[(int)C.b] = C.a;
				visited[(int) C.b] = 1;
				for(Edge D:list[(int) C.b]){
					Q.add(new Pair(Math.max(L[(int)C.b],D.cost),D.to));
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
	
	ArrayList<Integer> Kahntsort(){

		ArrayList<Integer> ans = new ArrayList<Integer>();
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		int[] in = new int[size];
		for(int i=0;i<size;i++) {
			for(Edge e:list[i]) {
				in[e.to]++;
			}
		}
		for(int i=0;i<size;i++) {
			if(in[i]==0) {
				q.add(i);
			}
		}
		while(!q.isEmpty()) {
			int v = q.poll();
			ans.add(v);
			for(Edge e:list[v]) {
				in[e.to]--;
				if(in[e.to]==0) {
					q.add(e.to);
				}
			}
		}
		for(int i=0;i<size;i++) {
			if(in[i]>0)return new ArrayList<Integer>();
		}
		return ans;
	}
}


class Tree extends Graph{
	
	public Tree(int N) {
		super(N);
	}
	
	long[] tyokkei(){
		long[] a = bfs(0);
		
		System.out.println();
		int maxdex = -1;
		long max = 0;
		for(int i=0;i<size;i++){
			if(max<a[i]){
				max = a[i];
				maxdex = i;
			}
		}
 
		long[] b = bfs(maxdex);
		System.out.println();
		int maxdex2 = -1;
		long max2 = 0;
		for(int i=0;i<size;i++){
			if(max2<b[i]){
				max2 = b[i];
				maxdex2 = i;
			}
		}
		long[] ans = {max2,maxdex,maxdex2};
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
	
	public int isBigger(int[] d, int i) {
		int ok = d.length;
		int ng = -1;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]>i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}
	
	public int isSmaller(int[] d, int i) {
		int ok = -1;
		int ng = d.length;
		while(Math.abs(ok-ng)>1) {
			int mid = (ok+ng)/2;
			if(d[mid]<i) {
				ok = mid;
			}else {
				ng = mid;
			}
		}
		return ok;
	}

	public HashSet<Integer> primetable(int m) {
		HashSet<Integer> pt = new HashSet<Integer>();
		for(int i=2;i<=m;i++) {
			boolean b = true;
			for(int d:pt) {
				if(i%d==0) {
					b = false;
					break;
				}
			}
			if(b) {
				pt.add(i);
			}
		}
		return pt;
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
	
	public long perm(int a,int num) {
		if(!isBuild) {
			buildFac();
		}
		return fac[a] * (rev(fac[a-num]))%mod;
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