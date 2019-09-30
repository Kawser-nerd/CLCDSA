import java.io.*;
import java.util.*;

public class MouseTrapFast implements Runnable {
	private final String problemID = getClass().getName() + "_small";
	private BufferedReader in;
	private PrintWriter out;
	
	private int[] tree;
	private int[] answer;
	private int dx = 2097152;
	private int k;
	private int sum(int a, int b) {
		a = a + dx;
		b = b + dx;
		int result = 0;
		while (a <= b) {
			if ((a & 1) == 1) {
				result = result + tree[a];
				a++;
			}
			if ((b & 1) == 0) {
				result = result + tree[b];
				b--;
			}
			a = a >> 1;
			b = b >> 1;
		}
		return result;
	}
	
	private void add(int u, int value) {
		u = u + dx;
		while (u >= 1) {
			tree[u] += value;
			u = u >> 1;
		}
	}
	
	private int find(int start, int steps) {
		int total = sum(0, k - 1);
		steps = steps % total;
		if (steps == 0) {
			steps = total;
		}
		int low = start;
		int hi = 2 * k - 1;
		while (low + 1 < hi) {
			int middle = (low + hi) / 2;
			int value = sum(start, middle);
			if (value < steps) {
				low = middle;
			} else {
				hi = middle;
			}
		}
		return hi;
	}
	
	private void solveSingleTest(int testNumber) throws IOException {
		k = Integer.parseInt(in.readLine());
		Scanner sc = new Scanner(in.readLine());
		int n = sc.nextInt();
		int[] d = new int[n];
		for (int i = 0; i < n; i++) {
			d[i] = sc.nextInt();
		}
		
		for (int i = dx; i < tree.length; i++) {
			tree[i] = 1;
		}
		for (int i = dx - 1; i >= 1; i--) {
			int ii = i << 1;
			tree[i] = tree[ii] + tree[ii + 1];
		}
		
		answer[0] = 1;
		add(0, -1);
		add(k, -1);
		int cur = 0;
		for (int i = 1; i < k; i++) {
//			System.out.println("cur = " + cur);
			int next = find(cur, i + 1);
			if (next >= k) {
				next = next - k;
			}
			answer[next] = i + 1;
			add(next, -1);
			add(next + k, -1);
			cur = next;
		}
		out.print("Case #" + testNumber + ":");
		for (int i = 0; i < n; i++) {
			out.print(" " + answer[d[i] - 1]);
		}
		out.println();
	}

	private void solve() throws IOException {
		in = new BufferedReader(new FileReader(new File(problemID + ".in")));
		out = new PrintWriter(new File(problemID + ".out"));
		
		tree = new int[4194304];
		answer = new int[1000000];
		int testsNumber = Integer.parseInt(in.readLine());
		for (int testNumber = 1; testNumber <= testsNumber; testNumber++) {
			System.out.println("Running on test " + testNumber);
			solveSingleTest(testNumber);
		}
		
		in.close();
		out.close();
	}
	
	public static void main(String[] args) {
		new Thread(new MouseTrapFast()).start();
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
