import java.util.*;

public class Main {
    private static int N;
    private static int K;
    private static String S;

    public static void input(){
        Scanner scan = new Scanner(System.in);

        N = scan.nextInt();
        K = scan.nextInt();
        S = scan.next();
    }

    public static void main(String args[]) {
        //??
        input();

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        String[] s = new String[N - K + 1];
        int[] arr = new int[26];
        for (int i = 0; i <= N - K; i++) {
            if (i == 0) {
                for (int j = 0; j < N; j++) arr[S.charAt(j) - 'a']++;
            } else {
                arr[S.charAt(i - 1) - 'a']--;
                arr[S.charAt(i + K - 1) - 'a']++;
            }
            s[i] = Arrays.toString(arr);
            if (map.containsKey(s[i])) map.put(s[i], Math.max(map.get(s[i]), i));
            else map.put(s[i], i);
        }

        for (int i = 0; i <= N - K; i++) {
            if (map.get(s[i]) - i >= K) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}