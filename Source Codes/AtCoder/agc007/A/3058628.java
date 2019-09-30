import java.util.Scanner;

public class Main{
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt();
		int W = sc.nextInt();
		String[] A = new String[H];
		int[][] a = new int[H][W];
		Boolean N = true;
		for(int i=0;i<H;i++) {
			A[i] = sc.next();
			for(int j=0;j<W;j++) {
				if(A[i].charAt(j) == '#'){
					a[i][j] = 1;
				}else {
					a[i][j] = 0;
				}
			}
		}
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				if(a[i][j] == 1) {
					for(int k=i+1;k<H;k++) {
						for(int l=0;l<j;l++) {
							if(a[k][l] == 1) {
								N = false;
							}
						}
					}
				}
			}
		}
		if(N) {
			System.out.println("Possible");
		}else {
			System.out.println("Impossible");
		}
		
			
		
		
		}
}