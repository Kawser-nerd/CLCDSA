import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] p = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			p[i] = sc.nextInt();
			sum += p[i];
		}
		Arrays.sort(p);
		sum -= p[n - 1] / 2;
		System.out.println(sum);
		sc.close();
	}
}