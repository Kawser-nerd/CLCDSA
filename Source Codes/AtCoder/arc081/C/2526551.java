import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    char[] cs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        cs = sc.next().toCharArray();
        solve();
    }

    void solve() {
        int[] used = new int[26];
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> occurrences = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            occurrences.add(new ArrayList<>());
        }
        for (int i = cs.length - 1; i >= 0; i--) {
            occurrences.get(cs[i] - 'a').add(i);
            used[cs[i] - 'a']++;
            boolean flag = true;
            for (int j = 0; j < used.length; j++) {
                if (used[j] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                list.add(i);
                Arrays.fill(used, 0);
            }
        }
        Collections.sort(list);
        list.add(cs.length);
        for (int i = 0; i < occurrences.size(); i++) {
            Collections.sort(occurrences.get(i));
        }
        //for (int i = 0; i < occurrences.get(0).size(); i++) {
            //System.out.print(" " + occurrences.get(0).get(i));
        //}
        //System.out.println();
        int index = 0;
        int currentPosition = 0;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            //System.out.println(i + " " + currentPosition);
            for (int j = 0; j < used.length; j++) {
                int nextOccurrence =
                        lower_bound(occurrences.get(j), currentPosition);
                if (nextOccurrence == occurrences.get(j).size()) {
                    ans.append((char)(j + 'a'));
                    break;
                }
                //System.out.println(index);
                //System.out.println(list.get(index) + " " + occurrences.get(j).get(nextOccurrence) + " " + list.get(index + 1));
                if (index < list.size() - 1) {
                    if (list.get(index) <= occurrences.get(j).get(nextOccurrence) &&
                            occurrences.get(j).get(nextOccurrence) < list.get(index + 1)) {
                        ans.append((char) (j + 'a'));
                        currentPosition = occurrences.get(j).get(nextOccurrence) + 1;
                        index++;
                        break;
                    }
                }
            }
            //System.out.println(ans);
        }
        System.out.println(ans);
    }

    static int lower_bound(List<Integer> arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        while (high - low >= 0) {
            int mid = (low + high) / 2;
            if (key <= arr.get(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}