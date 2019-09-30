import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    static public final char[] n = new char[]{'M', 'A', 'R', 'C', 'H'};
    static public Map<Character, Integer> map = new HashMap<Character, Integer>();
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) map.put(n[i], 0);
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            char c = sc.next().toCharArray()[0];
            if(map.containsKey(c)) map.put(c, map.get(c) + 1);
        }
        long ans = 0;
        for (int i = 0; i < 3; i++) {
            if(map.get(n[i]) == 0) continue;
            for (int j = i + 1; j < 4; j++) {
                if(map.get(n[j]) == 0) continue;
                for (int k = j + 1; k < 5; k++) {
                    if(map.get(n[k]) == 0) continue;
                    ans += (long)map.get(n[i]) * map.get(n[j]) * map.get(n[k]);
                }
            }
        }

        System.out.println(ans);
        sc.close();
    }

}