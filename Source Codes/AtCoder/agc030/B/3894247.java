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
		int L = ni();
		int n = ni();
		int[] x = na(n);
		// L-(x[l]-x[l-1])
		// L-(x[l+1]-x[l-1])
		// L-(x[l+1]-x[l-2])
		// if l-2 = 0
		// L-(x[l+2]-x[l-2]) +(L-x[l+2])
		
		// L-(x[l+1]-x[l])
		// L-(x[l+1]-x[l-1])
		// L-(x[l+2]-x[l-1])
		// L-(x[l+2]-x[l-2])
		// +x[l-2]
		long ans = go(x, L);
		for(int i = 0;i < n;i++)x[i] = L-x[i];
		Arrays.sort(x);
		ans = Math.max(ans, go(x, L));
		out.println(ans);
	}
	
	
	
	static long go(int[] x, long L)
	{
		int n = x.length;
		long[] cum = new long[n+1];
		for(int i = 0;i < n;i++) {
			cum[i+1] = cum[i] + x[i];
		}
		long max = Long.MIN_VALUE;
		for(int i = 0;i < n;i++) {
			int l = i, r = n-1-i;
			if(l <= r) {
				long ret = L*(2*l+1) - (cum[i+l+1] - cum[i+1]) * 2 + (cum[i] - cum[i-l]) * 2 - x[i];
				max = Math.max(max, ret);
			}else {
				// L-(x[l]-x[l-1])
				// L-(x[l+1]-x[l-1])
				// L-(x[l+1]-x[l-2])
				// +x[l-2]
				long ret = L*(2*r+1) - (cum[i+r+1] - cum[i+1]) * 2 + (cum[i] - cum[i-r-1]) * 2 - x[i];
				max = Math.max(max, ret);
			}
		}
		return max;
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