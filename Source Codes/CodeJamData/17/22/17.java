package codejam.unicorn;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Unicorn {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("src/codejam/unicorn/B-large.in"));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for (int t_i = 1; t_i <= T; t_i++) {
            String[] split = br.readLine().split(" ");
            int N = Integer.parseInt(split[0]);
            
            int R = Integer.parseInt(split[1]);
            int O = Integer.parseInt(split[2]);
            int Y = Integer.parseInt(split[3]);
            int G = Integer.parseInt(split[4]);
            int B = Integer.parseInt(split[5]);
            int V = Integer.parseInt(split[6]);

            int r = R + O + V;
            int y = O + Y + G;
            int b = G + B + V;
            
            int[] c = {R, O, Y, G, B, V};
            int[][] next = {{2, 3, 4}, {4}, {4, 5, 0}, {0}, {0, 1, 2}, {2}};
            char[] ch = {'R', 'O', 'Y', 'G', 'B', 'V'};
            
            String answer = null;
            if (Math.max(Math.max(r, y), b) * 2 > N) {
                answer = "IMPOSSIBLE";
            } else {
                StringBuilder S = new StringBuilder();

                // choose first
                int last = 0;
                if (c[0] > 0) {
                    last = 0;
                } else if (c[2] > 0) {
                    last = 2;
                } else if (c[4] > 0) {
                    last = 4;
                }
                c[last]--;
                S.append(ch[last]);
                if (hasYellow(last)) y--;
                if (hasRed(last)) r--;
                if (hasBlue(last)) b--;
                
                int first = last;
                
                for (int i = 1; i < N; i++) {
                    if (next[last].length == 1) {
                        last = next[last][0];
                    } else {
                        if (c[next[last][1]] != 0) {
                            last = next[last][1];
                        } else if (c[next[last][0]] == 0) {
                            last = next[last][2];
                        } else if (c[next[last][2]] == 0) {
                            last = next[last][0];
                        } else {
                            int c1 = next[last][0];
                            int c2 = next[last][2];
                            
                            if (hasRed(last)) {
                                if (       y >= b && c[c1] > 0 && hasYellow(c1)) {
                                    last = c1;
                                } else if (y >= b && c[c2] > 0 && hasYellow(c2)) {
                                    last = c2;
                                } else if (b >= y && c[c1] > 0 && hasBlue(c1)) {
                                    last = c1;
                                } else if (b >= y && c[c2] > 0 && hasBlue(c2)) {
                                    last = c2;
                                }
                            } else if (hasYellow(last)) {
                                if (       r >= b && c[c1] > 0 && hasRed(c1)) {
                                    last = c1;
                                } else if (r >= b && c[c2] > 0 && hasRed(c2)) {
                                    last = c2;
                                } else if (b >= r && c[c1] > 0 && hasBlue(c1)) {
                                    last = c1;
                                } else if (b >= r && c[c2] > 0 && hasBlue(c2)) {
                                    last = c2;
                                }
                            } else if (hasBlue(last)) {
                                if (       r >= y && c[c1] > 0 && hasRed(c1)) {
                                    last = c1;
                                } else if (r >= y && c[c2] > 0 && hasRed(c2)) {
                                    last = c2;
                                } else if (y >= r && c[c1] > 0 && hasYellow(c1)) {
                                    last = c1;
                                } else if (y >= r && c[c2] > 0 && hasYellow(c2)) {
                                    last = c2;
                                }
                            }
                        }
                    }

                    if (c[last] == 0) {
                        answer = "IMPOSSIBLE";
                        break;
                    }
                    
                    c[last]--;
                    S.append(ch[last]);
                    if (hasYellow(last)) y--;
                    if (hasRed(last)) r--;
                    if (hasBlue(last)) b--;
                }
                
                if (hasRed(first) && hasRed(last)) {
                    answer = "IMPOSSIBLE";
                } else if (hasYellow(first) && hasYellow(last)) {
                    answer = "IMPOSSIBLE";
                } else if (hasBlue(first) && hasBlue(last)) {
                    answer = "IMPOSSIBLE";
                }
                
                if (answer == null) {
                    answer = S.toString();
                }
            }
            
            sb.append("Case #").append(t_i).append(": ").append(answer).append("\n");
        }

        Files.write(Paths.get("src/codejam/unicorn/out.out"), sb.toString().getBytes());
        System.out.println(sb.toString());
    }

    private static boolean hasRed(int c) {
        return c == 5 || c == 0 || c == 1;
    }
    private static boolean hasYellow(int c) {
        return c == 1 || c == 2 || c == 3;
    }
    private static boolean hasBlue(int c) {
        return c == 3 || c == 4 || c == 5;
    }
}
