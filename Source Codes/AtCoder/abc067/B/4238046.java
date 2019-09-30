import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();

		int[] l = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = sc.nextInt();
		}

		Arrays.sort(l);

		int sum = 0;
		for (int i = n - 1; i >= n - k; i--) {
			sum += l[i];
		}

		System.out.println(sum);

		sc.close();
	}

}