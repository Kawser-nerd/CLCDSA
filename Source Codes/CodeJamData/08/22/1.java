import java.io.*;
import java.util.*;

public class NumberFast implements Runnable {
	private final String problemID = getClass().getName() + "_small";
	private BufferedReader in;
	private PrintWriter out;
	private long a, b, p;
	private Random rnd;
	
	private int[] parent;
	private int merges;
	
	private int get(int u) {
		if (u == parent[u]) {
			return u;
		}
		int result = get(parent[u]);
		parent[u] = result;
		return result;
	}
	
	private void merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return;
		}
		merges++;
		if (rnd.nextBoolean()) {
			parent[u] = v;
		} else {
			parent[v] = u;
		}
	}
	
	private void mergeSets(long q) {
		if (q < p) {
			return;
		}
//		System.out.println("merging q = " + q);
		long first = a - (a % q);
		if (first < a) {
			first = first + q;
		}
		long cur = first + q;
		while (cur <= b) {
			merge((int) (first - a), (int) (cur - a));
			cur = cur + q;
		}
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		Scanner sc = new Scanner(in.readLine());
		a = sc.nextLong();
		b = sc.nextLong();
		p = sc.nextLong();
		int length = (int) (b - a + 1);
		
		rnd = new Random(324857285);
		parent = new int[length];
		for (int i = 0; i < parent.length; i++) {
			parent[i] = i;
		}
		
		long[] numbers = new long[length];
		for (int i = 0; i < numbers.length; i++) {
			numbers[i] = a + i;
		}
		
		boolean[] mark = new boolean[(int) Math.sqrt(b) + 5];
		
		merges = 0;
		for (long q = 2; q * q <= b; q++) {
			if (mark[(int) q]) {
				continue;
			}
			long qq = q;
			while (qq < mark.length) {
				mark[(int) qq] = true;
				qq = qq + q;
			}
			
			mergeSets(q);
			long cur = a - (a % q);
			if (cur < a) {
				cur = cur + q;
			}
			while (cur <= b) {
				long num = numbers[(int) (cur - a)];
				while (num % q == 0) {
					num /= q;
				}
				numbers[(int) (cur - a)] = num;
				cur = cur + q;
			}
		}
		
		for (int i = 0; i < numbers.length; i++) {
			if (numbers[i] != 1) {
				mergeSets(numbers[i]);
			}
		}
		out.println("Case #" + testNumber + ": " + (length - merges));
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + ".in")));
		out = new PrintWriter(new File(problemID + ".out"));
		
		int testsNumber = Integer.parseInt(in.readLine());
		for (int testNumber = 1; testNumber <= testsNumber; testNumber++) {
			System.out.println("Running on test " + testNumber);
			solveSingleTest(testNumber);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) {
		new Thread(new NumberFast()).start();
	}

	public void run() {
		try {
			solve();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
