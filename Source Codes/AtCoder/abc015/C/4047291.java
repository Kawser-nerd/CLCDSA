import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public boolean solve(int n, int k, int[][] ts) {
		int[] selects = new int[n];
		Arrays.fill(selects, 0);
		
		while (true) {
			int xor = 0;
			for (int i=0; i<n; i++) {
				xor = xor ^ ts[i][selects[i]];
			}
			
			if (xor == 0) {
				return true;
			}
			
			selects[0]++;
			for (int i=0; i<n-1; i++) {
				if (selects[i] >= k) {
					selects[i] = 0;
					selects[i+1]++;
				} else {
					break;
				}
			}
			if (selects[n-1] >= k) {
				break;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k = in.nextInt();
		int ts[][] = new int[n][k];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				ts[i][j] = in.nextInt();
			}
		}
		
		in.close();
		
		Main main = new Main();
		boolean ret = main.solve(n, k, ts);
		
		if (ret) {
			System.out.println("Found");
		} else {
			System.out.println("Nothing");
		}
	}

}