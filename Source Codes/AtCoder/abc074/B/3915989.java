import java.util.*;

public class Main {

	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int total = 0;
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			total += Math.min(Math.abs(x - 0), Math.abs(x - k)) * 2;
		}
		System.out.println(total);
	}
}