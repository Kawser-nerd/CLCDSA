import com.sun.corba.se.impl.orbutil.ObjectUtility;

import javax.print.attribute.standard.DateTimeAtCompleted;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;

public class B {
    public static void main(String[] args) throws Exception {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(
                    "b.in"
            )));
            int t = Integer.parseInt(in.readLine());

            PrintWriter out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
                    "bout.txt")));

            for (int tk = 0; tk < t; tk++) {
                String res = "";
                String[] data = in.readLine().split(" ");
                int n = Integer.parseInt(data[0]);
                int m = Integer.parseInt(data[1]);
                ArrayList<ArrayList<int[]>> a = new ArrayList<ArrayList<int[]>>();
                for (int i = 0; i < 12; i++) {
                    a.add(new ArrayList<int[]>());

                }
                ArrayList<String> words = new ArrayList<String>();
                for (int i = 0; i < n; i++) {
                    String word = in.readLine();
                    words.add(word);
                    int[] w = new int[28];
                    w[26] = i;
                    for (int j = 0; j < word.length(); j++) {
                        w[word.charAt(j)-'a'] += 1 <<j;
                    }
                    a.get(word.length()).add(w);
                }
                for (Iterator<ArrayList<int[]>> iterator = a.iterator(); iterator.hasNext(); ) {
                    ArrayList<int[]> next = iterator.next();
                    if (next.size() == 0)
                        iterator.remove();
                }
                for (int i = 0; i < m; i++) {
                    String dict = in.readLine();
                    for (ArrayList<int[]> ints : a) {
                        for (int[] anInt : ints) {
                            anInt[27] = 0;
                        }
                    }
                    res += words.get(process(dict, a)[26]) + " ";
                }

                System.out.println("tk = " + tk + " " + res);
                out.println("Case #" + (tk + 1) + ": " + res.trim());
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    static int[] process(String dict,  Collection<ArrayList<int[]>> a) {
        int[] best = null;
        int score = -1;
        int order = 10000000;
        for (ArrayList<int[]> set : a) {
            int[] w;
            if (set.size() == 1) {
                w = set.get(0);
            } else {
                int cur = 0;
                int s;
                while (true) {
                    boolean p = false;
                    s = dict.charAt(cur) - 'a';
                    for (int[] word : set) {
                        if (word[s] > 0) {
                            p =true;
                            break;
                        }
                    }
                    if (p)
                        break;
                    cur++;
                }
                HashMap<Integer, ArrayList<int[]>> b = new HashMap<Integer, ArrayList<int[]>>();
                for (int[] word : set) {
                    int v = word[s];
                    if (!b.containsKey(v)) {
                        b.put(v, new ArrayList<int[]>());
                    }
                    if (v ==0) {
                        word[27]++;
                    }
                    b.get(v).add(word);
                }
                w =  process(dict.substring(cur + 1), b.values());
            }

            if (score < w[27]) {
                score = w[27];
                order = w[26];
                best = w;
            }
            if (score == w[27] && order > w[26]) {
                score = w[27];
                order = w[26];
                best = w;
            }
        }
        return best;
    }

}
