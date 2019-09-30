import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
        int d = sc.nextInt();
        int l = sc.nextInt();

        long ans = countPattern(x,y,d,l);
        ans = modsub(ans, countPattern(x-1,y,d,l) * 2);
        ans = modsub(ans, countPattern(x,y-1,d,l) * 2);
        ans = ans + countPattern(x-1,y-1,d,l) * 4 + countPattern(x-2,y,d,l) + countPattern(x,y-2,d,l);
        ans = modsub(ans, countPattern(x-2,y-1,d,l) * 2);
        ans = modsub(ans, countPattern(x-1,y-2,d,l) * 2);
        ans = ans + countPattern(x-2,y-2,d,l);
        ans = ans % 1000000007 * (r-x+1)*(c-y+1);
        System.out.println(ans % 1000000007);
    }

    private static long countPattern(int x, int y, int d, int l){
        if(x <= 0 || y <= 0 || x*y < d+l){
            return 0;
        }
        long ans = 1;
        for (int i = 0; i < l; i++) {
            ans = ans % 1000000007 * ((x * y) - i) % 1000000007 * modinv(l - i, 1000000007) % 1000000007;
        }
        for (int i = 0; i < d; i++) {
            ans = ans % 1000000007 * ((x * y) - l - i) % 1000000007 * modinv(d - i, 1000000007) % 1000000007;
        }
        return ans;
    }


    private static long modinv(long num, long mod){
        long result = 1;
        long n = mod - 2;
        BitSet bs = BitSet.valueOf(new long[]{n});
        for(int i = 0;i < bs.size();i++){
            if(bs.get(i)){
                result = result * num % mod;
            }
            num = num * num % mod;
        }
        return result;
    }

    private static long modsub(long a, long b){
        if(a < b){
            return a-b+1000000007;
        }
        return a-b;
    }


}