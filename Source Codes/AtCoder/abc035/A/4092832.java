import java.util.*;
public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int A = sc.nextInt();
        int B = sc.nextInt();
        System.out.println(A % 16 == 0 && B % 9 == 0 ? "16:9": "4:3");
    }
}