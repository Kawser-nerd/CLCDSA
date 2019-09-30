import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int ans = 0;

        int tmp[] = new int[n];
        Arrays.fill(tmp, 100_001);

        for (int i = 0; i < n; i++) {
            Arrays.sort(tmp);

            int w = sc.nextInt();
            boolean canStack = false;
            for (int j = 0; j < ans; j++) {
                if (tmp[j] >= w) {
                    canStack = true;
                    tmp[j] = w;
                    break;
                }
            }

            if (!canStack) {
                tmp[ans++] = w;
            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            new Main().main(sc);
        } catch (Exception e) {
            throw e;
        }
    }
}