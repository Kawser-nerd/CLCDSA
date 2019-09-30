import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[1000001];
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[a]++;
			if(b + 1 < arr.length) {
				arr[b + 1]--;
			}
		}
		for (int i = 1; i < arr.length; i++) {
			arr[i] = arr[i] + arr[i - 1];
		}
		Arrays.sort(arr);
		System.out.println(arr[arr.length - 1]);
	}
}