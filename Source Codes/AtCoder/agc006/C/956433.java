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
		long[] x = new long[n];
		for(int i = 0;i < n;i++)x[i] = nl();
		int m = ni();
		long K = nl();
		int[] a = na(m);
		for(int i = 0;i < a.length;i++)a[i]--;
		
		int[] ord = new int[n-1];
		for(int i = 0;i < n-1;i++)ord[i] = i;
		for(int i = 0;i < m;i++){
			int d = ord[a[i]-1]; ord[a[i]-1] = ord[a[i]]; ord[a[i]] = d;
		}
		int[][] sf = sparseNext(ord);
		int[] nf = new int[n-1];
		for(int i = 0;i < n-1;i++){
			nf[i] = go(i, K, sf);
		}
		
		long xx = x[0];
		for(int i = 0;i < n;i++){
			if(i > 0){
				xx += x[nf[i-1]+1]-x[nf[i-1]];
			}
			out.println(xx);
		}
	}
	
	public static int go(int from, long step, int[][] sf)
	{
		int cur = from;
		for(int i = sf.length-1;i >= 0;i--){
			if(step<<~i<0){
				cur = sf[i][cur];
				if(cur == -1)break;
			}
		}
		return cur;
	}
	
	public static int[][] sparseNext(int[] f)
	{
		int n = f.length;
		final int m = 61; // 
		int[][] sf = new int[m][n];
		sf[0] = Arrays.copyOf(f, n);
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sf[i][j] = sf[i-1][j] == -1 ? -1 : sf[i-1][sf[i-1][j]];
			}
		}
		return sf;
	}

	
	public static int[] uniq(int[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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