import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;


public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	// 101
	// 0001 -> 01
	
	// 01
	// 1
	
	
	
	static boolean[] tob(char[] s)
	{
		boolean[] ret = new boolean[4000];
		for(int i = 0;i < s.length;i++){
			ret[i] = s[s.length-1-i] == '1';
		}
		return ret;
	}
	
	static void solve()
	{
		int n = ni();
		boolean[] X = tob(ns().toCharArray());
		boolean[][] v = new boolean[n][];
		for(int i = 0;i < n;i++){
			v[i] = tob(ns().toCharArray());
		}
		
		boolean[] basis = null;
		while(true){
			Arrays.sort(v, new Comparator<boolean[]>() {
				public int compare(boolean[] a, boolean[] b) {
					for(int i = 3999;i >= 0;i--){
						if(a[i] != b[i]){
							if(a[i])return 1;
							return -1;
						}
					}
					return 0;
				}
			});
			
			boolean[] b = Arrays.copyOf(v[0], 4000);
			
			int[] h = new int[n];
			Arrays.fill(h, -1);
			for(int i = 0;i < n;i++){
				for(int j = 3999;j >= 0;j--){
					if(v[i][j]){
						h[i] = j;
						break;
					}
				}
			}
			for(int i = 1;i < n;i++){
				if(h[0] == h[i]){
					if(Arrays.equals(v[0], v[i]))continue;
					for(int j = 0;j < 4000;j++){
						b[j] ^= v[i][j];
					}
					break;
				}
			}
			
//			outer:
//			for(int j = 3999;j >= 0;j--){
//				if(b[j]){
//					for(int i = 1;i < n;i++){
//						if(h[i] == j){
//							for(int k = 0;k <= j;k++){
//								b[k] ^= v[i][k];
//								continue outer;
//							}
//						}
//					}
//					break;
//				}
//			}
			int hb = -1;
			for(int j = 3999;j >= 0;j--){
				if(b[j]){
					hb = j;
					break;
				}
			}
			
			int p = 0;
			outer:
			for(int i = 0;i < n;i++){
				for(int j = 3999;j >= hb;j--){
					if(v[i][j]){
						for(int k = 0;k <= hb;k++){
							v[i][j-hb+k] ^= b[k];
						}
					}
				}
				for(int k = hb-1;k >= 0;k--){
					if(v[i][k]){
						v[p] = v[i];
						p++;
						continue outer;
					}
				}
			}
			v = Arrays.copyOf(v, p+1);
			v[p] = b;
			
//			tr();
//			tf(b);
//			for(int i = 0;i < p;i++){
//				tf(v[i]);
//			}
			if(p == 0){
				basis = b;
				break;
			}
			n = p+1;
		}
		
		int hba = -1;
		for(int i = 3999;i >= 0;i--){
			if(basis[i]){
				hba = i;
				break;
			}
		}
		
		long ans = 0;
		int mod = 998244353;
		boolean[] o = new boolean[4000];
		for(int i = 3999;i >= hba;i--){
			if(X[i]){
				ans += pow(2, i-hba, mod);
			}
			if(X[i] != o[i]){
				for(int j = hba;j >= 0;j--){
					o[i-hba+j] ^= basis[j];
				}
			}
		}
//		tf(X);
//		tf(o);
		boolean ok = true;
		for(int i = hba-1;i >= 0;i--){
			if(!X[i] && o[i]){
				ok = false;
				break;
			}
			if(X[i] &&!o[i]){
				ok = true;
				break;
			}
		}
		if(ok)ans++;
		out.println(ans%mod);
	}
	
	public static void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
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