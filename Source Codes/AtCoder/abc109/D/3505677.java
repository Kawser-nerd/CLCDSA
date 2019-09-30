import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int H=sc.nextInt();
		int W=sc.nextInt();
		int[][] masu=new int[H][W];
		int[][] buri=new int[H*W][4];
		int b_c=0;

		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				masu[i][j]=sc.nextInt();
			}
		}
		int muki=1;

		for(int i=0; i<H; i++) {
			for(int j=0; j<W-1; j++) {
				if(muki==1) {
					if(masu[i][j]%2==1) {
						masu[i][j+1]++;
						masu[i][j]--;
						buri[b_c][0]=i+1;
						buri[b_c][1]=j+1;
						buri[b_c][2]=i+1;
						buri[b_c][3]=j+2;
						b_c++;
					}
					else {
						//
					}
				}

				else if(muki==-1) {
					if(masu[i][W-1-j]%2==1) {
						masu[i][W-j-2]++;
						masu[i][W-j-1]--;
						buri[b_c][0]=i+1;
						buri[b_c][1]=W-j;
						buri[b_c][2]=i+1;
						buri[b_c][3]=W-j-1;
						b_c++;
					}
					else {
						//
					}
				}
			}
			if(i<H-1 && muki==1) {
				if(masu[i][W-1]%2==1) {
					masu[i][W-1]--;
					masu[i+1][W-1]++;
					buri[b_c][0]=i+1;
					buri[b_c][1]=W;
					buri[b_c][2]=i+2;
					buri[b_c][3]=W;
					b_c++;
				}
				muki*=-1;
			}

			else if(i<H-1 && muki==-1) {
				if(masu[i][0]%2==1) {
					masu[i][0]--;
					masu[i+1][0]++;
					buri[b_c][0]=i+1;
					buri[b_c][1]=1;
					buri[b_c][2]=i+2;
					buri[b_c][3]=1;
					b_c++;
				}
				muki*=-1;
			}
		}
		System.out.println(b_c);
		for(int i=0; i<b_c; i++) {
			System.out.println(buri[i][0]+" "+buri[i][1]+" "+buri[i][2]+" "+buri[i][3]);
		}
	}
}