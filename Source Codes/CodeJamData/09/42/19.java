import java.io.IOException;


public class ProblemB extends CodeJammer {

	int best;
	
	int r,c,f;
	
	@Override
	public void process() throws IOException {
		// TODO Auto-generated method stub
		//Just do a depth-first search to get the small data set.
		int[] data = reader.readArray();
		r = data[0];
		c = data[1];
		f = data[2];
		boolean[][] grid = new boolean[r][c];
		
		for (int i=0; i<r; i++) {
			String row = reader.readString();
			for (int j=0; j<c; j++) {
				grid[i][j] = (row.charAt(j)=='#');
			}
		}
		
		best = r*c+1; //sentinel for "nothing found"
		
		DFS(grid,0,0,0,0,0);
		
		if (best < r*c+1) {
			output("Yes " + best);
		} else {
			output("No");
		}
	}
	
	//last act is -1 or +1 if a move, else 0
	public void DFS(boolean[][] grid, int row, int col, int fell, int dug, int lastAct) {
		if (fell > f) return; //fell too far
		if (row == r-1) { //reached the bottom
			if (dug < best) best = dug;
			return;
		}
		
		//check if you need to keep falling
		if (!grid[row+1][col]) {
			DFS(grid,row+1,col,fell+1,dug,0);
			return;
		}
		
		//otherwise, try your options!
		if (col > 0 && !grid[row][col-1]) {
			//move left
			if (lastAct != 1) { //don't go in circles
				DFS(grid,row,col-1,0,dug,-1);
			}
			//dig left
			if (grid[row+1][col-1]) {
				grid[row+1][col-1] = false;
				DFS(grid,row,col,0,dug+1,0);
				grid[row+1][col-1] = true; //backtrack
			}
		}
		
		if (col < c-1 && !grid[row][col+1]) {
			//move right
			if (lastAct != -1) {
				DFS(grid,row,col+1,0,dug,1);
			}
			//dig left
			if (grid[row+1][col+1]) {
				grid[row+1][col+1] = false;
				DFS(grid,row,col,0,dug+1,0);
				grid[row+1][col+1] = true; //backtrack
			}
		}
		
	}
	
	public static void main(String[] args) {
		ProblemB p = new ProblemB();
		p.run(args);
	}

}
