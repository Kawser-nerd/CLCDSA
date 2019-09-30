import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int Q = sc.nextInt();
		int[] A = new int[N];
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < N; ++i) {
			A[i] = sc.nextInt();
		}
		for (int trial = 0; trial < N; ++trial) {
			PriorityQueue<PriorityQueue<Integer>> pq = new PriorityQueue<>(new Comparator<PriorityQueue<Integer>>() {
				@Override
				public int compare(PriorityQueue<Integer> o1, PriorityQueue<Integer> o2) {
					return Integer.compare(o1.peek(), o2.peek());
				}
			});
			for (int i = 0; i < N; ++i) {
				int t = i;
				PriorityQueue<Integer> tmp = new PriorityQueue<>();
				while (t < N && A[t] >= A[trial]) {
					tmp.add(A[t]);
					++t;
				}
				if (tmp.size() >= K) {
					pq.add(tmp);
				}
				i = t;
			}
			int cnt = 0;
			int max = 0;
			while (cnt < Q && !pq.isEmpty()) {
				PriorityQueue<Integer> cand = pq.poll();
				++cnt;
				max = Math.max(max, cand.poll());
				if (cand.size() >= K)
					pq.add(cand);
			}
			if (cnt == Q) {
				ans = Math.min(ans, max - A[trial]);
			}
		}
		System.out.println(ans);
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}