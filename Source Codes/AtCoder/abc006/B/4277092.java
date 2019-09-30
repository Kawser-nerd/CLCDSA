import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];

		if (n == 1 || n == 2) {
			System.out.println(0);
			return;
		} else if (n==3) {
			System.out.println(1);
			return;
		}
		a[0] = 0;
		a[1] = 0;
		a[2] = 1;
		for (int i = 3; i < n; i++) {
			a[i] = a[i-1] + a[i-2] + a[i-3];
			a[i] %= 10007;
		}
		System.out.println(a[n-1]);
	}
}