import java.util.Scanner;
import java.util.Arrays;
public class Main{
	static int[][] map;
	static long ans;
	static boolean[] used;
	static int[] r;
	static int R;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		R = sc.nextInt();
		map=new int[n][n];
		used=new boolean[n];
		ans=Long.MAX_VALUE;
		r=new int[R];
		for(int i = 0; i<R; i++){
			r[i]= sc.nextInt()-1;
		}
		for(int i = 0; i<n; i++){
			Arrays.fill(map[i],Integer.MAX_VALUE/2);
		}
		for(int i = 0; i<m; i++){
			int a = sc.nextInt()-1;
			int b = sc.nextInt()-1;
			int c = sc.nextInt();
			map[a][b]=c;
			map[b][a]=c;
		}
		for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				for(int k = 0; k<n; k++){
					if(i!=j && j!=k && k!=i){
						map[j][k]=Math.min(map[j][k],map[j][i]+map[i][k]);
					}
				}
			}
		}
		for(int i :r){
			used[i]=true;
			dfs(i,0,1);
			used[i]=false;
		}
		System.out.println(ans);
	}
	static void dfs(int now,long cost,int count){
		if(count==R){
			ans=Math.min(ans,cost);
		}
		for(int i:r){
			if(!used[i]){
				used[i]=true;
				dfs(i,cost+map[now][i],count+1);
				used[i]=false;
			}
		}
	}
}