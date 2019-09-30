import java.util.ArrayList;
import java.util.Scanner;
import static java.lang.System.*;


public class Main {
	static Scanner sc = new Scanner(System.in);
	static ArrayList <Integer> train = new ArrayList();
	
	public static void main (String [] args){

		int a = sc.nextInt();
//		int b = sc.nextInt();
//		int c = sc.nextInt();
//		train.add(0);
		int count = 0;
		String answer = null; 
		for(int i = a;i > 0;i--){
			count += (i*10000);
		}
		count = count/a;
		answer = String.valueOf(count);
		out.println(answer);
		out.flush();
	}
	
	static ArrayList<Integer> gcd(int a,int b){
		for(int i=101;i > 0; i--){
			if(a%i == 0){
				if(b%i == 0){
					train.add(i);
				}
			}
		}
		return train;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.