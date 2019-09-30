package gcj2011.r2;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.Queue;
import java.util.Scanner;

public class D {
	static String BASEPATH = "x:\\gcj\\2011r2\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt2.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
//	static String INPUT = "4\r\n" +
//			"2 1\r\n" +
//			"0,1\r\n" +
//			"3 3\r\n" +
//			"0,1 1,2 0,2\r\n" +
//			"5 5\r\n" +
//			"0,4 0,2 2,4 1,2 1,4\r\n" +
//			"7 9\r\n" +
//			"0,6 0,2 0,4 2,4 3,4 2,3 3,5 4,5 1,5";
//	static String INPUT = "1\r\n15 14\r\n" +
//	"1,6 3,8 0,2 4,14 2,3 3,4 1,4 3,13 2,10 3,11 2,7 0,5 4,9 4,12"; // 3 10
//	static String INPUT = "1\r\n3 2\r\n0,1 0,2";
	static String INPUT = "";
	
	public void call()
	{
		int n = ni();
		int m = ni();
		BitSet bs = new BitSet();
		for(int i = 0;i < m;i++){
			String co = in.next();
			int ind = co.indexOf(',');
//			f[i] = Integer.parseInt(co.substring(0, ind));
//			t[i] = Integer.parseInt(co.substring(ind+1));
			int ff = Integer.parseInt(co.substring(0, ind));
			int tt = Integer.parseInt(co.substring(ind+1));
			if(ff > tt){
				int d = ff; ff = tt; tt = d;
			}
			if(ff != tt){
				bs.set(ff*10000+tt);
			}
		}
		
		int c = bs.cardinality();
		int[] f = new int[c];
		int[] t = new int[c];
		for(int i = bs.nextSetBit(0), u = 0;i != -1;i = bs.nextSetBit(i + 1), u++){
			f[u] = i / 10000;
			t[u] = i % 10000;
		}
		
		int[][] g = packU(n, f, t);
		
		gmask = new long[n];
		for(int i = 0;i < n;i++){
			for(int l : g[i]){
				gmask[i] |= 1L<<l;
			}
		}
		
		int[] d = new int[n];
		Arrays.fill(d, 999999);
		d[0] = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0);
		while(q.size() > 0){
			int cur = q.poll();
			for(int l : g[cur]){
				if(d[l] > d[cur] + 1){
					d[l] = d[cur] + 1;
					q.add(l);
				}
			}
		}
		
		int path = rec(g, d, 0, 0);
		out.printf("%d %d\n", d[1] - 1, path);
	}
	
	long[] gmask;
	int[] hist = new int[40];
	
	int rec(int[][] g, int[] d, int cur, int pos)
	{
		if(cur == 1){
			long mask = 0;
			long hmask = 0;
			for(int i = 0;i < pos;i++){
				mask |= gmask[hist[i]];
				hmask |= 1L<<hist[i];
			}
			mask &= ~hmask;
			return Long.bitCount(mask);
		}else{
			hist[pos] = cur;
			int max = 0;
			for(int l : g[cur]){
				if(d[l] == d[cur] + 1){
					max = Math.max(max, rec(g, d, l, pos+1));
				}
			}
			return max;
		}
	}
	
	static int[][] packU(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int t : to)p[t]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	Scanner in;
	PrintWriter out;
	
	public D(Scanner in, PrintWriter out)
	{
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		
		Scanner in = INPUT.isEmpty() ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = INPUT.isEmpty() ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new D(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
