import java.util.*;
import java.io.*;

class Main {
    static long gcd(long a, long b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for(int i = 0; i < T; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();
            long d = sc.nextLong();

            if(b > a) {
                System.out.println("No");
                continue;    
            }
            if(b > d) {
                System.out.println("No");
                continue;                   
            }
            if(c >= b) {
                System.out.println("Yes");
                continue;
            }

            long g = gcd(b,d);
            long aa = b - g + a % g;

            if(aa > c) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }


        }
    }
}