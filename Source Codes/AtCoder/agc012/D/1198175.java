import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), x = ni(), y = ni();
		int[][] bs = new int[n][];
		int[] mins = new int[n];
		int[] argmins = new int[n];
		Arrays.fill(mins, Integer.MAX_VALUE);
		Arrays.fill(argmins, -1);
		for(int i = 0;i < n;i++){
			bs[i] = new int[]{ni()-1, ni()};
		}
		for(int i = 0;i < n;i++){
			if(bs[i][1] < mins[bs[i][0]]){
				mins[bs[i][0]] = bs[i][1];
				argmins[bs[i][0]] = i;
			}
		}
		Ranking rs = new Ranking(2);
		for(int i = 0;i < n;i++){
			rs.query(mins[i], argmins[i]);
		}
		int mod = 1000000007;
		int[][] fif = enumFIF(500000, mod);
		DJSet ds = new DJSet(n);
		
		for(int i = 0;i < n;i++){
			if((long)bs[i][1] + mins[bs[i][0]] <= x){
				ds.union(i, argmins[bs[i][0]]);
			}
			if(mins[bs[i][0]] == rs.min[0]){
				if((long)bs[i][1] + rs.min[1] <= y){
					if(rs.argmin[1] != -1){
						ds.union(rs.argmin[1], i);
					}
				}
			}else{
				if((long)bs[i][1] + rs.min[0] <= y){
					ds.union(rs.argmin[0], i);
				}
			}
		}
		boolean[] diff = new boolean[n];
		for(int i = 0;i < n;i++){
			if(bs[ds.root(i)][0] != bs[i][0]){
				diff[ds.root(i)] = true;
			}
		}
		long gret = 1;
		for(int i = 0;i < n;i++){
			if(diff[i]){
				int[] counts = new int[n];
				for(int j = 0;j < n;j++){
					if(ds.root(j) == i){
						counts[bs[j][0]]++;
					}
				}
				long den = 1;
				int all = 0;
				for(int k = 0;k < n;k++){
					all += counts[k];
					den = den * fif[1][counts[k]] % mod;
				}
				long ret = fif[0][all] * den % mod;
				gret = gret * ret % mod;
			}
		}
		
		out.println(gret);
	}
	
	public static class Ranking {
		public long[] min;
		public int[] argmin;
		public int K;
		
		public Ranking(int K)
		{
			this.K = K;
			min = new long[K];
			Arrays.fill(min, Long.MAX_VALUE);
			argmin = new int[K];
			Arrays.fill(argmin, -1);
		}
		
		public void query(long v, int ind)
		{
//			if(v >= min[K-1])return;
			for(int i = 0;i < K;i++){
				if(v < min[i]){
					for(int j = K-2;j >= i;j--){
						min[j+1] = min[j];
						argmin[j+1] = argmin[j];
					}
					min[i] = v;
					argmin[i] = ind;
					break;
				}
			}
		}
	}

	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}

	public static void main(String[] args) throws Exception
	{
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
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
	
	private static long nl()
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
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}