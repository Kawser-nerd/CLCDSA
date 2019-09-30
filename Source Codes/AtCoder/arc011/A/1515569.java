import java.util.HashMap;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt(), n = in.nextInt(), N = in.nextInt();
        int ans = 0, rem = 0;
        while(N + rem >= m){
            ans += N;
            N += rem;
            rem = N % m;
            N = N / m * n;
        }
        System.out.println(ans + N);
    }
}