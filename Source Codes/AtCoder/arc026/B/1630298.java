import java.util.*;

public class Main {
    private static long N;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextLong();
    }

    public static void main(String args[]) {
        //??
        input();

        long sum = 1;
        for (long i=2;i<=Math.sqrt(N);i++){
            if (N % i == 0) sum += i + N/i;
        }
        if (N % Math.sqrt(N) == 0) sum -= Math.sqrt(N);

        if (sum == N) System.out.println("Perfect");
        else if (sum > N) System.out.println("Abundant");
        else System.out.println("Deficient");
    }
}