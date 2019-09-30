import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] w = new int[N];
        for (int i = 0; i < N; i++) {
            w[i] = sc.nextInt();
        }

        ArrayList<Integer> li = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int max = -1;

            int min = Integer.MAX_VALUE;
            int minIdx = -1;

            for (int j = 0; j < li.size(); j++) {
                if (li.get(j) > max) {
                    max = li.get(j);
                }

                if (li.get(j) < min && li.get(j) >= w[i]) {
                    minIdx = j;
                    min = li.get(j);
                }
            }

            if (w[i] > max) {
                li.add(w[i]);
            } else {
                li.set(minIdx, w[i]);
            }
        }

        System.out.println(li.size());
    }
}