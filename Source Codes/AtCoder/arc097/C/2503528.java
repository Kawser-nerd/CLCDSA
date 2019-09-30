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
		int[] a = new int[2*n];
		for(int i = 0;i < 2*n;i++){
			char c = nc();
			if(c == 'W'){
				a[i] = -ni();
			}else{
				a[i] = ni();
			}
		}
		
		long[][] dp = new long[n+1][n+1];
		for(int i = 0;i <= n;i++){
			Arrays.fill(dp[i], Integer.MAX_VALUE);
		}
		dp[0][0] = 0;
		
		boolean[][] fronts = new boolean[n+1][n+1];
		int[] fs = new int[n+1];
		boolean[][] fronts2 = new boolean[n+1][n+1];
		int[] fs2 = new int[n+1];
		for(int i = 0;i < n+1;i++){
			boolean[] front = new boolean[n+1];
			int f = 0;
			for(int j = 0;j < 2*n;j++){
				if(a[j] == i+1)break;
				if(a[j] < 0){
					front[-a[j]] = true;
				}else if(a[j] < i+1)continue;
				f++;
			}
			fronts[i] = front;
			fs[i] = f;
		}
		for(int i = 0;i < n+1;i++){
			boolean[] front = new boolean[n+1];
			int f = 0;
			for(int j = 0;j < 2*n;j++){
				if(a[j] == -(i+1))break;
				if(a[j] > 0){
					front[a[j]] = true;
				}else if(a[j] > -(i+1))continue;
				f++;
			}
			fronts2[i] = front;
			fs2[i] = f;
		}
		
		for(int i = 0;i < n+1;i++){
			for(int j = 0;j < n+1;j++){
//				tr(i, j, fs, fs2);
				if(i < n){
					dp[i+1][j] = Math.min(
							dp[i+1][j], dp[i][j] + fs[i]);
					if(j+1 <= n && fronts[i][j+1])fs[i]--;
				}
				if(j < n){
					dp[i][j+1] = Math.min(
							dp[i][j+1], dp[i][j] + fs2[j]);
					if(i+1 <= n && fronts2[j][i+1])fs2[j]--;
				}
			}
		}
//		tr(dp);
		out.println(dp[n][n]);
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