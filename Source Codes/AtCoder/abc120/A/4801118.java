import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		
		
		int max = 0;
		
		max = B/A;
		
		if(max > C){
			System.out.println(C);
		}else{
			System.out.println(max);
		}
	}	

}