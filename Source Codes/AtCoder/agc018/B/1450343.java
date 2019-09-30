import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] tmpArray = br.readLine().split(" ");
		int n = Integer.parseInt(tmpArray[0]);
		int m = Integer.parseInt(tmpArray[1]);
		
		int[][] matrix = new int[n][m];
		
		for(int i = 0; i < n; i++){
			tmpArray = br.readLine().split(" ");
			for(int j = 0; j < m ; j++){
				matrix[i][j] = Integer.parseInt(tmpArray[j]);

			}
		}
		
		//?????????????
		boolean[] hold = new boolean[m + 1];
		Arrays.fill(hold, true);
		hold[0] = false;
		
		System.out.println(calcMaxNum(matrix, hold));
	}
	
	static int calcMaxNum (int[][] matrix, boolean[] hold){
		int n = matrix.length;
		int m = matrix[0].length;
		
		//????????????
		int count = 0;
		for(int i = 0; i < hold.length ;i++){
			if(hold[i] == true){
				count++;
			}
		}
		
		if(count == 0){
			return Integer.MAX_VALUE;
		}
		//System.out.println(count+"sports will be held");
		
		int[] member = new int[m + 1];
		Arrays.fill(member, 0);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				if(hold[matrix[i][j]]){
					member[matrix[i][j]]++;
					break;
				}
			}
		}
		
		int max = 0;
		int maxSport = 1;
		for(int i = 1; i <= m; i++){
			if(max < member[i]){
				max = member[i];
				maxSport = i;
			}
		}
		
		//????????????????
		hold[maxSport] = false;
		int max2 = calcMaxNum(matrix, hold);
		return Math.min(max, max2);
	}

}