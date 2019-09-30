import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		 int num = Integer.parseInt(a+b);
	for(int i=1;i<400;i++){
		if(i*i==num){
			System.out.println("Yes");
		    System.exit(0);
		}
	}
	System.out.println("No");
	}
}