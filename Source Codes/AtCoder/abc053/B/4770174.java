import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        //        int n = sc.nextInt();
        String s = sc.next();

        int a = s.indexOf("A");
        int z = s.lastIndexOf("Z");

        String str = s.substring(a, z + 1);

        //        boolean ans = false;

        //        for (int i = 0; i < n; i++) {
        //
        //        }

        //        if (1200 <= n)
        //            ans = true;

        sc.close();

        System.out.println(str.length());
        //        System.out.println(ans ? "Yes" : "No");

    }
}