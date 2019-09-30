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
		
		int[] inputClone = Arrays.copyOf(input, n);
		
		Arrays.sort(inputClone);
		
		int med = n/2;
		
		for(int i = 0; i < n; i++){
			if(input[i] < inputClone[med]){
				System.out.println(inputClone[med]);
			}
			else {
				System.out.println(inputClone[med - 1]);
			}
		}
	}

}