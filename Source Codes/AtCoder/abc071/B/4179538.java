import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<String> s = Arrays.asList(sc.next().split(""));
        Collections.sort(s);
        Set<String> set = new HashSet<>(s);
        char alphabet = 'a';
        for (int i = 0; i < 26; i++) {
            if (!set.contains(String.valueOf(alphabet))) {
                System.out.println(alphabet);
                return;
            }
            alphabet++;
        }
        System.out.println("None");
    }

}