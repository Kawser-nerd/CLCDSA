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
		char[] s = ns().toCharArray();
		int n = s.length;
		
		long[][] dp = new long[5][3]; // #o #x
		dp[0][0] = 1;
		int mod = 1000000007;
		for(int i = 0;i < n;i++){
			long[][] ndp = new long[5][3]; // #o #x
			for(int j = 0;j <= 4;j++){
				for(int k = 0;k < 3;k++){
					if(s[i] == '0' || s[i] == '?'){
						ndp[j][k == 2 ? 1 : k+1] += dp[j][k];
					}
					if(s[i] == '1' || s[i] == '?'){
						if(k == 0){
							ndp[Math.min(j+1, 4)][0] += dp[j][k];
						}else{
							ndp[j][k-1] += dp[j][k];
						}
					}
				}
			}
			for(int j = 0;j <= 4;j++){
				for(int k = 0;k < 3;k++){
					dp[j][k] = ndp[j][k] % mod;
				}
			}
		}
		
		long ret = 0;
		for(int j = 0;j <= 4;j++){
			for(int k = 0;k < j && k < 3;k++){
				ret += dp[j][k];
			}
		}
		out.println(ret%mod);
	}
	
	static boolean ok2(int[] a)
	{
		int bal = 0;
		int z = 0;
		for(int i = 0;i < a.length;i++){
			if(a[i] == 0){
				z++;
			}else{
				bal++;
				bal -= z == 0 ? 0 : z - (z-1)/2*2;
				z = 0;
			}
		}
		bal -= z == 0 ? 0 : z - (z-1)/2*2;
		return bal > 0;
	}
	
	static boolean sh(int[] a)
	{
		boolean ch = false;
		for(int i = 0;i < a.length-2;i++){
			if(
					a[i] == 1 && a[i+1] == 0 && a[i+2] == 1 ||
					a[i] == 0 && a[i+1] == 1 && a[i+2] == 0
					){
				ch = true;
				int[] b = new int[a.length-2];
				int p = 0;
				for(int j = 0;j < i;j++)b[p++] = a[j];
				b[p++] = a[i]+a[i+1]+a[i+2] >= 2 ? 1 : 0;
				for(int j = i+3;j < a.length;j++)b[p++] = a[j];
				if(sh(b))return true;
			}
		}
		if(!ch)return ok(a);
		
		return false;
	}
	
	static boolean ok(int[] a)
	{
		if(a.length == 1){
			return a[0] == 1;
		}
		
		for(int i = 0;i < a.length-2;i++){
			int[] b = new int[a.length-2];
			int p = 0;
			for(int j = 0;j < i;j++)b[p++] = a[j];
			b[p++] = a[i]+a[i+1]+a[i+2] >= 2 ? 1 : 0;
			for(int j = i+3;j < a.length;j++)b[p++] = a[j];
			if(ok(b))return true;
		}
		return false;
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
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