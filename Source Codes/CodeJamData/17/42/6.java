package b;

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
		Solver<Object> solver = Solver.getInstance("B-large.in");
		Scanner sc = solver.getScanner();
		int casenum = sc.nextInt();
		for(int caseid=0;caseid<casenum;caseid++) {
			int n = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			int[] p = new int[m];
			int[] b = new int[m];
			for(int i=0;i<m;i++) {
				p[i] = sc.nextInt();
				b[i] = sc.nextInt();
			}
			Task task = new Task(n,c,m,p,b);
			solver.addTask(task);
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	public static final int INF = 1 << 29;
	int n,c,m;
	int[] p,b;
	
	public Task(int n, int c, int m, int[] p, int[] b) {
		super();
		this.n = n;
		this.c = c;
		this.m = m;
		this.p = p;
		this.b = b;
	}

	int minW = 0;
	@Override
	public Object call() throws Exception {
		int[] count = new int[c];
		for(int i=0;i<m;i++) {
			count[b[i]-1]++;
		}
		for(int i=0;i<c;i++) {
			minW = Math.max(minW, count[i]);
		}
		Arrays.sort(p);
		int l = 0;
		int r = m;
		while(l + 1 < r) {
			int c = (l + r) / 2;
			if (promotions(c) < INF) {
				r = c;
			}else{
				l = c;
			}
		}
		return r + " " + promotions(r);
	}
	
	public int promotions(int w) {
		if (w < minW) return INF;
		int idx = m - 1;
		int promoted = 0;
		int promoting = 0;
		for(int row=n;row>=1;row--) {
			int count = 0;
			while(idx >= 0 && p[idx] > row) {
				promoted++;
				promoting++;
				idx--;
			}
			while(idx >= 0 && p[idx] == row) {
				if (count < w) {
					count++;
				}else{
					promoted++;
					promoting++;
				}
				idx--;
			}
			if (count < w && promoting > 0) {
				int min = Math.min(w - count, promoting);
				promoting -= min;
			}
		}
		if (promoting > 0) {
			return INF;
		}
		return promoted;
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
