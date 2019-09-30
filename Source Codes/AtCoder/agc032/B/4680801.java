import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();

		int nC2 = n * (n - 1) / 2;
		System.out.println(nC2 - n / 2);

		int sum = n;
		if (n % 2 == 0) {
			sum++;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i + j != sum) {
					System.out.println(i + " " + j);
				}
			}
		}
	}

}