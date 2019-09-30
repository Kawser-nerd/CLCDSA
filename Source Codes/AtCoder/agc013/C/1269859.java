import java.io.*;
import java.util.*;

public class Main {
	
	int[] solve(int[] init, int[] dir, int mod, long time) {
		int n = init.length;
		int[] finalPos = new int[n];
		
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++) {
			order[i] = i;
		}
		
		Arrays.sort(order, (Integer a, Integer b) -> Integer.compare(init[a], init[b]));
		
		int card0 = -1;
		for (int i = 0; i < n; i++) {
			if (order[i] == 0) {
				card0 = i;
			}
		}
		
		for (int i = 0; i < n; i++) {
			finalPos[i] = (int) Math.floorMod(init[i] + time * dir[i], mod);
		}
		
		Arrays.sort(finalPos);
		
		long firstMet = 0;
		
		for (int i = 1; i < n; i++) {
			if (dir[i] != dir[0]) {
				firstMet += count(init[0], dir[0], init[i], dir[i], mod, time);
				firstMet %= n;
			}
		}
		
		int firstCard;
		if (dir[0] == 1) {
			firstCard = (int) (Math.floorMod(card0 + firstMet, n));
		} else {
			firstCard = (int) (Math.floorMod(card0 - firstMet, n));
		}
		
		int posFirst = (int) Math.floorMod(init[0] + time * dir[0], mod);
		
		int idxFirst = -1;
		if (dir[0] == 1) {
			for (int i = n - 1; i >= 0; i--) {
				if (finalPos[i] == posFirst) {
					idxFirst = i;
					break;
				}
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (finalPos[i] == posFirst) {
					idxFirst = i;
					break;
				}
			}
		}
		
		if (idxFirst == -1) {
			throw new AssertionError();
		}
		
		int[] ans = new int[n];
		
		for (int i = 0; i < n; i++) {
			int card = (firstCard + i) % n;
			ans[order[card]] = finalPos[(idxFirst + i) % n];
		}
		
		return ans;
	}
	
	long count(int x0, int d0, int x1, int d1, int mod, long time) {
		if (d0 == -1) {
			int tmp = x0;
			x0 = x1;
			x1 = tmp;
		}
		
		int first = x1 - x0;
		if (first < 0) {
			first += mod;
		}
		
		time = 2 * time - first;
		if (time < 0) {
			return 0;
		}
		
		return time / mod + 1;
	}

	void submit() {
		int n = nextInt();
		int mod = nextInt();
		long time = nextLong();
		
		int[] init = new int[n];
		int[] dir = new int[n];
		
		for (int i = 0; i < n; i++) {
			init[i] = nextInt();
			dir[i] = nextInt() == 1 ? 1 : -1;
		}
		
		int[] ret = solve(init, dir, mod, time);
		for (int x : ret) {
//			out.print(x + " ");
			out.println(x);
		}
		out.println();
	}

	void preCalc() {

	}

	void stress() {

	}

	void test() {

	}

	Main() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		preCalc();
		submit();
		//stress();
		//test();
		out.close();
	}

	static final Random rng = new Random();

	public static void main(String[] args) throws IOException {
		new Main();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}