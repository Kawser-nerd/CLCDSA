import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int h = sc.nextInt();
		int[] arrA = new int[n];
		int[] arrB = new int[n];
		for (int i = 0; i < n; i++) {
			arrA[i] = sc.nextInt();
			arrB[i] = sc.nextInt();
		}
		Arrays.sort(arrA);
		Arrays.sort(arrB);
		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arrB[i] <= arrA[n - 1]) {
				break;
			}
			h -= arrB[i];
			count++;
			if (h <= 0) {
				break;
			}
		}
		if (h > 0) {
			count += h / arrA[n - 1];
			if (h % arrA[n - 1] != 0) {
				count++;
			}
		}
		System.out.println(count);
	}
}