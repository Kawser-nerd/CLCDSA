import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class BL {

    private static final String FILE_NAME = "B-large";

    public static void main (String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME+".in"));
        Scanner scanner = new Scanner(in);
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME+"L.out"));
        int t = scanner.nextInt();
        for (int c = 1; c <= t; ++c) {
            int speedN = scanner.nextInt();
            long speedT = scanner.nextLong();
            int n = scanner.nextInt();
            int cc = scanner.nextInt();
            long totalTime = 0;
            List<Long> savedTimes = new ArrayList<Long>();
            int[] d = new int[cc];
            for (int i = 0; i < n; ++i) {
                int time;
                if (i < cc) {
                    d[i] = 2*scanner.nextInt();
                    time = d[i];
                } else {
                    time = d[i%cc];
                }
                if (totalTime >= speedT) {
                    savedTimes.add((long)time/2);
                } else if (totalTime+time > speedT) {
                    savedTimes.add(((totalTime+time)-speedT)/2);
                }
                totalTime += time;
            }
            Collections.sort(savedTimes);
            int len = savedTimes.size();
            for (int i = 0; i < speedN && i < len; ++i) {
                totalTime -= savedTimes.get(len-i-1);
            }
            StringBuilder ans = new StringBuilder();
            ans.append("Case #");
            ans.append(c);
            ans.append(": ");
            ans.append(totalTime);
            out.write(ans.toString()+"\n");
            System.out.println(ans.toString());
        }
        out.close();
    }
}
