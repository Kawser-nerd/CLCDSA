import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		IO io = new IO();
		int n = io.nextInt();
		int s1 = io.nextInt() - 1;
		int s2 = io.nextInt() - 1;
		long[] x = new long[n];
		long[] y = new long[n];
		for(int i=0;i<n;i++) {
			int xraw = io.nextInt();
			int yraw = io.nextInt();
			x[i] = xraw + yraw;
			y[i] = xraw - yraw;
		}
		long d = Math.max(Math.abs(x[s1] - x[s2]), Math.abs(y[s1] - y[s2]));
		UnionFind uf = new UnionFind(n);
		int[] degree = new int[n];
		solveHalf(n, x, y, d, d, degree, uf);
		solveHalf(n, y, x, d, d-1, degree, uf);
		long sum = 0;
		for(int i=0;i<n;i++) {
			if (uf.isConnected(s1, i)) {
				sum += degree[i];
			}
		}
		System.out.println(sum / 2);
	}
	

	@SuppressWarnings("unchecked")
	public static void solveHalf(int n,long[] x,long[] y,long dx, long dy,int[] degree,UnionFind uf) {
		long[] unzipx = new long[n];
		HashMap<Long, Integer> zipx = new HashMap<>();
		
		ArrayList<Pair> al = new ArrayList<>();
		for(int i=0;i<n;i++) {
			al.add(new Pair(i,x[i], y[i]));
		}
		al.sort((p1,p2)->{
			if (p1.x != p2.x) return Long.compare(p1.x, p2.x);
			return Long.compare(p1.y, p2.y);
		});
		int nx = 0;
		for(int i=0;i<n;i++) {
			Pair p = al.get(i);
			if (nx == 0 || unzipx[nx-1] != p.x) {
				unzipx[nx] = p.x;
				zipx.put(p.x, nx);
				nx++;
			}
		}
		
		ArrayList<Pair>[] points = new ArrayList[nx];
		for(int i=0;i<nx;i++) {
			points[i] = new ArrayList<>();
		}
		for(int i=0;i<n;i++) {
			Pair p = al.get(i);
			points[zipx.get(p.x)].add(p);
		}
		
		int[][] imos = new int[nx][];
		for(int i=0;i<nx;i++) {
			imos[i] = new int[points[i].size()+1];
		}
		
		for(Pair p: al) {
			union(dy, uf, points, imos, p, degree, zipx.get(p.x - dx));
			union(dy, uf, points, imos, p, degree, zipx.get(p.x + dx));
		}
		
		for(int i=0;i<nx;i++) {
			int m = points[i].size();
			for(int j=0;j<m;j++) {
				if (j > 0) {
					imos[i][j] += imos[i][j-1];
				}
				if (imos[i][j] > 0) {
					uf.union(points[i].get(j).i, points[i].get(j+1).i);
				}
			}
		}
	}


	private static void union(long dy, UnionFind uf, ArrayList<Pair>[] points, int[][] imos, Pair p, int[] degree, Integer x2) {
		if (x2 == null) {
			return;
		}
		int i1 = Bound.lowerBound(points[x2], p.y - dy);
		int i2 = Bound.upperBound(points[x2], p.y + dy);
		if (i1 > i2) {
			return;
		}
		degree[p.i] += i2 - i1 + 1;
		imos[x2][i1]++;
		imos[x2][i2]--;
		uf.union(p.i, points[x2].get(i1).i);
	}
}
class Bound {
	static int lowerBound(ArrayList<Pair> a,int fromIndex,int toIndex,long key) {
		if (a.get(toIndex-1).y < key) {
			return toIndex;
		}else if(a.get(fromIndex).y >= key) {
			return fromIndex;
		}
		int l = fromIndex;
		int r = toIndex - 1;
		while(l + 1 < r) {
			int c = (l + r) >>> 1;
			if (a.get(c).y >= key) {
				r = c;
			}else{
				l = c;
			}
		}
		return r;
	}
	static int lowerBound(ArrayList<Pair> a,long key) {
		return lowerBound(a, 0, a.size(), key);
	}
	static int upperBound(ArrayList<Pair> a,int fromIndex,int toIndex,long key) {
		if (a.get(toIndex-1).y <= key) {
			return toIndex - 1;
		}else if(a.get(fromIndex).y > key) {
			return fromIndex - 1;
		}
		int l = fromIndex;
		int r = toIndex - 1;
		while(l + 1 < r) {
			int c = (l + r) >>> 1;
			if (a.get(c).y > key) {
				r = c;
			}else{
				l = c;
			}
		}
		return l;
	}
	static int upperBound(ArrayList<Pair> a,long key) {
		return upperBound(a, 0, a.size(), key);
	}
}

class Pair {
	int i;
	long x,y;
	public Pair(int i, long x, long y) {
		super();
		this.i = i;
		this.x = x;
		this.y = y;
	}
}
class UnionFind {
	private int[] parent;
	public UnionFind(int size) {
		parent = new int[size];
		Arrays.fill(parent, -1);
	}
	public boolean union(int x,int y) {
		x = root(x);
		y = root(y);
		if (x!=y) {
			if (parent[y] < parent[x]) {
				int tmp = y;
				y = x;
				x = tmp;
			}
			parent[x] += parent[y];
			parent[y] = x;
			return true;
		}
		return false;
	}
	public boolean isConnected(int x,int y) {
		return root(x)==root(y);
	}
	private int root(int x) {
		return parent[x] < 0 ? x : (parent[x] = root(parent[x]));
	}
	public int size(int x) {
		return -parent[root(x)];
	}
	public ArrayList<ArrayList<Integer>> groups() {
		int n = parent.length;
		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		HashMap<Integer,Integer> hm = new HashMap<Integer, Integer>();
		for(int i=0;i<n;i++) {
			int r = root(i);
			if (!hm.containsKey(r)) {
				hm.put(r, g.size());
				g.add(new ArrayList<Integer>());
			}
			g.get(hm.get(r)).add(i);
		}
		return g;
	}
	public String toString() {
		return Arrays.toString(parent);
	}
}

class IO extends PrintWriter {
	private final InputStream in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;
	
	public IO() { this(System.in);}
	public IO(InputStream source) { super(System.out); this.in = source;}
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
	private static boolean isNewLine(int c) { return c == '\n' || c == '\r';}
	public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
	public boolean hasNextLine() { while(hasNextByte() && isNewLine(buffer[ptr])) ptr++; return hasNextByte();}
	public String next() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public char[] nextCharArray(int len) {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		char[] s = new char[len];
		int i = 0;
		int b = readByte();
		while(isPrintableChar(b)) {
			if (i == len) {
				throw new InputMismatchException();
			}
			s[i++] = (char) b;
			b = readByte();
		}
		return s;
	}
	public String nextLine() {
		if (!hasNextLine()) {
			throw new NoSuchElementException();
		}
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while(!isNewLine(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	public long nextLong() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
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
		if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
			throw new NumberFormatException();
		}
		return (int) nl;
	}
	public char nextChar() {
		if (!hasNext()) {
			throw new NoSuchElementException();
		}
		return (char) readByte();
	}
	public double nextDouble() { return Double.parseDouble(next());}
	public int[] nextIntArray(int n) { int[] a = new int[n]; for(int i=0;i<n;i++) a[i] = nextInt(); return a;}
	public long[] nextLongArray(int n) { long[] a = new long[n]; for(int i=0;i<n;i++) a[i] = nextLong(); return a;}
	public double[] nextDoubleArray(int n) { double[] a = new double[n]; for(int i=0;i<n;i++) a[i] = nextDouble(); return a;}
	public void nextIntArrays(int[]... a) { for(int i=0;i<a[0].length;i++) for(int j=0;j<a.length;j++) a[j][i] = nextInt();}
	public int[][] nextIntMatrix(int n,int m) { int[][] a = new int[n][]; for(int i=0;i<n;i++) a[i] = nextIntArray(m); return a;}
	public char[][] nextCharMap(int n,int m) { char[][] a = new char[n][]; for(int i=0;i<n;i++) a[i] = nextCharArray(m); return a;}
	public void close() { super.close(); try {in.close();} catch (IOException e) {}}
}