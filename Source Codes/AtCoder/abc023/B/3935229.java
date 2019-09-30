import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        ArrayList<String> s = new ArrayList<>();
        s.add("b");
        if (S.equals("b")) {
            System.out.println(0);
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (i % 3 == 1) {
                s.add(0, "a");
                s.add("c");
            } else if (i % 3 == 2) {
                s.add(0, "c");
                s.add("a");
            } else if (i % 3 == 0) {
                s.add(0, "b");
                s.add("b");
            }
            String ans[] = s.toArray(new String[s.size()]);
            if (String.join("", ans).equals(S)) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}