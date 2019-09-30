import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] freq = new int[100002];
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt() + 1;
            freq[a - 1]++;
            freq[a]++;
            freq[a + 1]++;
        }
        System.out.println(Arrays.stream(freq).max().getAsInt());
    }
}