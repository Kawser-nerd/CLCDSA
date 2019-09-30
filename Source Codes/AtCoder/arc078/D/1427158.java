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
		int[][] g = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(g[i], -1);
		}
		int m = ni();
		long csum = 0;
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			g[f][t] = g[t][f] = ni();
			csum += g[f][t];
		}
		
		long[][] dp = new long[1<<n][n];
		for(int i = 0;i < 1<<n;i++){
			Arrays.fill(dp[i], -9999999999L);
		}
		
		long[] score = new long[1<<n];
		for(int i = 0;i < 1<<n;i++){
			for(int j = 0;j < n;j++){
				if(i<<~j<0){
					for(int k = j+1;k < n;k++){
						if(i<<~k<0 && g[j][k] != -1){
							score[i] += g[j][k];
						}
					}
				}
			}
		}
		
		for(int i = 1;i < 1<<n-1;i+=2){
			dp[i][0] = score[i];
		}
		for(int i = 1;i < 1<<n;i++){
			for(int j = 0;j < n;j++){
				if(dp[i][j] < 0)continue;
				for(int to = 1;to < n;to++){
					if(g[j][to] != -1 && i<<~to>=0){
						int mask = (1<<n)-1^i^1<<to;;
						for(int u = mask;u >= 0;u--){ u &= mask; 
							int l = u^1<<to;
//						for(int l = 0;l < 1<<n;l++){
//							if((i&l) == 0 && l<<~to<0){
								dp[i|l][to] = Math.max(
										dp[i|l][to], 
										dp[i][j] + score[l] + g[j][to]);
//							}
						}
					}
				}
			}
		}
//		long max = 0;
//		for(int i = 0;i < 1<<n;i++){
//			max = Math.max(max, dp[i][n-1] + score[(1<<n)-1-i]);
//		}
		
		out.println(csum - dp[(1<<n)-1][n-1]);
		
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