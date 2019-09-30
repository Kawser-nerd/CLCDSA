import java.util.HashMap;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashMap<String, Integer> map = new HashMap<>();
        map.put("Sunday", 0);
        map.put("Monday",5);
        map.put("Tuesday", 4);
        map.put("Wednesday", 3);
        map.put("Thursday", 2);
        map.put("Friday", 1);
        map.put("Saturday", 0);
        System.out.println(map.get(in.next()));
    }
}