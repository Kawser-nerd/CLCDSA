import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = Integer.parseInt(scanner.next());
        int K = Integer.parseInt(scanner.next());

        ArrayList<String> alphabet = new ArrayList<>();
        ArrayList<String> original = new ArrayList<>();

        String originalWord = scanner.next();

        for (int i = 0; i < N; i++) {
            alphabet.add(originalWord.substring(i, i + 1));
            original.add(originalWord.substring(i, i + 1));
        }
        alphabet.sort(Comparator.naturalOrder());

        int count = 0;
        String tmp = "";
        String confirm = "";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - i; j++) {
                String alpha = alphabet.get(j);
                tmp = tmp + alpha;
                alphabet.remove(alpha);
                for (int k = 0; k < tmp.length(); k++) {
                    String w = tmp.substring(k, k + 1);
                    String o = originalWord.substring(k, k + 1);
                    if (!w.equals(o)) {
                        count++;
                    }
                }
                count += check(alphabet, original, i + 1);

                if (count <= K) {
                    confirm = tmp;
                    count = 0;
                    break;
                } else {
                    alphabet.add(alpha);
                    alphabet.sort(Comparator.naturalOrder());
                    tmp = confirm;
                    count = 0;
                }
            }
        }
        System.out.println(confirm);
    }

    public static int check(ArrayList<String> alphabet, ArrayList<String> original, int startIndex) {

        int count = 0;
        ArrayList<String> word = new ArrayList<>();
        for (int i = 0; i < alphabet.size(); i++) {
            word.add(alphabet.get(i));
        }
        for (int i = startIndex; i < original.size(); i++) {
            String tmp = original.get(i);
            if (word.contains(tmp)) {
                word.remove(tmp);
            } else {
                count++;
            }
        }

        return count;
    }
}