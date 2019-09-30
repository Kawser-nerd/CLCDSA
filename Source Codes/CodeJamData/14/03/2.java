import java.util.*;
import java.io.*;
public class C {
	public static void main(String[]args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter writer = new PrintWriter("c-large.out");
		int inputs = in.nextInt();
		for(int caseNum = 1; caseNum <= inputs; caseNum++) {
			int row = in.nextInt();
			int col = in.nextInt();
			int total = row*col;
			int mines = in.nextInt();
			int spaces = total - mines;
			boolean poss = false;
			char[][] grid = new char[row][col];
			for(int i = 0;  i< row; i++) {
				Arrays.fill(grid[i], '*');
			}
			boolean special = false;
			int ans = 0;
			if(spaces == 1) {
				ans = 1;
				special = true;
				grid[0][0] = '.';
				poss = true;
			}
			
			
			if(col == 1) {
				ans = spaces;
				poss = true;
				for(int i = 0 ; i <spaces; i++) {
					grid[i][0] = '.';
				}
				special = true;
			}
			
			if(row == 1) {
				ans = 1;
				poss = true;
				for(int i = 0 ; i <spaces; i++) {
					grid[0][i] = '.';
				}
				special = true;
			}
			
			if(mines == 0) {
				poss = true;
				ans = col;
				for(int i = 0;  i< row; i++) {
					Arrays.fill(grid[i], '.');
				}
				special = true;
			}
			
			for(int i = 2; i <= row; i++) {
				//System.out.println(i + " " + spaces/i + " " + spaces % i);
				if((spaces/i == col && spaces% i != 0) || (spaces/i == 2 && spaces%i == 1) || spaces / i > col || spaces/i<2) {
					continue;
				} else if(i != 2 || spaces%i != 1) {
					//System.out.println(spaces + " "+ i);
					ans = i;
					poss = true;
					break;
				}
			}

			//System.out.println(ans);
			writer.printf("Case #%d:\n", caseNum);
			if(poss) {
				if(!special) {
					for(int i = 0 ; i< ans;i++){
						for(int j = 0; j < spaces/ans-1; j++) {
							grid[i][j] = '.';
							//System.out.println(i + " " + j);
						}
					}
					if(spaces % ans != 1) {
						for(int i = 0 ; i < ans; i++) {
							grid[i][spaces/ans-1] = '.';
						}
						for(int i = 0 ; i< spaces%ans; i++) {
							grid[i][spaces/ans] = '.';
						}
					} else {
						for(int i = 0 ; i < (spaces%ans +ans+1)/2; i++) {
							grid[i][spaces/ans-1] = '.';
						}
						for(int i = 0 ; i< (spaces%ans + ans)/2; i++) {
							grid[i][spaces/ans] = '.';
						}
					}
				}
				grid[0][0] = 'c';
				for(int i = 0; i < row; i++) {
					for(int j = 0; j < col; j++) {
						writer.print(grid[i][j]);
					}
					writer.println();
				}
			} else {
				writer.println("Impossible");
			}
		}
		writer.close();
	}
}
