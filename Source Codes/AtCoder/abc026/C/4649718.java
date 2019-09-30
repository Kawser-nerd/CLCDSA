import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] boss = new int[N + 1];
        boss[0] = -1;

        Map<Integer, List<Integer>> members = new HashMap<Integer, List<Integer>>();

        for (int i = 1; i <= N - 1; i++) {
            int b = sc.nextInt();
            boss[i + 1] = b;

            List<Integer> member = new ArrayList<Integer>();
            if (members.containsKey(b)) {
                member = members.get(b);
            }
            member.add(i + 1);
            members.put(b, member);
        }

        Queue<Integer> checkMember = new ArrayDeque<Integer>();
        for (int i = 1; i <= N; i++) {
            if (!members.containsKey(i)) {
                checkMember.add(i);
            }
        }

        int[] salary = new int[N + 1];
        while (!checkMember.isEmpty()) {
            int n = checkMember.poll();

            if (!members.containsKey(n)) { // ???????
                salary[n] = 1;
            } else { // ???????
                int max = Integer.MIN_VALUE;
                int min = Integer.MAX_VALUE;
                for (Integer m : members.get(n)) {
                    max = Math.max(max, salary[m]);
                    min = Math.min(min, salary[m]);
                }
                salary[n] = max + min + 1;
            }

            if (!checkMember.contains(boss[n]) && boss[n] != -1) {
                checkMember.add(boss[n]);
            }
        }

        out.println(salary[1]);
    }
}