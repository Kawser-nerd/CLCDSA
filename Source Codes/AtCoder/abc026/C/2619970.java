import java.util.*;

public class Main {
    static int n;
    static int[] B;
    static List<Integer>[] team = new ArrayList[n];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        team = new ArrayList[n];
        for(int i = 0; i < n; i++) team[i] = new ArrayList<>();

        for(int i = 1; i < n; i++) {
            int b = in.nextInt()-1;
            team[b].add(i);
        }

        int ans = rec(0);
        System.out.println(ans);
    }

    static int rec(int t) {
        if(team[t].size() == 0) {
            return 1;
        }

        int max = 0;
        int min = Integer.MAX_VALUE;
        for(int c : team[t]) {
            int salary = rec(c);
            max = Math.max(salary, max);
            min = Math.min(salary, min);
        }
        return(max + min + 1);
    }
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.