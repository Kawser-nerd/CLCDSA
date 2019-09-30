import java.util.*;
class Main
{
    static int MOD = 1000000007;
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();

        int[] cntA = new int[n+1];
        int[] cntB = new int[n+1];
        int[] cntC = new int[n+1];
        int[] cntQ = new int[n+1];
        cntA[0] = cntB[0] = cntC[0] = cntQ[0] = 0;
        for(int i = 1; i < n+1; i++){
            char c = s.charAt(i-1);
            cntA[i] = cntA[i-1];
            cntB[i] = cntB[i-1];
            cntC[i] = cntC[i-1]; 
            cntQ[i] = cntQ[i-1];           
            switch(c){
                case 'A':
                    cntA[i]++;
                    break;
                case 'B':
                    cntB[i]++;
                    break;
                case 'C':
                    cntC[i]++;
                    break;
                default:
                    cntQ[i]++;
                    break;

            }
        }
        long ans = 0;
        long left;
        long right;
        for(int i = 0; i < n; i++){
            left = right = 0;
            if(s.charAt(i) == 'B' || s.charAt(i) == '?'){
                left += cntA[i+1] * pow3(cntQ[i]) % MOD;
                left += cntQ[i] * pow3(cntQ[i] - 1) % MOD;
                left %= MOD;
                right += (cntC[n] - cntC[i+1]) * pow3(cntQ[n] - cntQ[i+1]) % MOD;
                right += (cntQ[n] - cntQ[i+1]) * pow3(cntQ[n] - cntQ[i+1] - 1) % MOD;
                right %= MOD;
                ans += left * right % MOD;
                ans %= MOD;
            }
        }
        System.out.println(ans);
    }
    static long pow3(int n){
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(n % 2 == 0){
            long d = pow3(n / 2);
            return d * d % MOD;
        }
        return 3 * pow3(n-1) % MOD;
    }
}