import java.util.Scanner;
import java.util.ArrayDeque;
public class Main{
	static int h;
	static int w;
	static char[][] map;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		h=sc.nextInt();
		w= sc.nextInt();
		map=new char[h][w];
		int black=0;
		for(int i =0; i<h; i++){
			String s=sc.next();
			for(int j = 0; j<w; j++){
				map[i][j]=s.charAt(j);
				if(map[i][j]=='#'){
					black++;
				}
			}
		}
		ArrayDeque<Integer> qux=new ArrayDeque<>();
		ArrayDeque<Integer> quy=new ArrayDeque<>();
		qux.add(0);
		quy.add(0);
		int[] dx={1,0,0,-1};
		int[] dy={0,1,-1,0};
		int[][] ans=new int[h][w];
		map[0][0]='#';
		while(!qux.isEmpty()){
			int x = qux.poll();
			int y = quy.poll();
			for(int i=0; i<4; i++){
				if(jud(x+dx[i],y+dy[i])){
					qux.add(x+dx[i]);
					quy.add(y+dy[i]);
					map[y+dy[i]][x+dx[i]]='#';
					ans[y+dy[i]][x+dx[i]]=ans[y][x]+1;
				}
			}
		}
		if(ans[h-1][w-1]==0){
			System.out.println(-1);
		}else{
			System.out.println(h*w-black-ans[h-1][w-1]-1);
		}
	}
	static boolean jud(int x,int y){
		return x>=0 && x<w && y>=0 && y<h && map[y][x]!='#';
	}
}