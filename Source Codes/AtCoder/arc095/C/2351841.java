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
		map = nm(n,m);
		int[] ord = new int[n];
		out.println(dfs(0, ord, 0) ? "YES" : "NO");
	}
	
	static int ct = 0;
	static char[][] map;
	
	static boolean dfs(int pos, int[] ord, int ptn)
	{
		int n = ord.length;
		if(pos == n){
			ct++;
			int m = map[0].length;
			boolean[] dp = new boolean[1<<m];
			dp[0] = true;
			for(int k = 0;k < m;k++){
				inner:
				for(int l = k+1;l < m;l++){
					for(int i = 0;i <= n-1-i;i++){
						int j = n-1-i;
						if(map[ord[i]][k] == map[ord[j]][l] && map[ord[j]][k] == map[ord[i]][l]){
						}else{
							continue inner;
						}
					}
					
					int mask = (1<<m)-1^1<<k^1<<l;
					for(int i = mask;i >= 0;i--){
						i &= mask; 
						dp[i|1<<k|1<<l] |= dp[i];
						} // include i=0
				}
			}
			inner:
			for(int k = 0;k < m;k++){
				int l = k;
				for(int i = 0;i <= n-1-i;i++){
					int j = n-1-i;
					if(map[ord[i]][k] == map[ord[j]][l] && map[ord[j]][k] == map[ord[i]][l]){
					}else{
						continue inner;
					}
				}
				
				dp[(1<<m)-1] |= dp[(1<<m)-1^1<<k];
			}
			return dp[(1<<m)-1];
		}
		for(int i = pos < n/2 && pos >= 1 ? ord[pos-1] + 1 : 0;i < n;i++){
			if(ptn<<~i>=0){
				if(pos >= (n+1)/2 && i < ord[n-1-pos])continue;
				ord[pos] = i;
				boolean res = dfs(pos+1, ord, ptn|1<<i);
				if(res)return true;
			}
		}
		return false;
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