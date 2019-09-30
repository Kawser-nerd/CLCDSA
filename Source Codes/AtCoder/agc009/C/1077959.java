import java.util.*;

public class Main {
	static int N;
	static long A, B;
	static long[] S;
	static long[][] dpA;
	static long[][] dpB;
	static BinaryIndexedTree bitA;
	static BinaryIndexedTree bitB;
	static final long MOD = 1_000_000_000 + 7;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		A = sc.nextLong();
		B = sc.nextLong();
		S = new long[N];
		bitA = new BinaryIndexedTree(N);
		bitB = new BinaryIndexedTree(N);
		Stack<Query> stackA = new Stack<>();
		Stack<Query> stackB = new Stack<>();
		for (int i = 0; i < N; ++i) {
			S[i] = sc.nextLong();
		}
		Arrays.sort(S);

		bitA.addVal(0 + 1, 1);
		bitB.addVal(0 + 1, 1);
		stackA.push(new Query(0 + 1, 1));
		stackB.push(new Query(0 + 1, 1));
		int leftA = -1;
		int leftB = -1;
		for (int i = 0; i + 1 < N; ++i) {
			long sA = 0;
			long sB = 0;
			while (S[i + 1] - S[leftA + 1] >= A)
				++leftA;
			while (S[i + 1] - S[leftB + 1] >= B)
				++leftB;
			sB = bitA.getVal((leftB + 1) + 1);
			sA = bitB.getVal((leftA + 1) + 1);
			if (S[i + 1] - S[i] < A) {
				while (!stackA.isEmpty()) {
					Query q = stackA.pop();
					bitA.addVal(q.pos, -q.val);
				}
			}
			if (S[i + 1] - S[i] < B) {
				while (!stackB.isEmpty()) {
					Query q = stackB.pop();
					bitB.addVal(q.pos, -q.val);
				}
			}
			bitA.addVal((i + 1) + 1, sA);
			bitB.addVal((i + 1) + 1, sB);
			stackA.add(new Query((i + 1) + 1, sA));
			stackB.add(new Query((i + 1) + 1, sB));
		}
		System.out.println((bitA.getVal(N) + bitB.getVal(N)) % MOD);
	}

	static class BinaryIndexedTree {
		int n;
		long[] val;

		public BinaryIndexedTree(int n) {
			this.n = n;
			val = new long[n + 1];
		}

		void addVal(int k, long v) {
			while (k <= n) {
				val[k] += v;
				val[k] = (val[k] + MOD) % MOD;
				k += k & -k;
			}
		}

		long getVal(int k) {
			long s = 0;
			while (k > 0) {
				s += val[k];
				s = (s + MOD) % MOD;
				k -= k & -k;
			}
			return s;
		}

		void clear() {
			val = new long[n + 1];
		}
	}

	static class Query {
		int pos;
		long val;

		public Query(int pos, long val) {
			this.pos = pos;
			this.val = val;
		}
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}