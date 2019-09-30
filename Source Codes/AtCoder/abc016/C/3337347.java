import java.util.Arrays;
import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();

		cost = new long[n][n];
		for(long[] x: cost){
		    java.util.Arrays.fill(x, Integer.MAX_VALUE);
		}
		for (int i = 0; i < m; i++) {
			int from = scanner.nextInt()-1;
			int to = scanner.nextInt()-1;
			cost[from][to] = 1;
			cost[to][from] = 1;
		}
		varsize = n;
		
		for(int i=0;i<n;i++) {
			dis=new long[n];
			used=new boolean [n];
			dijkstra(i);
			int cnt=0;
			for(int j=0;j<varsize;j++) {
				if(dis[j]==2) {
					cnt++;
				}
			}
			System.out.println(cnt);
		}

	}

	static long cost[][];
	static long dis[];
	static boolean used[];
	static int varsize;

	//??s???????????????
	static void dijkstra(int s) {
		Arrays.fill(dis, Integer.MAX_VALUE);
		dis[s]=0;
		
		while(true) {
			int var=-1;
			//?????????????????????????
			for(int u=0;u<varsize;u++) {
				if(!used[u]&&(var==-1||dis[u]<dis[var]))var=u;
			}
			
			if(var==-1)break;
			used[var]=true;
			
			for(int u=0;u<varsize;u++) {
				dis[u]=Math.min(dis[u],dis[var]+cost[var][u]);
			}
		}
	}
	
}