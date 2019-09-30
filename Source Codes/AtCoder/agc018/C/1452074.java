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
	
	static void solve()
	{
		int x = ni(), y = ni(), z = ni();
		int n = x+y+z;
		int[][] ds = new int[n][];
		long asum = 0;
		for(int i = 0;i < n;i++){
			ds[i] = na(3);
			ds[i][1] -= ds[i][0];
			ds[i][2] -= ds[i][0];
			asum += ds[i][0];
		}
		Arrays.sort(ds, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[1] - b[1]);
			}
		});
		
		long[] gain = new long[n+1];
		{
			KMajorPriorityQueue kmjp = new KMajorPriorityQueue();
			for(int i = 0;i < n;i++){
				kmjp.add(ds[i][2]-ds[i][1]);
				gain[i+1] += kmjp.kMajorSum(i+1-y);
			}
		}
		{
			KMajorPriorityQueue kmjp = new KMajorPriorityQueue();
			for(int i = n-1;i >= 0;i--){
				kmjp.add(ds[i][2]);
				gain[i] += kmjp.kMajorSum(z-(i-y));
			}
		}
		long sum = 0;
		for(int i = 0;i < n;i++){
			sum += ds[i][1];
			gain[i+1] += sum;
		}
		long max = 0;
		for(int i = y;i <= y+z;i++){
			max = Math.max(max, gain[i] + asum);
		}
		out.println(max);
	}
	
	public static class SimpleMinHeapL {
		public long[] a;
		public int n;
		public int pos;
		public static final long INF = Long.MAX_VALUE;
		
		public SimpleMinHeapL(int m)
		{
			n = m+1;
			a = new long[n];
			Arrays.fill(a, INF);
			pos = 1;
		}
		
		public SimpleMinHeapL(long[] in)
		{
			n = in.length+1;
			if((n&1)==1)n++;
			a = new long[n];
			pos = 1+in.length;
//			Arrays.fill(a, INF);
			a[0] = a[n-1] = a[n-2] = INF;
			System.arraycopy(in, 0, a, 1, in.length);
			for(int t = pos/2-1;t >= 1;t--){
				for(int c = t;2*c < pos;){
					int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
					if(a[smaller] < a[c]){
						long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
						c = smaller;
					}else{
						break;
					}
				}
			}
		}
		
		public void add(long x)
		{
			if(pos >= n)a = Arrays.copyOf(a, n*=2);
			a[pos++] = x;
			for(int c = pos-1, p = c>>>1;p >= 1 && a[c] < a[p];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
			}
		}
		
		public long poll()
		{
			if(pos == 1)return INF;
			pos--;
			long ret = a[1];
			a[1] = a[pos];
			a[pos] = INF;
			for(int c = 1;2*c < pos;){
				int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[smaller] < a[c]){
					long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
					c = smaller;
				}else{
					break;
				}
			}
			return ret;
		}
		
		public long min() { return a[1]; }
		public int size() { return pos-1; }
	}
	
	public static class KMajorPriorityQueue
	{
		SimpleMinHeapL pq, ipq;
		long sum;
		
		public KMajorPriorityQueue() {
			pq = new SimpleMinHeapL(1);
			ipq = new SimpleMinHeapL(1);
			sum = 0;
		}
		
		public void add(long v) {
			pq.add(v);
			sum += v;
		}
		
		public long kMajorSum(int K) {
			if(K < 0)K = 0;
			
			// remove
			while(pq.size() > K){
				long v = pq.poll();
				ipq.add(-v);
				sum -= v;
			}
			// add
			while(pq.size() < K){
				long v = -ipq.poll();
				pq.add(v);
				sum += v;
			}
			// exchange
			while(ipq.size() > 0 && pq.size() > 0 && pq.min() < -ipq.min()){
				long e = pq.poll(), f = -ipq.poll();
				sum -= e; sum += f;
				pq.add(f);
				ipq.add(-e);
			}
			return sum;
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