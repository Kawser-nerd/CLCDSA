import java.util.Scanner;

public class Main {
	static public void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[][] aArray = new int[2][n];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				aArray[i][j] = scan.nextInt();
			}
		}
		scan.close();

		int max = 0;
		for (int i = 0; i < n; i++) {
			int tmpMax = aArray[0][0];
			for (int j = 0; j < i; j++) {
				tmpMax += aArray[0][j + 1];
			}
			for (int j = i; j < n; j++) {
				tmpMax += aArray[1][j];
			}
			if (max < tmpMax) {
				max = tmpMax;
			}
		}

		System.out.println(max);
	}
}