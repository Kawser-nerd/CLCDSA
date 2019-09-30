import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N + 1];
		long[] B = new long[N + 1];
		for(int i = 0; i < N; i++) {
			A[i + 1] = sc.nextLong();
			B[i + 1] = sc.nextLong();
		}
		sc.close();
		long cnt = 0;
		for(int i = N; i >= 1; i--) {
			long r = A[i] % B[i];
			if(r != 0) {
				cnt += B[i] - r;
			}
			A[i - 1] += cnt;
		}
		System.out.println(cnt);
	}
}