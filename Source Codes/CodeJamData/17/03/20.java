package year2017.qualification;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.SortedMap;
import java.util.TreeMap;

public class BathroomStalls {
    
    public static void main(String[] args) throws Exception {
        File inputFile = new File("C-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            long N = in.nextLong();
            long K = in.nextLong();
            long max = -1;
            long min = -1;
            SortedMap<Long,Long> map = new TreeMap<Long,Long>();
            map.put(N, 1L);
            while (true) {
                long last = map.lastKey();
                long lastCount = map.remove(last);
                last--;
                long half = last/2;
                Long count = map.get(half);
                if (count == null) count = 0L;
                count += lastCount;
                map.put(half, count);
                long secondHalf = last-half;
                count = map.get(secondHalf);
                if (count == null) count = 0L;
                count += lastCount;
                map.put(secondHalf, count);
                K -= lastCount;
                if (K <= 0) {
                    max = Math.max(half, secondHalf);
                    min = Math.min(half, secondHalf);
                    break;
                }
            }
            
            out.println("Case #"+(t+1)+": " + max + " " + min);
        }

        out.close();
    }
    
}
