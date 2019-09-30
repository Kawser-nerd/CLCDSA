import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(System.in);

		Main main = new Main();
		// ??
		int l;
		// ??
		int N = 0;

		for(l = 1; l < 11;l++) {
			main.output(false, (int)Math.pow(10,l));
			if(main.input(scan) == 0) {
				break;
			}
		}

		if(l != 11) {
			int nMin = (int)Math.pow(10, l - 1);
			int nMax = (int)Math.pow(10, l) - 1;

			while(nMin != nMax) {
				int n = (nMin + nMax) / 2;
				main.output(false, (n * 10L));
				if(main.input(scan) == 0) {
					nMin = n + 1;
				} else {
					nMax = n;
				}
			}
			N = nMin;
		} else {
			for(l = 0; l < 10;l++) {
				main.output(false, (int)Math.pow(10,l) * 2);
				if(main.input(scan) == 1) {
					N = (int)Math.pow(10,l);
					break;
				}
			}
		}
		main.output(true, N);
	}

	private void output(boolean answerFlag, long n) {
		if(answerFlag) {
			System.out.println("! " + n);
		} else {
			System.out.println("? " + n);
		}
		System.out.flush();
	}

	private int input(Scanner scan) throws Exception {
		String input = scan.next();

		if("Y".equals(input)) {
			return 1;
		} else
		if("N".equals(input)) {
			return 0;
		} else {
			throw new Exception();
		}
	}
}