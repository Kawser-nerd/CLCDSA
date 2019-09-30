import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String c = sc.next();
        //        int[] A = new int[N];
        //        for (int i = 0; i < N; i++) {
        //            A[i] = sc.nextInt();
        //        }
        int[] ans = new int[4];
        for (int i = 0; i < N; i++) {
            //System.out.println(Character.getNumericValue(c.charAt(i)) - 1 + " " + c.charAt(i));
            ans[Character.getNumericValue(c.charAt(i)) - 1]++;
        }
        System.out.println(Math.max(ans[0], Math.max(ans[1], Math.max(ans[2], ans[3]))) + " "
                + Math.min(ans[0], Math.min(ans[1], Math.min(ans[2], ans[3]))));
        sc.close();
    }
}