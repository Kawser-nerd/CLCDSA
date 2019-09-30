import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
    static final long BASE = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        long[] factorial = new long[101];
        factorial[0] = 1;
        for (int i = 1; i < 101; i++) {
            factorial[i] = (factorial[i - 1] * i) % BASE;
        }

        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int N = sc.nextInt();
            String[] cars = new String[N];
            Set<Character> interior = new HashSet<Character>();
            int[] singleLetterStrs = new int[26];
            int[] starts = new int[26];
            int[] ends = new int[26];
            char[] next = new char[26];

            boolean possible = true;
            for (int i = 0; i < N; i++) {
                cars[i] = sc.next();
                int firstChar = cars[i].charAt(0) - 'a';
                char lastChar = cars[i].charAt(cars[i].length() - 1);
                if (isSingleLetter(cars[i])) {
                    int index = firstChar;
                    singleLetterStrs[index]++;
                } else {
                    for (Character ch : getInteriorChars(cars[i])) {
                        if (interior.contains(ch)) {
                            possible = false;
                            break;
                        }
                        interior.add(ch);
                    }
                    starts[firstChar]++;
                    ends[lastChar - 'a']++;
                    next[firstChar] = lastChar;
                }
            }

            int numGroups = 0;
            for (int i = 0; i < 26; i++) {
                if (!possible) {
                    break;
                }
                char ch = (char) ('a' + i);
                if (interior.contains(ch) && (singleLetterStrs[i] + starts[i] + ends[i] > 0)) {
                    possible = false;
                }
                if (starts[i] > 1 || ends[i] > 1) {
                    possible = false;
                }
                if (singleLetterStrs[i] > 0 && starts[i] == 0 && ends[i] == 0) {
                    numGroups++;
                } else if (starts[i] == 1 && ends[i] == 0) {
                    numGroups++;
                }
            }

            possible = possible && !hasCycles(next);

            System.out.print("Case #" + caseNum + ": ");
            if (!possible) {
                System.out.println(0);
                continue;
            }

            long ways = 1;
            for (int i = 0; i < 26; i++) {
                ways = (ways * factorial[singleLetterStrs[i]]) % BASE;
            }
            ways = (ways * factorial[numGroups]) % BASE;
            System.out.println(ways);
        }
    }

    private static boolean hasCycles(char[] next) {
        for (int i = 0; i < 26; i++) {
            if (next[i] == 0) {
                continue;
            }
            char start = (char) ('a' + i);
            int currIndex = i;
            while (next[currIndex] != 0 && next[currIndex] != start) {
                currIndex = next[currIndex] - 'a';
            }
            if (next[currIndex] == start) {
                return true;
            }
        }
        return false;
    }

    private static Set<Character> getInteriorChars(String str) {
        Set<Character> chars = new HashSet<Character>();
        if (isSingleLetter(str)) {
            return chars;
        }
        int startIndex = 0;
        while (str.charAt(startIndex + 1) == str.charAt(0)) {
            startIndex++;
        }
        int endIndex = str.length() - 1;
        while (str.charAt(endIndex - 1) == str.charAt(str.length() - 1)) {
            endIndex--;
        }
        for (int i = startIndex + 1; i < endIndex; i++) {
            chars.add(str.charAt(i));
        }
        return chars;
    }

    private static boolean isSingleLetter(String str) {
        char ch = str.charAt(0);
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) != ch) {
                return false;
            }
        }
        return true;
    }
}
