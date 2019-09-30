package b;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
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
			String s1 = sc.next();
			String s2 = sc.next();
			Task task = new Task(s1, s2);
			solver.addTask(task);
		}
		solver.finish();
	}

}
class Task implements Callable<Object> {
	String s1,s2;
	public Task(String s1,String s2) {
		this.s1 = s1;
		this.s2 = s2;
	}
	
	@Override
	public Object call() throws Exception {
		int n = s1.length();
		char[] a = s1.toCharArray();
		char[] b = s2.toCharArray();
		Pair[][] dp = new Pair[n+1][21];
		dp[0][10] = new Pair(BigInteger.ZERO, BigInteger.ZERO);
		for(int i=0;i<n;i++) {
			for(int j=0;j<=20;j++) {
				if (dp[i][j] == null) continue;
				for(int d1=0;d1<=9;d1++) {
					if (a[i] != '?' && d1 != a[i] - '0') {
						continue;
					}
					for(int d2=0;d2<=9;d2++) {
						if (b[i] != '?' && d2 != b[i] - '0') {
							continue;
						}
						int nj = (j - 10) * 10 + (d1 - d2) + 10;
						if (nj < 0) nj = 0;
						if (nj > 20) nj = 20;
						Pair next = dp[i][j].next(d1, d2);
						if (dp[i+1][nj] == null || dp[i+1][nj].compareTo(next) > 0) {
							dp[i+1][nj] = next;
						}
					}
				}
			}
		}
		
//		System.out.println(Arrays.toString(dp[n]));
		
		Pair best = null;
		for(int i=0;i<=20;i++) {
			if (dp[n][i] == null) {
				continue;
			}
			if (best == null || best.compareTo(dp[n][i]) > 0) {
				best = dp[n][i];
			}
		}
		
		return putLeadingZero(best.a.toString(), n) + " " + putLeadingZero(best.b.toString(), n);
	}
	
	public static String putLeadingZero(String s,int n) {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<n-s.length();i++) {
			sb.append('0');
		}
		sb.append(s);
		return sb.toString();
	}
}

class Pair implements Comparable<Pair>{
	BigInteger a,b;

	public Pair(BigInteger a, BigInteger b) {
		super();
		this.a = a;
		this.b = b;
	}
	
	public Pair next(int x,int y) {
		return new Pair(a.multiply(BigInteger.TEN).add(BigInteger.valueOf(x)), b.multiply(BigInteger.TEN).add(BigInteger.valueOf(y)));
	}

	@Override
	public int compareTo(Pair o) {
		BigInteger d1 = a.subtract(b).abs();
		BigInteger d2 = o.a.subtract(o.b).abs();
		int cmp = d1.compareTo(d2);
		if (cmp != 0) {
			return cmp;
		}
		cmp = a.compareTo(o.a);
		if (cmp != 0) {
			return cmp;
		}
		return b.compareTo(o.b);
	}

	@Override
	public String toString() {
		return "(" + a + "," + b + ")";
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
