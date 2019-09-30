import java.util.*;
import java.io.*;
import java.awt.geom.*;
import java.math.*;

public class Main {

	static final Reader in = new Reader();
	static final PrintWriter out = new PrintWriter(System.out,false);
	static boolean debug = false;

	static int[][] g;

	static int[][] undirectedGraph(int n, int[] v1, int[] v2) {
		int[] cnt = new int[n];
		for (int i : v1) cnt[i]++;
		for (int i : v2) cnt[i]++;

		int[][] g = new int[n][];
		for (int i=0; i<n; i++) g[i] = new int[cnt[i]];
		for (int i=0; i<v1.length; i++) {
			int s = v1[i];
			int t = v2[i];
			g[s][--cnt[s]] = t;
			g[t][--cnt[t]] = s;
		}

		return g;
	}

	static int[] dijkstra(int[][] g, int source) {
		int n = g.length;

		final int[] d = new int[n];
		Arrays.fill(d, -1);
		d[source] = source;

		TreeSet<Integer> pQ = new TreeSet<Integer>(new Comparator<Integer>(){
			public int compare(Integer a, Integer b) {
				if (d[a] != d[b]) return d[b] - d[a];
				return a - b;
			}
		});
		pQ.add(source);

		while (!pQ.isEmpty()) {
			int cur = pQ.pollFirst();

			for (int i=0; i<g[cur].length; i++) {
				int next = g[cur][i];
				int dist = Math.min(d[cur], g[cur][i]);
				if (dist > d[next]) {
					pQ.remove(next);
					d[next] = dist;
					pQ.add(next);
				}
			}
		}

		return d;
	}

	static void solve(){
		int n = in.nextInt();
		int m = in.nextInt();
		int source = in.nextInt() - 1;

		int[] s = new int[m];
		int[] t = new int[m];
		for (int i=0; i<m; i++) {
			s[i] = in.nextInt() - 1;
			t[i] = in.nextInt() - 1;
		}

		g = undirectedGraph(n, s, t);
		int[] d = dijkstra(g, source);
		for (int i=0; i<n; i++) {
			if (i == d[i]) {
				out.println((i+1));
			}
		}
	}

	public static void main(String[] args) throws Exception {
		debug = args.length > 0;
		long start = System.nanoTime();

		solve();
		out.flush();

		long end = System.nanoTime();
		dump((end - start) / 1000000 + " ms");
		in.close();
		out.close();
	}

	static void dump(Object... o) { if (debug) System.err.println(Arrays.deepToString(o)); }
}

class Reader {
	private final InputStream in;
	private final byte[] buf = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	public Reader() { this(System.in);}
	public Reader(InputStream source) { this.in = source;}

	private boolean hasNextByte() {
		if (ptr < buflen) return true;
		ptr = 0;
		try{
			buflen = in.read(buf);
		}catch (IOException e) {e.printStackTrace();}
		if (buflen <= 0) return false;
		return true;
	}

	private int readByte() { if (hasNextByte()) return buf[ptr++]; else return -1;}

	private boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}

	private void skip() { while(hasNextByte() && !isPrintableChar(buf[ptr])) ptr++;}

	public boolean hasNext() {skip(); return hasNextByte();}

	public String next() {
		if (!hasNext()) throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext()) throw new NoSuchElementException();
		boolean minus = false;
		long num = readByte();

		if(num == '-'){
			num = 0;
			minus = true;
		}else if (num < '0' || '9' < num){
			throw new NumberFormatException();
		}else{
			num -= '0';
		}

		while(true){
			int b = readByte();
			if('0' <= b && b <= '9')
				num = num * 10 + (b - '0');
			else if(b == -1 || !isPrintableChar(b))
				return minus ? -num : num;
			else
				throw new NoSuchElementException();
		}
	}

	public int nextInt() {
		long num = nextLong();
		if (num < Integer.MIN_VALUE || Integer.MAX_VALUE < num)
			throw new NumberFormatException();
		return (int)num;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public char nextChar() {
		if (!hasNext()) throw new NoSuchElementException();
		return (char)readByte();
	}

	public String nextLine() {
		while (hasNextByte() && (buf[ptr] == '\n' || buf[ptr] == '\r')) ptr++;
		if (!hasNextByte()) throw new NoSuchElementException();

		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (b != '\n' && b != '\r' && b != -1) {
			sb.appendCodePoint(b);
			b = readByte();
		}

		return sb.toString();
	}

	public int[] nextIntArray(int n) {
		int[] res = new int[n];
		for (int i=0; i<n; i++) res[i] = nextInt();
		return res;
	}

	public char[] nextCharArray(int n) {
		char[] res = new char[n];
		for (int i=0; i<n; i++) res[i] = nextChar();
		return res;
	}

	public void close() {try{ in.close();}catch(IOException e){ e.printStackTrace();}};
}