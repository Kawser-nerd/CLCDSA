import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	static public class FenwickTree {
		int N;
		int[] t;

		public FenwickTree(final int N) {
			t = new int[N + 1];
			this.N = N;
		};

		public void add(int i, final int v) {
			if (i > N)
				return;
			i = Math.max(i, 1);
			for (int j = i; j <= t.length; j += j & -j)
				t[j - 1] += v;
		}

		public int cumsum(int i) {
			int s = 0;
			for (int j = i; 0 < j; j -= j & -j)
				s += t[j - 1];
			return s;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.valueOf(sc.next());
		int M = Integer.valueOf(sc.next());

		FenwickTree cumSum = new FenwickTree(M);
		FenwickTree indCountSum = new FenwickTree(M);
		int[] numByLength = new int[M + 1];
		Map<Integer, ArrayList<Integer>> startIndexListByLen = new HashMap<Integer, ArrayList<Integer>>();

		for (int i = 1; i <= N; i++) {
			int l = Integer.valueOf(sc.next());
			int r = Integer.valueOf(sc.next());
			int length = r - l + 1;
			cumSum.add(length, 1);
			numByLength[length] += 1;
			if (!startIndexListByLen.containsKey(length))
				startIndexListByLen.put(length, new ArrayList<Integer>());
			List<Integer> list = startIndexListByLen.get(length);
			list.add(l);
		}

		sc.close();

		for (int length = 1; length <= M; length++) {
			int smallerLength = length - 1;
			if (startIndexListByLen.containsKey(smallerLength)) {
				List<Integer> list = startIndexListByLen.get(smallerLength);
				for (int x : list) {
					indCountSum.add(x, 1);
					indCountSum.add(x + smallerLength, -1);
				}
			}
			
			int s1 = 0;
			for (int k = 0; k <= M; k += (length))
				s1 += indCountSum.cumsum(k);
			int s2 = cumSum.cumsum(M) - cumSum.cumsum(length - 1);
			System.out.println(s1 + s2);
		}
	}
}