import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        Deque<String> numDeque = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                numDeque.addFirst(sc.next());
            } else {
                numDeque.addLast(sc.next());
            }
        }
        Iterator<String> i = n % 2 == 0 ? numDeque.descendingIterator() : numDeque.iterator();
        while (i.hasNext()) {
            System.out.print(" " + i.next());
        }
    }
}