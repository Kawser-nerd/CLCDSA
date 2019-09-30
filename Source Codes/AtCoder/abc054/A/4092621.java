import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();

        if (A == B) {
        	System.out.println("Draw");
        	return;
        }
        
        A = A == 1 ? 14:A;
        B = B == 1 ? 14:B;
        
        System.out.println(A > B ? "Alice" : "Bob");
    }
}