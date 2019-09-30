import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int gcm=a*b/Euclid(a,b);
        int n=sc.nextInt();
        System.out.println(n%gcm==0?n:(n/gcm+1)*gcm);
    }
        private static int Euclid(int n, int m) {
        int tmp;
        while (true) {
            if (n == 0) {
                return m;
            } else if (m == 0) {
                return n;
            }
            tmp = n;
            n = m;
            m = tmp;
            n = n % m;

        }

    }
}