package gcj2017.q;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class D implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
	static String BASEPATH = "c:\\temp\\gcj2017\\q\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String INPATH = BASEPATH + D.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n;
	char[][] map;
	
	public void read() // not parallelized
	{
		n = ni();
		int K = ni();
		map = new char[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(map[i], '.');
		}
		for(int i = 0;i < K;i++){
			char x = in.next().charAt(0);
			int r = ni()-1;
			int c = ni()-1;
			map[r][c] = x;
		}
	}
	
	public void process() // parallelized!
	{
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == '.' || map[i][j] == '+'){
					g[i][j] = true;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == 'x' || map[i][j] == 'o'){
					for(int k = 0;k < n;k++){
						g[i][k] = false;
						g[k][j] = false;
					}
					g[i][j] = true;
				}
			}
		}
		int[] matg = doBipartiteMatching(g);
		
		// -(n-1), n-1
		boolean[][] h = new boolean[2*n][2*n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == '.' || map[i][j] == 'x'){
					h[i-j+n][i+j] = true;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == '+' || map[i][j] == 'o'){
					for(int k = 0;k < 2*n;k++){
						h[i-j+n][k] = false;
						h[k][i+j] = false;
					}
					h[i-j+n][i+j] = true;
				}
			}
		}
		
		int[] math = doBipartiteMatching(h);
		char[][] nmap = new char[n][n];
		int score = 0;
		int dif = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				boolean mg = matg[i] == j;
				boolean mh = math[i-j+n] == i+j;
				// if mg=false, map[i][j] must not be 'x','o'
				// if mh=false, map[i][j] must not be '+','o'
				if(mg)score++;
				if(mh)score++;
				if(mg && mh){
					nmap[i][j] = 'o';
				}else if(mg && !mh){
					nmap[i][j] = 'x';
				}else if(!mg && mh){
					nmap[i][j] = '+';
				}else{
					nmap[i][j] = '.';
				}
				if(nmap[i][j] != map[i][j])dif++;
			}
		}
		out.println(score + " " + dif);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(nmap[i][j] != map[i][j]){
					out.println(nmap[i][j] + " " + (i+1) + " " + (j+1));
				}
			}
		}
		// ...
		// +++
		// x..
	}
	
	public static int[] doBipartiteMatching(boolean[][] g)
	{
		int n = g.length;
		if(n == 0)return new int[0];
		int m = g[0].length;
		if(m == 0)return new int[n];
		int[] im = new int[m];
		Arrays.fill(im, -1);
		BitSet visited = new BitSet();
		int matched = 0;
		for(int i = 0;i < n;i++){
			if(visit(g, i, visited, im)) {
				visited.clear();
				matched++;
			}
		}

		int[] ret = new int[n];
		Arrays.fill(ret, -1);
		for(int i = 0;i < m;i++){
			if(im[i] != -1)ret[im[i]] = i;
		}
		return ret;
	}

	public static boolean visit(boolean[][] g, int cur, BitSet visited, int[] im)
	{
		if(cur == -1)return true;

		for(int i = visited.nextClearBit(0);i != g[cur].length;i = visited.nextClearBit(i+1)){
			if(g[cur][i]){
				visited.set(i);
				if(visit(g, im[i], visited, im)){
					im[i] = cur;
					return true;
				}
			}
		}
		return false;
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
	
	public D(int cas, Scanner in)
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
		CompletionService<D> cs = new ExecutorCompletionService<D>(es);
		
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
			D runner = new D(i+1, in);
			runner.read();
			cs.submit(runner, runner);
		}
		es.shutdown();
		String[] outs = new String[n];
		for(int i = 0;i < n;i++){
			D runner = cs.take().get(); // not ordered
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
