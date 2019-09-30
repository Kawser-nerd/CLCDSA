import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] a = new int[n][m];
		int[][] ret = new int[n][m];
		for (int i = 0;i < n;i++) {
			String s = sc.next();
			for (int j = 0;j < m;j++) {
				a[i][j] = Integer.valueOf(s.substring(j,j+1));
			}
		}

		for (int i = 1;i < n-1;i++) {
			for (int j = 1;j < m-1;j++) {
				int min = 10;
				min = Math.min(min,a[i-1][j]);
				min = Math.min(min,a[i][j-1]);
				min = Math.min(min,a[i+1][j]);
				min = Math.min(min,a[i][j+1]);
				a[i-1][j] -= min;
				a[i][j-1] -= min;
				a[i+1][j] -= min;
				a[i][j+1] -= min;
				ret[i][j] = min;
			}
		}

		for (int i = 0;i < n;i++) {
			for (int j = 0;j < m;j++) {
				System.out.print(ret[i][j]);
			}
			System.out.println("");
		}
	}
}