import java.util.*;

public class Main {
    private static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        dfs(0, n);
        System.out.println(count);
    }

    private static void dfs (long l, int n){
        if (l > n){
            return;
        }

        String str = String.valueOf(l);
        if (str.contains("3") && str.contains("5") && str.contains("7")){
            count++;
        }

        dfs(10 * l + 3, n);
        dfs(10 * l + 5, n);
        dfs(10 * l + 7, n);
    }


}