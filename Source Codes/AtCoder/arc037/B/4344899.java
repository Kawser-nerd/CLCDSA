import java.util.Scanner;
public class Main{
	static boolean[] map1;
	static int[][] map;
	static int n;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int m = sc.nextInt();
		int ans = 0;
		map=new int[n][n];
		map1=new boolean[n];
		for(int i = 0; i<m; i++){
			int u = sc.nextInt()-1;
			int v = sc.nextInt()-1;
			map[u][v]=1;
			map[v][u]=1;
		}
		for(int i = 0; i<n; i++){
			if(map1[i]==false){
				if(dfs(i)){
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
	static boolean dfs(int number){
		if(!map1[number]){
			map1[number]=true;
		}else{
			return false;
		}
		for(int i=0; i<n; i++){
			if(map[number][i]==1){
				map[i][number]=0;
				if(!dfs(i)){
					return false;
				}
			}
		}
		return true;
	}
}