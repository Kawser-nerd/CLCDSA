import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A, B, C, K, D, E, max = 0, ans;
		A = sc.nextInt();
		B = sc.nextInt();
		D = Math.max(A, B);
		C = sc.nextInt();
		E = Math.max(D, C);
		K = sc.nextInt();
		ans = A + B + C - E;
		ans += E * Math.pow(2.0, (double) K);
		System.out.println(ans);
		sc.close();
	}

}