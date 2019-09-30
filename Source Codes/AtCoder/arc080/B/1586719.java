import java.awt.Point;
import java.util.Scanner;

public class Main{
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int [][] ans = new int [n][m];
		int k = sc.nextInt();
		Point x = new Point(0,0);
		boolean flag = true ;
		for(int i = 1 ; i <= k ; i ++) {
			int temp = sc.nextInt();
			for(int j = 0 ; j < temp ; j ++) {
				if(flag) {
				ans[x.x][x.y] = i;
				x.x = x.x+1;
				if(x.x >= n && flag) {
					x.y = x.y+ 1 ;
					x.x = n-1 ;
					flag = false ;
				}
				}
				else {
					ans[x.x][x.y] = i;
					x.x = x.x-1;
					if(x.x < 0 && !flag) {
						x.y = x.y + 1 ;
						x.x = 0 ;
						flag = true ;
					}
				}
			}
		}
		for(int i = 0 ; i < n ; i ++) {
			for(int j = 0 ; j < m ; j ++) {
				System.out.print(ans[i][j] + " ");
			}
		System.out.println();
		}
	}	
}