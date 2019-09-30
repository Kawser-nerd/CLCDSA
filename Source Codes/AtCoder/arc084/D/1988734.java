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
	
	static int Z = 63;
	
	static long[] tob(char[] s)
	{
		long[] ret = new long[Z];
		for(int i = 0;i < s.length;i++){
			ret[i>>>6] |= (long)s[s.length-1-i]-'0'<<i;
		}
		return ret;
	}
	
	static void solve()
	{
		int n = ni();
		long[] X = tob(ns().toCharArray());
		long[][] v = new long[n][];
		for(int i = 0;i < n;i++){
			v[i] = tob(ns().toCharArray());
		}
		
		for(int i = 1;i < n;i++){
			v[0] = gcd(v[0], v[i]);
		}
		
		out.println(count(v[0], X, 998244353));
	}
	
	static long count(long[] b, long[] x, int mod)
	{
		int n = x.length;
		int hb = height(b);
		assert hb > 0;
		long ret = 0;
		long[] o = new long[x.length];
		for(int i = n*64-1;i >= hb-1;i--){
			ret = ret * 2 % mod;
			if(x[i>>>6]<<~i<0){
				ret++;
			}
			if((x[i>>>6]^o[i>>>6])<<~i<0){
				xor(b, 0, hb, o, i-hb+1);
			}
		}
		ret++;
		for(int i = n-1;i >= 0;i--){
			int comp = Long.compareUnsigned(x[i], o[i]);
			if(comp < 0){
				ret--;
				break;
			}
			if(comp > 0){
				break;
			}
		}
		return (int)(ret%mod);
	}
	
	static int height(long[] a)
	{
		for(int i = a.length-1;i >= 0;i--){
			if(a[i] != 0)return i*64+64-Long.numberOfLeadingZeros(a[i]);
		}
		return 0;
	}
	
	static long[] gcd(long[] a, long[] b)
	{
		int ha = height(a);
		int hb = height(b);
		while(hb != 0){
			if(ha >= hb)xor(b, 0, hb, a, ha-hb);
			long[] d = a; a = b; b = d;
			ha = hb; hb = height(b);
		}
		return a;
	}
	
	public static void xor(long[] from, int fl, int fr, long[] to, int tl)
	{
		if(fl >= fr)return;
		if(!(fl >= 0 && fl < from.length<<6))throw new RuntimeException();
		if(!(fr >= 0 && fr <= from.length<<6))throw new RuntimeException();
		if(!(tl >= 0 && tl < to.length<<6))throw new RuntimeException();
		if(!(tl+(fr-fl) >= 0 && tl+(fr-fl) <= to.length<<6))throw new RuntimeException();
		
		int tr = tl+(fr-fl);
		if(tl>>>6 == tr-1>>>6){
			if(fl>>>6 == fr-1>>>6){
				to[tl>>>6] ^= from[fl>>>6]<<-fr>>>fl-fr<<tl;
			}else{
				to[tl>>>6] ^= from[fl>>>6]>>>fl<<tl ^ from[(fl>>>6)+1]<<-fr>>>-fr<<tr-fr;
			}
		}else if((fl&63) < (tl&63)){
			to[tl>>>6] ^= from[fl>>>6]>>>fl<<tl;
			for(int i = (tl>>>6)+1, j = (fl>>>6);i <= (tr-1>>>6)-1;i++,j++){
				to[i] ^= from[j]>>>fl-tl ^ from[j+1]<<-(fl-tl);
			}
			if((fr-1&63) < (tr-1&63)){
				to[tr-1>>>6] ^= from[(fr-1>>>6)-1]>>>fl-tl ^ from[fr-1>>>6]<<-fr>>>-tr;
			}else{
				to[tr-1>>>6] ^= from[fr-1>>>6]<<-fr>>>-tr;
			}
		}else if((fl&63) > (tl&63)){
			to[tl>>>6] ^= from[fl>>>6]>>>fl<<tl ^ from[(fl>>>6)+1]<<-(fl-tl);
			for(int i = (tl>>>6)+1, j = (fl>>>6)+1;i <= (tr-1>>>6)-1;i++,j++){
				to[i] ^= from[j]>>>fl-tl ^ from[j+1]<<-(fl-tl);
			}
			if((fr-1&63) > (tr-1&63)){
				to[tr-1>>>6] ^= from[fr-1>>>6]<<-fr>>>-tr;
			}else{
				to[tr-1>>>6] ^= from[(fr-1>>>6)-1]>>>fl-tl ^ from[fr-1>>>6]<<-fr>>>-tr;
			}
		}else{
			to[tl>>>6] ^= from[fl>>>6]>>>fl<<tl;
			for(int i = (tl>>>6)+1, j = (fl>>>6)+1;i <= (tr-1>>>6)-1;i++,j++){
				to[i] ^= from[j];
			}
			to[tr-1>>>6] ^= from[fr-1>>>6]<<-fr>>>-tr;
		}
	}
	
//		
//		int hba = -1;
//		for(int i = 3999;i >= 0;i--){
//			if(basis[i]){
//				hba = i;
//				break;
//			}
//		}
//		
//		long ans = 0;
//		int mod = 998244353;
//		boolean[] o = new boolean[4000];
//		for(int i = 3999;i >= hba;i--){
//			if(X[i]){
//				ans += pow(2, i-hba, mod);
//			}
//			if(X[i] != o[i]){
//				for(int j = hba;j >= 0;j--){
//					o[i-hba+j] ^= basis[j];
//				}
//			}
//		}
////		tf(X);
////		tf(o);
//		boolean ok = true;
//		for(int i = hba-1;i >= 0;i--){
//			if(!X[i] && o[i]){
//				ok = false;
//				break;
//			}
//			if(X[i] &&!o[i]){
//				ok = true;
//				break;
//			}
//		}
//		if(ok)ans++;
//		out.println(ans%mod);
//	}
	
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