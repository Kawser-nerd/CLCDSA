import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> list = new ArrayList<>();
        list.add("a");
        list.add("b");
        list.add("c");
        Set<String> set = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            List<String> list2 = new ArrayList<>();
            for (int j = 0; j < list.size(); j++) {

                for (int k = 0; k < 3; k++) {
                    if (k == 0) {
                        String s = list.get(j);
                        list2.add(s + "a");
                    } else if (k == 1) {
                        String s = list.get(j);
                        list2.add(s + "b");
                    } else {
                        String s = list.get(j);
                        list2.add(s + "c");
                    }
                }
            }
            list.addAll(list2);
        }
        set.addAll(list);
        for (String string : set) {
            if (string.length() == n) {
                System.out.println(string);
            }
        }
    }

}