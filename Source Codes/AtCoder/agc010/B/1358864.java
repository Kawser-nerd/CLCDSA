import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Solver solver = new Solver();
		solver.init();
		solver.readHead(in.readLine());
		for (; solver.hasNext();) {
			solver.readBody(in.readLine());
		}
	}
}

class Solver {
	int N;
	int cnt;

	public void init() {
		N = 0;
		cnt = 0;
	}

	public void readHead(String str) {
		String[] strArr = str.split(" ");
		N = Integer.parseInt(strArr[0]);
		// System.out.println(N);
	}

	public boolean hasNext() {
		// return cnt < N;
		return cnt < 1;
	}

	public void readBody(String str) {
		// System.out.println(str);
		cnt++;
		String[] strArr = str.split(" ");
		long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += Long.parseLong(strArr[i]);
		}

		if (sum % ((long) N * ((long) N + 1) / 2) != 0) {
			System.out.println("NO");
			return;
		}
		long k = sum / ((long) N * ((long) N + 1) / 2);

		boolean able = true;
		long edge = 0;
		for (int i = 0; i < N; i++) {
			long d = -Long.parseLong(strArr[i]) - k;
			if (i == N - 1)
				d += Long.parseLong(strArr[0]);
			else
				d += Long.parseLong(strArr[i + 1]);
			// System.out.println(d);
			if (d > 0) {
				able = false;
				break;
			}
			if (d < 0) {
				if (d % N != 0) {
					able = false;
					break;
				}
				edge -= d;
			}
		}
		if (able) {
			// System.out.println(edge);
			able = (edge == N * k);
		}

		if (able)
			System.out.println("YES");
		else
			System.out.println("NO");
	}

}