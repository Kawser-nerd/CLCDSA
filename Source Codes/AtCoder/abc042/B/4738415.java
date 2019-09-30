import java.util.Scanner;
import java.util.Arrays;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int l = scan.nextInt();

		String[] strs = new String[n];
		for(int i = 0; i < n; i++){
			strs[i] = scan.next();
		}

		Arrays.sort(strs);

		for(int i = 0; i < n; i++){
			System.out.print(strs[i]);
		}
		System.out.println();
	}
}