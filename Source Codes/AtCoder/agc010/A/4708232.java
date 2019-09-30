import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int oddcount = 0;
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			if (a[i] % 2 == 1) {
				oddcount++;
			}
		}
		if (oddcount % 2 == 0) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}