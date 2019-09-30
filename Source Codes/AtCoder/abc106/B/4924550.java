import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i += 2) {

				for (int j = 1; j <= i; j++) {

					if (i % j == 0) {
						count++;
					}
				}
				if (count == 8) {
					cnt++;
				}
				count = 0;
			}
		System.out.println(cnt);
	}
}