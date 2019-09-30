import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		for(int i = 2; i < n; i++) {
			if(arr[i-2]+arr[i-1]+arr[i] < k) {
				System.out.println(i+1);
				return;
			}
		}
		System.out.println(-1);
	}
}