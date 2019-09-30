import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class GoPlusPlus {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner cin = new Scanner(new File("D-small-attempt0.in"));
        PrintStream cout = new PrintStream("D-small-attempt0.out");
//        Scanner cin = new Scanner(new File("A-large.in"));
//        PrintStream cout = new PrintStream("A-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;
            StringBuilder ans = new StringBuilder();

            int N = cin.nextInt();
            int L = cin.nextInt();
            String[] a = new String[N];
            boolean impossible = false;
            for (int i = 0; i < N; i++)
                a[i] = cin.next();
            String shit = cin.next();

            for (String each : a)
                if (each.equals(shit)) impossible = true;

            if (impossible) ans.append("IMPOSSIBLE");
            else {
                String one = "0";
                for (int i = 0; i < L - 1; i++) one += "1";

                String two = "";
                for (int i = 0; i < L; i++) two += "0?";

                ans.append(one);
                ans.append(" ");
                ans.append(two);
            }
            cout.printf("Case #%d: %s%n", _case, ans.toString());
        }

        cin.close();
        cout.close();
    }
}
