import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int X = sc.nextInt();
        
        System.out.println(Math.min(Math.abs(N-X), Math.abs(1-X)));
    }
}