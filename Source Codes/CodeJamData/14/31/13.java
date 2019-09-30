import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class CodeJam2014R1C1 {
    public static void main(String[] args) {
        try {
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("A-small.out"));
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("A-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split("/");
                long P = Long.parseLong(values[0]);
                long Q  = Long.parseLong(values[1]);
                long cmmdc = cmmdc(P, Q);
                P /= cmmdc;
                Q /= cmmdc;

                System.out.println(cmmdc);
                int total = 0;
                while (P < Q) {
                    P *= 2;
                    total++;
                }

                int result = total;
                while (P % Q != 0 && result < 40) {
                    P *= 2;
                    result++;
                }

                if (P % Q == 0) {
                    pw.println("Case #" + (i + 1) + ": " + total);
                } else {
                    pw.println("Case #" + (i + 1) + ": impossible");
                }
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static long cmmdc(long P, long Q) {
        return Q == 0 ? P : cmmdc(Q, P % Q);
    }
}
