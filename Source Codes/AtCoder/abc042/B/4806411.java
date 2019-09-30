import java.util.Arrays;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in); 
		
		int N = keyboard.nextInt();
		int L = keyboard.nextInt();
		
		String[] SI = new String[N];
		
		for(int i = 0; i < N; i ++) {
			SI[i] = keyboard.next();
		}
		
		Arrays.sort(SI);
		
		for(int i = 0; i < N; i ++) {
			System.out.print(SI[i]);
		}
		keyboard.close();	
	}
}