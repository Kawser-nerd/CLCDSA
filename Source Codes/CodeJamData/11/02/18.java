import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
public class B_small {

    public static void main(String[] args) throws Exception {
        new B_small();
    }

    public B_small() throws Exception {
        line = br.readLine();
        st = new StringTokenizer(line); 
        int caseCount = Integer.parseInt(st.nextToken());
        for (int caseNum = 1; caseNum <= caseCount; caseNum++) {
            String ans = null;

            line = br.readLine();
            st = new StringTokenizer(line);

            int[][] m = new int[26][26];
            int[][] r = new int[26][26];
            for (int i=0;i<26;i++) {
                Arrays.fill(m[i], -1);
                Arrays.fill(r[i], -1);
            }

            int c = Integer.parseInt(st.nextToken());
            for (int i=0;i<c;i++) {
                char s[] = st.nextToken().toCharArray();
                m[s[1]-'A'][s[0]-'A'] = m[s[0]-'A'][s[1]-'A'] = s[2]-'A';
            }
            int d = Integer.parseInt(st.nextToken());
            for (int i=0;i<d;i++) {
                char s[] = st.nextToken().toCharArray();
                r[s[1]-'A'][s[0]-'A'] = r[s[0]-'A'][s[1]-'A'] = 0;
            }

            int n = Integer.parseInt(st.nextToken());
            String input = st.nextToken();

            List<Character> list = new ArrayList<Character>();
            for (int i=0;i<n;i++) {
                char now = input.charAt(i);
                if (list.isEmpty()) 
                    list.add(now);
                else {
                    char last = list.get(list.size()-1);
                    if (m[last-'A'][now-'A']!=-1) {
                        list.remove(list.size()-1);
                        list.add((char)(m[last-'A'][now-'A']+'A'));
                    } else {

                        boolean clear = false;
                        for (char ch:list) {
                            if (r[ch-'A'][now-'A']==0) {
                                clear = true;
                                break;
                            }
                        }

                        if (clear) 
                            list.clear();
                        else
                            list.add(now); 
                    }
                }
                
            }

            ans = list.toString();
            

            buf.append(String.format("Case #%d: %s\n", caseNum, ans));
        }

        System.out.print(buf);
    }

    // {{{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line;
    StringTokenizer st;
    StringBuilder buf = new StringBuilder();

    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    } 
    // }}}
}
