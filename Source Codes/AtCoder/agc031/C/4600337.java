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
		List<int[]> one =new ArrayList<>();
		List<int[]> max = new ArrayList<>();
		{
			int[] a = {0};
			one.add(null);
			one.add(a);
			for(int i = 1;i < 18;i++){
				int[] b = con(con(a, new int[]{i}), a);
				one.add(b);
				a = b;
			}
			
			a = new int[]{0};
			max.add(null);
			max.add(a);
			for(int i = 2;i <= 17;i++){
				if(i % 2 == 0){
					int[] b = con(con(con(new int[]{i-1}, rev(one.get(i-1), i-1)), new int[]{i-1}), rem(a, 1));
					max.add(b);
					a = b;
				}else{
					int[] q = con(con(a, new int[]{i-1}), one.get(i-1));
					q = rot(q, i-q[0], i);
					max.add(q);
					a = q;
				}
			}
		}
		
		int n = ni(), a = ni(), b = ni();
		int c = Integer.bitCount(a^b);
		if(c % 2 == 0){
			out.println("NO");
		}else{
			int[] A = max.get(c);
			for(int i = c+1;i <= n;i++){
				int[] B = con(con(con(new int[]{i-1}, rot(rev(one.get(i-1), i-1), A[0], i-1)), new int[]{i-1}), rem(A, 1));
				
//				int u = 0;
//				for(int v : B){
//					u ^= 1<<v;
//				}
//				tr(u);
//				tr(A);
//				tr(B);
				A = B;
			}
			int[] map = new int[n];
			int p = 0, q = c;
			for(int i = 0;i < n;i++){
				if((a^b)<<~i<0){
					map[p++] = i;
				}else{
					map[q++] = i;
				}
			}
			out.println("YES");
			out.print(a);
			for(int i = 0;i < A.length;i++){
				a ^=1<<map[A[i]];
				out.print(" " + a);
			}
			out.println();
		}
		
		// 0 1 3 2
		// 0 2 3 1
		// 0 2 3 1 5 4 6 7
	}
	
	static int[] rem(int[] a, int f)
	{
		return Arrays.copyOfRange(a, f, a.length);
	}
	
	static int[] rev(int[] a, int d)
	{
		a = Arrays.copyOf(a, a.length);
		for(int i = 0;i < a.length;i++){
			a[i] = d-1-a[i];
		}
		return a;
	}
	
	static int[] rot(int[] a, int k, int d)
	{
		a = Arrays.copyOf(a, a.length);
		for(int i = 0;i < a.length;i++){
			a[i] = (a[i]+k)%d;
		}
		return a;
	}
	
	static int[] con(int[] a, int[] b)
	{
		int[] c = Arrays.copyOf(a, a.length+b.length);
		for(int i = 0;i < b.length;i++)c[i+a.length] = b[i];
		return c;
	}
	
	public static int[] rev_(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}

	
	static int[] copy(int[] a)
	{
		return Arrays.copyOf(a, a.length);
	}
	
	static int[] xor(int[] a, int v)
	{
		for(int i = 0;i < a.length;i++)a[i] ^= v;
		return a;
	}
	
	static int D = 5;
	
	static boolean dfs(int a, int b, int ptn)
	{
		if(ptn<<~a<0)return false;
		ptn |= 1<<a;
		if(a == b){
			return ptn+1 == 1<<(1<<D);
		}
		for(int i = 0;i < D;i++){
			if(dfs(a^1<<i, b, ptn))return true;
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