import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		int H = sc.nextInt();
		int W = sc.nextInt();
		char[][] board = new char[H][W];
		int[][] checkBoard = new int[H][W];
		int[] start = new int[3];
		
		for(int i = 0; i < H; i++){
			String line = sc.next();
			for(int j = 0; j < W; j++){
				char c = line.charAt(j);
				board[i][j] = c;
				checkBoard[i][j] = 3;
				
				if(c == 's'){
					start[0] = i;
					start[1] = j;
					start[2] = 0;
				}
			}
		}
		
		ArrayList<int[]> queue = new ArrayList<int[]>();
		queue.add(start);
		
		int[] dir = {-1, 0, 1, 0, -1};
		while(queue.size() != 0){
			int[] q = queue.remove(0);
			for(int k = 0; k < 4; k++){
				int x = q[0] + dir[k + 1];
				int y = q[1] + dir[k];
				if(x < 0 || x >= H) continue;
				if(y < 0 || y >= W) continue;
				
				if(board[x][y] == 'g'){
					System.out.println("YES");
					return;
				}
				
				if(board[x][y] == '.' && checkBoard[x][y] > q[2]){
					int[] p = {x, y, q[2]};
					queue.add(p);
					checkBoard[x][y] = q[2];
				}
				
				if(board[x][y] == '#' && checkBoard[x][y] > q[2] + 1){
					int qq = q[2] + 1;
					int[] p = {x, y, qq};
					queue.add(p);
					checkBoard[x][y] = qq;
				}
			}
		}
		
		System.out.println("NO");
	}
	
	public static void printBoard(int H, int W, char[][]board){
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
	}
}