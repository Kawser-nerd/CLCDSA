import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// get a integer
		int N = sc.nextInt();
		int output = (N * (N + 1))/2;
				
		// output
		System.out.println(output);
	}
}