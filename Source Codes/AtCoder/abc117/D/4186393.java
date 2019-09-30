import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		long K = in.nextLong();
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = in.nextLong();
		}

		long X = 0;
		for (int i = 39; i >= 0; i--) {
			int count = 0;
			for (long l : A) {
				count += (1 & (l >> i));
			}
			if (count <= N / 2) {
				long temp = X | 1L << i;
				if (temp <= K) {
					X = temp;
				}
			}
		}

		long sum = 0;
		for (long l : A) {
			sum += (X ^ l);
		}
		System.out.println(sum);
	}
}