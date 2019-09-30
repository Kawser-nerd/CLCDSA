import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		PriorityQueue<Long> left = new PriorityQueue<>(n);
		long[] center = new long[n];
		PriorityQueue<Long> right = new PriorityQueue<>((l1, l2) -> {
			return l2.compareTo(l1);
		});

		for (int i = 0; i < n; i++) {
			left.add(sc.nextLong());
		}
		for (int i = 0; i < n; i++) {
			center[i] = sc.nextLong();
		}
		for (int i = 0; i < n; i++) {
			right.add(sc.nextLong());
		}

		long[] lmove = new long[n + 1];
		lmove[0] = left.stream().mapToLong(i -> i).sum();
		long[] rmove = new long[n + 1];
		rmove[0] = right.stream().mapToLong(i -> i).sum();

		for (int i = 0; i < n; i++) {
			left.add(center[i]);
			lmove[i + 1] = lmove[i] - left.poll() + center[i];
		}
		for (int i = 0; i < n; i++) {
			right.add(center[n - 1 - i]);
			rmove[i + 1] = rmove[i] - right.poll() + center[n - 1 - i];
		}

		long ans = Long.MIN_VALUE;
		for (int i = 0; i <= n; i++) {
			long temp = lmove[i] - rmove[n - i];
			ans = Math.max(temp, ans);
		}
		System.out.println(ans);
	}
}