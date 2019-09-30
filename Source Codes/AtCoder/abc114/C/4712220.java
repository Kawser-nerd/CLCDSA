import java.util.Scanner;

public class Main {
    static int input;
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        input = Integer.parseInt(sc.next());


        System.out.println(dfs(0L));
    }


    public static int dfs(long s) {
        if (s > input) return 0;

        String strVal = String.valueOf(s);

        int val = 0;
        if (strVal.contains("3") && strVal.contains("5") && strVal.contains("7")) val = 1;

        val += dfs(s * 10 + 3);
        val += dfs(s * 10 + 5);
        val += dfs(s * 10 + 7);

        return val;
    }
}