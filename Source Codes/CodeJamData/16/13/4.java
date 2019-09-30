package gcj2016.r1a;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class C implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "c:\\temp\\gcj2016\\r1a\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int[] f;
	
	public void read() // not parallelized
	{
		int n = ni();
		f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
	}
	
	public void process() // parallelized!
	{
		ResultCluster rc = cluster(f);
		int ret = 0;
		int n = f.length;
		int t2 = 0;
		for(int[] x : rc.cycles){
			if(x.length == 2){
				int lret = 2;
				for(int t = 0;t < 2;t++){
					Queue<Integer> q = new ArrayDeque<>();
					q.add(x[t]);
					int[] d = new int[n];
					Arrays.fill(d, 99999);
					d[x[t]] = 0;
					d[x[t^1]] = 0;
					int maxd = 0;
					while(!q.isEmpty()){
						int cur = q.poll();
						for(int i = 0;i < n;i++){
							if(f[i] == cur && d[i] > d[cur] + 1){
								d[i] = d[cur] + 1;
								q.add(i);
								maxd = Math.max(maxd, d[i]);
							}
						}
					}
					lret += maxd;
				}
				t2 += lret;
			}else{
				ret = Math.max(ret, x.length);
			}
		}
		out.println(Math.max(t2, ret));
	}
	
	public static ResultCluster cluster(int[] f)
	{
		int n = f.length;
		DJSet ds = new DJSet(n);
		int[] red = new int[n+1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(ds.union(i, f[i]))red[p++] = f[i];
		}
		int[] clus = new int[n]; Arrays.fill(clus, -1);
		int cidgen = 0;
		for(int i = 0;i < n;i++)if(ds.upper[i] < 0)clus[i] = cidgen++;
		for(int i = 0;i < n;i++)clus[i] = clus[ds.root(i)];
		
		int[][] cycles = new int[p][];
		int[] temp = new int[n+1];
		for(int i = 0;i < p;i++){
			temp[0] = red[i];
			int j = 1;
			for(;;j++){
				temp[j] = f[temp[j-1]];
				if(temp[j] == temp[0])break;
			}
			cycles[clus[red[i]]] = Arrays.copyOf(temp, j);
		}
		ResultCluster rc = new ResultCluster();
		rc.clus = clus;
		rc.cycles = cycles;
		return rc;
	}
	
	public static class ResultCluster {
		int[] clus;
		int[][] cycles;
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
			if (x != y) {
				if (upper[y] < upper[x]) {
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
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
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
	
	public C(int cas, Scanner in)
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
		CompletionService<C> cs = new ExecutorCompletionService<C>(es);
		
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
			C runner = new C(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			C runner = cs.take().get(); // not ordered
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
