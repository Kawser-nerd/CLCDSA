import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        int sub = Math.abs(a-b);
        
        System.out.println(Math.min(sub, 10-sub));
    }
}