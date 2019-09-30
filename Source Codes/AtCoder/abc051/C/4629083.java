import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sx = sc.nextInt();
        int sy = sc.nextInt();
        int tx = sc.nextInt();
        int ty = sc.nextInt();

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < (tx - sx); i++) {
            ans.append("R");
        }
        for (int i = 0; i < (ty - sy); i++) {
            ans.append("U");
        }
        for (int i = 0; i < (tx - sx); i++) {
            ans.append("L");
        }
        for (int i = 0; i < (ty - sy); i++) {
            ans.append("D");
        }

        // ?????
        ans.append("L");
        for (int i = 0; i < (ty - sy) + 1; i++) {
            ans.append("U");
        }
        for (int i = 0; i < (tx - sx) + 1; i++) {
            ans.append("R");
        }
        ans.append("D");

        // ?????
        ans.append("R");
        for (int i = 0; i < (ty - sy) + 1; i++) {
            ans.append("D");
        }
        for (int i = 0; i < (tx - sx) + 1; i++) {
            ans.append("L");
        }
        ans.append("U");
        System.out.println(ans);
    }
}