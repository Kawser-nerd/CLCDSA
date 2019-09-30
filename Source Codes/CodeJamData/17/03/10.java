package gcj2017.q;
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

public class C implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
	static String BASEPATH = "c:\\temp\\gcj2017\\q\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-2-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	long n, K;
	
	public void read() // not parallelized
	{
		n = nl();
		K = nl();
	}
	
	public void process() // parallelized!
	{
		long base = n;
		long low = 1, high = 0;
		
		long last = -1;
		while(K > 0){
			long nlow = 0, nhigh = 0;
			long cons = Math.min(high, K);
			K -= cons;
			if(K == 0){
				last = base + 1;
				break;
			}
			if(base % 2 == 1){
				nlow += high;
				nhigh += high;
			}else{
				nhigh += 2*high;
			}
			
			cons = Math.min(low, K);
			K -= cons;
			if(K == 0){
				last = base;
				break;
			}
			if(base % 2 == 1){
				nlow += low*2;
			}else{
				nlow += low;
				nhigh += low;
			}
			
			low = nlow;
			high = nhigh;
			base = (base-1) / 2;
		}
		out.println((last)/2 + " " + ((last-1)/2));
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
