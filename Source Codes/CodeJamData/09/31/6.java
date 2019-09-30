package rueustas;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class ProbA {
    public static void main(String[] args) throws IOException {
        FileReader reader = new FileReader(new File("a.in"));
        FileWriter writer = new FileWriter(new File("a.out"));
        BufferedReader in = new BufferedReader(reader);
        String tStr = in.readLine();
        int T = Integer.parseInt(tStr);
        List<Long> best = new ArrayList<Long>();
        best.add(Long.valueOf(1));
        best.add(Long.valueOf(0));
        for (int i = 2; i < 70; i++) {
            best.add(Long.valueOf(i));
        }
        for (int t = 1; t <= T; t++) {
            long V = 0;
            String alien = in.readLine().trim();
            Map<Character, Long> vals = new HashMap<Character, Long>();
            char[] a = alien.toCharArray();
            long max = 0;
            Iterator<Long> ite = best.iterator();
            for (char c : a) {
                Character cc = Character.valueOf(c);
                if (!vals.containsKey(c)) {
                    Long next = ite.next();
                    if (next.longValue() > max) {
                        max = next.longValue();
                    }
                    vals.put(cc, next);
                }
            }
            max++;
            for (char c : a) {
                V = V * max;
                V = V + vals.get(Character.valueOf(c));
            }
            writer.append("Case #" + String.valueOf(t) + ": " + V + "\r\n");
        }
        reader.close();
        writer.close();
    }
}