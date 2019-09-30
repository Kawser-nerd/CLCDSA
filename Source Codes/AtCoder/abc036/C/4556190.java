import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] a2 = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            a2[i] = a[i];
        }
        Arrays.sort(a2);
        int cnt = 1;
        int tmp = a2[0];
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(a2[0], 0);
        for (int i = 0; i < n; i++) {
            if (tmp != a2[i]) {
                cnt++;
                tmp = a2[i];
                map.put(a2[i], cnt - 1);

            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(map.get(a[i]));
        }
        sc.close();
    }
}