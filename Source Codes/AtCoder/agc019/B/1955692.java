import java.util.Scanner;
import java.util.Arrays;
class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        String A = scan.next();
        long[] cnt = new long[26];
        Arrays.fill(cnt, 0);
        for(int i=0;i<A.length();++i){
            cnt[A.charAt(i) - 'a']++;
        }
        long ans = ((long)A.length()*(long)(A.length()-1))/2 + 1;
        for(long num : cnt){
            ans -= (num*(num-1))/2;
        }
        System.out.println(ans);
    }
}