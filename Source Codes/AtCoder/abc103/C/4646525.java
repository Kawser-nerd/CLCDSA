import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int a[] = new int[N];

		long sum = 0;

		for (int i = 0; i < N; i++) {
			a[i] = sc.nextInt()-1;
			sum += a[i];
		}
		System.out.println(sum);
	}
}