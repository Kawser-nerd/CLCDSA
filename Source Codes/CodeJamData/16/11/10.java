package Round1A2016;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final String word = sc.nextLine();
            Deque<Character> ans = new ArrayDeque<>();
            ans.addFirst(word.charAt(0));
            for (int i = 1; i < word.length(); ++i) {
                final char c = word.charAt(i);
                final char first = ans.getFirst();
                if (c >= first) {
                    ans.addFirst(c);
                } else {
                    ans.addLast(c);
                }
            }
            StringBuilder sb = new StringBuilder();
            for (Character c: ans) {
                sb.append(c);
            }
            System.out.printf("Case #%d: %s\n", testCase, sb.toString());
        }
    }
}