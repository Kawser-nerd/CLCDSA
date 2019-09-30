import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class CodeJam2014R1C2Large {

    private static boolean used[];
    private static String values[];
    private static List<String> words;

    private static long total = 1;
    private static long MODULO = 1000000007;

    public static void main(String[] args) {
        try {
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-small.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("B-small.out"));
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("B-large.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("B-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                int N = Integer.parseInt(line);
                line = br.readLine();
                values = line.split(" ");

                removeOneLetterWords();

                if (validWords()) {
                    pw.println("Case #" + (i + 1) + ": " + count());
                } else {
                    pw.println("Case #" + (i + 1) + ": " + 0);
                }

            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static void removeOneLetterWords() {
        boolean removed[] = new boolean[values.length];
        Set<String> linkedWords = new HashSet<String>();
        for (int i = 0; i < removed.length; i++) {
            removed[i] = false;
        }
        total = 1;
        for (char c = 'a'; c <= 'z'; c++) {
            int count = 0;
            for (int j = 0; j < values.length; j++) {
                if (!removed[j] && isOneLetter(values[j], c)) {
                    count++;
                    removed[j] = true;
                    linkedWords.add("" + c);
                }
            }
            for (int i = 1; i <= count; i++) {
                total *= i;
                total %= MODULO;
            }
        }
        words = new ArrayList<String>();
        for (String word : linkedWords) {
            words.add(word);
        }
        for (int i = 0; i < values.length; i++) {
            if (!removed[i]) {
                words.add(values[i]);
            }
        }

    }

    private static boolean isOneLetter(String value, char c) {
        for (int i = 0; i < value.length(); i++) {
            if (value.charAt(i) != c) {
                return false;
            }
        }
        return true;
    }

    private static boolean validWords() {
        for (String value : values) {
            if (!validWord(value)) {
                return false;
            }
        }
        return true;
    }

    private static boolean validWord(String value) {
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            int j = i - 1;
            while (j >= 0 && value.charAt(j) == c) {
                j--;
            }
            while (j >= 0) {
                if (value.charAt(j) == c) {
                    return false;
                }
                j--;
            }
        }
        return true;
    }

    private static long count() {
        boolean found = false;
        String first = "", second = "";
        int x = 0, y = 0;
        for (int i = 0; i < words.size(); i++) {
            first = words.get(i);
            for (int j = 0; j < words.size(); j++) {
                if (i != j) {
                    second = words.get(j);
                    if (first.charAt(first.length() - 1) ==  second.charAt(0)) {
                        if (!canAdd(first, second)) {
                            return 0;
                        }
                        else {
                            found = true;
                            x = i;
                            y = j;
                            i = words.size();
                            j = words.size();
                        }
                    }

                }
            }
        }
        if (!found) {

            for (int i = 0; i < words.size(); i++) {
                for (int j = 0; j < words.size(); j++) {
                    if (i != j && !canAdd(words.get(i), words.get(j))) {
                        return 0;
                    }
                }
            }

            for (int i = 1; i <= words.size(); i++) {
                total *= i;
                total %= MODULO;
            }
            return total;
        } else {
            words.set(x, first + second);
            words.remove(y);
            /*
            for (String word : words) {
                System.out.print(word + " ");
            }
            System.out.println();
*/
            return count();
        }
    }

    private static boolean canAdd(String s, String value) {
        char first = value.charAt(0);
        int last = s.length() - 1;
        while (last >= 0 && s.charAt(last) == first) {
            last--;
        }
        String tmp = s.substring(0, last + 1);
        for (char c : value.toCharArray()) {
            if (tmp.indexOf(c) != -1) {
                return false;
            }
        }
        return true;
    }

}
