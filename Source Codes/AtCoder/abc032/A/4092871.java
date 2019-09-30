import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();
        
        for (int i = N; i <= 2_000_001; i++) {
        	if (i % A == 0 && i % B == 0) {
        		System.out.println(i);
        		return;
        	}
        }
        
    }
}