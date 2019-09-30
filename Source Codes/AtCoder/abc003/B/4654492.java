import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();

        final String WILD_CARD = "atcoder@";

        boolean win = true;

        for(int i=0; i<s.length(); i++) {
            if (!win) {
                break;
            }
            if (s.charAt(i) == '@' && !WILD_CARD.contains("" + t.charAt(i))) {
                win = false;
            } else if(t.charAt(i) == '@' && !WILD_CARD.contains("" + s.charAt(i))) {
                win = false;
            } else if(s.charAt(i) != t.charAt(i) && s.charAt(i) != '@' && t.charAt(i) != '@') {
                win = false;
            }
        }

        if(win) {
            System.out.println("You can win");
        } else {
            System.out.println("You will lose");
        }
    }
}