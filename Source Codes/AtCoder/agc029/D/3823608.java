import java.util.*;

public class Main {
    static int H = 200000 + 11;
    static int W = 200000 + 11;
    static List<TreeSet<Integer>> heights = new ArrayList<>(H);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int n = sc.nextInt();
        for (int i = 0; i < w; i++) {
            if (i >= heights.size()) {
                heights.add(new TreeSet<Integer>());
            } else {
                heights.get(i).clear();
            }
            heights.get(i).add(h);
        }
        for (int i = 0; i < n; i++) {
            int h_i = sc.nextInt();
            int w_i = sc.nextInt();
            h_i -= 1;
            w_i -= 1;
            heights.get(w_i).add(h_i);
        }
        int current_h = 0, current_w = 0;
        int ans = h;
        while (current_h < h && current_w < w) {
            int hh = heights.get(current_w).higher(current_h);
            ans = Math.min(ans, hh);
            current_h += 1;
            if (heights.get(current_w).contains(current_h)) {
                break;
            }
            if (current_w + 1 >= w) {
                break;
            }
            if (!heights.get(current_w + 1).contains(current_h)) {
                current_w += 1;
            }
        }
        System.out.println(ans);
    }
}