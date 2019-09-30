import java.io.BufferedReader;
import java.io.IOException;
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
		int k = Integer.parseInt(tmpArray[1]);
		
		long result = 0;
		
		for(int b = 1; b <= n; b++){
			int p = n / b;
			int r = n % b;
			result += p*Math.max(0, b - k) + Math.max(0, r - k + 1);
		}
		
		if(k == 0){
			result -= n;
		}
		System.out.println(result);
	}

}