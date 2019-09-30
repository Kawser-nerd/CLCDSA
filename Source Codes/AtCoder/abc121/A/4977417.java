import java.util.Scanner;
public class Main {
@SuppressWarnings("resource")
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int max=0;
	int count=0;
	int H=sc.nextInt();
	int W=sc.nextInt();
	int masu[][]=new int[H][W];
	int h=sc.nextInt();
	int w=sc.nextInt();
	for(int i=0;i<h;i++) {
		while(max<W) {
		masu[i][max]=1;
		max++;
		}
		max=0;
	}
	for(int i=0;i<w;i++) {
		while(max<H) {
			masu[max][i]=1;
			max++;
		}
		max=0;
	}
	for(int j=0;j<H;j++) {
		for(int i=0;i<W;i++) {
			if(masu[j][i]==0) {
				count++;
			}

		}

	}
	System.out.println(count);
}
}