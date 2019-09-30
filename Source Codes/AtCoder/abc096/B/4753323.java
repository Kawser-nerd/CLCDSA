import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A, B, C, K, D, E, max = 0, max1;
		A = sc.nextInt();
		B = sc.nextInt();
		D = Math.max(A, B);
		C = sc.nextInt();
		E = Math.max(D, C);
		K = sc.nextInt();
		for (int i = 0; i < K; i++) {
			max = E * 2;
		}
		max1 = A + B + C - E;
		max1 += E * Math.pow(2.0, (double) K);
		System.out.println(max1);
		sc.close();
	}

}