import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();

		Scanner sc = new Scanner(System.in);
		main.solve(sc);
		sc.close();
	}

	void solve(Scanner sc) {
		int N = sc.nextInt();
		int[][] xy = new int[N][2];

		for (int i = 0; i < N; i++) {
			xy[i][0] = sc.nextInt();
			xy[i][1] = sc.nextInt();
		}

		double d = 0.0;

		for(int i = 0;i < N;i++) {
			for(int k = i;k < N-1;k++) {
				double x = Math.pow((double)Math.abs(xy[i][0] -  xy[k+1][0]),2);
				double y = Math.pow((double)Math.abs(xy[i][1] -  xy[k+1][1]),2);
				double s = Math.sqrt(x+y);
				if(d < s) {
					d = s;
				}
			}
		}
		System.out.println(d);
		System.out.println();
	}
}