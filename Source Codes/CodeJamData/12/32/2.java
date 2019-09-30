import java.io.*;
import java.util.Arrays;

/**
 * Created by IntelliJ IDEA.
 * User: yc14rp1
 * Date: 5/6/12
 * Time: 1:52 AM
 * To change this template use File | Settings | File Templates.
 */
public class Test1_2 {

    private static final int LOGGING_LEVEL = 0;

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\YC14rp1\\Downloads\\ab.in";
        int firstTestCase = 1;
        int lastTestCase = 10000;
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
                Double dist = Double.valueOf(split[0]);
                int n = Integer.valueOf(split[1]);
                int m = Integer.valueOf(split[2]);
                double[] pt = new double[n];
                double[] px = new double[n];
                double[] aks = new double[m];
                for (int i = 0; i < n; i++) {
                    strLine = br.readLine();
                    split = strLine.split(" ");
                    pt[i] = Double.valueOf(split[0]);
                    px[i] = Double.valueOf(split[1]);
                }
                strLine = br.readLine();
                split = strLine.split(" ");
                for (int i = 0; i < m; i++) {
                    aks[i] = Double.valueOf(split[i]);
                }
                if (t >= firstTestCase && t <= lastTestCase) {
                    String res = "";
                    double badtime = getBadTime(dist, n, pt, px);
                    sout("t" + badtime, 1);
                    System.out.println("Case #" + t + ":");
                    for (int i = 0; i < m; i++) {
                        double sec = 0;
                        int cur = 0;

                        double max = 0;
                        for (int j = 1; j < n; j++) {
                            double cm;
                            if (px[j] < dist) {
                                double time = Math.sqrt(2 * px[j] / aks[i]);
                                cm = pt[j] - time;
                                sout("t " + (pt[j] - time) + time + " " + pt[j], 1);
                            } else {
                                cm = 0;
                            }
                            if (cm > max) {
                                max = cm;
                            }
                        }
                            sout("m " + max, 1);
                        // without bad
                        sout("aks " + i, 1);
                        double alltime = Math.sqrt(2 * dist / aks[i]);
                        res = String.valueOf(alltime);
                        sout(res, 1);
                        double v = alltime + max;
                        //sout(String.valueOf(v), 1);
                        if (v<badtime) {
                            v = badtime;
                        }
                        System.out.println(v);
                    }
//                    System.out.println("Case #" + t + ": " + dist+" "+Arrays.toString(pt) + Arrays.toString(px) + Arrays.toString(aks));
                }
            }
            //Close the input stream
            in.close();
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static double getBadTime(Double dist, int n, double[] pt, double[] px) {
        double time;
        for (int j = 0; j < n - 1; j++) {
            if (px[j] == dist) {
                return pt[j];
            }
            if (px[j + 1] == dist) {
                return pt[j + 1];
            }
            if (px[j] < dist) {
                if (px[j + 1] >= dist) {
                    sout(pt[j] + " " + dist + " " + px[j] + " " + px[j + 1] + " " + pt[j + 1] + " " + pt[j], 1);
                    return pt[j] + (((dist - px[j]) * (pt[j + 1] - pt[j])) / (px[j + 1] - px[j]));
                }
            }
        }
        return 0;
    }

    private static void sout(String s, int level) {
        if (LOGGING_LEVEL >= level) {
            System.out.println(s);
        }
    }


}
