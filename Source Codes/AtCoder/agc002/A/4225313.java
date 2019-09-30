//
 
import java.util.*;
 
class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		
		//????0????0
		//????????????
		//?????????????????????????
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		if (a<=0 && 0<=b) System.out.println("Zero");
		else if (0<a && 0<b) System.out.println("Positive");
		else {
			System.out.println((Math.abs(a-b)+1)%2==0?"Positive":"Negative");
		}
		
	}
}