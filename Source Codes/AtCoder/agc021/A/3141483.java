import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        int ans = solve(N);
        System.out.println(ans);
    }
    static int help(long N){
        int ans = 0;
        while(N>0){
            ans += N%10;
            N = N/10;
        }
        return ans;
    }
    static int solve(long N){
        if(N<10) return (int)N;
        String s = String.valueOf(N);
        int len = s.length();
        int ans =  help(N);
        for(int i=2;i<=len;i++){
            long temp = (long)Math.pow(10,i-1);
            long cur = N/temp-1;
            ans = Math.max(ans,help(cur)+9*(i-1));
        }
        return ans;
    }
}