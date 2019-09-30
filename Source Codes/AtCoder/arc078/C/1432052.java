import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) {
		ConsoleScanner cin = new ConsoleScanner();
		PrintWriter cout = new PrintWriter(System.out);
		solve(cin, cout);
		cout.flush();
	}

	private static void solve(ConsoleScanner cin, PrintWriter cout) {
		// example();

		// ???
		// ??????left, right???

		long l = 1;
		Long firstYy = null;
		for (; l <= (long) 1e10; l *= 10) {
			cout.println("? " + l);
			cout.flush();
			String ans = cin.next();
			if ("N".equals(ans))
				break;
			cout.println("? " + (l + 1));
			cout.flush();
			String ans2 = cin.next();
			if ("N".equals(ans2))
				continue;
			if (firstYy == null)
				firstYy = l;
		}
		if (l == (long) 1e11) {
			cout.println("! " + firstYy);
			return;
		}
		long r = l * 10 - 1;
		while (l + 1 != r) {
			long m = (l + r) / 2;
			cout.println("? " + m);
			cout.flush();
			String ans = cin.next();
			switch (ans) {
			case "Y":
				r = m;
				break;
			case "N":
				l = m;
				break;
			default:
				throw new IllegalStateException();
			}
		}
		long N = r / 10;
		cout.println("! " + N);
	}

	static void example() {
		// N????????YYY...NNN
		// N?????????Y
		// N????????NNN...YYY

		// N=50?N=51????
		// ? 500 ~ ? 509????Y/N???
		for (int N : new int[] { 1, 7, 9, 10, 11, 50, 51, 99, 100 }) {
			String strN = Integer.toString(N);
			LinkedHashMap<Integer, Character> map = new LinkedHashMap<>();
			for (int n = 1; n <= 1000; n++) {
				String strn = Integer.toString(n);
				Character ans;
				if (n >= N && strn.compareTo(strN) >= 0)
					ans = 'Y';
				else if (n < N && strn.compareTo(strN) < 0)
					ans = 'Y';
				else
					ans = 'N';
				map.put(n, ans);
			}
			System.out.println(N + " " + map);
		}

	}

	static class ConsoleScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			try {
				while (!st.hasMoreElements())
					st = new StringTokenizer(br.readLine());
				return st.nextToken();
			} catch (IOException e) {
				throw new AssertionError(e);
			}
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

}