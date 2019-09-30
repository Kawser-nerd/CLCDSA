import java.util.Scanner;

class Main{
	public static int[][] sima=new int[12][12];
	public static int[][] test=new int[12][12];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);



		String unko="";
		for(int i=1; i<=10; i++) {
			unko=sc.next();
			for(int j=1; j<=10; j++) {
				if(unko.charAt(j-1)=='o') {
					sima[i][j]=1;
				}
				else if(unko.charAt(j-1)=='x') {
					sima[i][j]=0;
				}
			}
		}

		for(int i=0; i<12; i++) {
			for(int j=0; j<12; j++) {
				if(i==0 || i==11) {
					if(j==0 || j==11) {
						sima[i][j]=0;
						test[i][j]=0;
					}
				}
			}
		}


		boolean rinsetu=false;
		int sima_cnt=0;
		for(int i=1; i<=10; i++) {
			for(int j=1; j<=10; j++) {
				sima_cnt=0;
				for(int ii=0; ii<12; ii++) {
					for(int jj=0; jj<12; jj++) {
						test[ii][jj]=sima[ii][jj];
					}
				}
				test[i][j]=1;

				sima_cnt=0;
				for(int ii=1; ii<=10; ii++) {
					for(int jj=1; jj<=10; jj++) {
						if(test[ii][jj]==1) {
							sima_cnt++;
							D_F_S(ii,jj);
						}
					}
				}
				if(sima_cnt==1) {
					System.out.println("YES");
					System.exit(0);
				}
			}
		}
		System.out.println("NO");
		System.exit(0);

	}

	static void D_F_S(int x,int y) {
		test[x][y]=0;		//????
		for(int dx=-1; dx<=1; dx++) {
			for(int dy=-1; dy<=1; dy++) {
				if((Math.abs(dx)+Math.abs(dy))==1) {
					int nx=x+dx;
					int ny=y+dy;
					if(1<=nx && nx<11 && 1<=ny && ny<11 && test[nx][ny]==1) {
						D_F_S(nx,ny);
					}
				}
			}
		}
	}
}