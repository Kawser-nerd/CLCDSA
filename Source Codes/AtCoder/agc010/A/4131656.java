import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		int odd = 0;
		for (int i=0; i<N; i++) {
			int ai = sc.nextInt();
			if (ai % 2 != 0) odd++;
		}
		if (odd % 2 != 0) {
			System.out.println("NO");
		}
		else {
			System.out.println("YES");
		}

	}

}