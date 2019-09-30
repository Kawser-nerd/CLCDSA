import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        long n = sc.nextLong();
        long k = sc.nextLong();
        
        long sum = 0;
        for (int b = 1;b <= n;b++) {
        	if (b <= k) {
        	    continue;
        	}
        	
        	sum += (b - k) * (n / b) + Math.max(n % b - Math.max(k - 1, 0), 0);
        }
        
        System.out.println(sum);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}