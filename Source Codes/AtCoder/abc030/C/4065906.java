import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int[] arrA = new int[n];
		int[] arrB = new int[m];
		for (int i = 0; i < n; i++) {
			arrA[i] = sc.nextInt();
		}
		for (int i = 0; i < m; i++) {
			arrB[i] = sc.nextInt();
		}
		int idxA = 0;
		int idxB = 0;
		int time = 0;
		int count = 0;
		while (true) {
			if (time > arrA[n - 1]) {
				break;
			}
			for (int i = idxA; i < n; i++) {
				if (arrA[i] >= time) {
					time = arrA[i];
					time += x;
					idxA = i +1;
					break;
				}
			}
			if (time > arrB[m - 1]) {
				break;
			}
			for (int i = idxB; i < m; i++) {
				if (arrB[i] >= time) {
					time = arrB[i];
					time += y;
					idxB = i +1;
					break;
				}
			}
			count++;
		}
		System.out.println(count);
	}
}