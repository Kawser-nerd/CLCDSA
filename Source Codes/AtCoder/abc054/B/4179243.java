//

import java.util.*;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		int n = sc.nextInt(); int m = sc.nextInt();
		char[][] a = new char[n][n];
		for (int i=0; i<n; i++) a[i] = sc.next().toCharArray();
		char[][] b = new char[m][m];
		for (int i=0; i<m; i++) b[i] = sc.next().toCharArray();
		
		boolean F = false;
		loop: for (int i=0; i<n-m+1; i++) {
			for (int j=0; j<n-m+1; j++) {
				
				boolean temp = true;
				for (int x=0; x<m; x++) {
					for (int y=0; y<m; y++) {
						if (a[i+x][j+y] != b[x][y]) {
							temp = false;
						}
					}
				}
				if (temp == true) {
					F = true;
					break loop;
				}
				
			}
		}
		
		System.out.println(F?"Yes":"No");
		
	}
	
	static void printChar2Array(char[][] c) {
		for (int i=0; i<c.length; i++) {
			for (int j=0; j<c[0].length; j++) {
				System.out.print(c[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
}