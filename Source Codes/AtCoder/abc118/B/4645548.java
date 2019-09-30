import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int answers = sc.nextInt();
        int kinds = sc.nextInt();

        int[] likeCounts = new int[kinds + 1];
        Arrays.fill(likeCounts, 0);

        for (int i = 0; i < answers; i++) {
            int ansCount = sc.nextInt();
            for (int j = 0; j < ansCount; j++) {
                likeCounts[sc.nextInt()]++;
            }
        }

        System.out.println(IntStream.of(likeCounts).filter(i -> i == answers).count());

    }
}