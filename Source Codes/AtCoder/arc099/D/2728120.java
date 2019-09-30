import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	static final int O = 300000;
	
	
	static void solve()
	{
		int n = ni();
		char[] s = ns(n);
		
		RollingHashFactory rhf = new RollingHashFactory(2, 600000, new Random(114514));
		
		int pos = 0;
		long hu = 0, hl = 0;
		for(char c : s){
			if(c == '>'){
				pos++;
			}else if(c == '<'){
				pos--;
			}else if(c == '+'){
				hu += rhf.powers[0][O+pos];
				hu %= rhf.mods[0];
				hl += rhf.powers[1][O+pos];
				hl %= rhf.mods[1];
			}else if(c == '-'){
				hu += rhf.mods[0] - rhf.powers[0][O+pos];
				hu %= rhf.mods[0];
				hl += rhf.mods[1] - rhf.powers[1][O+pos];
				hl %= rhf.mods[1];
			}
		}
		
		ans = 0;
		dfs(0, n, s, rhf, hu, hl);
		out.println(ans);
	}
	
	static long ans = 0;
	
	static void dfs(int l, int r, char[] s, RollingHashFactory rhf, long HU, long HL)
	{
		if(l >= r)return;
		int h = l+r>>1;
		// h?????(??2??)
		long rhu = 0, rhl = 0;
		long[] hits = new long[r-h];
		{
			int p = 0;
			int pos = 0;
			hits[p++] = 0;
			for(int i = h+1;i < r;i++){
				char c = s[i];
				if(c == '>'){
					pos++;
				}else if(c == '<'){
					pos--;
				}else if(c == '+'){
					rhu += rhf.powers[0][O+pos];
					rhu %= rhf.mods[0];
					rhl += rhf.powers[1][O+pos];
					rhl %= rhf.mods[1];
				}else if(c == '-'){
					rhu += rhf.mods[0] - rhf.powers[0][O+pos];
					rhu %= rhf.mods[0];
					rhl += rhf.mods[1] - rhf.powers[1][O+pos];
					rhl %= rhf.mods[1];
				}
				long rh = rhu<<32|rhl;
				hits[p++] = rh;
			}
		}
		Arrays.sort(hits);
//		tr(h, r);
		
		long lhu = 0, lhl = 0;
		
		int pos = 0;
		for(int i = h;i >= l;i--){
			char c = s[i];
			if(c == '<'){
				pos++;
			}else if(c == '>'){
				pos--;
			}else if(c == '+'){
				lhu += rhf.powers[0][O+pos];
				lhu %= rhf.mods[0];
				lhl += rhf.powers[1][O+pos];
				lhl %= rhf.mods[1];
			}else if(c == '-'){
				lhu += rhf.mods[0] - rhf.powers[0][O+pos];
				lhu %= rhf.mods[0];
				lhl += rhf.mods[1] - rhf.powers[1][O+pos];
				lhl %= rhf.mods[1];
			}
			// (L+R)*P^(-LS) = G?
			long thu = HU*(pos < 0 ? invl(rhf.powers[0][-pos], rhf.mods[0]) :
				rhf.powers[0][pos]) - lhu;
			thu %= rhf.mods[0];
			if(thu < 0)thu += rhf.mods[0];
			
			long thl = HL*(pos < 0 ? invl(rhf.powers[1][-pos], rhf.mods[1]) :
				rhf.powers[1][pos]) - lhl;
			thl %= rhf.mods[1];
			if(thl < 0)thl += rhf.mods[1];
			
			long th = thu<<32|thl;
//			if(lowerBound(hits, th+1) - lowerBound(hits, th) > 0)tr(th, i, l, h, r);
			ans += lowerBound(hits, th+1) - lowerBound(hits, th);
		}
		
		dfs(l, h, s, rhf, HU, HL);
		dfs(h+1, r, s, rhf, HU, HL);
	}
	
	public static int lowerBound(long[] a, long v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}

	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	public static class RollingHash
	{
		public RollingHashFactory rhf;
		public long[][] buf;
		public int p;
		
		public RollingHash(int bufsize, RollingHashFactory rhf)
		{
			buf = new long[rhf.deg][bufsize+1];
			this.rhf = rhf;
			this.p = 1;
		}
		
		public void add(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i][p] = (buf[i][p-1]*rhf.muls[i]+c)%rhf.mods[i];
			p++;
		}
		
		public void addr(int c)
		{
			for(int i = 0;i < rhf.deg;i++)buf[i][p] = (buf[i][p-1]+rhf.powers[i][p-1]*c)%rhf.mods[i];
			p++;
		}
		
		public long queryTwin(int r)
		{
			return buf[0][r]<<32|buf[1][r];
		}
		
		public long queryTwin(int l, int r)
		{
			assert l > r;
			assert rhf.deg == 2;
			long h = 0;
			for(int i = 0;i < rhf.deg;i++){
				long v = (buf[i][r] - buf[i][l] * rhf.powers[i][r-l]) % rhf.mods[i];
				if(v < 0)v += rhf.mods[i];
				h = h<<32|v;
			}
			return h;
		}
		
		public long[] query(int l, int r)
		{
			assert l > r;
			long[] h = new long[rhf.deg];
			for(int i = 0;i < rhf.deg;i++){
				h[i] = (buf[i][r] - buf[i][l] * rhf.powers[i][r-l]) % rhf.mods[i];
				if(h[i] < 0)h[i] += rhf.mods[i];
			}
			return h;
		}
		
		public static long add(long a, long b, int w, RollingHashFactory rhf)
		{
			assert rhf.deg == 2;
			long high = ((a>>>32) * rhf.powers[0][w] + (b>>>32)) % rhf.mods[0];
			long low = ((long)(int)a * rhf.powers[1][w] + (int)b) % rhf.mods[1];
			return high<<32|low;
		}
	}
	
	public static class RollingHashFactory
	{
		public int[] mods;
		public int[] muls;
		public long[][] powers;
		public int deg;
		
		public RollingHashFactory(int deg, int n, Random gen)
		{
			this.deg = deg;
			mods = new int[deg];
			muls = new int[deg];
			for(int i = 0;i < deg;i++){
				mods[i] = BigInteger.probablePrime(30, gen).intValue();
				muls[i] = BigInteger.probablePrime(30, gen).intValue();
			}
			powers = new long[deg][n+1];
			for(int i = 0;i < deg;i++){
				powers[i][0] = 1;
				for(int j = 1;j <= n;j++){
					powers[i][j] = powers[i][j-1] * muls[i] % mods[i];
				}
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