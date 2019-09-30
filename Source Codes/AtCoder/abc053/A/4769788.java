import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        //        String s = sc.next();

        boolean ans = false;

        //        for (int i = 0; i < n; i++) {
        //
        //        }

        if (1200 <= n)
            ans = true;

        sc.close();

        System.out.println(ans ? "ARC" : "ABC");
        //        System.out.println(ans ? "Yes" : "No");

    }
}