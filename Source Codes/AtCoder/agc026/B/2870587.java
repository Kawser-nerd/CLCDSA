import java.util.*;
public class Main {
    static long gcd(long a, long b) {
        if(a<b) {
            long t = b;
            b = a;
            a = t;
        }
        if(b==0) {
            return a;
        }
        return gcd(a%b, b);
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int  t = sc.nextInt();
        while(t-->0){
            long a = sc.nextLong();
            long b = sc.nextLong();
            long c = sc.nextLong();
            long d = sc.nextLong();
            long diff = a-b;
            if(diff<0){
                System.out.println("No");
            } else
            if(b>d){
                System.out.println("No");
            } else
            if(c>=b) System.out.println("Yes");
            else {
                long gc = gcd(b,d);
                if((a%gc+b-gc) > c) {
                    System.out.println("No");
                } else System.out.println("Yes");
            }
        }
    }
}