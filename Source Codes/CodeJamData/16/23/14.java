package c.large.copy;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
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
			int n = sc.nextInt();
			String[] s = new String[n];
			String[] t = new String[n];
			for(int i=0;i<n;i++) {
				s[i] = sc.next();
				t[i] = sc.next();
			}
			Task task = new Task(n,s,t);
			solver.addTask(task);
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	int n;
	String[] s,t;
	
	
	public Task(int n, String[] s, String[] t) {
		super();
		this.n = n;
		this.s = s;
		this.t = t;
	}


	@Override
	public Object call() throws Exception {
		int max = 0;
		int n1 = 0;
		int n2 = 0;
		HashMap<String,Integer> hm1 = new HashMap<>();
		HashMap<String,Integer> hm2 = new HashMap<>();
		for(int i=0;i<n;i++) {
			if (!hm1.containsKey(s[i])) {
				hm1.put(s[i], n1++);
			}
			if (!hm2.containsKey(t[i])) {
				hm2.put(t[i], n2++);
			}
		}
		int source = n1 + n2;
		int sink = n1 + n2 + 1;
		MaximumFlow mf = new MaximumFlow(n1 + n2 + 2, source, sink);
		for(int i=0;i<n1;i++) {
			mf.addEdge(source, i, 1);
		}
		for(int i=0;i<n2;i++) {
			mf.addEdge(n1 + i, sink, 1);
		}
		for(int i=0;i<n;i++) {
			mf.addEdge(hm1.get(s[i]), n1 + hm2.get(t[i]), 1);
		}
		//|E| - |V| + |maximum-matching|
		return n - (n1 + n2) + mf.fordFulkerson();
	}
	
}
class MaximumFlow {
	public static final int INF = 100000000;

	int V;
	int source;
	int sink;

	ArrayList<Edge>[] graph;
	boolean[] used;

	@SuppressWarnings("unchecked")
	public MaximumFlow(int V,int source,int sink) {
		this.V = V;
		this.source = source;
		this.sink = sink;
		graph = new ArrayList[V];
		for(int i=0;i<V;i++) {
			graph[i] = new ArrayList<Edge>();
		}
		used = new boolean[V];
	}

	public void addEdge(int from,int to,int cap) {
		graph[from].add(new Edge(to,cap,graph[to].size()));
		graph[to].add(new Edge(from,0,graph[from].size()-1));
	}

	public int fordFulkerson() {
		int flow = 0;
		while(true) {
			Arrays.fill(used, false);
			int f = dfsFF(source,sink,INF);
			if (f==0) {
				break;
			}
			flow += f;
		}
		return flow;
	}

	private int dfsFF(int v,int t,int f) {
		if (v==t) {
			return f;
		}
		used[v] = true;
		for(int i=0;i<graph[v].size();i++) {
			Edge e = graph[v].get(i);
			if(!used[e.to] && e.cap>0) {
				int d = dfsFF(e.to,t,Math.min(f, e.cap));
				if(d>0) {
					e.cap-=d;
					graph[e.to].get(e.rev).cap += d;
					return d;
				}
			}
		}
		return 0;
	}

}
class Edge {
	int to;
	int cap;
	int rev;
	public Edge(int to,int cap,int rev) {
		this.to = to;
		this.cap = cap;
		this.rev = rev;
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
				System.out.println("Case #" + (i+1) + ": " + tasks.get(i).call());
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
				pw.println("Case #" + (i+1) + ": " + tasks.get(i).get());
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
