import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		char[][]c = new char[N][N];
		for(int i = 0; i < N; i++) {
			String s = scan.next();
			for(int j = 0; j < N; j++) {
				c[i][j] = s.charAt(j);
			}
		}
		scan.close();
		for(int i = 0; i < N; i++) {
			for(int j = N - 1; j >= 0; j--) {
				System.out.print(c[j][i]);
			}
			System.out.println();
		}
	}
}