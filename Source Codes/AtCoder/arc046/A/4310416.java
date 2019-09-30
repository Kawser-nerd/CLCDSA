import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int idx = 1;
		int count = 0;
		while (true) {
			int x = idx;
			int prev = x % 10;
			boolean flag = true;
			while (x > 0) {
				if (prev != x % 10) {
					flag = false;
					break;
				}
				x /= 10;
			}
			if (flag) {
				count++;
				if (count == n) {
					System.out.println(idx);
					return;
				}
			}
			idx++;
		}
	}
}