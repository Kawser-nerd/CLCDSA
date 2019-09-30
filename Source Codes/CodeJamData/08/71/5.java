import java.io.*;
import java.util.*;

public class A {
    PrintWriter out;
    Scanner in;

    public static void main(String[] args) throws Exception {
        new A().solve();
    }

    Map<String, Integer> nums = new HashMap();
    String[] names = new String[1010];
    List<String>[] ing = new List[1010];

    int go(String name) {
        int ind = nums.get(name);
        List<Integer> deps = new ArrayList();
        for (String dep : ing[ind]) {
            if (Character.isLowerCase(dep.charAt(0))) {
                //deps.add(1);
            } else {
                deps.add(go(dep));
            }
        }

        Collections.sort(deps);
        int ans = 0;
        for (int i = deps.size() - 1; i >= 0; --i) {
            int have = deps.size() - i - 1;
            have += deps.get(i);
            if (have > ans) {
                ans = have;
            }
        }
        ans = Math.max(ans, deps.size() + 1);
        //out.println("  " + name + " " + ans);
        return ans;
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("a.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("a.in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            int n = in.nextInt();
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                int m = in.nextInt();
                names[i] = s;
                nums.put(s, i);
                ing[i] = new ArrayList();
                for (int j = 0; j < m; ++j) {
                    ing[i].add(in.next());
                }
            }

            out.println(go(names[0]));
        }

        out.close();
    }
}
