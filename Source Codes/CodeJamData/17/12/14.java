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
			int p = sc.nextInt();
			int[] r = new int[n];
			for(int i=0;i<n;i++) {
				r[i] = sc.nextInt();
			}
			int[][] q = new int[n][p];
			for(int i=0;i<n;i++) {
				for(int j=0;j<p;j++) {
					q[i][j] = sc.nextInt();
				}
			}
			Task task = new Task(n,p,r,q);
			solver.addTask(task);
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	int n,m;
	int[] r;
	int[][] q;
	
	
	
	public Task(int n, int p, int[] r, int[][] q) {
		super();
		this.n = n;
		this.m = p;
		this.r = r;
		this.q = q;
	}



	@Override
	public Object call() throws Exception {
		for(int i=0;i<n;i++) {
			Arrays.sort(q[i]);
		}
		int[][] ql = new int[n][m];
		int[][] qr = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				ql[i][j] = divCeil(10 * q[i][j], 11 * r[i]);
				qr[i][j] = (10 * q[i][j]) / (9 * r[i]);
			}
		}
		int ans = 0;
		int[] idx = new int[n];
		for(int k=1;k<=1111112;k++) {
			while(true) {
				for(int i=0;i<n;i++) {
					while (idx[i] < m && qr[i][idx[i]] < k) {
						idx[i]++;
					}
				}
				boolean flag = true;
				for(int i=0;i<n;i++) {
					if (idx[i] < m && ql[i][idx[i]] <= k && k <= qr[i][idx[i]]) {
						
					}else{
						flag = false;
						break;
					}
				}
				if (flag) {
					for(int i=0;i<n;i++) {
						idx[i]++;
					}
					ans++;
				}else{
					break;
				}
			}
		}
		return ans;
	}
	
	public static int divCeil(int a, int b) {
		return (a + b - 1) / b;
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
