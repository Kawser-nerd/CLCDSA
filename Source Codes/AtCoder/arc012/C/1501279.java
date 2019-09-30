import java.util.*;

public class Main{    

    static int N = 19;
    
    static int[][] board;
    
    public static void main(String[] args){
           
       Scanner sc = new Scanner(System.in);             
       
       Scanner cin = new Scanner(System.in);
		board = new int[N][N];

		int ocount = 0;
		int xcount = 0;
		for(int i=0;i<N;i++){
			String st = cin.next();
			for(int j=0;j<N;j++){
				if(st.charAt(j) == 'o'){
					board[i][j] = 1;
					ocount++;
				}
				if(st.charAt(j) == 'x'){
					board[i][j] = 2;
					xcount++;
				}
			}
		}

		int prev = 0;
		if(ocount - 1 == xcount) prev = 1;
		if(ocount == xcount) prev = 2;

		if(prev == 0){
			System.out.println("NO");
			return;
		}

		if(ocount==0){
			System.out.println("YES");
			return;
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j] == prev){
					board[i][j] = 0;
					if(checkboard()){
						System.out.println("YES");
						return;
					}
					board[i][j] = prev;
				}
			}
		}

		System.out.println("NO");
       
    }
    
   static  boolean checkboard(){
		int[] vy = new int[]{1,1,1,0,0,-1,-1,-1};
		int[] vx = new int[]{1,0,-1,1,-1,1,0,-1};
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(board[i][j] != 0){
					int now = board[i][j];
					for(int k=0;k<8;k++){
						boolean flag = true;
						for(int l=0;l<5;l++){
							int y = i + vy[k] * l;
							int x = j + vx[k] * l;
							if(!ok(y,x) || board[y][x] != now){
								flag = false;
								break;
							}
						}
						if(flag) return false;
					}

				}
			}
		}
		return true;
    }

    static boolean ok(int y, int x){
            return y>=0 && x>=0 && y<N && x<N;
    }
        
}