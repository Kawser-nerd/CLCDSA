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
		int mod = 1000000007;
		long[] dp0 = new long[n+1];
		long[] dp1 = new long[n+1];
		Arrays.fill(dp0, 1);
		dp0[0] = 0;
		dp1[0] = 1;
		for(int i = 0;i < m;i++){
			{
				long[] ndp0 = Arrays.copyOf(dp0, n+1);
				long[] ndp1 = Arrays.copyOf(dp1, n+1);
				// -1 or 0
				ndp0[n] -= dp0[n];
				ndp1[n] -= dp1[n];
				for(int j = 1;j <= n;j++){
					if(j-1 > 0){
						ndp0[j-1] += dp0[j];
						if (ndp0[j-1] >= mod)
							ndp0[j-1] -= mod;
					}else{
						ndp1[j-1] += dp0[j];
						if (ndp1[j-1] >= mod)
							ndp1[j-1] -= mod;
					}
					ndp1[j-1] += dp1[j];
					if (ndp1[j-1] >= mod)
						ndp1[j-1] -= mod;
				}
				dp0 = ndp0;
				dp1 = ndp1;
			}
			{
				long[] ndp0 = Arrays.copyOf(dp0, n+1);
				long[] ndp1 = Arrays.copyOf(dp1, n+1);
				// 0 or +1
				for(int j = 1;j <= n-1;j++){
					ndp0[j+1] += dp0[j];
					if (ndp0[j+1] >= mod)
						ndp0[j+1] -= mod;
				}
				for(int j = 0;j <= n-1;j++){
					ndp1[j+1] += dp1[j];
					if (ndp1[j+1] >= mod)
						ndp1[j+1] -= mod;
				}
				dp0 = ndp0;
				dp1 = ndp1;
			}
		}
		long ret = 0;
		for(int i = 0;i <= n;i++){
			ret += dp1[i];
		}
		out.println(ret%mod);
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