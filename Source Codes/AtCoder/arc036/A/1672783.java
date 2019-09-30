import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] t = new int[n];
		for(int i = 0 ; i < n ; i++) t[i] = sc.nextInt();
		for(int i = 2 ; i < n ; i++) {
			if(t[i - 2] + t[i - 1] + t[i] < k) {
				System.out.println(i + 1);
				return;
			}
		}
		System.out.println(-1);
	}
}