package gcj2015.r3;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class A implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 7;
	static String BASEPATH = "c:\\temp\\gcj2015\\r3\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	int n, d;
	long[] s, m;
	long as, cs, rs;
	long am, cm, rm;
	
	public void read() // not parallelized
	{
		n = ni(); d = ni();
		s = new long[n];
		m = new long[n];
		s[0] = ni();
		as = ni();
		cs = ni();
		rs = ni();
		m[0] = ni();
		am = ni();
		cm = ni();
		rm = ni();
	}
	
	public void process() // parallelized!
	{
		for(int i = 1;i < n;i++){
			s[i] = (s[i-1] * as + cs)%rs;
			m[i] = (m[i-1] * am + cm)%rm;
		}
		
		m[0] = -1;
		for(int i = 1;i < n;i++){
			m[i] = m[i] % i;
		}
		int[][] g = parentToG(m);
		int[][] pars = parents3(g, 0);
		int[] par = pars[0];
		int[][] rights = makeRights(g, par, 0);
		
		int[][] ns = new int[n][];
		for(int i = 0;i < n;i++)ns[i] = new int[]{(int)s[i], i};
		Arrays.sort(ns, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] iord = rights[1], right = rights[2];
		SegmentTreeUnion st = new SegmentTreeUnion(n);
		for(int i = 0;i < n;i++){
			st.add(iord[ns[i][1]], right[iord[ns[i][1]]]+1, 1);
		}
		
		int ma = -1;
		for(int i = 0;i < n;i++){
			if(ns[i][1] == 0)ma = i;
		}
		int p = 0;
		int max = 0;
		for(int i = 0;i < n;i++){
			st.add(iord[ns[i][1]], right[iord[ns[i][1]]]+1, -1);
			while(p < n && ns[i][0] - ns[p][0] > d){
				st.add(iord[ns[p][1]], right[iord[ns[p][1]]]+1, 1);
				p++;
			}
			if(p <= ma && ma <= i){
				max = Math.max(max, n-st.count[1]);
			}
		}
		out.println(max);
	}
	
	public static class SegmentTreeUnion {
		public int M, H, N;
		public int[] st;
		public int[] count;
		
		public SegmentTreeUnion(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			count = new int[M];
		}
		
		public SegmentTreeUnion(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			count = new int[M];
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			count[i] = st[i] > 0 ? H/Integer.highestOneBit(i) : count[2*i]+count[2*i+1];
		}
		
		public void add(int l, int r, int v){ add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
				count[cur] = st[cur] > 0 ? 1 : 0;
			}else if(l <= cl && cr <= r){
				st[cur] += v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
	}	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved.get(e)){
					stack[p++] = e;
					ved.set(e);
				}
			}
		}
		return ord;
	}
	
	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 0;i--){
			int v = i;
			for(int e : g[ord[i]]){
				if(e != par[ord[i]]){
					v = Math.max(v, right[iord[e]]);
				}
			}
			right[i] = v;
		}
		return new int[][]{ord, iord, right};
	}

	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}
	
	public static int[][] parentToG(long[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[(int)par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[(int)par[i]][--ct[(int)par[i]]] = i;
				g[i][--ct[i]] = (int)par[i];
			}
		}
		return g;
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
	
	public A(int cas, Scanner in)
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
		CompletionService<A> cs = new ExecutorCompletionService<A>(es);
		
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
			A runner = new A(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			A runner = cs.take().get(); // not ordered
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
