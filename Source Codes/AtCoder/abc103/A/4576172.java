import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int A = reader.nextInt();
		int B = reader.nextInt();
		int C = reader.nextInt();
		int[] gaps = new int[6];

		gaps[0] = Math.abs(A - B) + Math.abs(B - C);
		gaps[1] = Math.abs(A - C) + Math.abs(C - B);
		gaps[2] = Math.abs(B - A) + Math.abs(A - C);
		gaps[3] = Math.abs(B - C) + Math.abs(C - A);
		gaps[4] = Math.abs(C - A) + Math.abs(A - B);
		gaps[5] = Math.abs(C - B) + Math.abs(B - A);

		int min = gaps[0];
		for (int i = 1; i < 6; i++) {
			if (gaps[i] < min) {
				min = gaps[i];
			}
		}

		reader.close();
		System.out.print(min);
	}
}