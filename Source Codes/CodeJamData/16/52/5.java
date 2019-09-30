package gcj2016.r3;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class B2 implements Runnable {
	static final boolean LARGE = false;
	static final boolean PROD = true;
	static final int NTHREAD = 7;
	static String BASEPATH = "c:\\temp\\gcj2016\\r3\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + B2.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n;
	int[] par;
	char[] got;
	int m;
	char[][] nices;
	
	public void read() // not parallelized
	{
		n = ni();
		par = new int[n+1];
		par[0] = -1;
		for(int i = 0;i < n;i++){
			par[i+1] = ni();
		}
		got = ("~" + in.next()).toCharArray();
		m = ni();
		nices = new char[m][];
		for(int i = 0;i  <m;i++){
			nices[i] = in.next().toCharArray();
		}
	}
	
	int[] des;
	
	public void process() // parallelized!
	{
		int[][] ch = parentToChildren(par);
		des = new int[n+1];
		dfs(ch, 0);
		
		int z = 100000;
		Random gen = new Random(114);
		boolean fi = true;
		for(char[] q : nices){
			int[] kmp = kmpTable(q);
			int ct = 0;
			for(int rep = 0;rep < z;rep++){
				if(go(kmp, ch, q, gen))ct++;
			}
			if(!fi){
				out.print(" ");
			}
			fi = false;
			out.printf("%.9f", (double)ct/z);
		}
		out.println();
	}
	
	boolean go(int[] kmp, int[][] ch, char[] nice, Random gen)
	{
		int p = 0;
		int cur = 0;
		int n = ch.length-1;
		boolean[] all = new boolean[n+1];
		all[0] = true;
		
//		int[] hist = new int[n+1];
		outer:
		for(int i = 0;i < n+1;i++){
//			hist[i] = cur;
			while(p >= 0 && nice[p] != got[cur])p = kmp[p];
			if(++p == nice.length){
				return true;
			}
			for(int c : ch[cur]){
				all[c] = true;
			}
			all[cur] = false;
			
			if(i < n){
				int u = gen.nextInt(n-i)+1;
				for(int j = 0;j < n+1;j++){
					if(all[j]){
						u -= des[j];
						if(u <= 0){
							cur = j;
							continue outer;
						}
					}
				}
			}
		}
		return false;
//		
//		for(int i = 0;i < haystack.length;i++){
//		}
	}
	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
	}
	
	void dfs(int[][] ch, int cur)
	{
		double num = 1;
		int und = 0;
		for(int e : ch[cur]){
			dfs(ch, e);
			und += des[e];
		}
		des[cur] = und + 1;
	}
	
	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
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
	
	public B2(int cas, Scanner in)
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
		CompletionService<B2> cs = new ExecutorCompletionService<B2>(es);
		
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
			B2 runner = new B2(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			B2 runner = cs.take().get(); // not ordered
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
