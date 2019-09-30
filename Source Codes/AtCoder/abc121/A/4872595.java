import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);

		int H=sc.nextInt();
		int W=sc.nextInt();

		int h=sc.nextInt();
		int w=sc.nextInt();

		int[][] matrix=new int[H][W];

		for(int i=0;i<H;i++) for(int j=0;j<W;j++) matrix[i][j]=0;

		for(int i=0;i<h;i++) {
			for(int j=0;j<W;j++) matrix[i][j]=1;
		}

		for(int i=0;i<H;i++) {
			for(int j=0;j<w;j++) matrix[i][j]=1;
		}

		int count=0;

		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				if(matrix[i][j]==0) count++;
			}
		}

		System.out.println(count);

		sc.close();

	}

}