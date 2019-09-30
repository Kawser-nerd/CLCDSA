import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        long K = sc.nextLong();

        double days = 5.0 * Math.pow(10, 15);  //?:10^12, 1000?: 10^15

        char ans = S.charAt(0);
        for(int i = 0; i < S.length(); i++){
            K -= Math.pow(Character.getNumericValue(S.charAt(i)), days);
            if(K <= 0){
                ans = S.charAt(i);
                break;
            }
        }

        out.println(ans);
    }
}