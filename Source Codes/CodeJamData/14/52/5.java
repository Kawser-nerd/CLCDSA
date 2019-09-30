package gcj2014.r3;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class BL implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "x:\\gcj\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + BL.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int P, Q;
	int n;
	int[] h;
	int[] g;
	
	public void read() // not parallelized
	{
		P = ni(); Q = ni(); n = ni();
		h = new int[n];
		g = new int[n];
		for(int i = 0;i < n;i++){
			h[i] = ni();
			g[i] = ni();
		}
	}
	
	public void process() // parallelized!
	{
		final int z = 1005;
		int[][] dp = new int[n+1][z+1]; // time free
		for(int i = 0;i < n+1;i++){
			Arrays.fill(dp[i], -999999999);
		}
		
		// if last attack, how many max free?
		int[] edp = new int[201];
		Arrays.fill(edp, -9999999);
		for(int i = 1;i <= 200;i++){
			if(i - Q <= 0){
				if(i - P <= 0){
					edp[i] = -1;
				}else{
					edp[i] = -9999999;
				}
			}else{
				edp[i] = Math.max(edp[i], edp[i-Q] + 1);
			}
			if(i-P-Q > 0)edp[i] = Math.max(edp[i], edp[i-P-Q]);
			if(i-P > 0)edp[i] = Math.max(edp[i], edp[i-P]-1);
//			tr(i, edp[i]);
		}
		
		dp[0][1] = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= z;j++){
				if(dp[i][j] < 0)continue;
				// no attack
				{
					int nj = Math.min(z, (h[i]+Q-1)/Q+j);
					dp[i+1][nj] = Math.max(dp[i+1][nj], dp[i][j]);
				}
				
				if(j+edp[h[i]] >= 0){
					int nj = Math.min(j+edp[h[i]], z);
					dp[i+1][nj] = Math.max(dp[i+1][nj], dp[i][j] + g[i]);
				}
			}
		}
		int ret = 0;
		for(int j = 0;j <= z;j++){
			ret = Math.max(ret, dp[n][j]);
		}
		out.println(ret);
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
	
	public BL(int cas, Scanner in)
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
		CompletionService<BL> cs = new ExecutorCompletionService<BL>(es);
		
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
			BL runner = new BL(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			BL runner = cs.take().get(); // not ordered
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
