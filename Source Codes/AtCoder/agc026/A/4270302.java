import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int ans = 0;
		int[] ar = new int[n];
		for (int i=0; i<n; i++) ar[i] = sc.nextInt();
		
		int color = 10000;
		for (int i=1; i<n; i++) {
			if (ar[i] == ar[i-1]) {
				ans++;
				ar[i] = color;
				color--;
			}
		}
		
		System.out.println(ans);
		
	}
}