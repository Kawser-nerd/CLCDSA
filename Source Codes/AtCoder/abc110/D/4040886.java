import java.util.Scanner;

public class Main {

    static int MOD = 1_000_000_007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int sq = (int) Math.ceil(Math.sqrt(M));
        int prime = 0;
        long ans = 1;
        Combination comb = new Combination(N + sq, MOD);
        for(int i = 2; i <= sq; i++){
            if(M%i == 0){
                prime = 0;
                while(M%i == 0){
                    prime++;
                    M /= i;
                }
                ans = (ans * comb.comb(N-1+prime, Math.min(N-1, prime))) %MOD;
            }
        }
        if(M > 1) ans = (ans * N) %MOD;
        System.out.println(ans);
        sc.close();

    }

}

class Combination {

    long fac[]; // factorial:??
    long inv[]; // inverse:????????fac[i]?MOD-2??????MOD???????
    int MOD;

    Combination(int size, int mod){
        this.fac = new long[size +1];
        this.inv = new long[size +1];
        this.MOD = mod;

        this.fac[0] = 1;
        this.inv[0] = 1;

        for(int i = 1; i <= size; i++){
            fac[i] = (fac[i -1] * i) %MOD;
            inv[i] = modPow(fac[i], (int)MOD -2) %MOD;
        }
    }

    /*
     * n?????r?????????? nCr ?MOD???????????
     */
    long comb(int n, int r){
        return fac[n] * inv[r] %MOD * inv[n - r] %MOD;
    }

    /*
     * base^exp ?MOD???????????
     * ????O(log(exp))
     */
    private long modPow(long base, int exp) {
        long ret = 1;
        while(exp > 0){
            if((exp & 1) == 1){
                ret = ret * base %MOD;
            }
            base = base * base %MOD;
            exp >>= 1;
        }
        return ret;
    }

}