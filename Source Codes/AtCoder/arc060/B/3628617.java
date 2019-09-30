import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long s = sc.nextLong();
        sc.close();

        if(n == s){
            System.out.println(n+1);
            return;
        }

        for(int i=2; i<(int)(Math.sqrt(n) + 10); i++){
            if(f(n, i) == s){
                System.out.println(i);
                return;
            }
        }

        long bmin = Long.MAX_VALUE;
        for(int i=1; i<=(int)(Math.sqrt(n)+ 10); i++){
            long b = (n-s) / i + 1;
            if(b <= 1) continue;
            if(f(n, b) == s){
                bmin = Math.min(b, bmin);
            }
        }

        if(bmin == Long.MAX_VALUE){
            System.out.println(-1);
        }else{
            System.out.println(bmin);
        }

    }

    static long f(long n, long b){
        long ret = 0;
        while(n != 0){
            ret += n % b;
            n /= b;
        }
        return ret;
    }
}