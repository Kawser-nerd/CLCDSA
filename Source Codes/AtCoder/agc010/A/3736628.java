import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		int cntOdd = 0;

		for (int i = 0; i < N; i++) {
			int num = sc.nextInt();
			if (num % 2 == 1) {
				cntOdd++;
			}
		}

		if (cntOdd % 2==1) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}