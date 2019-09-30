import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni(), K = ni();
		int[] P = na(n);
		for(int i = 0;i < n;i++)P[i]--;
		int[] Q = na(n);
		for(int i = 0;i < n;i++)Q[i]--;
		
		// -p, q, p, -q
		// q -p -q p
		
		/*
[5, [-q]]
[6, [p, -q]]
[7, [q, p, -q]]
[8, [q]]
[9, [q, -p]]
[10, [q, -p, -q]]
		 * 
		 */
		if(K == 1){
			for(int i = 0;i < n;i++){
				out.print(P[i]+1 + " ");
			}
			out.println();
			return;
		}
		
		int[] A = mul(inv(P), Q, P, inv(Q)); 
		int[] B = mul(Q, inv(P), inv(Q), P);
		
		int[] f = new int[n];
		for(int i = 0;i < n;i++)f[i] = i;
		f = pow(A, (K-2)/6, f);
		if(K % 6 == 2){
			f = mul(Q, f);
		}else if(K % 6 == 3){
			f = mul(Q, inv(P), f);
		}else if(K % 6 == 4){
			f = mul(Q, inv(P), inv(Q), f);
		}else if(K % 6 == 5){
			f = mul(inv(Q), f);
		}else if(K % 6 == 0){
			f = mul(P, inv(Q), f);
		}else if(K % 6 == 1){
			f = mul(Q, P, inv(Q), f);
		}
		f = pow(B, (K+1)/6, f);
		
		for(int i = 0;i < n;i++){
			out.print(f[i]+1 + " ");
		}
		out.println();
	}
	
	static int[] pow(int[] f, int e, int[] a)
	{
		while(e > 0){
			if((e&1) == 1){
				a = mul(f, a);
			}
			f = mul(f, f);
			e>>>=1;
		}
		return a;
	}
	
	static int[] mul(int[]... x)
	{
		int[] f = mul(x[x.length-2], x[x.length-1]);
		for(int i = x.length-3;i >= 0;i--){
			f = mul(x[i], f);
		}
		return f;
	}
	
	static int[] mul(int[] f, int[] g)
	{
		int[] ret = new int[f.length];
		for(int i = 0;i < g.length;i++){
			ret[i] = f[g[i]];
		}
		return ret;
	}
	
	static int[] inv(int[] f)
	{
		int[] ret = new int[f.length];
		for(int i = 0;i < f.length;i++)ret[f[i]] = i;
		return ret;
	}
	
	static List<String> clean(List<String> x)
	{
		outer:
		while(true){
			for(int i = 0;i < x.size()-1;i++){
				String l = x.get(i);
				String r = x.get(i+1);
				if(l.length() == 1 && r.length() == 2 && l.charAt(0) == r.charAt(1)){
					x.remove(i);
					x.remove(i);
					continue outer;
				}
				if(r.length() == 1 && l.length() == 2 && r.charAt(0) == l.charAt(1)){
					x.remove(i);
					x.remove(i);
					continue outer;
				}
			}
			return x;
		}
	}
	
	static List<String> rev(List<String> x)
	{
		List<String> y = new ArrayList<>();
		for(int i = x.size()-1;i >= 0;i--){
			String t = x.get(i);
			if(t.length() == 2){
				y.add(t.substring(1));
			}else{
				y.add("-" + t);
			}
		}
		return y;
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