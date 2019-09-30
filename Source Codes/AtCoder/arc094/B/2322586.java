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
		
		int q = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < q; i++){
			String[] tmpArray = br.readLine().split(" ");
			int a = Integer.parseInt(tmpArray[0]);
			int b = Integer.parseInt(tmpArray[1]);
			
			if(a > b){
				int tmp = a;
				a = b;
				b = tmp;
			}
			
			long result = 0;
			if(a == b){
				result = 2*a - 2;
			}
			else if(a + 1 == b){
				result = 2*a - 2;
			}
			else {
				long c = (long)Math.sqrt((long)a*b);
//				System.out.println("c = "+c);
				if(c*c == (long)a*b){
					c--;
				}
				
				if(c*(c+1) >= (long)a*b){
					result = 2*c - 2;
				}
				else {
					result = 2*c - 1;
				}
			}
			System.out.println(result);
		}
		
	}

}