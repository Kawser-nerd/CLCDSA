import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int Z = sc.nextInt();
		int S = X + Y + Z;
		int[] A = new int[S];
		int[] B = new int[S];
		int[][] lis = new int[S][2];
		long ADD = 0;
		for (int i = 0; i < S; ++i) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			int C = sc.nextInt();
			ADD += C;
			A[i] -= C;
			B[i] -= C;
			lis[i] = new int[] { A[i] - B[i], i, A[i], B[i] };
		}
		Arrays.sort(lis, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return -Integer.compare(o1[0], o2[0]);
			}
		});
		for (int i = 0; i < S; ++i) {
			A[i] = lis[i][2];
			B[i] = lis[i][3];
		}
		long[] cum1 = new long[S];
		long[] cum2 = new long[S];
		Arrays.fill(cum1, -Long.MAX_VALUE / 10);
		Arrays.fill(cum2, -Long.MAX_VALUE / 10);
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		long cur = 0;
		for (int i = 0; i < S; ++i) {
			pq.add(A[i]);
			cur += A[i];
			while (pq.size() > X) {
				cur -= pq.peek();
				pq.poll();
			}
			if (pq.size() == X) {
				cum1[i] = Math.max(cum1[i], cur);
			}
		}
		pq.clear();
		cur = 0;
		for (int i = S - 1; i >= 0; --i) {
			pq.add(B[i]);
			cur += B[i];
			while (pq.size() > Y) {
				cur -= pq.peek();
				pq.poll();
			}
			if (pq.size() == Y) {
				cum2[i] = Math.max(cum2[i], cur);
			}
		}
		long ans = -Long.MAX_VALUE / 10;
		for (int i = 0; i + 1 < S; ++i) {
			ans = Math.max(ans, cum1[i] + cum2[i + 1] + ADD);
		}
		System.out.println(ans);
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}
}