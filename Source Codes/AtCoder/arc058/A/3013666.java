import java.io.BufferedInputStream;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        String N = scan.next();
        int K = scan.nextInt();
        HashSet<Integer> dis = new HashSet<>();
        for (int i=0;i<K;i++) dis.add(scan.nextInt());
        int low = 0;
        while (dis.contains(low)) low++;

        int[] num = new int[N.length()];
        for (int i=0;i<num.length;i++) num[i] = N.charAt(i) - '0';
        String res = dfs(dis, 0, num, low);
        if (res != null) {
            System.out.println(res);
            return;
        }
        int first = low;
        if (first == 0) {
            first++;
            while (dis.contains(first)) first++;
        }
        System.out.print(first);
        for (int i=0;i<num.length;i++) System.out.print(low);
        System.out.println();
    }

    private static String dfs(HashSet<Integer> dis, int idx, int[] num, int low) {
        if (idx == num.length) return "";
        int i = num[idx];
        while (dis.contains(i)) i++;
        if (i > 9) return null;
        if (i == num[idx]) {
            String next = dfs(dis, idx + 1, num, low);
            if (next != null) return "" + i + next;
            i++;
            while (dis.contains(i)) i++;
            if (i > 9) return null;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(i);
        for (int j=0;j<num.length-idx-1;j++) sb.append(low);
        return sb.toString();
    }
}