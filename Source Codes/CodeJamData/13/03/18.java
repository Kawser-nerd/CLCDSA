import java.io.*;
import java.lang.String;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class C {
    private static List<BigInteger> values;

    private static void testValue(String s, PrintStream cout) { 
        BigInteger v = new BigInteger(s);
        BigInteger ans = v.multiply(v);
        String ansStr = ans.toString();
        for (int i = 0; i < ansStr.length(); ++i) {
            if (ansStr.charAt(i) != ansStr.charAt(ansStr.length() - 1 - i))
                return;
        }
        values.add(ans);
        // cout.printf("%s %s\n", s, ansStr);
    }

    private static void initializeValues(PrintStream cout) {
        values = new ArrayList<BigInteger>();
        values.add(new BigInteger("1"));
        values.add(new BigInteger("4"));
        values.add(new BigInteger("9"));
        for (int len = 2; len <= 50; ++len) {
            // cout.printf("%d\n", len);
            int bits = len / 2;
            for (int num = 0; num < (1 << bits); ++num) {
                int[] digits = new int[bits];
                int tmp = num, sum = 0;
                for (int j = 0; j < bits; ++j) {
                    digits[j] = tmp % 2;
                    sum += digits[j];
                    tmp = tmp / 2;
                }
                if (digits[bits - 1] == 0 || sum >= 6)
                    continue;
                String first = "", second = "";
                for (int j = 0; j < bits; ++j) {
                    first += digits[bits - 1 - j];
                    second += digits[j];
                }
                if (len % 2 == 0)
                    testValue(first + second, cout);
                else {
                    for (int j = 0; j <= 2; ++j)
                        testValue(first + j + second, cout);
                }

                first = ""; second = ""; digits[bits - 1] = 2;
                for (int j = 0; j < bits; ++j) {
                    first += digits[bits - 1 - j];
                    second += digits[j];
                }
                if (len % 2 == 0)
                    testValue(first + second, cout);
                else {
                    for (int j = 0; j <= 2; ++j)
                        testValue(first + j + second, cout);
                }
            }
        }
    }

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-large-2.in"));
		PrintStream cout = System.out;

        initializeValues(cout);
        // for (int i = 0; i < values.size(); ++i) {
        //    cout.printf("%s\n", values.get(i).toString());
        // }
        int numOfCases = Integer.parseInt(in.readLine());
		for (int caseNo = 1; caseNo <= numOfCases; ++caseNo) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			BigInteger a = new BigInteger(st.nextToken()), b = new BigInteger(st.nextToken());
            int ans = 0;
            for (int i = 0; i < values.size(); ++i) {
                if (a.compareTo(values.get(i)) != 1 && values.get(i).compareTo(b) != 1) {
                    ++ans;
                }
            }
            cout.printf("Case #%d: %s\n", caseNo, ans);
		}
		cout.flush();
	}
}


