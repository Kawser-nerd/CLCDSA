package gcj2017.r2;
import java.io.File;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.CompletionService;
import java.util.concurrent.ExecutorCompletionService;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class D implements Runnable {
	static final boolean LARGE = false;
	static final boolean PROD = true;
	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
	static String BASEPATH = "c:\\temp\\gcj2017\\r2\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String PREFIX = BASEPATH + D.class.getSimpleName().charAt(0);
	static String INPATH = PREFIX + (LARGE ? "-large.in" : "-small-attempt0.in");
//	static String INPATH = PREFIX + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n, m;
	int maxmove;
	char[][] map;
	
	public void read() // not parallelized
	{
		m = ni(); n = ni();
		maxmove = ni();
		map = new char[n][];
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
			assert map[i].length == m;
		}
	}
	
	public void process() // parallelized!
	{
		int ns = 0;
		int nt = 0;
		
		int[][] ids = new int[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(ids[i], -1);
		}
		int[][] sols = new int[100][];
		int[][] turs = new int[100][];
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'S'){
					sols[ns] = new int[]{i, j};
					ids[i][j] = ns++;
					map[i][j] = '.';
				}
				if(map[i][j] == 'T'){
					turs[nt] = new int[]{i, j};
					ids[i][j] = nt++;
					map[i][j] = '.';
				}
			}
		}
		
		boolean[][][] ok = new boolean[ns][1<<nt][nt];
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int j = 0;j < 1<<nt;j++){
			char[][] lmap = new char[n][];
			for(int k = 0;k < n;k++){
				lmap[k] = Arrays.copyOf(map[k], m);
			}
			for(int k = 0;k < nt;k++){
				if(j<<~k<0){
					for(int u = 0;u < 4;u++){
						int r = turs[k][0], c = turs[k][1];
						while(r >= 0 && r < n && c >= 0 && c < m && map[r][c] == '.'){
							lmap[r][c] = '@';
							r += dr[u]; c += dc[u];
						}
					}
				}
			}
			for(int k = 0;k < nt;k++){
				if(j<<~k<0){
					for(int u = 0;u < 4;u++){
						int r = turs[k][0], c = turs[k][1];
						while(r >= 0 && r < n && c >= 0 && c < m && map[r][c] == '.'){
							lmap[r][c] = 'G';
							r += dr[u]; c += dc[u];
						}
					}
					
					int[][] ds = mind(lmap);
					for(int i = 0;i < ns;i++){
						if(ds[sols[i][0]][sols[i][1]] <= maxmove){
							ok[i][j][k] = true;
						}
					}
					
					for(int u = 0;u < 4;u++){
						int r = turs[k][0], c = turs[k][1];
						while(r >= 0 && r < n && c >= 0 && c < m && map[r][c] == '.'){
							lmap[r][c] = '@';
							r += dr[u]; c += dc[u];
						}
					}
				}
			}
		}
		
		boolean[][] dp = new boolean[1<<ns][1<<nt];
		int[][][] prev = new int[1<<ns][1<<nt][];
		dp[(1<<ns)-1][(1<<nt)-1] = true;
		int mini = -1, minj = -1, best = 99999;
		for(int i = (1<<ns)-1;i >= 0;i--){
			for(int j = (1<<nt)-1;j >= 0;j--){
				if(!dp[i][j])continue;
				if(Integer.bitCount(i) < best){
					mini = i; minj = j; best = Integer.bitCount(i);
				}
				for(int k = 0;k < ns;k++){
					if(i<<~k<0){
						for(int l = 0;l < nt;l++){
							if(j<<~l<0){
								if(ok[k][j][l]){
									dp[i^1<<k][j^1<<l] = true;
									prev[i^1<<k][j^1<<l] = new int[]{k, l};
								}
							}
						}
					}
				}
			}
		}
		out.println(ns-best);
		int[][] route = new int[ns-best][];
		int q = ns-best-1;
		int r = mini, c = minj;
		while(q >= 0){
			route[q--] = prev[r][c];
			int nr = r^1<<prev[r][c][0];
			int nc = c^1<<prev[r][c][1];
			r = nr; c = nc;
		}
		for(int[] ro : route){
			out.println((ro[0]+1) + " " + (ro[1]+1));
		}
	}
	
	public static int[][] mind(char[][] map){
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		int n = map.length;
		if(n == 0)return new int[0][0];
		int m = map[0].length;
		int l = dr.length;
		int[][] d = new int[n][m];
		int I = 999999999;
		for(int i = 0;i < n;i++) {
			Arrays.fill(d[i], 999999999);
		}
		
		int B = Integer.numberOfTrailingZeros(Integer.highestOneBit(m))+1;
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == 'G'){
					q.add(i<<B|j);
					d[i][j] = 0;
				}
			}
		}
		
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur>>>B, c = cur&(1<<B)-1;
			for(int k = 0;k < l;k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.' && d[nr][nc] == I) {
					d[nr][nc] = d[r][c] + 1;
					q.add(nr<<B|nc);
				}
			}
		}
		return d;
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
			System.out.println("OUTPATH : ");
			System.out.println(OUTPATH);
		}
	}
}
