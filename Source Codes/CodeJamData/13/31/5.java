import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    public static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    public void runOnce(Scanner input, PrintWriter output) {
        String line = input.nextLine();

        String s = line.substring(0, line.indexOf(" "));
        int n = Integer.parseInt(line.substring(line.indexOf(" ") + 1));

        int[] nextV = new int[s.length()];
        for (int i = s.length() - 1; i >= 0; i--) {
            if (isVowel(s.charAt(i))) {
                nextV[i] = i;
            } else {
                if (i == s.length() - 1) {
                    nextV[i] = s.length();
                } else {
                    nextV[i] = nextV[i + 1];
                }
            }
        }

        boolean[] isConsCons = new boolean[s.length()];
        for (int i = 0; i < s.length(); i++) {
            isConsCons[i] = (nextV[i] >= (i + n));
        }

        int[] nextConsCons = new int[s.length()];
        for (int i = s.length() - 1; i >= 0; i--) {
            if (isConsCons[i]) {
                nextConsCons[i] = i;
            } else {
                if (i == s.length() - 1) {
                    nextConsCons[i] = s.length();
                } else {
                    nextConsCons[i] = nextConsCons[i + 1];
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int nextCons = nextConsCons[i];
            if (nextCons == s.length()) {
                break;
            }
            int firstPos = nextCons + n - 1;
            ans += (s.length() - firstPos);
        }

        output.println(ans);
    }

    public void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();

        input.nextLine();
        for (int tt = 1; tt <= t; tt++) {
            if (tt % 100 == 0) {
                System.out.println("Test running: " + tt);
            }
            output.print("Case #" + tt + ": ");
            runOnce(input, output);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner input = new Scanner(System.in);
//        Scanner input = new Scanner(new File("A-small-attempt0.in"));
        Scanner input = new Scanner(new File("A-large.in"));

//        PrintWriter output = new PrintWriter(System.out);
//        PrintWriter output = new PrintWriter(new File("A-small.out"));
        PrintWriter output = new PrintWriter(new File("A-large.out"));

        new A().run(input, output);

        input.close();
        output.close();
    }
}
