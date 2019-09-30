import java.util.*;

public class Main {
	int N;
	int[] C;
	Map<Integer, List<Integer>> indexes;
	static final long MOD = 1000000007;
	long result;
	long[] memo;

	long add(long a, long b) {
		return (a + b) % MOD;
	}

	Main() {
		Scanner in = new Scanner(System.in);
		N = Integer.parseInt(in.nextLine());
		C = new int[N];
		int cMax = -1;
		for (int i = 0; i < N; ++i) {
			C[i] = Integer.parseInt(in.nextLine());
			cMax = Math.max(cMax, C[i]);
		}
		in.close();
		this.memo = new long[cMax + 1];
		Arrays.fill(this.memo, 0);
		this.memo[C[0]] = 1;

		for (int i = 1; i < N; ++i) {
			if (C[i - 1] != C[i]) {
				this.memo[C[i]] = this.add(this.memo[C[i]], this.memo[C[i - 1]]);
			}
		}
		this.result = this.memo[C[C.length - 1]];
	}

	public static void main(String[] args) {
		Main ins = new Main();
		System.out.println(ins.result);
	}
}