package A;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;

public class BotTrust {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("src/A/A-large.in"));
        String s = reader.readLine();
        int t = Integer.parseInt(s);
        PrintWriter writer = new PrintWriter("src/A/output.txt");
        for (int i = 0; i < t; i++) {
            s = reader.readLine();
            String[] ss = s.split("\\s+");
            int n = Integer.parseInt(ss[0]);
            Queue<Integer> qo = new ArrayDeque<Integer>();
            Queue<Integer> qb = new ArrayDeque<Integer>();
            Queue<Character> qcolor = new ArrayDeque<Character>();
            int po = 1;
            int pb = 1;
            for (int j = 0; j < n; j++) {
                char color = ss[j + j + 1].charAt(0);
                int pos = Integer.parseInt(ss[j + j + 2]);
                qcolor.add(color);
                if (color == 'B') {
                    qb.add(pos);
                } else {
                    qo.add(pos);
                }
            }
            qo.add(1);
            qb.add(1);
            int ans = 0;
            while (!qcolor.isEmpty()) {
                char color = qcolor.poll();
                if (color == 'B') {
                    int nb = qb.poll();
                    int moveb = Math.abs(pb - nb) + 1;
                    pb = nb;
                    ans += moveb;
                    int no = qo.peek();
                    int moveo = no - po;
                    if (Math.abs(moveo) > moveb) {
                        moveo = moveb * moveo / Math.abs(moveo);
                    }
                    po += moveo;
                } else {
                    int no = qo.poll();
                    int moveo = Math.abs(po - no) + 1;
                    po = no;
                    ans += moveo;
                    int nb = qb.peek();
                    int moveb = nb - pb;
                    if (Math.abs(moveb) > moveo) {
                        moveb = moveo * moveb / Math.abs(moveb);
                    }
                    pb += moveb;
                }
            }
            writer.println("Case #" + (i + 1) + ": " + ans);
        }
        writer.close();
    }
}
