import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long A[] = new long[3 * N];
		for (int i = 0; i < 3 * N; i++) {
			A[i] = sc.nextLong();
		}
		long ans = -Long.MAX_VALUE;

		PriorityQueue<Long> quefront = new PriorityQueue<Long>(N + 1);
		PriorityQueue<Long> queback = new PriorityQueue<Long>(N + 1, new MyComparator());
		long front[] = new long[N];
		long back[] = new long[N];
		System.arraycopy(A, 0, front, 0, N);
		System.arraycopy(A, 2 * N, back, 0, N);
		long sumfront = 0;
		long sumback = 0;
		long tmp[][] = new long[N + 1][2];
		for (int i = 0; i < N; i++) {
			quefront.add(front[i]);
			queback.add(back[i]);
			sumfront += front[i];
			sumback += back[i];
		}
		tmp[0][0] = sumfront;
		tmp[N][1] = sumback;
		for (int i = N; i < 2 * N; i++) {
			sumfront += A[i];
			quefront.add(A[i]);
			sumfront -= (long) quefront.poll();
			tmp[i - N + 1][0] = sumfront;
		}
		for (int i = 2 * N - 1; i >= N; i--) {
			sumback += A[i];
			queback.add(A[i]);
			sumback -= (long) queback.poll();
			tmp[i - N][1] = sumback;
		}
		for (int i = 0; i < N + 1; i++) {
			ans = Math.max(ans, tmp[i][0] - tmp[i][1]);
		}
		System.out.println(ans);
	}
}

class MyComparator implements Comparator<Object> {

	public int compare(Object obj1, Object obj2) {

		long num1 = (long) obj1;
		long num2 = (long) obj2;

		if (num1 > num2) {
			return -1;
		} else if (num1 < num2) {
			return 1;
		} else {
			return 0;
		}
	}
}