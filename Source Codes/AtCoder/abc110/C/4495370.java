import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static final String YES = "Yes";
    public static final String NO = "No";

    public static String process(TestCase testCase) {
        final String S = testCase.S;
        final String T = testCase.T;

        Map<Character, Integer> sCharFreq = countCharFrequencies(S);
        Map<Character, Integer> tCharFreq = countCharFrequencies(T);

        Map<Integer, Integer> sFreqMap = toFreqMap(sCharFreq);
        Map<Integer, Integer> tFreqMap = toFreqMap(tCharFreq);

        return sFreqMap.equals(tFreqMap) ? YES : NO;
    }

    private static Map<Character, Integer> countCharFrequencies(String str) {
        Map<Character, Integer> map = new HashMap<>();
        str.chars().mapToObj(i -> (char) i).forEach(c -> {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        });
        return map;
    }

    private static Map<Integer, Integer> toFreqMap(Map<Character, Integer> charFreq) {
        Map<Integer, Integer> map = new HashMap<>();
        charFreq.values().forEach(c -> {
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        });
        return map;
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        String S = sc.next();
        String T = sc.next();

        return new TestCase(S, T);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final String S;
        final String T;

        public TestCase(String S, String T) {
            this.S = S;
            this.T = T;
        }
    }
}