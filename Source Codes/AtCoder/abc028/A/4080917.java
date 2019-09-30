import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if (N == 100) {
        	System.out.println("Perfect");
        } else if (N >= 90) {
        	System.out.println("Great");
        } else if (N >= 60) {
        	System.out.println("Good");
        } else {
        	System.out.println("Bad");
        }
    }
}