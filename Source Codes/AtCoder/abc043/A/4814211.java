import java.util.Arrays;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in); 
		
		int N = keyboard.nextInt();
		
		int ame = 0;
		
		for(int i = 1; i <= N ; i++ ) {
			ame += i;
		}
			System.out.println(ame);	
			
		keyboard.close();	
	}
}