import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] a = new int[3];
		int max = 0;
		int mai = 0;
		for (int i = 0; i < 3; i++) {
			a[i] = sc.nextInt();
			if (max < a[i]) {
				max = a[i];
				mai = i;
			}
		}
		int k = sc.nextInt();
		int sum = 0;
		for (int i = 0; i < k; i++) {
			max = max * 2;
		}
		sum = max;
		for (int i = 0; i < 3; i++) {
			if (i != mai) {
				sum += a[i];
			}
		}
		System.out.println(sum);
		sc.close();
	}

}