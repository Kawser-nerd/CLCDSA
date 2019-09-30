package year2017.qualification;

import java.awt.Point;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class FashionShow {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("D-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            final int N = in.nextInt();
            int M = in.nextInt();
            boolean[] rows = new boolean[N+1];
            boolean[] cols = new boolean[N+1];
            Set<Integer> diagPlus = new HashSet<Integer>();
            Set<Integer> diagMinus = new HashSet<Integer>();
            char[][] board = new char[N+1][N+1];
            int value = 0;
            for (int m=0; m<M; m++) {
                char s = in.next().charAt(0);
                int r = in.nextInt();
                int c = in.nextInt();
                board[r][c] = s;
                if (s == '+' || s == 'o') {
                    diagPlus.add(r+c);
                    diagMinus.add(r-c);
                    value++;
                }
                if (s == 'x' || s == 'o') {
                    rows[r] = true;
                    cols[c] = true;
                    value++;
                }
            }
            List<Point> list = new ArrayList<Point>(N*N);
            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++) {
                    list.add(new Point(r, c));
                }
            }
            Collections.sort(list, new Comparator<Point>() {
                public int compare(Point o1, Point o2) {
                    return cost(o1, N) - cost(o2, N);
                }
            });
            int c = 1;
            for (int r = 1; r<=N; r++) {
                if (!rows[r]) {
                    while (cols[c]) c++;
                    // insert r,c
                    rows[r] = true;
                    cols[c] = true;
                    if (board[r][c] == '+') {
                        board[r][c] = 'O';
                    } else {
                        board[r][c] = 'X';
                    }
                    value++;
                }
            }
            for (Point p : list) {
                if (!diagPlus.contains(p.x+p.y) && !diagMinus.contains(p.x-p.y)) {
                    // insert
                    diagPlus.add(p.x + p.y);
                    diagMinus.add(p.x - p.y);
                    if (board[p.x][p.y] == 'X' || board[p.x][p.y] == 'x') {
                        board[p.x][p.y] = 'O';
                    } else {
                        board[p.x][p.y] = 'P';
                    }
                    value++;
                }
            }

            int improved = 0;
            StringBuilder sb = new StringBuilder();
            for (int r=1; r<=N; r++) {
                for (c=1; c<=N; c++) {
                    char s = board[r][c];
                    if (s == 'X') {
                        sb.append("x " + r + " " + c + "\n"); improved++;
                    } else if (s == 'P') {
                        sb.append("+ " + r + " " + c + "\n"); improved++;
                    } else if (s == 'O') {
                        sb.append("o " + r + " " + c + "\n"); improved++;
                    }
                }
            }

            out.println("Case #"+(t+1)+": " + value + " " + improved);
            out.print(sb.toString());
        }

        out.close();
    }

    static int cost(Point p, int N) {
        int r = p.x - 1;
        int c = p.y - 1;
        return Math.min(r, c) + Math.min(N-p.x, c) + Math.min(r, N-p.y) + Math.min(N-p.x, N-p.y);
    }
    
}
