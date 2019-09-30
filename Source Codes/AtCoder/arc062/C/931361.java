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
		int[][] cs = new int[n][];
		long[] chs = new long[n];
		long ret = 0;
		for(int i = 0;i < n;i++){
			cs[i] = na(4);
			chs[i] = h(cs[i]);
		}
		LongHashCounter lhc = new LongHashCounter();
		for(int i = n-1;i >= 0;i--){
			for(int j = i+1;j < n;j++){
				// 01
				// 32
				// 10
				// 23
				inner:
				for(int d = 0;d < 4;d++){
					long[] hs = {
							h(cs[i][1], cs[i][0], cs[j][d+1&3], cs[j][d+0&3]),
							h(cs[i][2], cs[i][1], cs[j][d+0&3], cs[j][d+3&3]),
							h(cs[i][3], cs[i][2], cs[j][d+3&3], cs[j][d+2&3]),
							h(cs[i][0], cs[i][3], cs[j][d+2&3], cs[j][d+1&3])
					};
					Arrays.sort(hs);
					long plus = 1;
					for(int k = 0;k < 4;){
						int l = k;
						while(l < 4 && hs[k] == hs[l])l++;
						int count = lhc.get(hs[k]);
						if(hs[k] == chs[j])count--;
						if(count <= 0)continue inner;
						long dup = 1;
						if(
								hs[k] / 1000000 % 1000 == hs[k] % 1000 &&
								hs[k] / 1000000000 % 1000 == hs[k] / 1000 % 1000){
							dup = 2;
							if(
									hs[k] / 1000 % 1000 == hs[k] % 1000){
								dup = 4;
							}
						}
								
						long mul = 1;
						for(int t = 1;t <= l-k;t++){
							mul = mul * dup;
							mul = mul * (count-t+1);
						}
						plus = plus * mul;
						
						k = l;
					}
					ret += plus;
				}
			}
			lhc.inc(chs[i], 1);
		}
		out.println(ret);
	}
	
	static long h(int... x)
	{
		long ret = Long.MAX_VALUE;
		for(int i = 0;i < 4;i++){
			long h = 0;
			for(int j = 0;j < 4;j++){
				h = h * 1000 + x[i+j&3];
			}
			ret = Math.min(ret, h);
		}
		return ret;
	}
	
	public static class LongHashCounter {
		public long[] keys;
		public int[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public LongHashCounter(){
			allocated = new int[scale];
			keys = new long[scale];
		}
		
		public boolean containsKey(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != 0){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public int get(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != 0){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return 0;
		}
		
		public int inc(long x, int v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != 0){
				if(x == keys[pos]){
					allocated[pos] += v;
					return allocated[pos];
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return v;
		}
		
		public int put(long x, int v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != 0){
				if(x == keys[pos]){
					int oldval = allocated[pos];
					allocated[pos] = v;
					return oldval;
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return 0;
		}
		
		public boolean remove(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != 0){
				if(x == keys[pos]){
					size--;
					// take last and fill rmpos
					int last = pos;
					pos = pos+1&mask;
					while(allocated[pos] != 0){
						int lh = h(keys[pos])&mask;
						// lh <= last < pos
						if(
								lh <= last && last < pos ||
								pos < lh && lh <= last ||
								last < pos && pos < lh
								){
							keys[last] = keys[pos];
							allocated[last] = allocated[pos];
							last = pos;
						}
						pos = pos+1&mask;
					}
					keys[last] = 0;
					allocated[last] = 0;
					
					return true;
				}
				pos = pos+1&mask;
			}
			return false;
		}
		
		private void resizeAndPut(long x, int v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			int[] nallocated = new int[nscale];
			long[] nkeys = new long[nscale];
			for(int i = next(0);i < scale;i = next(i+1)){
				long y = keys[i];
				int pos = h(y)&nmask;
				while(nallocated[pos] != 0)pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = allocated[i];
			}
			{
				int pos = h(x)&nmask;
				while(nallocated[pos] != 0)pos = pos+1&nmask;
				nkeys[pos] = x;
				nallocated[pos] = v;
			}
			allocated = nallocated;
			keys = nkeys;
			scale = nscale;
			rscale = nrscale;
			mask = nmask;
		}
		
		public int next(int itr)
		{
			while(itr < scale && allocated[itr] == 0)itr++;
			return itr;
		}
		
		private int h(long x)
		{
			x ^= x>>>33;
			x *= 0xff51afd7ed558ccdL;
			x ^= x>>>33;
			x *= 0xc4ceb9fe1a85ec53L;
			x ^= x>>>33;
			return (int)x;
		}
		
		@Override
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(int i = next(0);i < scale;i = next(i+1)){
				sb.append(",");
				sb.append(keys[i] + ":" + allocated[i]);
			}
			return sb.length() == 0 ? "" : sb.substring(1);
		}
	}
	
	public static void main(String[] args) throws Exception
	{
//		int n = 400, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n*4; i++) {
//			sb.append(999 + " ");
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