import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = Integer.parseInt(sc.nextLine());
        List<int[]> list = new ArrayList<>();
        // List???????????
        for (int i = 0; i < num; i++) {
            String[] str = sc.nextLine().split(" ");
            list.add(Stream.of(str).mapToInt(Integer::parseInt).toArray());
        }

        // ?????????????????????????
        double maxLength = 0;
        for (int i = 0; i < list.size(); i++) {
            int[] baseNums = list.get(i);
            for (int k = 0; k < list.size(); k++) {
                // ?????????????????
                if (i <= k) {
                    continue;
                }
                int[] targetNums = list.get(k);
                double xLength = Math.pow(Math.abs(baseNums[0] - targetNums[0]), 2);
                double yLength = Math.pow(Math.abs(baseNums[1] - targetNums[1]), 2);
                double sqrt = Math.sqrt(xLength + yLength);
                if (sqrt > maxLength) {
                    maxLength = sqrt;
                }
            }
        }
        System.out.println(maxLength);
    }
}