import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(reader.readLine());
		int [][] grid = new int[2][N];
		for(int i=0;i<2;i++) {
			String [] temp = reader.readLine().split("[ ]");
			for(int j=0;j<N;j++) {
				grid[i][j] = Integer.parseInt(temp[j]);
			}
		}
		System.out.println(solution(grid, N));
	}
	
	public static int solution(int [][] grid, int N) {
		for(int i=1;i>=0;i--) {
			for(int j=N-1;j>=0;j--) {
				int current=0;
				if(j+1<N) {
					current= Math.max(current, grid[i][j+1]);
				}
				if(i+1<2) {
					current= Math.max(current, grid[i+1][j]);
				}
				
				grid[i][j]+=current;
			}
		}
		return grid[0][0];
	}

}