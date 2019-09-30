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
		int n = ni(), K = ni();
		String[] ss = new String[n];
		for(int i = 0;i < n;i++){
			ss[i] = ns();
		}
		boolean[][] back = new boolean[n+1][K+1];
		back[n][K] = true;
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j <= K;j++){
				back[i][j] |= back[i+1][j];
				if(j+ss[i].length() <= K)back[i][j] |= back[i+1][j+ss[i].length()];
			}
		}
		
		// [i][j]=(i????????j???????substring?????)
		boolean[][] dp = new boolean[n+1][K+1];
		dp[0][0] = true;
		char[][] css = new char[n+1][];
		css[0] = new char[0];
		for(int i = 0;i < n;i++){
			char[] cst = new char[css[i].length+ss[i].length()];
			int p = 0;
			for(int j = 0;j < ss[i].length();j++)cst[p++] = ss[i].charAt(j);
			for(int j = 0;j < css[i].length;j++)cst[p++] = css[i][j];
			int[] z = Z(cst);
			
			int t = 0;
			boolean sadd = false;
			for(int j = 0;j <= K;j++){
				if(!dp[i][j])continue;
				if(j+ss[i].length() <= K && back[i+1][j+ss[i].length()]){
					// (i,j) -> (i+1,j+|s|)
					// cs[i][0:j)+s cs[i+1]=cs[i][0:t)+s ? cs[i][0:t) ?
					int comp = comp(j, true, t, sadd, z, ss[i].length(), cst);
					if(comp < 0){
						t = j; sadd = true;
					}else if(comp == 0){
						if(j+ss[i].length() > t + (sadd ? ss[i].length() : 0)){
							t = j; sadd = true;
						}
					}
				}
				if(back[i+1][j]){
					// (i,j) -> (i+1,j)
					// cs[i][0:j) cs[i+1]=cs[i][0:t)+s ? cs[i][0:t) ?
					int comp = comp(j, false, t, sadd, z, ss[i].length(), cst);
					if(comp < 0){
						t = j; sadd = false;
					}else if(comp == 0){
						if(j > t + (sadd ? ss[i].length() : 0)){
							t = j; sadd = false;
						}
					}
				}
			}
			for(int j = 0;j <= K;j++){
				if(!dp[i][j])continue;
				if(j+ss[i].length() <= K && back[i+1][j+ss[i].length()]){
					// (i,j) -> (i+1,j+|s|)
					// cs[i][0:j)+s cs[i+1]=cs[i][0:t)+s ? cs[i][0:t) ?
					int comp = comp(j, true, t, sadd, z, ss[i].length(), cst);
					if(comp <= 0)dp[i+1][j+ss[i].length()] = true;
				}
				if(back[i+1][j]){
					// (i,j) -> (i+1,j)
					// cs[i][0:j) cs[i+1]=cs[i][0:t)+s ? cs[i][0:t) ?
					int comp = comp(j, false, t, sadd, z, ss[i].length(), cst);
					if(comp <= 0)dp[i+1][j] = true;
				}
			}
			css[i+1] = new char[t+(sadd ? ss[i].length() : 0)];
			for(int j = 0;j < t;j++)css[i+1][j] = css[i][j];
			if(sadd){
				for(int j = 0;j < ss[i].length();j++)css[i+1][j+t] = ss[i].charAt(j);
			}
//			tr(new String(css[i+1]));
//			tr(dp[i+1]);
//			tr(back[i+1]);
		}
		out.println(new String(css[n]));
	}
	
	// x1 >= x2
	static int comp(int x1, boolean s1, int x2, boolean s2, int[] z, int slen, char[] cst)
	{
		if(x1 < x2){
			return -comp(x2, s2, x1, s1, z, slen, cst);
		}
//		if(!s1 && !s2)return 0;
		if(!s2)return 0;
		if(x1 == x2){
			return 0;
		}
		if(!s1 || x1 >= x2+slen){
			if(z[x2+slen] >= slen || x2+z[x2+slen] >= x1)return 0;
			return cst[x2+slen+z[x2+slen]] - cst[z[x2+slen]];
		}else{
			// x1 s
			// x2 s
//			tr(x1, x2, slen, z, cst.length);
			if(x2+z[x2+slen] >= x1){
				if(z[x1-x2] >= slen-(x1-x2)){
					return 0;
				}else{
					return cst[z[x1-x2]] - cst[x1-x2+z[x1-x2]];
				}
			}else{
				return cst[x2+slen+z[x2+slen]] - cst[z[x2+slen]];
			}
		}
	}
	
	public static int[] Z(char[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
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