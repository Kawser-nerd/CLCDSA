import java.util.*;

class Main {
        public static void main(String args[]) {
                try (Scanner sc = new Scanner(System.in)) {
                        String S = sc.next();
                        if ((S.length()-(S.charAt(0)==S.charAt(S.length() - 1)?1:0)) % 2 == 0) {
                                System.out.println("Second");
                        } else {
                                System.out.println("First");
                        }
                }
        }
}