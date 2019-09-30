import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = br.readLine();

		int n = input.length();
		int ts = n;
		//Ts????????
		for(int i = 1; i < n; i++){
			if(input.charAt(i - 1) != input.charAt(i)){
				ts = Math.min(Math.max(i, n - i), ts);
			}
		}
		
		System.out.println(ts);
	}

}