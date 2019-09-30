import java.util.Scanner;

public class Main {
	public static void main (String[] args){
		Scanner sc=new Scanner(System.in);
		int H=sc.nextInt();
		int W=sc.nextInt();
		int D=sc.nextInt();
		int[][] map=new int[H*W+1][2];
		int[][] ary=new int[H][W];
		int[][] ans=new int[D][H*W/D+2];
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				ary[i][j]=sc.nextInt();
				map[ary[i][j]][0]=i;
				map[ary[i][j]][1]=j;
			}
		}
		for(int i=0; i<D; i++) {
			for(int j=i; j<=H*W; j+=D) {
				if(j==i) {
					ans[i][0]=0;
				}
				else {
					ans[i][(j-i)/D]=Math.abs(map[j][0]-map[j-D][0])+Math.abs(map[j][1]-map[j-D][1]);
					ans[i][(j-i)/D]+=ans[i][(j-i)/D-1];
				}
			}
		}
		int Q=sc.nextInt();
		for(int i=0; i<Q; i++) {
			int from=sc.nextInt();
			int to=sc.nextInt();
			int mod=from%D;
			if(from<D) {
				System.out.println(ans[mod][(to-mod)/D]);
			}
			else{
				System.out.println(ans[mod][(to-mod)/D]-ans[mod][(from-mod)/D]);
			}
		}
		sc.close();
	}
}