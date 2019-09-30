import java.util.Arrays;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int R = scan.nextInt();
		int C = scan.nextInt();
		int K = scan.nextInt();
		int N = scan.nextInt();

		int [][]p = new int[N][2];
		int []row = new int[R + 1];
		int []col = new int[C + 1];
		Arrays.fill(row, 0);
		Arrays.fill(col, 0);
		for(int i = 0; i < N; i++) {
			int r = scan.nextInt();
			int c = scan.nextInt();
			p[i][0] = r;
			p[i][1] = c;
			row[r] ++;
			col[c]++;
		}
		scan.close();
		int []row1 = new int[100000 + 1];
		int []col1 = new int[100000 + 1];

		Arrays.fill(row1, 0);
		Arrays.fill(col1, 0);
		for(int i = 1; i <= R; i++) {
			row1[row[i]]++;
		}
		for(int i = 1; i <= C; i++) {
			col1[col[i]]++;
		}
		long cnt = 0;
		for(int i = 0; i <= K; i++) {
			cnt += row1[i] * col1[K - i];
		}
		for(int i = 0; i < N; i++) {
			if(row[p[i][0]] + col[p[i][1]] == K) {
				cnt --;
			}else if(row[p[i][0]] + col[p[i][1]] == K + 1) {
				cnt ++;
			}
		}
		System.out.println(cnt);

	}
}