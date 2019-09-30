import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class killer {

    private List<String> words;
    private List<String> alphas;
    private List<String> best;
    private List<Integer> masks;
    private List<int[]> masks2;

    int maxNum;
    int maxNumIndex;

    private void solve() throws Exception {
        final Scanner in = new Scanner(new File("killer.in"));
        final PrintWriter pw = new PrintWriter("killer.out");

        final int testCnt = in.nextInt();

        for (int caseNum = 1; caseNum <= testCnt; ++caseNum) {

            final int n = in.nextInt();
            final int m = in.nextInt();
            words = new ArrayList<String>();
            alphas = new ArrayList<String>();
            best = new ArrayList<String>();
            masks = new ArrayList<Integer>();
            masks2 = new ArrayList<int[]>();

            for (int i = 0; i < n; ++i) {
                words.add(in.next());
            }
            for (int i = 0; i < m; ++i) {
                alphas.add(in.next());
            }

            for (String word : words) {
                int mask = 0;
                int[] mask2 = new int[26];
                int index = 0;
                for (char cChar : word.toCharArray()) {
                    mask |= 1 << (cChar - 'a');
                    mask2[cChar - 'a'] |= (1 << index);
                    ++index;
                }
                masks.add(mask);
                masks2.add(mask2);
            }

            for (String alpha : alphas) {

                maxNum = -1;
                maxNumIndex = -1;

                for (int size = 1; size <= 10; ++size) {

                    final List<Integer> cWords = new ArrayList<Integer>();
                    for (int i = 0; i < words.size(); ++i) {
                        if (words.get(i).length() == size) {
                            cWords.add(i);
                        }
                    }

                    if (cWords.isEmpty()) {
                        continue;
                    }
                    if (cWords.size() == 1) {
                        if (0 > maxNum || 0 == maxNum && cWords.get(0) < maxNumIndex) {
                            maxNum = 0;
                            maxNumIndex = cWords.get(0);
                        }
                        continue;
                    }

                    find(alpha, 0, cWords, 0);
                }
                best.add(words.get(maxNumIndex));
            }
            pw.printf("Case #%d:", caseNum);
            for (String word : best) {
                pw.printf(" %s", word);
            }
            pw.println();
        }
        pw.close();
        in.close();
    }

    private void find(String alpha, int pos, List<Integer> nums, int result) {

        if (result > maxNum || result == maxNum && !nums.isEmpty() && nums.get(0) < maxNumIndex) {
            maxNum = result;
            maxNumIndex = nums.get(0);
        }

        if (nums.size() <= 1 || pos >= 26) {
            return;
        }

        int hasMask = 0;
        int tMask = 1 << (alpha.charAt(pos) - 'a');
        for (int index : nums) {
            if ((masks.get(index) & tMask) != 0) {
                hasMask++;
            }
        }

        if (nums.size() - hasMask > 0 && hasMask > 0) {
            List<Integer> p0 = new ArrayList<Integer>();
            for (int index : nums) {
                if ((masks.get(index) & tMask) == 0) {
                    p0.add(index);
                }
            }

            find(alpha, pos + 1, p0, result + 1);
        }

        if (hasMask == 0) {
            find(alpha, pos + 1, nums, result);
        }
        Map<Integer, List<Integer>> lists = new HashMap<Integer, List<Integer>>();

        int cNum = alpha.charAt(pos) - 'a';
        for (int index : nums) {
            if ((masks.get(index) & tMask) != 0) {
                List<Integer> set = lists.get(masks2.get(index)[cNum]);
                if (set == null) {
                    set = new ArrayList<Integer>();
                    lists.put(masks2.get(index)[cNum], set);
                }
                set.add(index);
            }
        }

        for (Map.Entry<Integer, List<Integer>> list : lists.entrySet()) {
            if (list.getValue().size() > 1) {
                find(alpha, pos + 1, list.getValue(), result);
            }
        }
    }

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        new killer().solve();
    }

}
