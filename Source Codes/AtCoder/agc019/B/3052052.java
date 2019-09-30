import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();

        long[] num = new long[26];
        for(int i=0; i<s.length(); i++){
            num[s.charAt(i) - 'a']++;
        }
        long ans = 1 + (long)(s.length()) * (long)((s.length() - 1)) / 2;
        for(int i=0; i<26; i++){
            ans -= num[i] * (num[i] - 1) / 2;
        }

        System.out.println(ans);
    }
}