import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int sum = 0;
		int maxP = 0;
		for (int i = 0; i < n; i++) {
			int p = sc.nextInt();
			sum += p;
			if (p > maxP)
				maxP = p;
		}
		sum -= maxP / 2;
		System.out.println(sum);
		sc.close();
	}
}