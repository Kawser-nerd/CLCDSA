import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		String N = sc.next();
		String output = "";
		
		for (int i = 0; i < N.length(); i++) {
			int output_size = output.length();
			if(N.charAt(i) == 'B') {
				if(output_size > 0) {
					output = output.substring(0, output_size - 1);
				}
			} else {
				output = output + N.substring(i, i+1); 
			}
			
		}
				
		// output
		System.out.println(output);
	}
}