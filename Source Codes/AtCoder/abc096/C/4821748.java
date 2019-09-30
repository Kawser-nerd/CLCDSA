import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);

		int H = reader.nextInt();
		int W = reader.nextInt();
		int[][] arr = new int[H][W];
		String ans = "Yes";
		for (int i = 0; i< H; i++) {
			String row = reader.next();
			for (int j = 0; j< W; j++) {
				char ch = row.charAt(j);
				if (ch == '#') {
					arr[i][j] = 1;
				} else {
					arr[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j< W; j++) {
				if (arr[i][j] == 1) {
					boolean flag = false;
					if (i > 0) {
						flag = (arr[i-1][j] == 1) || flag;
					}
					if (i < H - 1) {
						flag = (arr[i+1][j] == 1) || flag;
					}
					if (j > 0) {
						flag = (arr[i][j-1] == 1) || flag;
					}
					if (j < W - 1) {
						flag = (arr[i][j+1] == 1) || flag;
					}
					if (!flag) {
						ans = "No";
					}
				}

			}
		}
		System.out.print(ans);
		reader.close();
	}
}