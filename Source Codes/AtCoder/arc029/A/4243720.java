import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[4]; 
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int min = Integer.MAX_VALUE;
		for (int i = 0; i < 16; i++) {
			int[] val = new int[2];
			for (int j = 0; j < n; j++) {
				val[(i >> j) % 2] += arr[j];
			}
			int v = Math.max(val[0], val[1]);
			if (min > v) {
				min = v;
			}
		}
		System.out.println(min);
	}
}