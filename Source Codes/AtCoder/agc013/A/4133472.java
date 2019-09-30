import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int prev = 0;
		int type = 0;
		int count = 1;
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();
			if (i == 0) {
				prev = a;
				continue;
			}
			if (type == -1) {
				if (prev < a) {
					count++;
					type = 0;
				}
			} else if (type == 1) {
				if (prev > a) {
					count++;
					type = 0;
				}
			} else {
				if (prev < a) {
					type = 1;
				} else if (prev > a) {
					type = -1;
				}
			}
			prev = a;
		}
		System.out.println(count);
	}
			
}