import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] ways = new int[200001];
        ArrayList<Integer> stones = new ArrayList<>();

        int current = sc.nextInt();
        stones.add(current);
        for(int i = 1; i < n; i++){
            current = sc.nextInt();
            if (current != stones.get(stones.size()-1)){
                stones.add(current);
            }


        }
        int [] count = new int[stones.size()];
        count[0] = 1;
        ways[stones.get(0)] = 1;
        for (int i = 1; i < stones.size();i++){
            count[i] = (count[i - 1] + ways[stones.get(i)]) % 1_000_000_007;
            ways[stones.get(i)] = count[i];
        }

        System.out.println(count[stones.size() - 1]);
    }
}