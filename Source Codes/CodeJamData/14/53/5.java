package gcj2014.r3;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class C implements Runnable {
	static final boolean LARGE = false;
	static final boolean PROD = true;
	static final int NTHREAD = 1;
	static String BASEPATH = "x:\\gcj\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n;
	char[] els;
	int[] ids;
	int[] sids;
	
	public void read() // not parallelized
	{
		n = ni();
		els = new char[n];
		ids = new int[n];
		for(int i = 0;i < n;i++){
			els[i] = in.next().charAt(0);
			ids[i] = ni();
		}
		sids = Arrays.copyOf(ids, n);
		Arrays.sort(sids);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || sids[i] != sids[i-1]){
				sids[p++] = sids[i];
			}
		}
		sids = Arrays.copyOf(sids, p);
	}
	
	public void process() // parallelized!
	{
		go(0, new BitSet(), new BitSet(), 2001);
		out.println(ret == 999999 ? "CRIME TIME" : ret);
	}
	
	int ret = 999999;
	Set<Long> cache = new HashSet<Long>();
	
	void go(int time, BitSet ins, BitSet outs, int gen)
	{
		long h = time;
		h = h * 1000000009 + ins.hashCode();
		h = h * 1000000009 + outs.hashCode();
		h = h * 1000000009 + gen;
		if(!cache.add(h))return;
		
		if(time == n){
			ret = Math.min(ret, ins.cardinality());
			return;
		}
		char el = els[time];
		int id = ids[time];
		if(id > 0){
			doit(el, id, ins, outs, gen, time);
		}else{
			for(int v : sids){
				if(v > 0){
					doit(el, v, ins, outs, gen, time);
				}
			}
			for(int i = 2001;i < gen;i++){
				doit(el, i, ins, outs, gen+1, time);
			}
			doit(el, gen, ins, outs, gen+1, time);
		}
	}
	
	void doit(char el, int id, BitSet ins, BitSet outs, int gen, int time)
	{
		if(el == 'E'){
			if(ins.get(id))return;
			boolean prevouts = outs.get(id);
			outs.clear(id);
			ins.set(id);
			
			go(time+1, ins, outs, gen);
			
			ins.clear(id);
			outs.set(id, prevouts);
		}else{
			if(outs.get(id))return;
			boolean previns = ins.get(id);
			ins.clear(id);
			outs.set(id);
			
			go(time+1, ins, outs, gen);
			
			outs.clear(id);
			ins.set(id, previns);
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
