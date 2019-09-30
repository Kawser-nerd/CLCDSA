import java.util.*;
import java.io.*;

public class Main{
	static int Inf = Integer.MAX_VALUE/2;
	static FastScanner sn = new FastScanner();
	static int N,M,Q;
	static int[] a,b,y,v,w;
	static ArrayList<Node> node = new ArrayList<Node>();
	static ArrayList<Node> node2 = new ArrayList<Node>();
	static Union_Find f;
	public static void main(String[] args){
		N = sn.nextInt();
		M = sn.nextInt();		
		for(int i = 0; i < M; ++i){
			int a = sn.nextInt();
			int b = sn.nextInt();
			int y = sn.nextInt();			
			--a; --b;
			Node n = new Node();
			n.fs = a; n.sc = b; n.y = y;
			node.add(n);
		}
		Collections.sort(node);
		
		Q = sn.nextInt();		
		for(int i = 0; i < Q; ++i){
			int v = sn.nextInt();
			int w = sn.nextInt();
			Node n = new Node();
			n.fs = i; n.sc = --v; n.y = w;
			node2.add(n);
		}
		Collections.sort(node2);
		
		f = new Union_Find(N);
		int ans[] = new int[Q];
		int l = 0;
		for(int i = 0; i < Q; ++i){
			while(l < M && node.get(l).y > node2.get(i).y){
				f.unite(node.get(l).fs,node.get(l).sc);
				++l;
			}			
			ans[node2.get(i).fs] = f.size(node2.get(i).sc);
		}
		
		for(int i = 0;i < Q; ++i){
			System.out.println(ans[i]);
		}
	}
}

class Node implements Comparable<Node>{
	int fs;
	int sc;
   	int y;	
	public int compareTo(Node n){
		if(this.y > n.y) return -1;
		else if(this.y == n.y) return 0;
		else return 1;
	}
}

//union find
class Union_Find{
	int[] par;
	int[] rank;
	int[] size;
	Union_Find(int MAX_N){
		this.par = new int[MAX_N];
		this.rank = new int[MAX_N];
		this.size = new int[MAX_N];
		for(int i = 0; i < MAX_N; ++i){
			par[i] = i;
			rank[i] = 0;
			size[i] = 1;
		}
	}

	int root(int x){
		if(x == par[x]) return x;
		return par[x] = root(par[x]);
	}

	boolean same(int x, int y){
		return root(x) == root(y);
	}

	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x == y) return;
		if(rank[x] < rank[y]){
			par[x] = y;
			size[y] += size[x];
		}
		else{
			par[y] = x;
			size[x] += size[y];
			if(rank[x] == rank[y]) rank[x]++;
		}
 	}
	int size(int x){
		return size[root(x)];
	}
}

class FastScanner {
	private final InputStream in = System.in;
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
	public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
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
				return minus ? -n : n;
			}else{
					throw new NumberFormatException();
			}
			b = readByte();
		}
	}
	public int nextInt() {
		long nl = nextLong();
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
		return (int) nl;
	}
	public double nextDouble() { return Double.parseDouble(next());}
}