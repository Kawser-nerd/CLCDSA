import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] a = new int[n];

		for (int i = 0; i <= n - 1; i++) {
			a[i] = sc.nextInt();
		}

		sc.close();

		int count = 0;
		Arrays.sort(a);

		for (int j = 0; j <= n - 2; j++) {
			if (a[j] == a[j + 1]) {
				count++;
			}
		}

		if (count % 2 > 0) {
			count++;
		}

		System.out.println(n - count);
	}
}