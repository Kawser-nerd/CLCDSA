package c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	public static void main(String[] args) throws Exception {
		Solver<Object> solver = Solver.getInstance("C-large.in");
		Scanner sc = solver.getScanner();
		int casenum = sc.nextInt();
		for(int caseid=0;caseid<casenum;caseid++) {
			int h = sc.nextInt();
			int w = sc.nextInt();
			char[][] map = new char[h][];
			for(int i=0;i<h;i++) {
				map[i] = sc.next().toCharArray();
			}
			solver.addTask(new Task(h,w,map));
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	public static final String IMPOSSIBLE = "IMPOSSIBLE\n";
	int h,w;
	char[][] map;
	
	public Task(int h, int w, char[][] map) {
		super();
		this.h = h;
		this.w = w;
		this.map = map;
	}

	int[][] shooterH;
	int[][] dirH;
	int[][] shooterV;
	int[][] dirV;
	@Override
	public Object call() throws Exception {
		shooterH = new int[h][w];
		shooterV = new int[h][w];
		dirH = new int[h][w];
		dirV = new int[h][w];
		for(int i=0;i<h;i++) {
			Arrays.fill(shooterH[i], -1);
			Arrays.fill(shooterV[i], -1);
		}
		boolean[] canHorizontial = new boolean[110];
		boolean[] canVertical = new boolean[110];
		int[] shooterI = new int[110];
		int[] shooterJ = new int[110];
		int shooterNum = 0;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if (map[i][j] == '-' || map[i][j] == '|') {
					shooterI[shooterNum] = i;
					shooterJ[shooterNum] = j;
					if (beam(map,i,j,0,shooterNum)) {
						canHorizontial[shooterNum] = true;
					}
					if (beam(map,i,j,1,shooterNum)) {
						canVertical[shooterNum] = true;
					}
					if (!canHorizontial[shooterNum] && !canVertical[shooterNum]) {
						return IMPOSSIBLE;
					}
					shooterNum++;
				}
			}
		}
		TwoSAT sat = new TwoSAT(shooterNum);
		//horizontial -> x , vertical -> ¬x
		for(int i=0;i<shooterNum;i++) {
			if (!canHorizontial[i]) {
				sat.addClause(false, i, false, i);
			}
			if (!canVertical[i]) {
				sat.addClause(true, i, true, i);
			}
		}
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if (map[i][j] != '.') {
					continue;
				}
				if (shooterH[i][j] == -1 && shooterV[i][j] == -1) {
					return IMPOSSIBLE;
				}
				if (shooterH[i][j] == -1) {
					boolean b = dirV[i][j] == 0;
					sat.addClause(b, shooterV[i][j], b, shooterV[i][j]);
				}else if(shooterV[i][j] == -1) {
					boolean b = dirH[i][j] == 0;
					sat.addClause(b, shooterH[i][j], b, shooterH[i][j]);
				}else{
					boolean b1 = dirV[i][j] == 0;
					boolean b2 = dirH[i][j] == 0;
					sat.addClause(b2, shooterH[i][j], b1, shooterV[i][j]);
				}
			}
		}
		boolean[] ans = sat.solve();
		if (ans == null) {
			return IMPOSSIBLE;
		}
		for(int i=0;i<shooterNum;i++) {
			map[shooterI[i]][shooterJ[i]] = ans[i] ? '-' : '|';
		}
		StringBuilder sb = new StringBuilder();
		sb.append("POSSIBLE\n");
		for(int i=0;i<h;i++) {	
			for(int j=0;j<w;j++) {
				sb.append(map[i][j]);
			}
			sb.append('\n');
		}
		return sb.toString();
	}
	
	public static final int[] DI = {0,-1,0,1};
	public static final int[] DJ = {1,0,-1,0};
	public boolean beam(char[][] map,int si,int sj,int hv,int beamId) {
		if (beam(map,si,sj,0+hv,beamId,hv,false) && beam(map,si,sj,2+hv,beamId,hv,false)) {
			beam(map,si,sj,0+hv,beamId,hv,true);
			beam(map,si,sj,2+hv,beamId,hv,true);
			return true;
		}
		return false;
	}
	public boolean beam(char[][] map,int si,int sj,int dir,int beamId,int hv,boolean write) {
		int ci = si;
		int cj = sj;
		while(true) {
			ci += DI[dir];
			cj += DJ[dir];
			//beam stops
			if (ci < 0 || ci >= h || cj < 0 || cj >= w || map[ci][cj] == '#') {
				return true;
			}
			//destroy
			if (map[ci][cj] == '-' || map[ci][cj] == '|') {
				return false;
			}
			//mirror
			if (map[ci][cj] == '/') {
				dir ^= 1;
			}else if(map[ci][cj] == '\\') {
				dir ^= 3;
			}
			//empty
			if (map[ci][cj] == '.' && write) {
				if (dir == 0 || dir == 2) {
					shooterH[ci][cj] = beamId;
					dirH[ci][cj] = hv;
				}else{
					shooterV[ci][cj] = beamId;
					dirV[ci][cj] = hv;
				}
			}
		}
	}
	
}
class TwoSAT {
	int n;
	SCC graph;
	public TwoSAT(int n) {
		this.n = n;
		graph = new SCC(n * 2); //￢x0, ..., ￢xn, x0, ..., xn  
	}
	
	//(￢x0 ∨ x1) -> (false, 0, true, 1)
	public void addClause(boolean tf1, int x1, boolean tf2, int x2) {
//		System.out.println((tf1 ? "" : "￢") + x1 + "∨" + (tf1 ? "" : "￢") + x2);
		graph.addEdge(x1 + (tf1 ? 0 : n), x2 + (tf2 ? n : 0)); //￢x1 -> x2
		graph.addEdge(x2 + (tf2 ? 0 : n), x1 + (tf1 ? n : 0)); //￢x2 -> x1
	}
	
	//充足不可能なときnull, そうでなければ真偽の割り当て
	public boolean[] solve() {
		graph.scc();
		int[] order = graph.order;
		boolean[] res = new boolean[n];
		for(int i=0;i<n;i++) {
			if (order[i] == order[i+n]) {
				return null;
			}
			if (order[i+n] > order[i]) {
				res[i] = true;
			}
		}
		return res;
	}
}
class SCC {
	int n;
	ArrayList<Integer>[] graph; //グラフ
	ArrayList<Integer>[] rgraph; //逆辺からなるグラフ
	ArrayList<Integer> vertices; //帰りがけ順に頂点を並べる
	boolean[] used;
	int[] order; //強連結成分のトポロジカル順序
	int sccNum;
	
	@SuppressWarnings("unchecked")
	public SCC(int n) {
		this.n = n;
		graph = new ArrayList[n];
		rgraph = new ArrayList[n];
		for(int i=0;i<n;i++) {
			graph[i] = new ArrayList<>();
			rgraph[i] = new ArrayList<>();
		}
	}
	
	public void addEdge(int from,int to) {
//		System.out.println(from + "->" + to);
		graph[from].add(to);
		rgraph[to].add(from);
	}
	
	private void dfs(int v) {
		used[v] = true;
		for(int u: graph[v]) {
			if (!used[u]) {
				dfs(u);
			}
		}
		vertices.add(v);
	}
	
	private void rdfs(int v, int k) {
		used[v] = true;
		order[v] = k;
		for(int u: rgraph[v]) {
			if (!used[u]) {
				rdfs(u, k);
			}
		}
	}
	
	public void scc() {
		used = new boolean[n];
		order = new int[n];
		vertices = new ArrayList<>();
		sccNum = 0;
		for(int i=0;i<n;i++) {
			if (!used[i]) {
				dfs(i);
			}
		}
		Arrays.fill(used, false);
		for(int i=vertices.size()-1;i>=0;i--) {
			int v = vertices.get(i);
			if (!used[v]) {
				rdfs(v, sccNum++);
			}
		}
	}
	
	//scc()の後に呼び出して強連結成分をトポロジカル順序で返す
	@SuppressWarnings("unchecked")
	public ArrayList<Integer>[] restoreSCCs() {
		ArrayList<Integer>[] res = new ArrayList[sccNum];
		for(int i=0;i<sccNum;i++) {
			res[i] = new ArrayList<>();
		}
		for(int i=0;i<n;i++) {
			res[order[i]].add(i);
		}
		return res;
	}
}

interface Solver<R> {
	public Scanner getScanner();
	public void addTask(Callable<R> task);
	public void finish();
	public static <T> Solver<T> getInstance(String filename) throws IOException {
		if (filename == null) {
			return new DebugSolver<>();
		}else{
			return new ConcurrentSolver<>(filename);
		}
	}
}
class DebugSolver<R> implements Solver<R> {
	private ArrayList<Callable<R>> tasks = new ArrayList<>();
	public DebugSolver() {
		
	}
	public Scanner getScanner() {
		return new Scanner(System.in);
	}
	public void addTask(Callable<R> task) {
		tasks.add(task);
	}
	public void finish() {
		for(int i=0;i<tasks.size();i++) {
			try {
				long stime = System.nanoTime();
				System.out.print("Case #" + (i+1) + ": " + tasks.get(i).call());
				System.out.println((System.nanoTime() - stime) / 1000000 + " ms");
			} catch (Exception e) {
				e.printStackTrace();
				return;
			}
		}
	}
}
class ConcurrentSolver<R> implements Solver<R>{
	private ExecutorService es = Executors.newFixedThreadPool(4,(runnable)->new Thread(null, runnable, "", 16L * 1024L * 1024L)); //16MB stack size
	private ArrayList<FutureTask<R>> tasks = new ArrayList<>();
	private Scanner sc;
	private PrintWriter pw;
	public ConcurrentSolver(String filename) throws IOException {
		if (filename == null) {
			sc = new Scanner(System.in);
			pw = new PrintWriter(System.out);
		}else{
			sc = new Scanner(new File(filename));
			Matcher matcher = Pattern.compile("(.+)\\.in").matcher(filename);
			String filenameOut;
			if (matcher.matches()) {
				filenameOut = matcher.group(1) + ".out";
			}else{
				filenameOut = "out.txt";
			}
			pw = new PrintWriter(new File(filenameOut));
		}
	}
	public Scanner getScanner() {
		return sc;
	}
	public void addTask(Callable<R> task) {
		FutureTask<R> futureTask = new FutureTask<>(new TaskWrapper(tasks.size() + 1, task));
		tasks.add(futureTask);
		es.submit(futureTask);
	}
	public void finish() {
		for(int i=0;i<tasks.size();i++) {
			try {
				pw.print("Case #" + (i+1) + ": " + tasks.get(i).get());
			} catch (InterruptedException | ExecutionException e) {
				e.printStackTrace();
			}
		}
		pw.flush();
		es.shutdown();
	}
	class TaskWrapper implements Callable<R> {
		int id;
		Callable<R> c;
		public TaskWrapper(int caseId,Callable<R> c) {
			this.id = caseId;
			this.c = c;
		}
		public R call() throws Exception {
			System.out.println("Start #" + id);
			long stime = System.nanoTime();
			R res = c.call();
			System.out.println("End #" + id + " (" + (System.nanoTime() - stime) / 1000000 + "ms)");
			return res;
		}
	}
}
