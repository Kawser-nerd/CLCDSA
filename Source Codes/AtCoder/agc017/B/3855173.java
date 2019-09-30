import java.util.*;
import java.io.*;

/*
   AtCoder contest code
   coder : yoichidon
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        long D = sc.nextLong();

        for(int plus = 0; plus<N; plus++){
            int minus = (N-1)-plus;
            long max = A + D * plus - C * minus;
            long min = A + C * plus - D * minus;
            if(min <= B && B <= max){
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");

    }
}