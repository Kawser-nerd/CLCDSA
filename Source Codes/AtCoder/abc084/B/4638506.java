import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		String[] S = sc.next().split("");
		if (S.length != A + B + 1) {
			System.out.println("No");
			return;
		}
		for (int i = 0; i < A; i++) {
			try {
				Integer.parseInt(S[i]);
			} catch (Exception e) {
				System.out.println("No");
				return;
			}
		}
		if (!(S[A].equals("-"))) {
			System.out.println("No");
			return;
		}
		for (int i = A + 1; i < A + B + 1; i++) {
			try {
				Integer.parseInt(S[i]);
			} catch (Exception e) {
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}

}