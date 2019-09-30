import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		int count = 0;
		for (int i = 0; i < n; i++) {
			 int a = sc.nextInt();
			 if (a % 2 == 0) {
				a--;
				count++;
			}
			if (a % 3 == 2) {
				a -= 2;
				count += 2;
			}
		}
		System.out.print(count);
	}
}