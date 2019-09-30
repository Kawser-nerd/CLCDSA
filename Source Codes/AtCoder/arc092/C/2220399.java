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
		int[] a = na(n);
		long s0 = 0;
		boolean[] use0 = new boolean[n];
		for(int i = 0;i < n;i+=2){
			if(a[i] > 0){
				s0 += a[i];
				use0[i] = true;
			}
		}
		long s1 = 0;
		boolean[] use1 = new boolean[n];
		for(int i = 1;i < n;i+=2){
			if(a[i] > 0){
				s1 += a[i];
				use1[i] = true;
			}
		}
		
		if(s0 == 0 && s1 == 0){
			int max = Integer.MIN_VALUE;
			int arg = -1;
			for(int i = 0;i < n;i++){
				if(a[i] > max){
					max = a[i];
					arg = i;
				}
			}
			out.println(max);
			out.println(n-1);
			for(int i = n-1;i > arg;i--){
				out.println(i+1);
			}
			for(int i = 0;i < arg;i++){
				out.println(1);
			}
			return;
		}
		
		if(s0 > s1){
			out.println(s0);
			go(n, use0);
		}else{
			out.println(s1);
			go(n, use1);
		}
	}
	
	static void go(int n, boolean[] use0)
	{
		int first = 0;
		for(int i = 0;i < n;i++){
			if(use0[i]){
				first = i;
				break;
			}
		}
		int nu = 0;
		for(int i = 0;i < n;i++){
			if(use0[i])nu++;
		}
		
		{
			int ans = 0;
			int st = 0;
			for(int i = n-1;i >= first;i--){
				if(st == 0){
					if(use0[i]){
						st = 1;
						continue;
					}
					ans++;
				}else if(i > 0 && !use0[i] && !use0[i+1] && !use0[i-1]){
					ans++;
					i--;
				}
			}
			for(int i = 0;i < nu-1;i++){
				ans++;
			}
			for(int i = 0;i < first;i++){
				ans++;
			}
			out.println(ans);
		}
		{
			int st = 0;
			for(int i = n-1;i >= first;i--){
				if(st == 0){
					if(use0[i]){
						st = 1;
						continue;
					}
					out.println(i+1);
				}else if(i > 0 && !use0[i] && !use0[i+1] && !use0[i-1]){
					out.println(i+1);
					i--;
				}
			}
			for(int i = 0;i < nu-1;i++){
				out.println(first+2);
			}
			for(int i = 0;i < first;i++){
				out.println(1);
			}
		}
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