import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); in.nextLine();
        List<Pair> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            list.add(new Pair(in.nextLine()));
        }
        list.stream()
            .sorted(Comparator.comparing(Pair::getRev))
            .map(Pair::getStr).forEach(System.out::println);
    }
}

class Pair {
    String str;
    String rev;
    public Pair(String str) {
        this.str = str;
        this.rev = new StringBuilder(str).reverse().toString();
    }
    public String getStr() { return str; }
    public String getRev() { return rev; }
}