import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] m = new int[n];
		for(int i  = 0 ; i < n ; i++) m[i] = sc.nextInt();
		int ans = 0;
		for(int i = 0 ; i < n ; i++) {
			if(m[i] < 80) {
				ans += 80 - m[i];
			}
		}
		System.out.println(ans);
	}
}