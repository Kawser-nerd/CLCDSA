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
		char[][] map = nm(n,m);
		int er = -1, ec = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'E'){
					er = i; ec = j;
				}
			}
		}
		int[][] cum = new int[n+1][m+1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + (map[i][j] == 'o' ? 1 : 0);
			}
		}
		int[][][][] dp = new int[n][][][];
		for(int i = 0;i < n;i++){
			dp[i] = new int[n-i][][];
			for(int j = 0;i+j < n;j++){
				dp[i][j] = new int[m][];
				for(int k = 0;k < m;k++){
					dp[i][j][k] = new int[m-k];
					Arrays.fill(dp[i][j][k], -99999999);
				}
			}
		}
		for(int h = 1;h <= n;h++){
			for(int w = 1;w <= m;w++){
				for(int i = 0;i+h-1 < n;i++){
					for(int j = 0;j+w-1 < m;j++){
						if(i <= er && er < i+h && j <= ec && ec < j+w){
							int k = i+h-1, l = j+w-1;
							if(h == 1 && w == 1){
								dp[i][k-i][j][l-j] = 0;
								continue;
							}
							// (r1,c1,r2,c2)
							// ((r2-er),(c2-ec), n-1-(er-r1), m-1-(ec-c1))
							if(i+1 <= k){
								dp[i][k-i][j][l-j] = Math.max(dp[i][k-i][j][l-j], dp[i+1][k-(i+1)][j][l-j]
										+ get(Math.max(i, k-er), Math.max(j, l-ec), Math.min(i, n-1-(er-(i+1))), Math.min(l, m-1-(ec-j)), cum));
							}
							if(i <= k-1){
								dp[i][k-i][j][l-j] = Math.max(dp[i][k-i][j][l-j], dp[i][k-1-i][j][l-j]
									+ get(Math.max(k, k-1-er), Math.max(j, l-ec), Math.min(k, n-1-(er-i)), Math.min(l, m-1-(ec-j)), cum));
							}
							if(j+1 <= l){
								dp[i][k-i][j][l-j] = Math.max(dp[i][k-i][j][l-j], dp[i][k-i][j+1][l-(j+1)]
										+ get(Math.max(i, k-er), Math.max(j, l-ec), Math.min(k, n-1-(er-i)), Math.min(j, m-1-(ec-(j+1))), cum));
							}
							if(j <= l-1){
								dp[i][k-i][j][l-j] = Math.max(dp[i][k-i][j][l-j], dp[i][k-i][j][l-1-j]
										+ get(Math.max(i, k-er), Math.max(l, (l-1)-ec), Math.min(k, n-1-(er-i)), Math.min(l, m-1-(ec-j)), cum));
							}
						}
					}
				}
			}
		}
		out.println(dp[0][n-1][0][m-1]);
	}
	
	static int get(int r1, int c1, int r2, int c2, int[][] cum)
	{
		if(r1 > r2 || c1 > c2)return 0;
		return cum[r2+1][c2+1] - cum[r1][c2+1] - cum[r2+1][c1] + cum[r1][c1];
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