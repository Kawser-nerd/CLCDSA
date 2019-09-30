package Y2017.r1b;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 * Created by david on 22/04/17.
 */
public class StableNeighbours {
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        try (PrintWriter writer = new PrintWriter("solution.txt", "UTF-8")) {
            for (int i = 1; i <= n; ++i) {
                writer.print(String.format("Case #%d: ", i));
                solve(scanner, writer);
            }
        }
    }

    public static class Impossible extends RuntimeException { }
    public static class Solved extends RuntimeException {
        String solution;
        public Solved(String solution) {
            this.solution = solution;
        }
    }

    public static String buildSharedColor(int shared, int opposite, int total, char s, char o) {
        if(shared == 0) {
            return o+"";
        }

        if (shared < opposite - 1) {

            StringBuilder res = new StringBuilder(o+"");
            for(int i = 0; i < shared; ++i) {
                res.append(""+s + o);
            }
            return res.toString();
        }

        if (shared == opposite && total == shared + opposite) {
            StringBuilder res = new StringBuilder();
            for(int i = 0; i < shared; ++i) {
                res.append(""+s + o);
            }
            throw new Solved(res.toString());
        }

        if (shared == opposite - 1 && total > opposite + shared) {
            StringBuilder res = new StringBuilder(o+"");
            for(int i = 0; i < shared; ++i) {
                res.append(""+s + o);
            }
            return res.toString();
        }
        throw new Impossible();

    }

    public static void solve(Scanner scanner, PrintWriter writer) {
        int N = scanner.nextInt();
        int R = scanner.nextInt();
        int O = scanner.nextInt();
        int Y = scanner.nextInt();
        int G = scanner.nextInt();
        int B = scanner.nextInt();
        int V = scanner.nextInt();//red yellow blue

        try {
            String firstBlue = buildSharedColor(O, B, N, 'O', 'B');
            String firstRed = buildSharedColor(G, R, N, 'G', 'R');
            String firstYellow = buildSharedColor(V, Y, N, 'V', 'Y');

            B -= O;
            R -= G;
            Y -= V;

            if(B > R+Y) {
                throw new Impossible();
            }

            if( R > B+Y) {
                throw new Impossible();
            }

            if (Y > R+B) {
                throw new Impossible();
            }

            if(R==0) {
                assert(B == Y);
                assert(B != 0);
                --B;
                --Y;

                StringBuilder b = new StringBuilder(firstBlue + firstYellow);
                for(int i = 0; i < B; ++i) {
                    b.append("BY");
                }
                throw new Solved(b.toString());
            }

            --R;
            StringBuilder b = new StringBuilder(firstRed);
            boolean firstB = true;
            boolean firstY = true;
            char last = 'R';
            while(R+B+Y > 0) {
                if((R>=Y || last == 'Y') && (R >= B || last == 'B') && last != 'R') {
                    --R;
                    assert last != 'R';
                    last = 'R';
                    b.append('R');
                } else if((B >= Y || last == 'Y') && (B >= R || last == 'R') && last != 'B') {
                    --B;
                    assert last != 'B';
                    last = 'B';
                    if(firstB) {
                        b.append(firstBlue);
                        firstB = false;
                    } else {
                        b.append('B');
                    }
                } else if ((Y >= B || last == 'B') && (Y >= R || last == 'R') && last != 'Y'){
                    --Y;
                    assert last != 'Y';
                    last = 'Y';
                    if(firstY) {
                        b.append(firstYellow);
                        firstY = false;
                    } else {
                        b.append('Y');
                    }
                } else {
                    throw new RuntimeException("BUG");
                }
            }
            throw new Solved(b.toString());

        } catch (Impossible ignored) {
            writer.println("IMPOSSIBLE");
        } catch (Solved s) {
            writer.println(s.solution);
        }
    }
}
