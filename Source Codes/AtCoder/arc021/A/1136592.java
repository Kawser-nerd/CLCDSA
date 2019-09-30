import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int[][] a = new int[4][4];
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 4;j++) {
				a[i][j] = sc.nextInt();
			}
		}
		boolean b = false;
		for (int i = 0;i < 4;i++) {
			for (int j = 0;j < 4;j++) {
				if (i!=3&&a[i][j]==a[i+1][j]) b = true;
				if (j!=3&&a[i][j]==a[i][j+1]) b = true;
			}
		}

		if (b) {
			System.out.println("CONTINUE");
		} else {
			System.out.println("GAMEOVER");
		}
	}
}