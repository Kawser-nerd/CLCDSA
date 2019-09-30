import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
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
		String input = br.readLine();
		
		String[] tmpArray = input.split(" ");
		
		long array[] = new long[n];
		
		for(int i = 0; i < n; i++){
			array[i] = Long.parseLong(tmpArray[i]);
		}
		
		long result = 0;
		
		result = solve(array);
		
		System.out.println(result);
		
	}
	
	static long solve(long[] array){
		int n = array.length;
		long result = 0;

		long tmpXor = array[0];
		long tmpSum = array[0];
		int left = 0;
		int right = 0;
		int count[] = new int[n];

		while(left < n){
//			System.out.println("left "+left+" right "+right+" sum "+tmpSum);
			if(right < n - 1 && (long)(tmpXor^array[right + 1]) == tmpSum+array[right + 1]){
				tmpXor ^= array[right + 1];
				tmpSum += array[right + 1];
				right++;
			}
			
			else {
				count[left] = right - left + 1;
				tmpSum -= array[left];
				tmpXor = tmpSum;
				if(left < n - 1 && left == right){
					right = left + 1;
					tmpXor = array[left + 1];
					tmpSum = array[left + 1];
				}
				
				left++;
			}
		}
		
		for(int i = 0; i < n; i++){
//			System.out.print(count[i]+" ");
			result += count[i];
		}
		return result;
		
	}

}