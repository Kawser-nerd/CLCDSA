import java.util.ArrayDeque;
import java.util.Scanner;
public class Main{
	final int MOD=1_000_000_000+7;
	public static void main(String[] args){
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] a=new int[n];
		int[] b=new int[n];


		for(int i=0;i<n;i++){
			a[i]=sc.nextInt()-1;
		}
		for(int i=0;i<n;i++){
			b[i]=sc.nextInt()-1;
		}

		long[][] map=new long[n][n];

		long[][] duplicate=new long[n][n];
		duplicate[0][0]=1;
		ArrayDeque<Pair> q=new ArrayDeque<Pair>();
		q.add(new Pair(0,0));
		boolean[][] arrived=new boolean[n][n]; 
		while(!q.isEmpty()){
			Pair p=q.poll();
			for(int i=0;i<2;i++){
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n&&nx<=ny){
					if(!arrived[ny][nx]&&nx!=ny){
						q.add(new Pair(nx,ny));
						arrived[ny][nx]=true;
					}
					duplicate[ny][nx]=(duplicate[ny][nx]+duplicate[p.y][p.x])%MOD;
				}
			}
		}
//		showMt(duplicate);

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arrived[i][j]=false;
		map[0][0]=1;
		
		q.clear();
		q.add(new Pair(0,0));
		while(!q.isEmpty()){
			Pair p=q.poll();
			if(a[p.x]==b[p.y]){
				int now=0;
				int nx=p.x+1;
				int ny=p.y+1;
				for(;nx<n&&ny<n;nx++,ny++){
					if(a[nx]==b[ny]){
						now++;
						map[ny][nx]=(map[ny][nx]+duplicate[now][now]*(MOD-map[p.y][p.x]))%MOD;
					}
				}
			}
			for(int i=0;i<2;i++){
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				if(0<=nx&&nx<n&&0<=ny&&ny<n){
					if(!arrived[ny][nx]){
						q.add(new Pair(nx,ny));
						arrived[ny][nx]=true;
					}
					map[ny][nx]=(map[ny][nx]+map[p.y][p.x])%MOD;
				}
			}
			//			showMt(map);
			//			System.out.println();
		}
		long ans=map[n-1][n-1];
		System.out.println(ans%MOD);	
	}
	void showMt(int[][] map){
		for(int i=0;i<map.length;i++){
			for(int j=0;j<map[0].length;j++){
				System.out.print(map[i][j]+(j==map[0].length-1?"\n":" "));
			}
		}
	}
	void showMt(long[][] map){
		for(int i=0;i<map.length;i++){
			for(int j=0;j<map[0].length;j++){
				System.out.print(map[i][j]+(j==map[0].length-1?"\n":" "));
			}
		}
	}

	int[] dx={1,0};
	int[] dy={0,1};
	class Pair{
		int x;
		int y;
		Pair(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
}