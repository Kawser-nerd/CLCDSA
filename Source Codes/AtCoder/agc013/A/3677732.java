import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A[] = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}

		int part = 0;
		int P = 0;
		int E = 0;

		while (P < N) {
			if (P == N-1) {
				part++;
				break;
			}

			E = P + 1;

			while(E < N && A[E-1] == A[E]) {
				E++;
			}

			if (A[P] <= A[E]) {
				while(E < N && A[E-1] <= A[E]) {
					E++;
				}
				part++;
			} else {
				while(E < N && A[E-1] >= A[E]) {
					E++;
				}
				part++;
			}
			P = E;
		}
		System.out.println(part);
	}
}