package gcj2016.r2;
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

public class A implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "c:\\temp\\gcj2016\\r2\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n, r, p, s;
	
	public void read() // not parallelized
	{
		n = ni();
		r = ni();
		p = ni();
		s = ni();
	}
	
	public void process() // parallelized!
	{
		if(towin[n][0] == r && towin[n][1] == p && towin[n][2] == s){
			out.println(smallest[n][0]);
		}else if(towin[n][0] == p && towin[n][1] == s && towin[n][2] == r){
			out.println(smallest[n][1]);
		}else if(towin[n][0] == s && towin[n][1] == r && towin[n][2] == p){
			out.println(smallest[n][2]);
		}else{
			out.println("IMPOSSIBLE");
		}
	}
	
	static int[][] towin;
	static String[][] smallest;
	
	public static void preprocess()
	{
		// R < P < S < R
		// R P S
		boolean[][][][] d = new boolean[13][3][][]; // R P
		towin = new int[13][];
		for(int i = 0;i < 13;i++){
			for(int j = 0;j < 3;j++){
				d[i][j] = new boolean[(1<<i)+1][(1<<i)+1];
			}
			if(i == 0){
				d[0][0][1<<i][0] = true;
				d[0][1][0][1<<i] = true;
				d[0][2][0][0] = true;
			}else{
				for(int j = 0;j < 3;j++){
					for(int k = j+1;k < 3;k++){
						for(int rj = 0;rj <= 1<<i-1;rj++){
							for(int pj = 0;rj+pj <= 1<<i-1;pj++){
								if(!d[i-1][j][rj][pj])continue;
								for(int rk = 0;rk <= 1<<i-1;rk++){
									for(int pk = 0;rk+pk <= 1<<i-1;pk++){
										if(!d[i-1][k][rk][pk])continue;
										if(win(j, k)){
											d[i][j][rj+rk][pj+pk] = true;
										}else{
											d[i][k][rj+rk][pj+pk] = true;
										}
									}
								}
							}
						}
					}
				}
				for(int rj = 0;rj <= 1<<i;rj++){
					for(int pj = 0;rj+pj <= 1<<i;pj++){
						if(d[i][0][rj][pj]){
//							trz(i, rj, pj, (1<<i)-rj-pj);
							towin[i] = new int[]{rj, pj, (1<<i)-rj-pj};
						}
					}
				}
			}
		}
		
		smallest = new String[13][3];
		for(int i = 0;i < 13;i++){
			for(int j = 0;j < 3;j++){
				smallest[i][j] = "~";
			}
		}
		smallest[0][0] = "R";
		smallest[0][1] = "P";
		smallest[0][2] = "S";
		for(int k = 1;k <= 12;k++){
			for(int i = 0;i < 3;i++){
				for(int j = 0;j < 3;j++){
					if(i != j){
						String can = smallest[k-1][i] + smallest[k-1][j];
						if(win(i, j)){
							if(can.compareTo(smallest[k][i]) < 0){
								smallest[k][i] = can;
							}
						}else{
							if(can.compareTo(smallest[k][j]) < 0){
								smallest[k][j] = can;
							}
						}
					}
				}
			}
//			trz(smallest[k]);
		}
	}
	
	private static boolean win(int x, int y)
	{
		if(x < y)x += 3;
		return x == y+1;
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
	private static void trz(Object... o) { if(!PROD)System.out.println(Arrays.deepToString(o)); }
	
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
