import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        sc.close();

        for(int i=0; i<n-1; i++){
            if(c*(n-1-i) - d*i <= b-a && b-a <= -c*i + (n-1-i)*d){
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}