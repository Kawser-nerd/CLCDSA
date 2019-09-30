import java.util.*;

public class Main {

    public static void main(String[] args) {

        Map<Integer, String> map = new HashMap<>();

        StringBuilder str = new StringBuilder("123456");
        for(int i=0; i<30; i++) {
            map.put(i, str.toString());
            int x = i % 5;
            int y = x + 1;
            char tmp = str.charAt(x);
            str.setCharAt(x, str.charAt(y));
            str.setCharAt(y, tmp);
        }

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt() % 30;

        System.out.println(map.get(n));
    }
}