import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashMap<Integer,Integer> map = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if(!map.containsKey(a)) map.put(a, 0);
            if(map.get(a) % 2 == 0) ans++;
            else ans--;
            map.put(a, map.get(a)+1);
        }

        System.out.println(ans);
        sc.close();
    }

}