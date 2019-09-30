import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            Map<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < 2 * N - 1; i++) {
                for (int j = 0; j < N; j++) {
                    int height = sc.nextInt();
                    if (counts.containsKey(height)) {
                        counts.put(height, counts.get(height) + 1);
                    } else {
                        counts.put(height, 1);
                    }
                }
            }
            List<Integer> heights = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
                if (entry.getValue() % 2 != 0) {
                    heights.add(entry.getKey());
                }
            }
            Collections.sort(heights);
            System.out.print("Case #" + caseNum + ":");
            for (int h : heights) {
                System.out.print(" " + h);
            }
            System.out.println();
        }
    }
}
