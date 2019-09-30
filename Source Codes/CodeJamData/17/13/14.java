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
		Solver<Object> solver = Solver.getInstance("C-small-attempt1.in");
		Scanner sc = solver.getScanner();
		int casenum = sc.nextInt();
		for(int caseid=0;caseid<casenum;caseid++) {
			int hd = sc.nextInt();
			int ad = sc.nextInt();
			int hk = sc.nextInt();
			int ak = sc.nextInt();
			int b = sc.nextInt();
			int d = sc.nextInt();
			Task task = new Task(hd,ad,hk,ak,b,d);
			solver.addTask(task);
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	int hd,ad,hk,ak,b,d;
	
	
	
	public Task(int hd, int ad, int hk, int ak, int b, int d) {
		super();
		this.hd = hd;
		this.ad = ad;
		this.hk = hk;
		this.ak = ak;
		this.b = b;
		this.d = d;
	}

	public static int INF = 1 << 29;
	int[][][][] dp;

	@Override
	public Object call() throws Exception {
		dp = new int[hd+1][hk+1][hk+1][ak+1];
		for(int i=0;i<=hd;i++) {
			for(int j=0;j<=hk;j++) {
				for(int k=0;k<=hk;k++) {
					Arrays.fill(dp[i][j][k], -1);
				}
			}
		}
		int ans = f(hd,hk,ad,ak);
		if (ans >= INF) {
			System.err.println(this);
		}
		return ans >= INF ? "IMPOSSIBLE" : ans;
	}
	
	public int f(int hd,int hk,int ad,int ak) {
		if (hk <= 0) {
			return 0;
		}
		if (hd <= 0) {
			return INF;
		}
		if (dp[hd][hk][ad][ak] >= 0) {
			return dp[hd][hk][ad][ak];
		}
		dp[hd][hk][ad][ak] = -2;
		int min = INF;
		//attack
		min = Math.min(min, f(hd-ak, hk-ad, ad, ak) + 1);
		//buff
		if (b > 0 && ad < hk) {
			min = Math.min(min, f(hd-ak, hk, Math.min(ad+b, hk), ak) + 1);
		}
		//cure
		int hd2 = this.hd - ak;
		if (hd2 > 0) {
			if (dp[hd2][hk][ad][ak] != -2) {
				min = Math.min(min, f(hd2,hk,ad,ak) + 1);
			}
		}
		//debuff
		if (d > 0 && ak > 0) {
			int ak2 = Math.max(0, ak-d);
			min = Math.min(min, f(hd-ak2, hk, ad, ak2) + 1);
		}
		return dp[hd][hk][ad][ak] = min;
	}

	@Override
	public String toString() {
		return "Task [hd=" + hd + ", ad=" + ad + ", hk=" + hk + ", ak=" + ak + ", b=" + b + ", d=" + d + "]";
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
