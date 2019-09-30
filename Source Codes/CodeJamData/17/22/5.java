package year2017.round1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class StableNeighbors {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("B-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            int N = in.nextInt();
            int R = in.nextInt();
            int O = in.nextInt();
            int Y = in.nextInt();
            int G = in.nextInt();
            int B = in.nextInt();
            int V = in.nextInt();
            StringBuilder answer = new StringBuilder(); 
            if (B == O && B+O == N) {
                for (int i=0; i<B; i++) answer.append("BO");
            } else if (R == G && R+G == N) {
                for (int i=0; i<R; i++) answer.append("RG");
            } else if (V == Y && V+Y == N) {
                for (int i=0; i<V; i++) answer.append("VY");
            } else {
                boolean ok = true;
                if (B <= O && O > 0) {
                    ok = false;
                } else {
                    B -= O;
                }
                if (R <= G && G > 0) {
                    ok = false;
                } else {
                    R -= G;
                }
                if (Y <= V && V > 0) {
                    ok = false;
                } else {
                    Y -= V;
                }
                Data[] data = new Data[] {
                    new Data('B', B),
                    new Data('R', R),
                    new Data('Y', Y)
                };
                Arrays.sort(data, new Comparator<Data>() {
                    public int compare(Data o1, Data o2) {
                        int diff = o1.count - o2.count;
                        if (diff == 0) {
                            diff = o1.c - o2.c;
                        }
                        return diff;
                    }
                });
                int min = data[0].count;
                int mid = data[1].count;
                int max = data[2].count;
                if (mid + min < max) {
                    ok = false;
                }
                if (ok) {
                    int all = min - (max-mid);
                    for (int i=0; i<all; i++) {
                        answer.append(data[2].c).append(data[1].c).append(data[0].c);
                    }
                    for (int i=0; i<mid-all; i++) {
                        answer.append(data[2].c).append(data[1].c);
                    }
                    int rest = max-mid;
                    for (int i=0; i<rest; i++) {
                        answer.append(data[2].c).append(data[0].c);
                    }
                    StringBuilder sb = new StringBuilder();
                    for (char c : answer.toString().toCharArray()) {
                        if (c == 'B' && O > 0) {
                            for (int i=0; i<O; i++) {
                                sb.append("BO");
                            }
                            O = 0;
                        } else if (c == 'R' && G > 0) {
                            for (int i=0; i<G; i++) {
                                sb.append("RG");
                            }
                            G = 0;
                        } else if (c == 'Y' && V > 0) {
                            for (int i=0; i<V; i++) {
                                sb.append("YV");
                            }
                            V = 0;
                        }
                        sb.append(c);
                    }
                    answer = sb;
                } else {
                    answer.append("IMPOSSIBLE");
                }
            }
            out.println("Case #"+(t+1)+": " + answer);
        }

        out.close();
    }
    
    static class Data {
        Data(char c, int count) {
            this.c = c;
            this.count = count;
        }
        char c;
        int count;
    }
    
}
