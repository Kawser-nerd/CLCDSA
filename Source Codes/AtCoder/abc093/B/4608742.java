import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long k = scanner.nextLong();
        if(b-a+1 <= 2*k) {
            for(long i = a;i <= b;i++) {
                System.out.println(i);
            }
        } else {
            long i,j;
            for(i = a;i < k+a;i++) {
                System.out.println(i);
            }
            for(j = b-k+1;j <= b;j++) {
                System.out.println(j);
            }
        }
    }
}