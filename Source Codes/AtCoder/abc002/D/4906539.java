import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		boolean[][] con = new boolean[N][N];
		for(int i = 0; i < M; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			con[x][y] = con[y][x] = true;
		}

		int answer = 0;
		label: for(int i = 0; i < (1 << N); i++) {
			int count = Integer.bitCount(i);
			if(answer >= count)
				continue;

			for(int j = 0; j < N; j++) {
				for(int n = j + 1; n < N; n++){
					if((((i >> j) & 1) == 1 && ((i >> n) & 1) == 1 && !con[j][n]))
						continue label;
				}
			}

			answer = count;
		}

		System.out.println(answer);
	}

}