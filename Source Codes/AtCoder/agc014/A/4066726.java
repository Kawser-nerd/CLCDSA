import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        
        if (A % 2 != 0 || B % 2 != 0 || C % 2 != 0) {
        	System.out.println(0);
        	return;
        }
        
        
        for (int i = 1; i <= 30; i++) {
        	long a = B/2 + C/2;
        	long b = A/2 + C/2;
        	long c = B/2 + A/2;
        	
        	if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
            	System.out.println(i);
            	return;
        	} else {
        		A = a;
        		B = b;
        		C = c;
        	}
        }
        
        System.out.println(-1);
    }
}