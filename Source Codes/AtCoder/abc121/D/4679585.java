import java.util.Scanner;

public class Main{

	public static void main (String[] args) {

		Main main = new Main ();
		main.solve();
	}

	private void solve(){

		Scanner scanner = new Scanner (System.in);

		long A = scanner.nextLong();
		long B = scanner.nextLong();
		long answer = 0;
		long C = 0;

		if (A%2==0) {

			if (B%2==0) {

				C=(B-A)/2;

				if (C%2==0) {
					answer = B;
				} else {
					answer = B^1;
				}

			} else {

				C=(B-A)/2;

				if (C%2==0) {
					answer = 1;
				} else {
					answer = 0;
				}
			}

		} else {

			if (B%2==0) {

				C = (B-A-1)/2;

				if (C%2==0) {
					answer = A^B;
				} else {
					answer = A^B^1;
				}
			} else {

				C = (B-A)/2;

				if (C%2==0) {
					answer = A;
				} else {
					answer = A^1;
				}
			}

		}

		System.out.println(answer);
	}
}