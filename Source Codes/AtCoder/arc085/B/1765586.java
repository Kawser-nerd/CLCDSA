import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


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
		int z = Integer.parseInt(tmpArray[1]);//X???????
		int w = Integer.parseInt(tmpArray[2]);//Y???????
		
		int[] input = new int[n];//??
		tmpArray = br.readLine().split(" ");
		for(int i = 0; i < n; i++){
			input[i] = Integer.parseInt(tmpArray[i]);
		}
		
		int score = 0;
		
		if(n == 1){
			score = Math.abs(w - input[n-1]);
		}
		else {
			score = Math.max(Math.abs(input[n-2] - input[n-1]), Math.abs(w - input[n-1]));
		}
		
		System.out.println(score);
	}


}