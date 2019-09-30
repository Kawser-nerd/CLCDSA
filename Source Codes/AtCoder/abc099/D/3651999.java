import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int C = sc.nextInt();
		int D[][] = new int[C][C];
		int c[][] = new int[N][N];
		for(int i = 0; i < C; i++) {
			for(int j = 0; j < C; j++) {
				D[i][j] = sc.nextInt();
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				c[i][j] = sc.nextInt() - 1;
			}
		}
		
		int num0[] = new int[C];
		int num1[] = new int[C];
		int num2[] = new int[C];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				switch((i + j) % 3) {
				case 0:
					num0[c[i][j]]++;
					break;
				case 1:
					num1[c[i][j]]++;
					break;
				case 2:
					num2[c[i][j]]++;
					break;
				}
			}
		}
		
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < C; i++) {
			int temp0 = 0;
			for(int color = 0; color < C; color++) {
				temp0 += D[color][i] * num0[color];
			}
			for(int j = 0; j < C; j++) {
				if(j == i) continue;
				int temp1 = 0;
				for(int color = 0; color < C; color++) {
					temp1 += D[color][j] * num1[color];
				}
				for(int k = 0; k < C; k++) {
					if(k == i || k == j) continue;
					int temp2 = 0;
					for(int color = 0; color < C; color++) {
						temp2 += D[color][k] * num2[color];
					}
					ans = Math.min(ans, temp0 + temp1 + temp2);
				}
			}
		}
		System.out.println(ans);
	}
}