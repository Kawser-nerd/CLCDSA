import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double[] arr = new double[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		double total = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 != n % 2) {
				total += arr[i] * arr[i];
			} else {
				total -= arr[i] * arr[i];
			}
		}
		System.out.println(total * Math.PI);
	}
}