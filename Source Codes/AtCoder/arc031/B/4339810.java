import java.util.Scanner;
public class Main{
	static int sum;
	static int[] dx={0,0,1,-1};
	static int[] dy={1,-1,0,0};
	static char[][] map;
	static int count;
	static boolean[][] ma;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		map = new char[10][10];
		
		for(int i = 0; i<10; i++){
			String a=sc.next();
			for(int j = 0; j<10; j++){
				map[i][j]=a.charAt(j);
				if(map[i][j]=='o'){
					sum++;
				}
			}
		}
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				if(map[i][j]=='x'){
					map[i][j]='o';
					count=0;
					ma=new boolean[10][10];
					dfs(j,i);
					if(count==(sum+1)){
						System.out.println("YES");
						return;
					}else{
						map[i][j]='x';
					}
				}
			}
		}
		System.out.println("NO");
	}
	static boolean judge(int x,int y){
		return x>=0 && x<10 && y>=0 && y<10;
	}
	
	static void dfs(int x,int y){
		if(ma[y][x]==true){
			return;
		}
		count++;
		map[y][x]='x';
		ma[y][x]=true;
		for(int i = 0; i<4; i++){
			if(judge(x+dx[i],y+dy[i]) && map[y+dy[i]][x+dx[i]]!='x'){
				dfs(x+dx[i],y+dy[i]);
			}
		}
		map[y][x]='o';
	}
}