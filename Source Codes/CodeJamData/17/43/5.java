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

public class C implements Runnable {
	static final boolean LARGE = true;
	static final boolean PROD = true;
	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
	static String BASEPATH = "c:\\temp\\gcj2017\\r2\\";
//	static String BASEPATH = "/home/ec2-user/";
	
	static String PREFIX = BASEPATH + C.class.getSimpleName().charAt(0);
	static String INPATH = PREFIX + (LARGE ? "-large.in" : "-small-attempt1.in");
//	static String INPATH = PREFIX + (LARGE ? "-large-practice.in" : "-small-practice.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	int n,m;
	char[][] map;
	
	public void read() // not parallelized
	{
		n = ni(); m = ni();
		map = new char[n][];
		for(int i = 0;i < n;i++){
			map[i] = in.next().toCharArray();
			assert map[i].length == m;
		}
	}
	
	public void process() // parallelized!
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		// "/" 3210 ^3
		// "\" 1032 ^1
		int[][] ids = new int[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(ids[i], -1);
		}
		int idgen = 0;
		int[][][] mark = new int[2][n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(mark[0][i], -1);
			Arrays.fill(mark[1][i], -1);
		}
		
		int[] assign = new int[200];
		int[] youcan = new int[200];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '-' || map[i][j] == '|'){
					int id = idgen++;
					ids[i][j] = id;
					inner:
					for(int k = 0;k < 4;k++){
						int r = i, c = j;
						int dir = k;
						while(true){
							r += dr[dir]; c += dc[dir];
							if(r >= 0 && r < n && c >= 0 && c < m){
								if(map[r][c] == '-' || map[r][c] == '|'){
									continue inner;
								}else if(map[r][c] == '#'){
									break;
								}else if(map[r][c] == '.'){
								}else if(map[r][c] == '/'){
									dir ^= 3;
								}else if(map[r][c] == '\\'){
									dir ^= 1;
								}else{
									throw new RuntimeException();
								}
							}else{
								break;
							}
						}
						youcan[id] |= 1<<k;
					}
					if((youcan[id]&5) == 5){
						for(int k = 0;k < 4;k+=2){
							int r = i, c = j;
							int dir = k;
							while(true){
								r += dr[dir]; c += dc[dir];
								if(r >= 0 && r < n && c >= 0 && c < m){
									if(map[r][c] == '#'){
										break;
									}else if(map[r][c] == '.'){
										assert mark[dir&1][r][c] == -1;
										mark[dir&1][r][c] = 2*id;
									}else if(map[r][c] == '/'){
										dir ^= 3;
									}else if(map[r][c] == '\\'){
										dir ^= 1;
									}else{
										throw new RuntimeException();
									}
								}else{
									break;
								}
							}
						}
						assign[id]++;
					}
					if((youcan[id]&10) == 10){
						for(int k = 1;k < 4;k+=2){
							int r = i, c = j;
							int dir = k;
							while(true){
								r += dr[dir]; c += dc[dir];
								if(r >= 0 && r < n && c >= 0 && c < m){
									if(map[r][c] == '#'){
										break;
									}else if(map[r][c] == '.'){
										assert mark[dir&1][r][c] == -1;
										mark[dir&1][r][c] = 2*id+1;
									}else if(map[r][c] == '/'){
										dir ^= 3;
									}else if(map[r][c] == '\\'){
										dir ^= 1;
									}else{
										throw new RuntimeException();
									}
								}else{
									break;
								}
							}
						}
						assign[id]--;
					}
					if((youcan[id]&5) != 5 && (youcan[id]&10) != 10){
						out.println("IMPOSSIBLE");
						return;
					}
				}
			}
		}
		
		int[] from = new int[n*m*2];
		int[] to = new int[n*m*2];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					if(mark[0][i][j] == -1 && mark[1][i][j] == -1){
						out.println("IMPOSSIBLE");
						return;
					}
					int canid = -1;
					if(mark[0][i][j] != -1 && mark[1][i][j] == -1){
						canid = mark[0][i][j];
					}
					if(mark[0][i][j] == -1 && mark[1][i][j] != -1){
						canid = mark[1][i][j];
					}
					if(canid != -1){
						if(canid % 2 ==0){
							if(assign[canid/2] == -1){
								out.println("IMPOSSIBLE");
								return;
							}
							assign[canid/2] = 1;
						}else{
							if(assign[canid/2] == 1){
								out.println("IMPOSSIBLE");
								return;
							}
							assign[canid/2] = -1;
						}
					}else{
						from[p] = mark[0][i][j]^1; to[p] = mark[1][i][j]; p++;
						from[p] = mark[1][i][j]^1; to[p] = mark[0][i][j]; p++;
					}
				}
			}
		}
		
		int[][] g = packD(idgen*2, from, to, p);
		int[] clus = decomposeToSCC(g);
		
		int[] mtime = new int[idgen];
		for(int i = 0;i < idgen;i++)mtime[i] = i;
		
		for(int i = 0;i < idgen;i++){
			if(clus[i*2] == clus[i*2+1]){
				out.println("IMPOSSIBLE");
				return;
			}
			if(assign[i] == 0){
				assign[i] = clus[2*i] > clus[2*i+1] ? -2 : 2;
			}
		}
		
		int time = idgen;
		for(int rep = 0;rep < 11000;rep++){
			boolean contradict = false;
			for(int i = 0;i < idgen*2;i++){
				for(int e : g[i]){
					boolean x = assign[i/2] * (i%2 == 1 ? -1 : 1) > 0;
					boolean y = assign[e/2] * (e%2 == 1 ? -1 : 1) > 0;
					if(x && !y){
						contradict = true;
						if(Math.abs(assign[i/2]) == 1 && Math.abs(assign[e/2]) == 1){
							out.println("IMPOSSIBLE");
							return;
						}else if(Math.abs(assign[i/2]) == 1 && Math.abs(assign[e/2]) == 2){
							assign[e/2] = -assign[e/2];
							mtime[e/2] = time++;
						}else if(Math.abs(assign[i/2]) == 2 && Math.abs(assign[e/2]) == 1){
							assign[i/2] = -assign[i/2];
							mtime[i/2] = time++;
						}else if(mtime[i/2] < mtime[e/2]){
							assign[i/2] = -assign[i/2];
							mtime[i/2] = time++;
						}else{
							assign[e/2] = -assign[e/2];
							mtime[e/2] = time++;
						}
					}
				}
			}
			if(!contradict){
				out.println("POSSIBLE");
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						if(ids[i][j] >= 0){
							if(assign[ids[i][j]] > 0){
								map[i][j] = '|';
							}else{
								map[i][j] = '-';
							}
						}
					}
				}
				for(char[] row : map){
					out.println(new String(row));
				}
				
				check(map);
				
				return;
			}
		}
		assert false;
		out.println("IMPOSSIBLE");
	}
	
	void check(char[][] map)
	{
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		boolean[][] passed = new boolean[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '-' || map[i][j] == '|'){
					for(int k = map[i][j] == '-' ? 1 : 0;k < 4;k+=2){
						int r = i, c = j;
						int dir = k;
						while(true){
							r += dr[dir]; c += dc[dir];
							if(r >= 0 && r < n && c >= 0 && c < m){
								if(map[r][c] == '-' || map[r][c] == '|'){
									throw new RuntimeException(i + " " + j);
								}else if(map[r][c] == '#'){
									break;
								}else if(map[r][c] == '.'){
									passed[r][c] = true;
								}else if(map[r][c] == '/'){
									dir ^= 3;
								}else if(map[r][c] == '\\'){
									dir ^= 1;
								}else{
									throw new RuntimeException();
								}
							}else{
								break;
							}
						}
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.' && !passed[i][j]){
					throw new RuntimeException("W" + i + " " + j);
				}
			}
		}
	}
	
	public static int[] decomposeToSCC(int[][] g)
	{
		int n = g.length;
		int[] stack = new int[n+1];
		int[] ind = new int[n+1];
		int[] ord = new int[n];
		Arrays.fill(ord, -1);
		int[] low = new int[n];
		Arrays.fill(low, -1);
		int sp = 0;
		int id = 0; // preorder
		int[] clus = new int[n];
		int cid = 0;
		int[] cstack = new int[n+1];
		int csp = 0;
		boolean[] incstack = new boolean[n];
		for(int i = 0;i < n;i++){
			if(ord[i] == -1){
				ind[sp] = 0;
				cstack[csp++] = i;
				stack[sp++] = i;
				incstack[i] = true;
				while(sp > 0){
					int cur = stack[sp-1];
					if(ind[sp-1] == 0){
						ord[cur] = low[cur] = id++;
					}
					if(ind[sp-1] < g[cur].length){
						int nex = g[cur][ind[sp-1]];
						if(ord[nex] == -1){
							ind[sp-1]++;
							ind[sp] = 0;
							incstack[nex] = true;
							cstack[csp++] = nex;
							stack[sp++] = nex;
						}else{
							// shortcut
							if(incstack[nex])low[cur] = Math.min(low[cur], low[nex]);
							ind[sp-1]++;
						}
					}else{
						if(ord[cur] == low[cur]){
							while(csp > 0){
								incstack[cstack[csp-1]] = false;
								clus[cstack[--csp]] = cid;
								if(cstack[csp] == cur)break;
							}
							cid++;
						}
						if(--sp >= 1)low[stack[sp-1]] = Math.min(low[stack[sp-1]], low[stack[sp]]);
					}
				}
			}
		}
		return clus;
	}

	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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
			System.out.println("OUTPATH : ");
			System.out.println(OUTPATH);
		}
	}
}
