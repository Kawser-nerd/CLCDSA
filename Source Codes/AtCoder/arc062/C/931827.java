import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author liymsheep
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private int[] rotate(int[] array) {
            int[] result = new int[4];
            for (int i = 0; i < 4; ++i) {
                result[(i + 1) & 3] = array[i];
            }
            return result;
        }

        private long hash(int[] array) {
            long result = 0;
            for (int i = 0; i < 4; ++i) {
                result = (result << 10L) + array[i];
            }
            return result;
        }

        private void put(Map<Long, Integer> map, long value) {
            int ways = 0;
            if (map.containsKey(value)) {
                ways = map.get(value);
            }
            ++ways;
            map.put(value, ways);
        }

        private long rep(int[] color) {
            long value = Long.MAX_VALUE;
            long current = hash(color);
            for (int i = 0; i < 4; ++i) {
                value = Math.min(value, current);
                current -= ((long) color[i]) << 30L;
                current <<= 10L;
                current += color[i];
            }
            return value;
        }

        private int get(Map<Long, Integer> map, long value) {
            Integer result = map.get(value);
            return result == null ? 0 : result;
        }

        private int[] reverse(int[] array) {
            int[] result = new int[array.length];
            for (int i = 0; i < array.length; ++i) {
                result[array.length - 1 - i] = array[i];
            }
            return result;
        }

        private int power(int x, int y) {
            int z = 1;
            for (int i = 0; i < y; ++i) {
                z = z * x;
            }
            return z;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long[][] arr = new long[n + 1][5];
            for (int i = 0; i <= n; ++i) {
                arr[i][0] = 1;
                for (int j = 1; j <= 4; ++j) {
                    arr[i][j] = arr[i][j - 1] * (i - j + 1);
                }
            }

            Map<Long, Integer> count = new HashMap<>();
            Map<Long, Integer> rot = new HashMap<>();
            long[] minHash = new long[n];
            int[][][] arrangements = new int[n][4][];
            for (int i = 0; i < n; ++i) {
                int[] colors = new int[4];
                for (int j = 0; j < 4; ++j) {
                    colors[j] = in.nextInt();
                }
//            colors = reverse(colors);
                minHash[i] = rep(colors);
                put(count, minHash[i]);
                int rotation = 0;
                for (int j = 0; j < 4; ++j) {
                    arrangements[i][j] = colors;
                    if (hash(colors) == minHash[i]) {
                        ++rotation;
                    }
                    colors = rotate(colors);
                }
                rot.put(minHash[i], rotation);
            }

            long answer = 0;
            int[] c1 = new int[4];
            int[] c2 = new int[4];
            int[] c3 = new int[4];
            int[] c4 = new int[4];
            long[] features = new long[4];
            for (int i = 0; i < n; ++i) {
                int[] bottom = arrangements[i][0];
                bottom = reverse(bottom);
                for (int j = i + 1; j < n; ++j) {
                    if (i != j) {
                        for (int k = 0; k < 4; ++k) {
                            int[] top = arrangements[j][k];
                            c1[0] = top[1];
                            c1[1] = top[0];
                            c1[2] = bottom[0];
                            c1[3] = bottom[1];
                            c2[0] = top[2];
                            c2[1] = top[1];
                            c2[2] = bottom[1];
                            c2[3] = bottom[2];
                            c3[0] = top[3];
                            c3[1] = top[2];
                            c3[2] = bottom[2];
                            c3[3] = bottom[3];
                            c4[0] = top[0];
                            c4[1] = top[3];
                            c4[2] = bottom[3];
                            c4[3] = bottom[0];
                            features[0] = rep(c1);
                            features[1] = rep(c2);
                            features[2] = rep(c3);
                            features[3] = rep(c4);
                            Arrays.sort(features);
//                        for (int s = 0; s < 4; ++s) {
//                            System.err.print(get(count, features[s]) + ", ");
//                        }
//                        System.err.println();
                            long currentWay = 1;
                            for (int t = 0; t < 4; ) {
                                int r = t;
                                while (r < features.length && features[t] == features[r]) {
                                    ++r;
                                }
                                int ways = get(count, features[t]);
                                if (features[t] == minHash[i]) {
                                    --ways;
                                }
                                if (features[t] == minHash[j]) {
                                    --ways;
                                }
                                if (ways < 0) {
                                    throw new RuntimeException();
                                }
                                if (ways < r - t) {
                                    currentWay = 0;
                                    break;
                                }
                                currentWay *= arr[ways][r - t] * power(rot.get(features[t]), r - t);
                                t = r;
                            }
                            answer += currentWay;
                        }
                    }
                }
            }
            if (answer % 3 != 0) {
                throw new RuntimeException();
            }
            answer /= 3;
            out.print(answer);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}