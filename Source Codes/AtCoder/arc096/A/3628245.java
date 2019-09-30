import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		int X = sc.nextInt();
		int Y = sc.nextInt();

		int prc = 0;
		if (X <= Y) {
			prc = C * 2 * X;
			prc += B * (Y - X);
		} else {
			prc = C * 2 * Y;
			prc += A * (X - Y);
		}

		int nrm = 0;
		nrm = A * X + B * Y;

		int onc = 0;
		if(X <= Y) {
			onc = C * 2 * Y;
		} else {
			onc = C * 2 * X;
		}

		int min = Integer.MAX_VALUE;

		if (prc<=nrm) {
			if(prc <= onc) {
				min = prc;
			} else {
				min = onc;
			}
		} else {
			if(nrm <= onc) {
				min = nrm;
			} else {
				min = onc;
			}
		}
		System.out.println(min);
	}
}