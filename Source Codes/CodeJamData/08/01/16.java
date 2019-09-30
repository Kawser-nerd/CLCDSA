import java.io.*;

/**
 * @author Dmitry Shyshkin
 */
public class Main {
    public static void main(String[] args) throws IOException {
        String fname = "A-large";
        BufferedReader reader = new BufferedReader(new FileReader(fname + ".in"));
        PrintWriter writer = new PrintWriter(new File(fname + ".out"));
        int n = Integer.parseInt(reader.readLine());
        for (int num = 0; num < n; ++num) {
            int s = Integer.parseInt(reader.readLine());
            String[] sa = new String[s];
            for (int i = 0; i < s; ++i) {
                sa[i] = reader.readLine().intern();
                System.out.println(sa[i]);
            }
            System.out.println();
            int q = Integer.parseInt(reader.readLine());
            String[] qa = new String[q];
            for (int i = 0; i < q; ++i) {
                qa[i] = reader.readLine().intern();
                System.out.println(qa[i]);
            }
            System.out.println();
            int[][] v = new int[s][q + 1];
            for (int j = q - 1; j >= 0; --j) {
                for (int i = s - 1; i >= 0; --i) {
                    if (sa[i] != qa[j]) {
                        v[i][j] = v[i][j + 1];
                    } else {
                        v[i][j] = Integer.MAX_VALUE;
                        for (int k = 0; k < s; ++k) {
                            if (k != i) {
                                v[i][j] = Math.min(v[i][j], v[k][j + 1]);
                            }
                        }
                        ++v[i][j];
                    }
                }
            }
            for(int i = 0; i < s; ++i) {
                for (int j = 0; j <= q; ++j) {
                    System.out.print(v[i][j]);
                }
                System.out.println();
            }
            int _min = Integer.MAX_VALUE;
            int index = 0;
            for (int i = 0; i < s; ++i) {
                if (q == 0 || qa[0] != sa[i]) {
                    if (_min > v[i][0]) {
                        _min = v[i][0];
                        index = i;
                    }
                    _min = Math.min(_min, v[i][0]);
                }
            }
            int i = index; int j = 0;
            int count = 0;
            while (j != q) {
                if(qa[j] != sa[i]) {
                    ++j;
                } else {
                    int min = Integer.MAX_VALUE;
                    for (int k = 0; k < s; ++k) {
                        if (min > v[k][j] && k != i) {
                            min = v[k][j];
                            index = k;
                        }
                    }
                    i = index;
                    assert qa[j] != sa[i];
                    ++count;
                    ++j;
                }
            }
            assert _min == count : String.format("min: %d, count: %d", _min, count);
            writer.format("Case #%d: %d\n", num + 1, _min);
        }

        reader.close();
        writer.close();
    }
}
