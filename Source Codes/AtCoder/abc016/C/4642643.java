import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        HashMap<Integer, List<Integer>> relations = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < M; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            addRelations(A, B, relations);
            addRelations(B, A, relations);
        }

        for (int i = 1; i <= N; i++) {
            Set<Integer> friendOfFriend = new HashSet<Integer>();
            if (relations.containsKey(i)) {
                for (int f : relations.get(i)) {
                    if (relations.containsKey(f)) {
                        for (int ff : relations.get(f)) {
                            if (i == ff || relations.get(i).contains(ff)) {
                                continue;
                            }

                            friendOfFriend.add(ff);
                        }
                    }
                }
            }
            out.println(friendOfFriend.size());
        }
    }

    public static void addRelations(int A, int B, HashMap<Integer, List<Integer>> relations) {
        List<Integer> list = new ArrayList<Integer>();
        if (relations.containsKey(A)) {
            list = relations.get(A);
        }

        list.add(B);
        relations.put(A, list);
    }
}