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
		int n = ni();
		int m = ni();
		int[] a = na(n-1);
		int[][] b = new int[n][];
		for(int i = 0;i < n;i++){
			b[i] = na(m);
		}
		long[][] imos = new long[n+2][n+2];
		int[] row = new int[n];
		int[] pw = new int[n];
		int[] nw = new int[n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++)row[j] = b[j][i];
			enumPrevWall(row, pw);
			enumNextWall(row, nw);
			for(int j = 0;j < n;j++){
				// [pw[j]+1,j]*[j,nw[j]-1]
				add(imos, pw[j]+1, j, j, nw[j]-1, row[j]);
			}
		}
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= n;j++){
				imos[i][j+1] += imos[i][j];
			}
		}
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= n;j++){
				imos[j+1][i] += imos[j][i];
			}
		}
		
		long[] xs = new long[n];
		for(int i = 0;i < n-1;i++){
			xs[i+1] = xs[i] + a[i];
		}
		
		long max = 0;
		for(int i = 0;i < n;i++){
			for(int j = i;j < n;j++){
				max = Math.max(max,-(xs[j]-xs[i])+imos[i][j]); 
			}
		}
		out.println(max);
	}
	
	static void add(long[][] imos, int r1, int r2, int c1, int c2, long v)
	{
		imos[r1][c1] += v;
		imos[r1][c2+1] -= v;
		imos[r2+1][c1] -= v;
		imos[r2+1][c2+1] += v;
	}
	
	public static int[] enumPrevWall(int[] a, int[] L)
	{
		int n = a.length;
		for(int i = 0;i < n;i++){
			L[i] = i-1;
			while(L[i] >= 0 && a[L[i]] < a[i])L[i] = L[L[i]];
		}
		return L;
	}
	
	public static int[] enumNextWall(int[] a, int[] L)
	{
		int n = a.length;
		for(int i = n-1;i >= 0;i--){
			L[i] = i+1;
			while(L[i] < n && a[L[i]] <= a[i])L[i] = L[L[i]];
		}
		return L;
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