import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		int x = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < d) {
				for (int j = 0; j * a[i] + 1 <= d; j++) {
					sum++;
				}
			} else {
				sum++;
			}
		}
		sum += x;
		System.out.println(sum);
		sc.close();
	}

}