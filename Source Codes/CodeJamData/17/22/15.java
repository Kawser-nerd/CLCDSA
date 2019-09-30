import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class StableNeighbors {

    static class Unicorn {
        int cnt;
        char color;

        public Unicorn(int cnt, char color) {
            this.cnt = cnt;
            this.color = color;
        }
    }

    static Unicorn[] unicorn;
    static int N;

    static boolean isPure(char color) {
        return color == 'R' || color == 'Y' || color == 'B';
    }

    static String doit(Unicorn[] unicorn) {
        Arrays.sort(unicorn, (u, v) -> Integer.compare(u.cnt, v.cnt));
        if (unicorn[0].cnt + unicorn[1].cnt < unicorn[2].cnt) return "IMPOSSIBLE";

        String[] circle = new String[unicorn[2].cnt];
        Arrays.fill(circle, "");
        for (int i = 0; i < unicorn[0].cnt; i++)
            circle[i] += unicorn[0].color;
        for (int i = 0; i < unicorn[1].cnt; i++)
            circle[circle.length - 1 - i] += unicorn[1].color;

        StringBuilder builder = new StringBuilder();
        for (String s : circle)
            builder.append(unicorn[2].color + s);
        return builder.toString();
    }

    static String alternating(Unicorn a, Unicorn b) {
        if (a.cnt != b.cnt) return "IMPOSSIBLE";
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < a.cnt; i++) {
            builder.append(a.color);
            builder.append(b.color);
        }
        return builder.toString();
    }

    static String ABABA(char A, char B, int BCnt) {
        StringBuilder builder = new StringBuilder();
        builder.append(A);
        for (int i=0; i<BCnt; i++) {
            builder.append(B);
            builder.append(A);
        }
        return builder.toString();
    }

    static String large(Unicorn[] unicorn) {
        // ROYGBV
        int R = 0, O = 1, Y = 2, G = 3, B = 4, V = 5;

        // O and B
        if (unicorn[R].cnt == 0 && unicorn[Y].cnt == 0 && unicorn[G].cnt == 0 && unicorn[V].cnt == 0)
            return alternating(unicorn[O], unicorn[B]);
        // V and Y
        if (unicorn[R].cnt == 0 && unicorn[G].cnt == 0 && unicorn[O].cnt == 0 && unicorn[B].cnt == 0)
            return alternating(unicorn[V], unicorn[Y]);
        // G and R
        if (unicorn[Y].cnt == 0 && unicorn[B].cnt == 0 && unicorn[O].cnt == 0 && unicorn[V].cnt == 0) {
            return alternating(unicorn[G], unicorn[R]);
        }

        if (unicorn[O].cnt > 0 && unicorn[O].cnt >= unicorn[B].cnt) return "IMPOSSIBLE";
        if (unicorn[V].cnt > 0 && unicorn[V].cnt >= unicorn[Y].cnt) return "IMPOSSIBLE";
        if (unicorn[G].cnt > 0 && unicorn[G].cnt >= unicorn[R].cnt) return "IMPOSSIBLE";

        unicorn[B].cnt -= unicorn[O].cnt;
        unicorn[R].cnt -= unicorn[G].cnt;
        unicorn[Y].cnt -= unicorn[V].cnt;
        if (Stream.of(unicorn).anyMatch(i -> i.cnt < 0)) return "IMPOSSIBLE";


        Unicorn[] small = new Unicorn[]{unicorn[B], unicorn[R], unicorn[Y]};
        String str = doit(small);
        if (str.equals("IMPOSSIBLE")) return str;

        if (unicorn[O].cnt > 0) str = str.replaceFirst("B", ABABA('B', 'O', unicorn[O].cnt));
        if (unicorn[V].cnt > 0) str = str.replaceFirst("Y", ABABA('Y', 'V', unicorn[V].cnt));
        if (unicorn[G].cnt > 0) str = str.replaceFirst("R", ABABA('R', 'G', unicorn[G].cnt));

        return str;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner cin = new Scanner(new File("B-small-attempt0.in"));
//        PrintStream cout = new PrintStream("B-small-attempt0.out");
        Scanner cin = new Scanner(new File("B-large.in"));
        PrintStream cout = new PrintStream("B-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;


            unicorn = new Unicorn[6];
            N = cin.nextInt();
            for (int i = 0; i < 6; i++) {
                unicorn[i] = new Unicorn(cin.nextInt(), "ROYGBV".charAt(i));
            }

//            Unicorn[] lala = Stream.of(unicorn).filter(u -> isPure(u.color)).toArray(Unicorn[]::new);
            String ans = large(unicorn);
            cout.printf("Case #%d: %s%n", _case, ans);
        }

        cin.close();
        cout.close();
    }
}
