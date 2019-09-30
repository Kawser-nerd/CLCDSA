import java.util.HashSet;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        final Scanner cin = new Scanner(System.in);
        final int n = cin.nextInt();

        if (n == 3) {
            System.out.println("2 5 63");
        } else if (n == 4) {
            System.out.println("2 5 20 63");
        } else if (n == 5) {
            System.out.println("2 5 20 63 30");
        } else {
            HashSet<Integer> nums = new HashSet<>();
            int[] offset = new int[] {2, 3, 4, 6};
            int k = 0;
            int summary = 0;
            for (int i = 0; i < n; i++) {
                k = i / 4;
                int ai = k * 6 + offset[i % 4];
                nums.add(ai);
                summary += ai;
            }
            int next6k = (k + 1) * 6;
            if (nums.contains(next6k)) next6k += 6;
            int fraction = summary % 6;
            int[] candidateToRemove = new int [] {0, 0, 8, 9, 0, 9};
            int[] candidateToAppend = new int [] {
                    0, 0, (k + 1) * 6, (k + 1) * 6, 0, k * 6 + 4};
            if (fraction != 0) {
                nums.remove(candidateToRemove[fraction]);
                int append = candidateToAppend[fraction];
                if (nums.contains(append)) append += 6;
                nums.add(append);
            }
            System.out.println(
                    nums.stream().map((Integer i) -> i.toString()).collect(Collectors.joining(" ")));
        }

    }
}