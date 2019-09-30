import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String SDash = sc.next();
        String T = sc.next();

        // ???????T?????
        StringBuilder S = new StringBuilder(SDash);
        boolean isRestorable = false;
        for (int i = S.length() - 1; i >= 0; i--) {
            boolean isRestorableTmp = true;
            for (int j = 0; j < T.length(); j++) {
                if (!(i + j < S.length() && (S.charAt(i + j) == '?' || S.charAt(i + j) == T.charAt(j)))) {
                    isRestorableTmp = false;
                    break;
                }
            }

            if (isRestorableTmp) {
                for (int j = 0; j < T.length(); j++) {
                    S.setCharAt(i + j, T.charAt(j));
                }
                isRestorable = true;
                break;
            }
        }

        if (isRestorable) {
            for (int i = 0; i < S.length(); i++) {
                if (S.charAt(i) == '?') {
                    S.setCharAt(i, 'a');
                }
            }
            out.println(S.toString());
        } else {
            out.println("UNRESTORABLE");
        }
    }
}