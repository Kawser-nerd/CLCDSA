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
		int A = ni(), B = ni();
		int oa = A, ob = B;
		if(2*(A+B) > n*m){
			out.println("NO");
			return;
		}
		
		char[][] s = new char[n][m];
		for(int i = 0;i < n;i++)Arrays.fill(s[i], '.');
		if(m % 2 == 1){
			for(int i = 0;i < n-1 && B > 0;i+=2){
				s[i][m-1] = '^';
				s[i+1][m-1] = 'v';
				B--;
			}
		}
		if(n % 2 == 1){
			for(int i = 0;i < m-1 && A > 0;i+=2){
				s[n-1][i] = '<';
				s[n-1][i+1] = '>';
				A--;
			}
		}
		for(int i = 0;i < n-1;i+=2){
			for(int j = 0;j < m-1;j+=2){
				if(A >= 1){
					s[i][j] = '<';
					s[i][j+1] = '>';
					A--;
					if(A > 0){
						s[i+1][j] = '<';
						s[i+1][j+1] = '>';
						A--;
					}
				}else if(B >= 1){
					s[i][j] = '^';
					s[i+1][j] = 'v';
					B--;
					if(B > 0){
						s[i][j+1] = '^';
						s[i+1][j+1] = 'v';
						B--;
					}
				}
			}
		}
		if(A > 0 || B > 0){
			A = oa; B = ob;
			if(n % 2 == 1 && m % 2 == 1 && A >= 2 && B >= 2 && n >= 3 && m >= 3){
				s = new char[n][m];
				for(int i = 0;i < n;i++)Arrays.fill(s[i], '.');
				s[n-3][m-3] = '<';
				s[n-3][m-2] = '>';
				s[n-3][m-1] = '^';
				s[n-2][m-1] = 'v';
				s[n-1][m-1] = '>';
				s[n-1][m-2] = '<';
				s[n-1][m-3] = 'v';
				s[n-2][m-3] = '^';
				A -= 2; B -= 2;
				for(int i = 0;i < n-3 && B > 0;i+=2){
					s[i][m-1] = '^';
					s[i+1][m-1] = 'v';
					B--;
				}
				for(int i = 0;i < m-3 && A > 0;i+=2){
					s[n-1][i] = '<';
					s[n-1][i+1] = '>';
					A--;
				}
				for(int i = 0;i < n-1;i+=2){
					for(int j = 0;j < m-1;j+=2){
						if(i == n-3 && j == m-3)continue;
						if(A >= 1){
							s[i][j] = '<';
							s[i][j+1] = '>';
							A--;
							if(A > 0){
								s[i+1][j] = '<';
								s[i+1][j+1] = '>';
								A--;
							}
						}else if(B >= 1){
							s[i][j] = '^';
							s[i+1][j] = 'v';
							B--;
							if(B > 0){
								s[i][j+1] = '^';
								s[i+1][j+1] = 'v';
								B--;
							}
						}
					}
				}
				if(A == 0 && B == 0){
					out.println("YES");
					for(char[] row : s){
						out.println(new String(row));
					}
					return;
				}
			}
			
			out.println("NO");
		}else{
			out.println("YES");
			for(char[] row : s){
				out.println(new String(row));
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