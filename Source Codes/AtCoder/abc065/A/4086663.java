import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
         long X = sc.nextLong();
         long A = sc.nextLong();
         long B = sc.nextLong();
         
         if (B - A > X) {
        	 System.out.println("dangerous");
         } else if (0 < B - A &&  B - A <= X ) {
        	 System.out.println("safe");
         } else {
        	 System.out.println("delicious");
         }
    }
}