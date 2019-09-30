import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Character> st = new LinkedList<>();
        String x = sc.next();
        for (char ch: x.toCharArray()) {
            if (ch == 'T' && !st.isEmpty() && st.getLast() == 'S') {
                st.removeLast();
            } else {
                st.addLast(ch);
            }
        }
        System.out.println(st.size());
    }
}