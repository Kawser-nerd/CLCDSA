import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main{
    private static final Map<Integer, String> MAPPING = new HashMap<Integer, String>() {{
        put(22, "Christmas Eve Eve Eve");
        put(23, "Christmas Eve Eve");
        put(24, "Christmas Eve");
        put(25, "Christmas");
    }};

    public static String process(TestCase testCase) {
        final int D = testCase.D;
        return MAPPING.get(D);
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int D = sc.nextInt();

        sc.close();
        return new TestCase(D);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int D;

        public TestCase(int D) {
            this.D = D;
        }
    }
}