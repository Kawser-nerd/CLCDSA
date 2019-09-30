import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int T = sc.nextInt();
		int[] c = new int[n];
		int[] t = new int[n];
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			t[i] = sc.nextInt();
		}
		int minCost = 1001;
		for(int i = 0; i < n; i++) {
			if(t[i] <= T && c[i] < minCost) {
				minCost = c[i];
			}
		}
		if(minCost == 1001) {
			System.out.println("TLE");
		} else {
			System.out.println(minCost);
		}
	}
}