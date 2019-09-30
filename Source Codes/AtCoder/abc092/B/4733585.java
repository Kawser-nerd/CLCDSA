import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, D, X, sum;
		N = sc.nextInt();
		D = sc.nextInt();
		X = sc.nextInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}
		for (int i = 0; i < N; i++) {
			for (int k = 0; k <= D; k++) {
				if (k * A[i] + 1 <= D) {
					X++;
				}
			}
		}
		sum = X;
		System.out.println(sum);
		sc.close();
	}

}