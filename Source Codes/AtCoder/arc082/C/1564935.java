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
//	static String INPUT = "3 0 3 3 0 2 2";
//	static String INPUT = "3 3 2 1 0 1 3";
//	static String INPUT = "3 1 2 2 1 3 0";
//	static String INPUT = "3 3 0 3 2 3 3";
	static String INPUT = "";
	
	static long[] p2 = new long[1000];
	static long[] ip2 = new long[1000];
	static long p(int n)
	{
		return n >= 0 ? p2[n] : ip2[-n];
	}
	
	static void solve()
	{
		int mod = 998244353;
		p2[0] = 1;
		ip2[0] = 1;
		long i2 = invl(2, mod);
		for(int i = 1;i < 1000;i++){
			p2[i] = p2[i-1] * 2 % mod;
			ip2[i] = ip2[i-1] * i2 % mod;
		}
		
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni()};
		}
		
		Arrays.sort(co, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		int ct = 0;
		
		
		long[][] nums = new long[n][n];
		long[][] sums = new long[n][n];
		{
			int[][] under = new int[n][n];
			// o-x
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(co[i][0] < co[j][0]){
						for(int k = 0;k < j;k++){
							if(co[i][0] <= co[k][0] && co[k][0] < co[j][0] && ccw(co[i], co[j], co[k]) > 0){
								under[i][j]++;
							}
						}
						under[i][j]++;
					}else{
						for(int k = i+1;k < j;k++){
							if(co[i][0] == co[k][0] && co[k][1] < co[j][1]){
								under[i][j]--;
							}
						}
					}
				}
			}
			
			for(int i = 0;i < n;i++){
				long[][] num = new long[n][n];
				long[][] sum = new long[n][n];
				for(int j = i+1;j < n;j++){
					num[j][i] = 1;
					sum[j][i] = p(-under[i][j]);
					nums[i][j] += num[j][i];
					sums[i][j] += sum[j][i];
					for(int k = i+1;k < j;k++){
						for(int l = i;l < k;l++){ // l-k-j
							if(ccw(co[l], co[k], co[j]) < 0){
								num[j][k] += num[k][l];
								sum[j][k] += sum[k][l];
							}
						}
						long q = p(-under[k][j]);
						num[j][k] = num[j][k] % mod;
						sum[j][k] = sum[j][k] % mod * q % mod;
						nums[i][j] += num[j][k];
						sums[i][j] += sum[j][k];
					}
					nums[i][j] %= mod;
					sums[i][j] %= mod;
				}
			}
		}
		
		{
			int[][] under = new int[n][n];
			// o-x
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(co[i][0] < co[j][0]){
						for(int k = 0;k < j;k++){
							if(co[i][0] <= co[k][0] && co[k][0] < co[j][0] && ccw(co[i], co[j], co[k]) >= 0){
								under[i][j]++;
							}
						}
						under[i][j]--;
					}else{
//						for(int k = i+1;k < j;k++){
//							if(co[i][0] == co[k][0] && co[k][1] < co[j][1]){
//								under[i][j]--;
//							}
//						}
						under[i][j]--;
					}
				}
			}
			for(int i = n-1;i >= 0;i--){
				long[][] num = new long[n][n];
				long[][] sum = new long[n][n];
				for(int j = i-1;j >= 0;j--){
					num[j][i] = 1;
					sum[j][i] = p(under[j][i]+1);
					nums[i][j] += num[j][i];
					sums[i][j] += sum[j][i];
					for(int k = i-1;k > j;k--){
						for(int l = i;l > k;l--){ // i-l-k-j
							if(ccw(co[l], co[k], co[j]) < 0){
								num[j][k] += num[k][l];
								sum[j][k] += sum[k][l];
							}
						}
						long q = p(under[j][k]);
						num[j][k] = num[j][k] % mod;
						sum[j][k] = sum[j][k] % mod * q % mod;
						nums[i][j] += num[j][k];
						sums[i][j] += sum[j][k];
					}
					nums[i][j] %= mod;
					sums[i][j] %= mod;
				}
			}
		}
		
//		for(long[] row : nums){
//			tr(row);
//		}
//		tr();
//		for(long[] row : sums){
//			tr(row);
//		}
//		tr(co);
		
		long ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				ret += sums[i][j] * sums[j][i];
				ret %= mod;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				int on = 0;
				for(int k = i+1;k < j;k++){
					if(ccw(co[i], co[j], co[k]) == 0){
						on++;
					}
				}
				ret -= p2[on];
			}
		}
		ret %= mod;
		if(ret < 0)ret += mod;
		out.println(ret);
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
	
	public static int ccw(long[] a, long[] b, long[] t) {
		return Long.signum((t[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (t[1] - a[1]));
	}

	
	public static void main(String[] args) throws Exception
	{
//		int n = 200, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(10000) + " ");
//			sb.append(gen.nextInt(10000) + " ");
//		}
//		INPUT = sb.toString();

		
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