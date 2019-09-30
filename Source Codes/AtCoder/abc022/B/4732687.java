import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int n, s;
		s = 0;
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		int a[] = new int[n+1];
		a[1]=sc.nextInt();

		for (int i = 2; i <= n; i++) {

			a[i] = sc.nextInt();
			for (int j = 1; j < i; j++) {
				if (a[j] == a[i]) {
					s=s+1;
					break;
				}
			}
		}
		System.out.println(s);
	}
}