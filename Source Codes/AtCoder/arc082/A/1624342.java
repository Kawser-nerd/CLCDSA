import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        int[] nums = new int[100000];
        int max = 0;

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(scanner.next());
            nums[tmp]++;
        }

        for (int i = 1; i < nums.length-1; i++) {
            max = Math.max(max, nums[i-1]+nums[i]+nums[i+1]);
        }

        System.out.println(max);
    }
}