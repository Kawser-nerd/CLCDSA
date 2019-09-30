
import javax.swing.*;
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class StableNeighbors {
    static String FAIL = "IMPOSSIBLE";

    static String repeat(String what, int n) {
        StringBuilder sb = new StringBuilder(what.length() * n);
        while (n-- > 0)
            sb.append(what);
        return sb.toString();
    }

    static String flip(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    static String solve(int R, int Y, int B) {
        if (R + Y + B == 0)
            return "";

        if (R > Y + B) return FAIL;
        if (Y > R + B) return FAIL;
        if (B > R + Y) return FAIL;

        String[] tmp = {
            repeat("R", R),
            repeat("Y", Y),
            repeat("B", B)
        };

        Arrays.sort(tmp, Comparator.comparing(String::length));

        String res = combine(tmp[2], flip(combine(tmp[0], tmp[1])));

        if (res.charAt(0) == res.charAt(res.length() - 1))
            return FAIL;
        if (res.contains("RR") || res.contains("YY") || res.contains("BB"))
            return FAIL;
        return res;
    }

    static String combine(String a, String b) {
        StringBuilder sb = new StringBuilder(a.length() + b.length());

        for (int pos = 0; pos < a.length() || pos < b.length(); pos++) {
            if (pos < a.length())
                sb.append(a.charAt(pos));
            if (pos < b.length())
                sb.append(b.charAt(pos));
        }

        return sb.toString();
    }

    static String solve(int total, int R, int O, int Y, int G, int B, int V) {
        if (G > 0) {
            if (G > R)
                return FAIL;

            if (G == R) {
                if (G + R == total) {
                    return repeat("GR", G);
                } else {
                    return FAIL;
                }
            } else {
                R -= G;
            }
        }

        if (O > 0) {
            if (O > B)
                return FAIL;

            if (O == B) {
                if (O + B == total) {
                    return repeat("OB", O);
                } else {
                    return FAIL;
                }
            } else {
                B -= O;
            }
        }

        if (V > 0) {
            if (V > Y)
                return FAIL;
            if (V == Y) {
                if (V + Y == total) {
                    return repeat("VY", V);
                } else {
                    return FAIL;
                }
            } else {
                Y -= V;
            }
        }

        // RYB

        String res = solve(R, Y, B);

        if (res == FAIL)
            return FAIL;

        res = res.replaceFirst("R", "R" + repeat("GR", G));
        res = res.replaceFirst("B", "B" + repeat("OB", O));
        res = res.replaceFirst("Y", "Y" + repeat("VY", V));

        return res;
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("c:\\codejam\\data"));
        jfc.showOpenDialog(null);

        LineNumberReader in = new LineNumberReader(new InputStreamReader(new FileInputStream(jfc.getSelectedFile()), "UTF-8"));
        FileOutputStream fos = new FileOutputStream(new File(jfc.getSelectedFile().toString() + ".out"));
        OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");
        Writer writer = line -> {
            System.out.println(line);
            out.write(line + "\n");
        };

        int T = Integer.parseInt(in.readLine());
        for (int c = 1; c <= T; c++) {
            String[] tmp = in.readLine().split(" ");

            int total = Integer.parseInt(tmp[0]);
            int R = Integer.parseInt(tmp[1]);
            int O = Integer.parseInt(tmp[2]);
            int Y = Integer.parseInt(tmp[3]);
            int G = Integer.parseInt(tmp[4]);
            int B = Integer.parseInt(tmp[5]);
            int V = Integer.parseInt(tmp[6]);

            writer.write("Case #" + c + ": " + solve(total, R, O, Y, G, B, V));
        }

        out.flush();
        fos.close();
    }

    interface Writer {
        void write(String s) throws Exception;
    }
}
