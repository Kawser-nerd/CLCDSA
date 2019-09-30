import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int R = scan.nextInt();
		int C = scan.nextInt();
		int K = scan.nextInt();
		String[][] s = new String[R][C];
		for(int i = 0; i < R;  i++) {
			String t = scan.next();
			String []a = t.split("");
			for(int j = 0; j < C; j++) {
				s[i][j] = a[j];
			}
		}
		scan.close();
		int[][] a = new int[R][C];
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(i == 0) {
					if(s[i][j].equals("o")) {
						a[i][j] = 1;
					}else {
						a[i][j] = 0;
					}
				}else {
					if(s[i][j].equals("o")) {
						a[i][j] += a[i - 1][j] + 1;
					}else {
						a[i][j] = 0;
					}
				}
			}
		}
		int[][] b = new int[R][C];
		for(int i = R - 1; i >= 0; i--) {
			for(int j = 0; j < C; j++) {
				if(i == R - 1) {
					if(s[i][j].equals("o")) {
						b[i][j] = 1;
					}else {
						b[i][j] = 0;
					}
				}else {
					if(s[i][j].equals("o")) {
						b[i][j] += b[i + 1][j] + 1;
					}else {
						b[i][j] = 0;
					}
				}
			}
		}
//		for(int i = 0; i < R; i++) {
//			for(int j = 0; j < C; j++) {
//				System.out.print(a[i][j] + "/" + b[i][j] + " ");
//			}
//			System.out.println();
//		}
		int cnt = 0;
		int flag = 0;
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				flag = 1;
				for(int k = 0; k <= K - 1; k++) {
					if(j - k >= 0 && j + k <= C - 1) {
						if((a[i][j + k] >= K - k && b[i][j + k] >= K - k
								&& a[i][j - k] >= K - k && b[i][j - k] >= K - k)) {
							flag = 0;
						}else {
							flag = 1;
							break;
						}
					}else {
						flag = 1;
						break;
					}
				}
				if(flag == 0) {
					//System.out.println((i + 1)+ " " + (j + 1));
					cnt ++;
				}
			}
		}
		System.out.println(cnt);
	}
}