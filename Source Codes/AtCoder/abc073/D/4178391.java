import java.util.Scanner;
public class Main{
	static int[][] t;
	static int[] r1;
	static long ans;
	static boolean[] used;
	static int R;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		R = sc.nextInt();
		used=new boolean[R];
		ans=Integer.MAX_VALUE;
		t = new int[n+1][n+1];
		r1 = new int[R];
		for(int i= 0; i<R; i++){
			r1[i]= sc.nextInt();
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				if(i!=j){
					t[i][j]=Integer.MAX_VALUE/10;
				}
			}
		}
		for(int i = 0; i<m; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			t[a][b]=c;
			t[b][a]=c;
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				for(int k = 1; k<=n; k++){
						t[j][k]=Math.min(t[j][k],t[j][i]+t[i][k]);
				}
			}
		}
		dfs(0,-1,0);
			System.out.println(ans);
			
	}
	static void dfs(int count, int last, int sum){
		if(count==R){
			ans=Math.min(ans,sum);
			return;
		}
		for(int i = 0; i<R; i++){
			if(!used[i]){
				used[i]=true;
				if(last==-1){
					dfs(count+1,i,0);
				}else{
					dfs(count+1,i,sum+t[r1[last]][r1[i]]);
				}
				used[i]=false;
			}
		}
	}
}