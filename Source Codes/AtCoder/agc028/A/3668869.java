import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextInt();
        long M = sc.nextInt();
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        sc.close();
        long lcm = lcm(N, M);
        long n = lcm / N;
        long m = lcm / M;
        boolean success = true;
        for(int i = 0; i < N; i++){
            if((n * i) % m == 0){
                if(s[(int) (i)] != t[(int) (n * i / m)]){
                    success = false;
                    break;
                }
            }
        }

        if(success){
            System.out.println(lcm);
        }else{
            System.out.println(-1);
        }
    }

    private static long gcd(long n, long m){
        if(n < m) return gcd(m, n);
        if(m == 0) return n;
        return gcd(m, n % m);
    }
    private static long lcm(long n, long m){
        return n * m / gcd(n, m);
    }
}