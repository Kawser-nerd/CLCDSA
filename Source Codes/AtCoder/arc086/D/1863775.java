import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class Main {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		int n = ni();
		long K = nl();
		long[] a = new long[n];
		for(int i = 0;i  < n;i++)a[i] = nl();
		Arrays.sort(a);
		
		
		List<Datum> all = new ArrayList<>();
		for(int d = 0;K-d >= 0 && d <= 60;d++){
			long[][] lows = new long[n][];
			for(int i = 0;i < n;i++){
				lows[i] = new long[]{a[i]&(1L<<d)-1, i};
			}
			Arrays.sort(lows, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return Long.compare(a[0], b[0]);
				}
			});
			
			long[] b = new long[n];
			for(int i = 0;i < n;i++){
				b[i] = a[i]>>>d;
			}
			if(K-d >= 0){
				long sup = Math.min(b[0], K-d);
				all.add(new Datum(sub(b), b[0]-sup, b[0]));
			}
			
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && lows[j][0] == lows[i][0])j++;
				
				for(int k = i;k < j;k++){
					b[(int)lows[k][1]]--;
				}
				if(b[0] >= 0 && j < n){
					long llow = lows[i][0]+1;
					long lhigh = lows[j][0];
					int num = Long.bitCount(lhigh);
					for(;lhigh >= llow;lhigh &= lhigh-1){
						num--;
					}
					num++;
//					int num = 
//							llow == lhigh ? Long.bitCount(llow) : 
//							Math.min(Long.bitCount(llow), Long.bitCount(llow / Long.highestOneBit(llow^lhigh)) + 1);
					
					if(K-d-num >= 0){
//						tr(d, sub(b), llow, lhigh);
						long sup = Math.min(b[0], K-d-num);
						all.add(new Datum(sub(b), b[0]-sup, b[0]));
					}
				}
				
				i = j;
			}
		}
		
		Collections.sort(all, (x, y) -> {
			for(int i = 0;i < x.sub.length;i++){
				if(x.sub[i] != y.sub[i])return Long.compare(x.sub[i], y.sub[i]);
			}
			return Long.compare(x.inf, y.inf);
		});
		long len = 0;
		for(int i = 0;i < all.size();){
			int j = i;
			while(j < all.size() && Arrays.equals(all.get(j).sub, all.get(i).sub))j++;
			
			long sup = -3;
			for(int k = i;k < j;k++){
//				tr(all.get(k));
				if(sup < all.get(k).inf){
					sup = all.get(k).sup;
					len += sup-all.get(k).inf+1;
				}else{
					if(all.get(k).sup > sup){
						len += all.get(k).sup - sup;
						sup = all.get(k).sup;
					}
				}
			}
			len %= 1000000007;
			
			i = j;
		}
		out.println(len%1000000007);
	}
	
	static long[] sub(long[] u)
	{
		int n = u.length;
		long[] v = new long[n-1];
		for(int i = 0;i < n-1;i++){
			v[i] = u[i+1] - u[i];
		}
		return v;
	}
	
	static class Datum
	{
		long[] sub;
		long inf, sup;
		public Datum(long[] sub, long inf, long sup) {
			this.sub = sub;
			this.inf = inf;
			this.sup = sup;
		}
		@Override
		public String toString() {
			return "Datum [" + (sub != null ? "sub=" + Arrays.toString(sub) + ", " : "") + "inf=" + inf + ", sup=" + sup
					+ "]";
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