import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int P = sc.nextInt();
            int[] E = new int[P];
            int[] F = new int[P];
            for (int i = 0; i < P; i++) {
                E[i] = sc.nextInt();
            }
            int total = 0;
            for (int i = 0; i < P; i++) {
                F[i] = sc.nextInt();
                total += F[i];
            }
            int numElems = (int) (Math.log(total) / Math.log(2) + 0.5);
            List<Integer> S = new ArrayList<>();
            Map<Integer, Integer> frequencies = new HashMap<>();
            frequencies.put(0, 1);
            for (int i = 0; i < P; i++) {
                if (!frequencies.containsKey(E[i])) {
                    frequencies.put(E[i], 0);
                }
                while (frequencies.get(E[i]) < F[i]) {
                    S.add(E[i]);
                    Map<Integer, Integer> temp = new HashMap<>(frequencies);
                    for (Map.Entry<Integer, Integer> entry : frequencies.entrySet()) {
                        int sum = entry.getKey() + E[i];
                        if (temp.containsKey(sum)) {
                            temp.put(sum, entry.getValue() + frequencies.get(sum));
                        } else {
                            temp.put(sum, entry.getValue());
                        }
                    }
                    frequencies = temp;
                }
            }

            System.out.print("Case #" + caseNum + ":");
            for (int i : S) {
                System.out.print(" " + i);
            }
            System.out.println();
        }
    }
}
