package gcj2014.r3;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class D implements Runnable {
	static final boolean LARGE = false;
	static final boolean PROD = false;
	static final int NTHREAD = 1;
	static String BASEPATH = "x:\\gcj\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "1\r\n" + 
//			"3\r\n" + 
//			"1000\r\n" + 
//			"200\r\n" + 
//			"1000\r\n" + 
//			"2\r\n" + 
//			"3\r\n" + 
			"8\r\n" + 
			"8\r\n" + 
			"0\r\n" + 
			"8\r\n" + 
			"0\r\n" + 
			"0\r\n" + 
			"0\r\n" + 
			"0\r\n" + 
			"10\r\n" + 
			"2\r\n" + 
			"5\r\n" + 
			"4\r\n" + 
			"5\r\n" + 
			"6\r\n" + 
			"7\r\n" + 
			"8\r\n" + 
			"10\r\n" + 
			"150\r\n" + 
			"200\r\n" + 
			"0\r\n" + 
			"5000\r\n" + 
			"0\r\n" + 
			"100\r\n" + 
			"0\r\n" + 
			"0\r\n" + 
			"0\r\n" + 
			"10000\r\n" + 
			"10\r\n" + 
			"3\r\n" + 
			"8\r\n" + 
			"5\r\n" + 
			"8\r\n" + 
			"7\r\n" + 
			"8\r\n" + 
			"9\r\n" + 
			"10\r\n" + 
			"";
	
	int n;
	int[] c;
	int[][][] g;
	int[] from;
	int[] to;
	
	public void read() // not parallelized
	{
		n = ni();
		c = na(n);
		from = new int[n-1];
		to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = i;
			to[i] = ni()-1;
		}
		g = packWU(n, from, to, from);
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	public void process() // parallelized!
	{
		int max = Integer.MIN_VALUE;
		for(int i = 0;i < n;i++){
			int lmin = Integer.MAX_VALUE;
			for(int j = 0;j < n;j++){
//				tr(i, j);
				int dif = dfs(i, j, new BitSet(), new BitSet(), new BitSet());
				lmin = Math.min(lmin, dif);
			}
			max = Math.max(max, lmin);
		}
		out.println(max);
	}
	
	int dfs(int a, int b, BitSet bofa, BitSet bofb, BitSet got){
		boolean gain = !got.get(a);
		int sc = gain ? c[a] : 0;
		got.set(a);
		
		int lmax = Integer.MIN_VALUE / 3;
		for(int[] e : g[a]){
			if(!bofa.get(e[1])){
				bofa.set(e[1]);
				bofb.set(e[1]);
				// TODO
				lmax = Math.max(lmax, -dfs(b, e[0], bofb, bofa, got));
				bofa.clear(e[1]);
				bofb.clear(e[1]);
			}
		}
		if(lmax == Integer.MIN_VALUE / 3){
			boolean bcanmove = !got.get(b);
			if(!bcanmove){
				for(int[] e : g[b]){
					if(!bofb.get(e[1])){
						bcanmove = true;
						break;
					}
				}
			}
			if(bcanmove){
				int u = sc - dfs(b, a, bofb, bofa, got);
				if(gain)got.clear(a);
				return u;
			}else{
				if(gain)got.clear(a);
				return sc;
			}
		}else{
			if(gain)got.clear(a);
			return sc + lmax;
		}
	}
	
	public static void preprocess()
	{
	}
	
	Scanner in;
	PrintWriter out;
	StringWriter sw;
	int cas;
	static List<Status> running = new ArrayList<Status>();
	
	public static int[][] tree(int n, Random gen)
	{
		int[][] e = new int[n-1][2];
		
		int[] f = new int[n];
		for(int i = 0;i < n;i++)f[i] = i; // offset
		for(int i = 0;i < n-1;i++) {
			int other = gen.nextInt(n-i)+i;
			int d = f[i]; f[i] = f[other]; f[other] = d;
		}
		
		for(int i = 0;i < n-1;i++) {
			e[i][0] = f[gen.nextInt(i+1)];
			e[i][1] = f[i+1];
		}
		
		// shuffle
		for(int i = 0;i < n-1-1;i++) {
			int other = gen.nextInt(n-1-i)+i;
			int d;
			d = e[i][0]; e[i][0] = e[other][0]; e[other][0] = d;
			d = e[i][1]; e[i][1] = e[other][1]; e[other][1] = d;
		}
		return e;
	}
	
	@Override
	public void run()
	{
		long S = System.nanoTime();
		// register
		synchronized(running){
			Status st = new Status();
			st.id = cas;
			st.S = S;
			running.add(st);
		}
		process();
		// deregister
		synchronized(running){
			for(Status st : running){
				if(st.id == cas){
					running.remove(st);
					break;
				}
			}
		}
		long G = System.nanoTime();
		
		if(PROD){
			System.err.println("case " + cas + " solved. [" + (G-S)/1000000 + "ms]");
			synchronized(running){
				StringBuilder sb = new StringBuilder("running : ");
				for(Status st : running){
					sb.append(st.id + ":" + (G-st.S)/1000000 + "ms, ");
				}
				System.err.println(sb);
			}
		}
	}
	
	private static class Status {
		public int id;
		public long S;
	}
	
	public D(int cas, Scanner in)
	{
		this.cas = cas;
		this.in = in;
		this.sw = new StringWriter();
		this.out = new PrintWriter(this.sw);
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private long nl() { return Long.parseLong(in.next()); }
	private int[] na(int n) { int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = ni(); return a; }
	private double nd() { return Double.parseDouble(in.next()); }
	private void tr(Object... o) { if(!PROD)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		{
			int n = 80, m = 99999;
			Random gen = new Random();
			StringBuilder sb = new StringBuilder();
			sb.append(1 + "\n");
			sb.append(n + " ");
			int[][] t = tree(n, gen);
			for(int i = 0;i < n;i++){
				sb.append(gen.nextInt(100) + " ");
			}
			for(int i = 0;i < n-1;i++){
				sb.append(gen.nextInt(n-i-1)+2 + " ");
			}
			INPUT = sb.toString();
		}
		
		long start = System.nanoTime();
		
		ExecutorService es = Executors.newFixedThreadPool(NTHREAD);
		CompletionService<D> cs = new ExecutorCompletionService<D>(es);
		
		if(PROD){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = PROD ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = PROD ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		preprocess();
		for(int i = 0;i < n;i++){
			D runner = new D(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			D runner = cs.take().get(); // not ordered
			runner.out.flush();
			runner.out.close();
			outs[runner.cas-1] = runner.sw.toString();
		}
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			out.append(outs[i]);
			out.flush();
		}
		
		long end = System.nanoTime();
		System.out.println((end - start)/1000000 + "ms");
		if(PROD){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
