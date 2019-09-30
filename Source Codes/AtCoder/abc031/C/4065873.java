import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int maxA = Integer.MIN_VALUE;
			int maxT = Integer.MIN_VALUE;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				int a;
				int b;
				if (i < j) {
					a = i;
					b = j;
				} else {
					a = j;
					b = i;
				}
				int taka = 0;
				int ao = 0;
				for (int k = a; k <= b; k++) {
					if ((k - a) % 2 == 0) {
						taka += arr[k];
					} else {
						ao += arr[k];
					}
				}
				if (maxA < ao) {
					maxA = ao;
					maxT = taka;
				}
			}
			if (max < maxT) {
				max = maxT;
			}
		}
		System.out.println(max);
	}
}