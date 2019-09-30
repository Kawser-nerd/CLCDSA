import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    int n, k;
    char[] cs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        k = sc.nextInt();
        cs = sc.next().toCharArray();
        solve();
    }

    void solve() {
        SortedMap<Character, Integer> sMap = new TreeMap<>();
        SortedMap<Character, Integer> tMap = new TreeMap<>();
        for (int i = 0; i < cs.length; i++) {
            if (!sMap.containsKey(cs[i])) {
                sMap.put(cs[i], 1);
                tMap.put(cs[i], 1);
            } else {
                sMap.put(cs[i], sMap.get(cs[i]) + 1);
                tMap.put(cs[i], tMap.get(cs[i]) + 1);
            }
        }
        int count = 0;
        char[] ans = new char[cs.length];
        int i;
        for (i = 0; i < n; i++) {
            char first = tMap.firstKey();
            if (first == cs[i]) {
                if (sMap.get(first) == 1) {
                    sMap.remove(first);
                } else {
                    sMap.put(first, sMap.get(first) - 1);
                }
                if (tMap.get(first) == 1) {
                    tMap.remove(first);
                } else {
                    tMap.put(first, tMap.get(first) - 1);
                }
                ans[i] = first;
            } else {
                boolean flag = false;
                for (Map.Entry<Character, Integer> entry : tMap.entrySet()) {
                    int misMatch = cs.length - i - 1;
                    char c;
                    for (int j = 0; j < 26; j++) {
                        c = (char)(j + 'a');
                        int sNum = sMap.getOrDefault(c, 0);
                        int tNum = tMap.getOrDefault(c, 0);
                        if (c == cs[i]) {
                            sNum--;
                        }
                        if (c == entry.getKey()) {
                            tNum--;
                        }
                        misMatch -= Math.min(sNum, tNum);
                    }
                    if (count + 1 + misMatch <= k) {
                        flag = true;
                        ans[i] = entry.getKey();
                        if (entry.getKey() != cs[i]) {
                            count++;
                        }
                        if (sMap.get(cs[i]) == 1) {
                            sMap.remove(cs[i]);
                        } else {
                            sMap.put(cs[i], sMap.get(cs[i]) - 1);
                        }
                        if (tMap.get(entry.getKey()) == 1) {
                            tMap.remove(entry.getKey());
                        } else {
                            tMap.put(entry.getKey(), tMap.get(entry.getKey()) - 1);
                        }
                        break;
                    }
                }
                if (!flag) {
                    ans[i] = cs[i];
                    if (sMap.get(cs[i]) == 1) {
                        sMap.remove(cs[i]);
                    } else {
                        sMap.put(cs[i], sMap.get(cs[i]) - 1);
                    }
                    if (tMap.get(cs[i]) == 1) {
                        tMap.remove(cs[i]);
                    } else {
                        tMap.put(cs[i], tMap.get(cs[i]) - 1);
                    }
                }
            }
        }
        for (int j = 0; j < cs.length; j++) {
            System.out.print(ans[j]);
        }
        System.out.println();
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