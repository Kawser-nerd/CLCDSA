import java.util.*;
 
public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int n = sc.nextInt();
		int a = sc.nextInt();
		if (n%500 <= a) {System.out.println("Yes");}
		else {System.out.println("No");}
	}
}