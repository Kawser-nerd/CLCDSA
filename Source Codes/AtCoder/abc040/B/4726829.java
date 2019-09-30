import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int base = getMaxSqueaBase(A);
		int min = A - (int) Math.pow(base, 2);

		if (min > 0) {
			for (int i = base; i > 0; i--) {
				int remain = A - (int) Math.pow(i, 2);
				int tmp = 0;
				while (i <= remain) {
					remain -= i;
					tmp++;
				}
				if (remain + tmp < min) {
					min = remain + tmp;
				}
			}
		}

		System.out.println(min);
		reader.close();
	}
	public static int getMaxSqueaBase(int num) {
		int base = 1;
		while (Math.pow((base + 1), 2) <= num) {
			base++;
		}
		return base;
	}
}