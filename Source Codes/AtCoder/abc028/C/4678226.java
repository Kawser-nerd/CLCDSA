import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int[] values = new int[5];
        for (int i = 0; i < 5; i++) {
            values[i] = sc.nextInt();
        }

        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                for (int k = j + 1; k < 5; k++) {
                    set.add(values[i] + values[j] + values[k]);
                }
            }
        }

        int index = 0;
        for (Integer value: set) {
            index++;
            if (index == (set.size() - 2)) System.out.println(value);
        }
    }
}