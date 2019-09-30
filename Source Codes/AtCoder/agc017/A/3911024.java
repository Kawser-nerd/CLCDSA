import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        int odd = 0;
        for (int i = 0; i < n; i++) {
           if( sc.nextInt() % 2 == 1 ) {
               odd++;
           }
        }
        if( odd == 0 ) {
            if( p == 0 ) {
                System.out.println((long)Math.pow(2, n));
            } else {
                System.out.println(0);
            }
        } else {
            System.out.println( (long)Math.pow(2, n-1));
        }
    }
}