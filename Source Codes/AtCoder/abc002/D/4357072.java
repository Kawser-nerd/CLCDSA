import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        // ???????????????????????????x1 -> y1???????y1 -> x1???????
        HashMap<Integer, ArrayList<Integer>> relations = new HashMap<Integer, ArrayList<Integer>>();

        for (int i = 0; i < M; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();

            ArrayList<Integer> friends = new ArrayList<Integer>();
            if(relations.containsKey(x)){
                friends = relations.get(x);
            }
            friends.add(y);
            relations.put(x, friends);
        }

        int max = 1;
        for(int n = 1; n <= N; n++){
            if(relations.containsKey(n)) {  //??????????????
                max = Math.max(max, 1 + maxRelations(relations, relations.get(n)));
            }
        }
        out.println(max);
    }

    public static int maxRelations(HashMap<Integer, ArrayList<Integer>> relations, ArrayList<Integer> friends){
        int max = 1;
        for(int f: friends){
            if(relations.containsKey(f)) {
                ArrayList<Integer> mutualFriends = new ArrayList<Integer>();
                for(int fFriend: relations.get(f)) { //?????????
                    if(friends.contains(fFriend)){
                        mutualFriends.add(fFriend);
                    }
                }
                // ?????????????????
                if(mutualFriends.size() != 0) {
                    max = Math.max(max, 1 + maxRelations(relations, mutualFriends));
                }
            }
        }
        return max;
    }
}