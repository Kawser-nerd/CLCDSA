import java.util.Scanner;

public class Main {

    static String[] S = new String[3];
    static int[] cnt = new int[3];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        S[0] = sc.next();
        S[1] = sc.next();
        S[2] = sc.next();

        cnt[0] = S[0].length();
        cnt[1] = S[1].length();
        cnt[2] = S[2].length();

        int ans = serch(0);
        if (ans == 0)
            System.out.println('A');
        else if (ans == 1)
            System.out.println('B');
        else
            System.out.println('C');
    }

    static int serch(int thisTurn) {
        if (cnt[thisTurn] <= 0)
            return thisTurn;

        int index =  S[thisTurn].length() - cnt[thisTurn];
        char c = S[thisTurn].charAt(index);
        cnt[thisTurn]--;

        if (c == 'a')
            return serch(0);
        else if (c == 'b')
            return serch(1);
        else
            return serch(2);
    }
}