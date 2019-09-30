import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String maxS = "";
		int max = 0;
		int total = 0;
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			int p = sc.nextInt();
			total += p;
			if (max < p) {
				max = p;
				maxS = s;
			}
		}
		if (max > (total) / 2) {
			System.out.println(maxS);
		} else {
			System.out.println("atcoder");
		}
	}
}