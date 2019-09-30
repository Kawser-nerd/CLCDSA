import java.util.*;

public class Main {
    static long n;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextLong();

        int h = 0;
        for(long i = n; i >= 2; i = i/2) h++;

        int turn = 1;
        long x = 1;
        while(x <= n) {
            // Aoki
            if (turn % 2 == 0) {
                turn++;
                x = h%2 == 0 ? 2*x : 2*x+1;
            }else{
                turn++;
                x = h%2 == 0 ? 2*x+1 : 2*x;
            }
        }

        if(turn%2 == 0) {
            System.out.println("Aoki");
        }else{
            System.out.println("Takahashi");
        }
    }
}