import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int r = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		char[][] s = new char[r][c];
		int[][] a = new int[r][c];
		int[][] b = new int[r][c];
		for(int i = 0 ; i < r ; i++) s[i] = sc.next().toCharArray();
		for(int i = 0 ; i < r ; i++) {
			for(int j = 0 ; j < c ; j++) {
				int cnt1 = 0;
				int cnt2 = 0;
				if(s[i][j] == 'x') continue;
				for(int k = 0 ; k < r ; k++) {
					if(0 <= i - k && i - k < r && s[i - k][j] == 'o') cnt1++;
					else break;
				}
				for(int k = 0 ; k < r ; k++) {
					if(0 <= i + k && i + k < r && s[i + k][j] == 'o') cnt2++;
					else break;
				}
				a[i][j] = cnt1;
				b[i][j] = cnt2;
			}
		}
//		for(int i = 0 ; i < r ; i++) {
//			for(int j = 0 ; j < c ; j++) {
//				System.out.print(a[i][j]);
//			}
//			System.out.println();
//		}
//
//		System.out.println();
//		for(int i = 0 ; i < r ; i++) {
//			for(int j = 0 ; j < c ; j++) {
//				System.out.print(b[i][j]);
//			}
//			System.out.println();
//		}
		int ans = 0;
		for(int i = 0 ; i < r ; i++) {
			for(int j = 0 ; j < c ; j++) {
				if(s[i][j] == 'x') continue;
				boolean ok = true;
				for(int k = 0 ; k < x ; k++) {
					if(!(0 <= j - k && j - k < c && a[i][j - k] >= x - k)) {
						ok = false;
						break;
					}
					if(!(0 <= j + k && j + k < c && a[i][j + k] >= x - k)) {
						ok = false;
						break;
					}
					if(!(0 <= j - k && j - k < c && b[i][j - k] >= x - k)) {
						ok = false;
						break;
					}
					if(!(0 <= j + k && j + k < c && b[i][j + k] >= x - k)) {
						ok = false;
						break;
					}
				}
				if(ok) ans++;
			}
		}
		System.out.println(ans);
	}
}