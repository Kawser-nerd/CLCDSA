import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	static int[][][][] dp;
	static int N;
	static Map<Integer,Integer>map;
	static int[][] zipmap;
	static int[][] sumx;
	static int[][] sumy;
	static int[] X;
	static int[] Y;

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int W = scan.nextInt();
		int H = scan.nextInt();
		N = scan.nextInt();

		dp = new int[2*N+1][2*N+1][2*N+1][2*N+1];
		X=new int[N];
		Y=new int[N];

		Map<Integer,Integer> ymap = new HashMap<Integer,Integer>();
		Map<Integer,Integer> xmap = new HashMap<Integer,Integer>();
		map = new HashMap<Integer,Integer>();
		zipmap = new int[2*N+1][2*N+1];
		sumx = new int[2*N+1][2*N+1];//sumx[x][y]=zipmap[x][0]+...+zipmap[x][y]
		sumy = new int[2*N+1][2*N+1];//sumy[x][y]=zipmap[0][y]+...+zipmap[x][y]
		int[] xzip = new int[2*N+1];
		int[] yzip = new int[2*N+1];

		for(int i=0;i<N;i++){
			int x = scan.nextInt();
			int y = scan.nextInt();
			X[i]=x;
			Y[i]=y;
			ymap.put(y, x);
		}
		Arrays.sort(X);Arrays.sort(Y);
		int before =0;
		int cnt=0;
		for(int i_=0;i_<N;i_++){//int i=1;i<=H;i++){
			int i=Y[i_];
			if(ymap.containsKey(i)){
				int zip = i-before-1;
				yzip[2*cnt]=zip;
				yzip[2*cnt+1]=1;
				xmap.put(ymap.get(i), 2*cnt+1);
				cnt++;
				before = i;
			}
		}
		int zip_ = H-before;
		yzip[2*cnt]=zip_;

		before=0;
		cnt=0;
		for(int i_=0;i_<N;i_++){//1;i<=W;i++){
			int i=X[i_];
			if(xmap.containsKey(i)){
				int zip = i-before-1;
				xzip[2*cnt]=zip;
				xzip[2*cnt+1]=1;
				map.put(2*cnt+1, xmap.get(i));
				cnt++;
				before =i;
			}
		}
		zip_=W-before;
		xzip[2*cnt]=zip_;

		for(int i=0;i<2*N+1;i++){
			for(int j=0;j<2*N+1;j++){
				zipmap[i][j] = xzip[i]*yzip[j];
			}
		}
		for(int i=0;i<2*N+1;i++){
			sumx[i][0]=zipmap[i][0];
			sumy[0][i]=zipmap[0][i];
			for(int j=1;j<2*N+1;j++){
				sumx[i][j] =sumx[i][j-1]+zipmap[i][j];
				sumy[j][i] = sumy[j-1][i]+zipmap[j][i];
			}
		}

		for(int i=0;i<2*N+1;i++){
			for(int j=0;j<2*N+1;j++){
				int x=0;
				while(x+i<2*N+1){
					int y=0;
						while(y+j<2*N+1){
							dp(x,y,x+i,y+j);
							y++;
						}
						x++;
					}
			}
		}
		System.out.println(dp[0][0][2*N][2*N]);


	}

	static void dp(int x1,int y1,int x2,int y2){
		for(int x =x1;x<=x2;x++){
//			for(int y=y1;y<=y2;y++){
				if(map.containsKey(x)&&map.get(x)>=y1&&map.get(x)<=y2){
					int y=map.get(x);
					int num=sumx[x][y2]-sumx[x][y1]+zipmap[x][y1] + sumy[x2][y]-sumy[x1][y]+zipmap[x1][y]-zipmap[x][y];
					dp[x1][y1][x2][y2] = Math.max(dp[x1][y1][x2][y2], num + dp[x1][y1][x-1][y-1]+dp[x+1][y1][x2][y-1]+dp[x1][y+1][x-1][y2]+dp[x+1][y+1][x2][y2]);
				}
		}

	}
}