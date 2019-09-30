import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		new Main().run();
	}



	void run()
	{
		Scanner cin = new Scanner(System.in);

		//????????char???????
		char[][] board = new char[8][8];
		for(int i=0;i<8;i++){
			String st = cin.next();
			for(int j=0;j<8;j++){
				board[i][j] = st.charAt(j);
			}
		}

		//???????????????
		if(dfs(0, 8, board)){
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					System.out.print(board[i][j]);
				}
				System.out.println();
			}
		}
		//????No Answer???
		else System.out.println("No Answer");
	}


	boolean dfs(int pos, int nokori, char[][] board)
	{
		//??8??????????true????
		if(nokori==0) return true;

		//??????????????false????
		if(pos==64) return false;

		//??pos??????
		int y = pos / 8;
		int x = pos % 8;

		boolean flg=board[y][x]=='Q';

		if(isPuttable(y, x, board)) {
				board[y][x]='Q';
				if(dfs(pos+1,nokori-1,board)) return true;

				if(!flg) {
					board[y][x]='.';
					if(dfs(pos+1,nokori,board)) return true;
				}
		}else {
			if(dfs(pos+1, nokori, board)) return true;
		}
		return false;
	}

	boolean ok(int y, int x){
		return y >= 0 && x >= 0 && y < 8 && x < 8;
	}

	boolean isPuttable(int y, int x, char[][] board){
		//8???????
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
		//?????????true???
		return true;
	}
}