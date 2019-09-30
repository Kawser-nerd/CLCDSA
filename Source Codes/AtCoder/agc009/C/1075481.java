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
		long A = nl(), B = nl();
		long[] s = new long[n];
		for(int i = 0;i < n;i++){
			s[i] = nl();
		}
		
		// (i,0,j) -> (i+1,0,j) (s[i+1]-s[i] >= B)
		// (i,1,j) -> (i+1,1,j) (s[i+1]-s[i] >= A)
		// (i,0,j) -> (i+1,1,i) (s[i+1]-s[j] >= A)
		// (i,1,j) -> (i+1,0,i) (s[i+1]-s[j] >= B)
		
		int mod = 1000000007;
		long[][] dp = new long[2][n+1];
		int[] p = {-1, -1};
		dp[0][0] = 1;
		dp[1][0] = 1;
		long[] sum = new long[2];
		int[] q = new int[2];
		for(int i = 1;i < n;i++){
			while(p[0]+1 < i && (p[0] == -1 || s[i]-s[p[0]] >= A)){
				sum[0] += dp[0][p[0]+1];
				if(sum[0] >= mod)sum[0] -= mod;
				p[0]++;
			}
			while(p[1]+1 < i && (p[1] == -1 || s[i]-s[p[1]] >= B)){
				sum[1] += dp[1][p[1]+1];
				if(sum[1] >= mod)sum[1] -= mod;
				p[1]++;
			}
			dp[1][i] += sum[0];
			dp[0][i] += sum[1];
			if(s[i]-s[i-1] < B){
				while(q[0] < i){
					sum[0] -= dp[0][q[0]];
					dp[0][q[0]++] = 0;
				}
				if(p[0] < q[0]-1)p[0] = q[0]-1;
				sum[0] = 0;
			}
			if(s[i]-s[i-1] < A){
				while(q[1] < i){
					sum[1] -= dp[1][q[1]];
					dp[1][q[1]++] = 0;
				}
				if(p[1] < q[1]-1)p[1] = q[1]-1;
				sum[1] = 0;
			}
//			tr(dp[0], sum[0], p[0], q[0]);
//			tr(dp[1], sum[1], p[1], q[1]);
//			tr(p);
		}
		while(p[0] < n){
			sum[0] += dp[0][++p[0]];
		}
		while(p[1] < n){
			sum[1] += dp[1][++p[1]];
		}
		out.println((sum[0]+sum[1])%mod);
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