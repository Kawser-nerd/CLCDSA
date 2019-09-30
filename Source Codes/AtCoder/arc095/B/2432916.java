import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] input = new int[n];
		
		String[] tmpArray = br.readLine().split(" ");
		
		for(int i = 0; i < n; i++){
			input[i] = Integer.parseInt(tmpArray[i]);
		}
		
		Arrays.sort(input);
		
		int a = 0;
		int b = n - 1;
		
		int med = input[n - 1]/2;
		for(int i = 1; i < n - 2; i++){
			if(Math.abs(input[a] - med) >= Math.abs(input[i] - med)){
				a = i;
			}
		}
		
		System.out.println(input[b]+" "+input[a]);
	}

}