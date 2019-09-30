import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
        boolean[] isVisited = new boolean[n+1];
        isVisited[0] = true;
        for(int i = 0; i < m; i++) {
            int num1 = sc.nextInt();
            int num2 = sc.nextInt();

            if(map.containsKey(num1)) {
                map.get(num1).add(num2);
            } else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(num2);
                map.put(num1, list);
            }

            if(map.containsKey(num2)) {
                map.get(num2).add(num1);
            } else {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(num1);
                map.put(num2, list);
            }

        }
        System.out.println(helper(map, isVisited, 1));
    }

    private static int helper(HashMap<Integer, ArrayList<Integer>> map, boolean[] isVisited, int current) {
        if(isVisited[current] || !map.containsKey(current)) return 0;
        isVisited[current] = true;
        if(check(isVisited)) {
            isVisited[current] = false;
            return 1;
        }
        ArrayList<Integer> list = map.get(current);
        int count = 0;
        for(int num: list) {
            count += helper(map, isVisited, num);
        }
        isVisited[current] = false;
        return count;
    }

    private static boolean check(boolean[] isVisited) {
        for(int i = 0; i < isVisited.length; i++) {
            if(!isVisited[i]) return false;
        }
        return true;
    }
}