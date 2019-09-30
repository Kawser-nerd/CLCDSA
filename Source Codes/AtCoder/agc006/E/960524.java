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
		int[][] a = new int[3][];
		for(int i = 0;i < 3;i++){
			a[i] = na(n);
		}
		boolean[] spin = new boolean[n];
		int[] vs = new int[n];
		for(int i = 0;i < n;i++){
			if(
					a[0][i] % 3 == 1 && 
					a[1][i] == a[0][i] + 1 && 
					a[2][i] == a[1][i] + 1){
				spin[i] = false;
				int v = a[2][i] / 3;
				if(v % 2 == i % 2){
					out.println("No");
					return;
				}
				vs[i] = v;
			}else if(
					a[2][i] % 3 == 1 && 
					a[1][i] == a[2][i] + 1 && 
					a[0][i] == a[1][i] + 1){
				spin[i] = true;
				int v = a[0][i] / 3;
				if(v % 2 == i % 2){
					out.println("No");
					return;
				}
				vs[i] = v;
			}else{
				out.println("No");
				return;
			}
		}
		
		boolean[] base = new boolean[n];
		for(int i = 0;i < n;i++){
			base[i] = (((vs[i]-1)-i)/2&1) == 1;
		}
		for(int i = 0;i < n;i++)vs[i]--;
		
		int[] ia = new int[n];
		for(int i = 0;i < n;i++)ia[vs[i]] = i;
		{
			int[] ft = new int[n+3];
			int[] poss = new int[n+3];
			// 201
			// 00000 00000
			// 01010 2 2 0
			// 
			for(int i = 0;i < n;i+=2){
				int from = ia[i]+sumFenwick(poss, ia[i])+i;
				int to = i;
				assert to <= from;
				ft[to+1]^=1;
				ft[from+1]^=1;
				addFenwick(poss, ia[i]+1, -2);
			}
			for(int i = 1;i < n;i++){
				ft[i] ^= ft[i-1];
				base[i] ^= (i&1) == 1 && ft[i] == 1;
			}
		}
		{
			int[] ft = new int[n+3];
			int[] poss = new int[n+3];
			for(int i = 1;i < n;i+=2){
				int from = ia[i]+sumFenwick(poss, ia[i]) + i-1;
				int to = i;
				assert to <= from;
				ft[to+1] ^= 1;
				ft[from+1] ^= 1;
				addFenwick(poss, ia[i]+1, -2);
			}
			for(int i = 2;i < n;i++){
				ft[i] ^= ft[i-1];
				base[i] ^= (i&1) == 0 && ft[i] == 1;
			}
		}
		
		boolean[] par = new boolean[2];
		for(int i = 0;i < n;i++){
			par[i&1] ^= base[i];
			par[i&1] ^= spin[i];
		}
		if(!par[0] && !par[1]){
			out.println("Yes");
		}else{
			out.println("No");
		}
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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