import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		// ?????
		boolean ans = false;
		int H = 10;
		int W = 10;
		int pos_x = 0;
		int pos_y = 0;

		char[][] map = new char[H][W];
		char[][] map_tmp = new char[H][W];
		for(int h=0; h<H; h++){
			map[h] = sc.next().toCharArray();
		}
		
		for(int h=0; h<H; h++){
			for(int w=0; w<W; w++){
				for(int i=0; i<H; i++){
					for(int j=0; j<W; j++){
						map_tmp[i][j] = map[i][j];
					}
				}
				if(map_tmp[h][w]=='o')continue;
				map_tmp[h][w]='o';
				
				walk(h, w, W, H, map_tmp);
				
				boolean flag = true;
				for(int i=0; i<H; i++){
					if(flag){
						for(int j=0; j<W; j++){
							if(map_tmp[i][j]=='o'){
								flag = false;
								break;
							}
						}
					}
				}
				if(flag)ans = true;
			}
		}
		

		
		if(ans){
			System.out.println("YES");
		}else{
			System.out.println("NO");
		}
		sc.close();
	}
	
	
	public static void walk(int pos_x, int pos_y, int W, int H, char[][] map){
		int[] dx = {1,-1,0,0};
		int[] dy = {0,0,1,-1};
		
		if(pos_x<0 || pos_x >= H || pos_y<0 || pos_y >=W)return;
		if(map[pos_x][pos_y] == 'x')return;
		if(map[pos_x][pos_y] == 'o'){
			map[pos_x][pos_y] = 'x';
			for(int i=0; i<4; i++){
				walk(pos_x + dx[i], pos_y + dy[i], W, H, map);
			}
			return;
		}
		return;
		
	}
	
}