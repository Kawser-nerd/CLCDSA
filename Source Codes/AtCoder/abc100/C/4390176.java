import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int ans = 0;
		for (int i=0; i<n; i++) {
			int temp = sc.nextInt();
			while (temp%2 == 0) {
				temp /= 2;
				ans++;
			}
		}
		
		System.out.println(ans);
		
	}
}