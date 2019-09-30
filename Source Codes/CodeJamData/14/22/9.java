package gcj2014.r1b;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class BLarge implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "x:\\gcj\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + BLarge.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int a, b, K;
	
	public void read() // not parallelized
	{
		a = ni(); b = ni(); K = ni();
	}
	
	public void process() // parallelized!
	{
		out.println(dfs(a-1, b-1, K-1, 30));
	}
	
	Map<Long, Long> cache = new HashMap<Long, Long>();
	
	long dfs(long a, long b, long K, int d)
	{
		if(d == -1)return 1L;
		
//		long h = ((a * 1000000009 + b) * 1000000009 + K) * 1000000009 + d;
//		if(cache.containsKey(h)){
//			return cache.get(h);
//		}
		
		long ad = a>>>d&1;
		long bd = b>>>d&1;
		long kd = K>>>d&1;
		long ret = 0;
		if(kd == 1){
			// 0 0 1
			// 0 1 1
			// 1 0 1
			ret += (a+1)*(b+1);
			if(ad == 1 && bd == 1){
				ret -= (a-(1<<d)+1)*(b-(1<<d)+1);
				ret += dfs(a-(1<<d), b-(1<<d), K-(1<<d), d-1);
			}
		}else{
			// 0 0 0
			// 0 1 0
			// 1 0 0
			if(ad == 0){
				if(bd == 0){
					ret += dfs(a, b, K, d-1);
				}else{
					ret += dfs(a, (1<<d)-1, K, d-1);
					ret += dfs(a, b-(1<<d), K, d-1);
				}
			}else{
				if(bd == 0){
					ret += dfs((1<<d)-1, b, K, d-1);
					ret += dfs(a-(1<<d), b, K, d-1);
				}else{
					ret += dfs((1<<d)-1, (1<<d)-1, K, d-1);
					ret += dfs(a-(1<<d), (1<<d)-1, K, d-1);
					ret += dfs((1<<d)-1, b-(1<<d), K, d-1);
				}
			}
		}
//		tr(a, b, K, d, ret);
//		cache.put(h, ret);
		return ret;
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
	
	public BLarge(int cas, Scanner in)
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
		CompletionService<BLarge> cs = new ExecutorCompletionService<BLarge>(es);
		
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
			BLarge runner = new BLarge(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			BLarge runner = cs.take().get(); // not ordered
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
