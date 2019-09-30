import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            String S = sc.next();
            char ch = S.charAt(0);
            Deque<Character> chars = new ArrayDeque<>();
            chars.addLast(S.charAt(0));
            for (int i = 1; i < S.length(); i++) {
                char next = S.charAt(i);
                if (next >= chars.getFirst()) {
                    chars.addFirst(next);
                } else {
                    chars.addLast(next);
                }
            }
            System.out.print("Case #" + caseNum + ": ");
            for (Character c : chars) {
                System.out.print(c);
            }
            System.out.println();
        }
    }
}
