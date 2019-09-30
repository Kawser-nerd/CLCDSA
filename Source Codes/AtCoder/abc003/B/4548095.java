import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        char[] sArr = sc.next().toCharArray();
        char[] tArr = sc.next().toCharArray();

        Set<Character> chars = new HashSet<>(Arrays.asList('@', 'a','t','c','o','d','e','r'));

        System.out.println(isWinner(chars, sArr, tArr) ? "You can win" : "You will lose");
    }

    static boolean isWinner(Set<Character> chars, char[] sArr, char[] tArr) {
        for (int i = 0; i < sArr.length; i++) {
            for (int j = 0; j < tArr.length; j++) {
                if (isValid(chars, sArr[i], tArr[i])) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    static boolean isValid(Set<Character> chars, char c1, char c2) {
        return (c1 == '@' && chars.contains(c2))
                || (c2 == '@' && chars.contains(c1))
                || (c1 == c2);
    }
}