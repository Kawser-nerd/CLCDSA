import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a[][] = new int[n][2];
        int b[][] = new int[n][2];
        boolean used[] = new boolean[n];
        for (int i = 0; i < n; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i][0] = sc.nextInt();
            b[i][1] = sc.nextInt();
        }

        Arrays.sort(a, (o1, o2) -> o1[0] - o2[0]);
        Arrays.sort(b, (o1, o2) -> o1[0] - o2[0]);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
        	int pare = -1;
        	int maxy = 0;
            for (int j = 0; j < n && (a[j][0] < b[i][0]); j++) {
                if (used[j]) {
                    continue;
                }
                if (a[j][1] < b[i][1] && maxy <= a[j][1]) {
                    pare = j;
                    maxy = a[j][1];
                }
            }
            
            if (pare != -1) {
                used[pare] = true;
                cnt++;
            }
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}