import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int s[][]=new int[n][m];
		for(int i=0;i<n;i++) {
			String c=sc.next();
			for(int j=0;j<m;j++)
				if(c.substring(j,j+1).equals("#"))s[i][j]=-1;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(s[i][j]==-1) {
					for(int y=i-1;y<=i+1;y++) {
						for(int x=j-1;x<=j+1;x++) {
							if(y>=0&&y<n&&x>=0&&x<m) {
								if(s[y][x]>-1)s[y][x]++;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				System.out.print(s[i][j]<0?"#":s[i][j]);
			}
			System.out.println();
		}
	}
}