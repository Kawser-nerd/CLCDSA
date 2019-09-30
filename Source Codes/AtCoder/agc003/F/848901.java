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
		int n = ni(), m = ni();
		long K = nl();
		char[][] map = nm(n,m);
		K--;
		int s = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '#'){
					s++;
				}
			}
		}
		int vc = 0;
		int hc = 0;
		for(int i = 0;i < n;i++){
			if(map[i][0] == '#' && map[i][m-1] == '#'){
				hc++;
			}
		}
		for(int i = 0;i < m;i++){
			if(map[0][i] == '#' && map[n-1][i] == '#'){
				vc++;
			}
		}
		int lhc = 0, lvc = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(j+1 < m && map[i][j] == '#' && map[i][j+1] == '#'){
					lhc++;
				}
				if(i+1 < n && map[i][j] == '#' && map[i+1][j] == '#'){
					lvc++;
				}
			}
		}
//		tr(lhc, lvc, hc, vc, s);
		if(hc > 0 && vc > 0){
			out.println(1);
			return;
		}
		int mod = 1000000007;
		if(hc == 0 && vc == 0){
			out.println(pow(s, K, mod));
		}else{
			int[][] M = new int[2][2];
			M[0][0] = s;
			M[1][1] = hc+vc;
			M[0][1] = mod-1;
			int[] v = new int[]{1, hc > 0 ? lhc : lvc};
			int[] ret = pow(M, v, K);
			out.println(ret[0]);
		}
	}
	
	///////// begin
	public static final int mod = 1000000007;
	public static final long m2 = (long)mod*mod;
	public static final long BIG = 8L*m2;
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e)
	{
		for(int i = 0;i < v.length;i++){
			if(v[i] >= mod)v[i] %= mod;
		}
		int[][] MUL = A;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v);
			MUL = p2(MUL);
		}
		return v;
	}
	
	// int matrix*int vector
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				if(sum >= BIG)sum -= BIG;
			}
			w[i] = (int)(sum % mod);
		}
		return w;
	}
	
	// int matrix^2 (be careful about negative value)
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			long[] sum = new long[n];
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					sum[j] += (long)A[i][k] * A[k][j];
					if(sum[j] >= BIG)sum[j] -= BIG;
				}
			}
			for(int j = 0;j < n;j++){
				C[i][j] = (int)(sum[j] % mod);
			}
		}
		return C;
	}
	
	//////////// end
	
	public static long invl(long a, long mod) {
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
		return p < 0 ? p + mod : p;
	}

	
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
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

	
	static int con(char[][] map)
	{
		int n = map.length, m = map[0].length;
		DJSet ds = new DJSet(n*m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(j+1 < m && map[i][j] == '#' && map[i][j+1] == '#'){
					ds.union(i*m+j, i*m+j+1);
				}
				if(i+1 < m && map[i][j] == '#' && map[i+1][j] == '#'){
					ds.union(i*m+j, (i+1)*m+j);
				}
			}
		}
		int ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '#' && ds.upper[i*m+j] < 0)ret++;
			}
		}
		return ret;
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