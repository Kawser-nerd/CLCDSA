package gcj2014.r1b;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CLarge implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "x:\\gcj\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + CLarge.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n, m;
	int[] label;
	boolean[][] g;
	
	public void read() // not parallelized
	{
		n = ni(); m = ni();
		label = new int[n];
		for(int i = 0;i < n;i++)label[i] = ni();
		g = new boolean[n][n];
		for(int i = 0;i < m;i++){
			int f = ni()-1, t = ni()-1;
			g[f][t] = g[t][f] = true;
		}
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}
	
	boolean canconnect(int[] par, int can)
	{
		int n = par.length;
		boolean[] rem = new boolean[n];
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int x = can; x != -1;x = par[x])q.add(x);
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int i = 0;i < n;i++){
				if(g[cur][i] && par[i] == -1 && !rem[i]){
					rem[i] = true;
					q.add(i);
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(par[i] == -1 && !rem[i])return false;
		}
		return true;
	}
	
	public void process() // parallelized!
	{
		int[][] lord = new int[n][];
		for(int i = 0;i < n;i++)lord[i] = new int[]{i, label[i]};
		Arrays.sort(lord, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		int start = lord[0][0];
		
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		StringBuilder sb = new StringBuilder();
		sb.append(label[start]);
		int prev = start;
		outer:
		for(int z = 0;z < n-1;z++){
			for(int i = 1;i < n;i++){
				int can = lord[i][0];
				if(par[can] == -1){
					for(int x = prev;x != -1;x = par[x]){
						if(g[x][can]){
							par[can] = x;
							if(canconnect(par, can)){
								sb.append(label[can]);
								prev = can;
								continue outer;
							}
							par[can] = -1;
						}
					}
				}
			}
		}
		tr(par);
		out.println(sb);
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if(x != y){
				if(upper[y] < upper[x]){
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for(int u : upper)
				if(u < 0)
					ct++;
			return ct;
		}
	}
	
	void dfs(int[][] gg, int cur, int prev, StringBuilder sb)
	{
		sb.append(label[cur]);
		int[][] rows = new int[gg[cur].length][];
		for(int i = 0;i < gg[cur].length;i++){
			rows[i] = new int[]{gg[cur][i], label[gg[cur][i]]};
		}
		Arrays.sort(rows, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		for(int i = 0;i < gg[cur].length;i++){
			if(rows[i][0] != prev){
				dfs(gg, rows[i][0], cur, sb);
			}
		}
	}
	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for(i = n - 1;i >= 0 && a[i] == base - 1;i--)
			;
		if(i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}
	
	public static void preprocess()
	{
	}
	
	Scanner in;
	PrintWriter out;
	StringWriter sw;
	int cas;
	static List<Status> running = new ArrayList<Status>();
	
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
	
	public CLarge(int cas, Scanner in)
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
		long start = System.nanoTime();
		
		ExecutorService es = Executors.newFixedThreadPool(NTHREAD);
		CompletionService<CLarge> cs = new ExecutorCompletionService<CLarge>(es);
		
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
			CLarge runner = new CLarge(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			CLarge runner = cs.take().get(); // not ordered
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
