import java.util.*;

public class Main {


    public static void main(String[] args) {
        new Main().execute();
    }

    private static final char BASE = '0';

    public void execute() {
        Scanner sc = new Scanner(System.in);
        final String S = sc.nextLine();
        System.out.println(dfs(S, 0,0));
        sc.close();

    }

    private long dfs(String S,long current, int pos) {
        current = current * 10 + (long) (S.charAt(pos) - BASE);
        if (pos == S.length() - 1) {
//            System.out.println(current);
            return current;
        }
        int depth = (S.length() - pos -2);
        long a = (current << depth) + dfs(S, 0, pos + 1);
        long b =  dfs(S, current, pos + 1);
        return a + b;

    }
}