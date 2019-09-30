import java.util.*;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C.in"));
        PrintWriter out = new PrintWriter("C.out");

        int t = in.nextInt();
        in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            System.out.println("Case #" + (tn + 1));
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int r = in.nextInt();
        int c = in.nextInt();
        char[][] a = new char[r][c];
        for (int i = 0; i < r; i++) {
            String s = in.next();
            for (int j = 0; j < c; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        List<List<Map<String, Integer>>> m = new ArrayList<List<Map<String, Integer>>>();
        for (int i = 0; i < r + 1; i++) {
            m.add(new ArrayList<Map<String, Integer>>());
            for (int j = 0; j < c; j++) {
                m.get(i).add(new HashMap<String, Integer>());
            }
        }

        m.get(0).get(0).put("....", 1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                for (Map.Entry<String, Integer> entry : m.get(i).get(j).entrySet()) {
                    char[] s = entry.getKey().toCharArray();
                    int k = entry.getValue();
                    for (char ch = 'a'; ch <= 'z'; ch++) if (a[i][j] == '.' || a[i][j] == ch) {
                        if (ch >= s[j] && ((j == 0) || ch >= s[j - 1])) {
                            char cc = s[j];
                            s[j] = ch;
                            String ss = String.valueOf(s);
                            Map<String, Integer> mm = (j == c - 1) ? m.get(i + 1).get(0) : m.get(i).get(j + 1);
                            Integer z = mm.get(ss);
                            if (z == null) {
                                mm.put(ss, k);
                            } else {
                                mm.put(ss, (z + k) % 10007);
                            }
                            s[j] = cc;
                        }
                    }
                }
            }
        }

        int res = 0;

        for (Map.Entry<String, Integer> entry : m.get(r).get(0).entrySet()) {
            res += entry.getValue();
            res %= 10007;
        }

        return "" + res;
    }

}
