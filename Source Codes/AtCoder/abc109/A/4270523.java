import java.util.*;
class Main {
	public static void main(String args[]) {
    	Scanner s = new Scanner(System.in);
      	int a = s.nextInt();
      	int b = s.nextInt();
      	System.out.println((a % 2 == 0 || b % 2 == 0) ? "No" : "Yes");
    }
}