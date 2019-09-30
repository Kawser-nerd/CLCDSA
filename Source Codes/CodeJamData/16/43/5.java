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

public class C implements Runnable {
	static final boolean LARGE = false;
	static final boolean PROD = true;
	static final int NTHREAD = 7;
	static String BASEPATH = "c:\\temp\\gcj2016\\r2\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt1.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int r, c;
	int n;
	int[] lovers;
	
	public void read() // not parallelized
	{
		r = ni();
		c = ni();
		n = 2*(r+c);
		lovers = na(2*(r+c));
	}
	
	public void process() // parallelized!
	{
//		for(int i = 1;i <= n;i++){
//			tr(i, where(i));
//		}
		
		for(int i = 0;i < 1<<r*c;i++){
			char[][] map = new char[r][c];
			for(int j = 0;j < r*c;j++){
				int rr = j/c, cc = j % c;
				map[rr][cc] = i<<~j<0 ? '\\' : '/';
			}
			if(ok(map)){
				out.println();
				for(int j = 0;j < r;j++){
					out.println(new String(map[j]));
				}
				return;
			}
		}
		out.println();
		out.println("IMPOSSIBLE");
	}
	
	int[] where(int id)
	{
		if(id <= c){
			return new int[]{-1, id-1, 0};
		}else if(id <= c + r){
			return new int[]{id-c-1, c, 3};
		}else if(id <= c + r + c){
			return new int[]{r, c-(id-(c+r)), 2};
		}else{
			return new int[]{r-(id-(c+r+c)), -1, 1};
		}
	}
	
	boolean ok(char[][] map)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		outer:
		for(int i = 0;i < n;i+=2){
			int rr = where(lovers[i])[0], cc = where(lovers[i])[1], dir = where(lovers[i])[2];
			for(int j = 0;j < r*c+5;j++){
				rr += dr[dir]; cc += dc[dir];
				if(rr >= 0 && rr < r && cc >= 0 && cc < c){
					if(map[rr][cc] == '/'){
						dir ^= 3;
					}else{
						dir ^= 1;
					}
				}else{
					int[] goal = where(lovers[i+1]);
					if(goal[0] == rr && goal[1] == cc){
						continue outer;
					}else{
						return false;
					}
				}
			}
			return false;
		}
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
