import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
      	if (k < n) {
        	System.out.println(x * k + y * Math.max(n - k, 0));  
        } else {
          	System.out.println(x * n);
        }
        
        
    }

}