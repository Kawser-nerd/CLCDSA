import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		int a = N / 1000;
		int b = N % 1000 / 100;
		int c = N % 100 / 10;
		int d = N % 10;
		String ans = "";

		for (int i = 0; i < 2; i++) {
			int sum = a;
			String tmp = "" + a;

			if (i == 0) {
				sum += b;
				tmp += "+" + b;
			} else {
				sum -= b;
				tmp += "-" + b;
			}
			for (int j = 0; j < 2; j++) {
				String tmp2 = tmp;
				int sum2 = sum;
				if (j == 0) {
					sum2 += c;
					tmp2 += "+" + c;
				} else {
					sum2 -= c;
					tmp2 += "-" + c;
				}
				for (int k = 0; k < 2; k++) {
					String tmp3 = tmp2;
					int sum3 = sum2;
					if (k == 0) {
						sum3 += d;
						tmp3 += "+" + d;
					} else {
						sum3 -= d;
						tmp3 += "-" + d;
					}
					if (sum3 == 7) {
						ans = tmp3 + "=7";
						break;
					}
				}
			}
		}

		System.out.println(ans);
		reader.close();
	}
}