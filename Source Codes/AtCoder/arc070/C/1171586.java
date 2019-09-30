import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] l = new long[N];
		long[] r = new long[N];
		long[] len = new long[N];
		long ans = 0;
		for (int i = 0; i < N; ++i) {
			l[i] = sc.nextLong() - 1;
			r[i] = sc.nextLong() - 1;
			len[i] = r[i] - l[i];
		}

		PriorityQueue<Long> pqL = new PriorityQueue<>(new Comparator<Long>() {
			@Override
			public int compare(Long o1, Long o2) {
				return -Long.compare(o1, o2);
			}
		});
		PriorityQueue<Long> pqR = new PriorityQueue<>();

		long slideR = 0, slideL = 0;
		pqL.add(l[0]);
		pqR.add(l[0]);
		for (int i = 1; i < N; ++i) {
			slideL -= len[i];
			slideR += len[i - 1];
			long L = pqL.peek() + slideL;
			long R = pqR.peek() + slideR;
			if (L <= l[i] && l[i] <= R) {
				pqL.add(l[i] - slideL);
				pqR.add(l[i] - slideR);
			} else {
				if (l[i] < L) {
					pqL.poll();
					pqL.add(l[i] - slideL);
					pqL.add(l[i] - slideL);
					pqR.add(L - slideR);
					L = pqL.peek() + slideL;
					R = pqR.peek() + slideR;
					ans += (R - l[i]);
				} else {
					pqR.poll();
					pqR.add(l[i] - slideR);
					pqR.add(l[i] - slideR);
					pqL.add(R - slideL);
					L = pqL.peek() + slideL;
					R = pqR.peek() + slideR;
					ans += (l[i] - L);
				}
			}
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}