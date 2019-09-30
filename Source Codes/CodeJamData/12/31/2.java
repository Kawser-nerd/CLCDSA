import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by IntelliJ IDEA.
 * User: yc14rp1
 * Date: 5/6/12
 * Time: 1:49 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test1_1 {

    private static final int LOGGING_LEVEL = 0;

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\z2.in";
        int firstTestCase = 1;
        int lastTestCase = 1000;
        try {
            // Open the file that is the first
            // command line parameter
            FileInputStream fstream = new FileInputStream(path);
            // Get the object of DataInputStream
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String strLine;
            //Read File Line By Line
            strLine = br.readLine();
            int tn = Integer.valueOf(strLine);
            for (int t = 1; t <= tn; t++) {
                strLine = br.readLine();
                String[] split = strLine.split(" ");
                int n = Integer.valueOf(split[0]);
                int[][] ps = new int[n][];
                for (int i = 0; i < n; i++) {
                    strLine = br.readLine();
                    split = strLine.split(" ");
                    int mi = Integer.parseInt(split[0]);
                    ps[i] = new int[mi];
                    for (int j = 0; j < mi; j++) {
                        ps[i][j] = Integer.parseInt(split[j + 1]);
                    }
                }
                if (t >= firstTestCase && t <= lastTestCase) {

                    String res = solve(n, ps);
                    System.out.println("Case #" + t + ": " + res);
                }
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static String solve(int n, int[][] ps) {
        for (int i = 0; i < n; i++) {
            Set<Integer> start = new HashSet<Integer>();
            start.add(i);
            Set<Integer> to_check = start;
            boolean flag = true;
            while (flag) {
                Set<Integer> added = new HashSet<Integer>();
                for (Integer j : to_check) {
                    sout(j+" "+ Arrays.deepToString(ps),1);
                    for (int p : ps[j]) {
                        if (start.contains(p-1)) {
                            return "Yes";
                        }
                        if (added.contains(p-1)) {
                            return "Yes";
                        } else {
                            added.add(p-1);
                        }
                    }
                }
                to_check = added;
                start.addAll(added);
                flag = added.size()>0;
            }
        }
        return "No";
    }

    private static void sout(String s, int level) {
        if (LOGGING_LEVEL >= level) {
            System.out.println(s);
        }
    }


}
