import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        int i = S.indexOf("WBWBWBW");

        String[] o = new String[]{"Do", "", "Re", "", "Mi", "Fa", "", "So", "", "La", "", "Si"};
        int oi = 5 - i % 12;
        if (oi < 0) {
            oi = o.length + oi;
        }
        out.println(o[oi]);
    }
}