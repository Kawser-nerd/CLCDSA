import java.util.*;

public class Main {
    static int r, c, k, n;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        r = in.nextInt();
        c = in.nextInt();
        k = in.nextInt();
        n = in.nextInt();
        int[] s = new int[n];
        int[] t = new int[n];
        int[] rCandies = new int[r];
        int[] cCandies = new int[c];
        for(int i = 0; i < n; i++) {
            int row = in.nextInt()-1;
            int col = in.nextInt()-1;
            s[i] = row;
            t[i] = col;
            rCandies[row]++;
            cCandies[col]++;
        }

        Map<Integer, Integer> mapH = new HashMap<>();
        Map<Integer, Integer> mapW = new HashMap<>();
        for(int i = 0; i < r; i++) mapH.merge(rCandies[i], 1, Integer::sum);
        for(int i = 0; i < c; i++) mapW.merge(cCandies[i], 1, Integer::sum);

        long ans = 0;
        for(Map.Entry<Integer, Integer> entry : mapH.entrySet()) {
            int key = entry.getKey();
            if(mapW.containsKey(k - key)) {
                ans += entry.getValue() * mapW.get(k - key);
            }
        }

        for(int i = 0; i < n; i++) {
            if(rCandies[s[i]] + cCandies[t[i]] == k) ans--;
            if(rCandies[s[i]] + cCandies[t[i]] == k+1) ans++;
        }

        System.out.println(ans);
    }
}