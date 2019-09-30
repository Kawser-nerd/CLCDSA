import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
	// arc074 D
	private class SumedQueue {
		private int maxSize = 0;
		private long sum = 0;
		private PriorityQueue<Integer> queue = null;
		
		public SumedQueue(int maxSize, boolean isReversed) {
			this.maxSize = maxSize;
			if (isReversed) {
				queue = new PriorityQueue<Integer>(new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						return o2 - o1;
					}
				});
			} else {
				queue = new PriorityQueue<Integer>();
			}
		}
		
		public void add(int n) {
			queue.add(n);
			sum += n;
			if (queue.size() > maxSize) {
				int out = queue.poll();
				sum -= out;
			}
		}
		
		public long total() {
			return sum;
		}
	}
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();

		SumedQueue left = new SumedQueue(N, false);
		SumedQueue right = new SumedQueue(N, true);
		
		int[] middle = new int[N];
		for (int i=0; i<N; i++) {
			left.add(in.nextInt());
		}
		for (int i=0; i<N; i++) {
			middle[i] = in.nextInt();
		}
		for (int i=0; i<N; i++) {
			right.add(in.nextInt());
		}
		in.close();

		// sums[i] : middle[i-1] is left(plus), middle[i] is right(minus)
		long sums[] = new long[N+1];
		sums[0] = left.total();
		for (int i=0; i<N; i++) {
			left.add(middle[i]);
			sums[i+1] = left.total();
		}

		sums[N] -= right.total();
		for (int i=N-1; i>=0; i--) {
			right.add(middle[i]);
			sums[i] -= right.total();
		}

		long max = Long.MIN_VALUE;
		for (int i=0; i<sums.length; i++) {
			if (sums[i] > max) {
				max = sums[i];
			}
		}
		
		System.out.println(max);
	}

	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}