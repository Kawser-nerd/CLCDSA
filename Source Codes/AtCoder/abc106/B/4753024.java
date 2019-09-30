import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, cnt = 0, sum = 0;
		N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			if (i % 2 != 0) {
				cnt = 0;
				for (int k = 1; k <= N; k++) {
					if (i % k == 0) {
						cnt++;
					}

				}
				if (cnt == 8) {
					sum++;
				}
			}
		}
		System.out.println(sum);
		sc.close();
	}

}