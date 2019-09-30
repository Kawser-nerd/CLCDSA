import java.util.*;

import static java.lang.System.*;

// -2????
// 2??????????
// https://sci-pursuit.com/math/binary-number-conversion.html
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();


        List<Integer> tmp = new ArrayList();

        if(N == 0){
            tmp.add(0);
        } else {
            int base = -2;
            while (N != 1) {
                int mod = N % base;
                switch (mod) {
                    case -1:
                        tmp.add(1);
                        N = N / base + 1;
                        break;
                    default:
                        tmp.add(mod);
                        N = N / base;
                }
            }
            tmp.add(N);
            Collections.reverse(tmp);
        }

        String ans = "";
        for(int i = 0; i < tmp.size(); i++){
            ans += Integer.toString(tmp.get(i));
        }
        out.println(ans);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.