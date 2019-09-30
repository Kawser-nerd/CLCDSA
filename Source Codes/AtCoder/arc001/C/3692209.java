import java.util.*;
public class Main{
	public static void main(String[] argv){
		Scanner scanIn = new Scanner(System.in);
		//??
		char[][] board = new char[8][8];
		for(int i=0;i<8;i++){
			String s = scanIn.next();
			board[i] = s.toCharArray();
		}
		//??????????
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(board[i][j]=='Q'){
					board[i][j] = '.';
					if(!isSettable(j,i,board)){
						System.out.println("No Answer");
						return;
					}
					board[i][j] = 'Q';
				}
			}
		}
		
		if(dfs(0,5,board)){
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++)
					System.out.printf(""+board[i][j]);
				System.out.println();
			}
		}else	System.out.println("No Answer");
	}
	
	//??????????DFS?????'.'??????????????????????
	public static boolean dfs(int point, int nokori, char[][] board){
		if(nokori==0)
			return true;
		if(point==64)
			return false;
		//??????
		int y = point/8;
		int x = point%8;
		if(isSettable(x, y, board)){
			board[y][x]='Q';
			if(dfs(point+1, nokori-1, board))
				return true;
			board[y][x]='.';
		}
		return dfs(point+1, nokori, board);
	}
	
	//???????Q???????????false????
	public static boolean isSettable(int x, int y, char[][] board){
		if(board[y][x]=='Q') return false;
		//vx, vy???????
		for(int vy=-1; vy<=1; vy++){
			for(int vx=-1; vx<=1; vx++){
				if(vy==0 && vx==0) continue;
				//??????????????????false
				int ty=y, tx=x;
				while(true){
					ty += vy; tx += vx;
					if(!ok(ty,tx)) break;
					if(board[ty][tx] == 'Q') return false;
				}
			}
		}
		return true;
	}
	private static boolean ok(int y, int x){
		return y >= 0 && x >= 0 && y < 8 && x < 8;
	}
}