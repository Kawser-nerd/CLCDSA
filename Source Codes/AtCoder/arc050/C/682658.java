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
		long a = nl(), b = nl();
		int mod = ni();
		long g = gcd(a, b);
		long ten = pow(10, g, mod);
		int[][] M = {
				{(int)ten, 1},
				{0, 1}
		};
		int[] v = new int[]{0, 1};
		v = pow(M, v, a/g, mod);
		int[][] M2 = {
				{10, 1},
				{0, 1}
		};
		int[] v2 = new int[]{0, 1};
		v2 = pow(M2, v2, b, mod);
		out.println((long)v[0]*v2[0]%mod);
	}
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e, int mod)
	{
		int[][] MUL = A;
		for(int i = 0;i < v.length;i++)v[i] %= mod;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v, mod);
			MUL = p2(MUL, mod);
		}
		return v;
	}
	
	
	// int matrix * int vector
	public static int[] mul(int[][] A, int[] v, int mod)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				sum %= mod;
			}
			w[i] = (int)sum;
		}
		return w;
	}
	
	// int matrix^2 (cannot ensure negative values)
	public static int[][] p2(int[][] A, int mod)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				long sum = 0;
				for(int k = 0;k < n;k++){
					sum += (long)A[i][k] * A[k][j];
					sum %= mod;
				}
				C[i][j] = (int)sum;
			}
		}
		return C;
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
	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
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