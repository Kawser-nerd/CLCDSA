package gcj2017.r2;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
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

public class A implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
	static String BASEPATH = "c:\\temp\\gcj2017\\r2\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String PREFIX = BASEPATH + A.class.getSimpleName().charAt(0);
	static String INPATH = PREFIX + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = PREFIX + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n;
	int[] g;
	int P;
	
	public void read() // not parallelized
	{
		n = ni();
		P = ni();
		g = na(n);
	}
	
	public void process() // parallelized!
	{
		int[] f = new int[P];
		for(int v : g){
			f[v%P]++;
		}
		// 1+3
		// 1+1+2
		// 3+3+2
		// 1+1+1+1
		// 2+2
		// 3+3+3+3
		
		if(P == 4){
			int[] u = new int[3];
			List<int[]> valid = new ArrayList<>();
			do{
				if(u[0]+u[1]+u[2] > 0 && u[0]+u[1]+u[2] <= 4 && (u[0]+2*u[1]+3*u[2])%4 == 0){
					valid.add(Arrays.copyOf(u, 3));
				}
			}while(inc(u, 5));
			
			int[][][] dp = new int[f[1]+1][f[2]+1][f[3]+1];
			for(int[][] row : dp){
				for(int[] row2 : row){
					Arrays.fill(row2, -99999999);
				}
			}
			dp[f[1]][f[2]][f[3]] = f[0];
			int ret = f[0];
			for(int i = f[1];i >= 0;i--){
				for(int j = f[2];j >= 0;j--){
					for(int k = f[3];k >= 0;k--){
						ret = Math.max(ret, dp[i][j][k] + (i+j+k > 0 ? 1 : 0));
						for(int[] v : valid){
							int ni = i-v[0], nj = j-v[1], nk = k-v[2];
							if(ni >= 0 && nj >= 0 && nk >= 0){
								dp[ni][nj][nk] = Math.max(dp[ni][nj][nk], dp[i][j][k] + 1);
							}
						}
					}
				}
			}
			out.println(ret);
		}else if(P == 3){
			int[] u = new int[2];
			List<int[]> valid = new ArrayList<>();
			do{
				if(u[0]+u[1] > 0 && u[0]+u[1] <= 3 && (u[0]+2*u[1])%3 == 0){
					valid.add(Arrays.copyOf(u, 2));
				}
			}while(inc(u, 4));
			
			int[][] dp = new int[f[1]+1][f[2]+1];
			for(int[] row : dp){
				Arrays.fill(row, -99999999);
			}
			dp[f[1]][f[2]] = f[0];
			int ret = f[0];
			for(int i = f[1];i >= 0;i--){
				for(int j = f[2];j >= 0;j--){
					ret = Math.max(ret, dp[i][j] + (i+j > 0 ? 1 : 0));
					for(int[] v : valid){
						int ni = i-v[0], nj = j-v[1];
						if(ni >= 0 && nj >= 0){
							dp[ni][nj] = Math.max(dp[ni][nj], dp[i][j] + 1);
						}
					}
				}
			}
			out.println(ret);
		}else{
			out.println(f[0] + (f[1]+1) / 2);
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	
	public static void preprocess()
	{
	}
	
	protected Scanner in;
	protected PrintWriter out;
	protected StringWriter sw;
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
		
		// get dump
		StringBuilder dump = new StringBuilder();
		for(Field f : this.getClass().getDeclaredFields()){
			int mo = f.getModifiers();
			if(!Modifier.isStatic(mo) && !Modifier.isProtected(mo)){
				try {
					dump.append(String.format("%s: %s\n", f.getName(), Arrays.deepToString(new Object[]{f.get(this)})));
				} catch (IllegalArgumentException | IllegalAccessException e) {
					e.printStackTrace();
				}
			}
		}
		
		try{
			process();
		}catch(Throwable t){
			// print dump
			System.err.println(dump);
			throw t;
		}
		
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
			System.out.println("OUTPATH : ");
			System.out.println(OUTPATH);
		}
	}
}
