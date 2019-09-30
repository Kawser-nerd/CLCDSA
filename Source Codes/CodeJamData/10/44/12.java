import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.reverse;
import static java.lang.Integer.*;
import static java.lang.Long.parseLong;
import java.util.*;
import java.awt.geom.*;
import java.io.*;


//// Apache Jakarta Common Lang : http://commons.apache.org/lang/
//import org.apache.commons.lang.builder.*;

// java -Xmx1024m -Xss5m
@SuppressWarnings("unchecked")
public class D {
//    private static final String IMPOSSIBLE = "IMPOSSIBLE";
    private static final String NO = "IMPOSSIBLE";
    public static final long MAX = Long.MAX_VALUE;
    public static final int INF = 1000000000;
    public static final int MOD = 9901; 
    public static final int UNDEF = -3;

    /*
     * 
     */
    private void run(int caseNumber) throws Exception {
        /*
         * 
         */
        int n = INT();
        int m = INT();
//        int[] p = new int[n];
        XY[] p = new XY[n];
        for (int i = 0; i < p.length; i++) {
            p[i]=new XY(INT(),INT());
        }
//        int[] q = new int[m];
        XY[] q = new XY[m];
        for (int i = 0; i < q.length; i++) {
            q[i]=new XY(INT(),INT());
        }
        
        
        /// reading input done
        if(caseNumber<caseStart||caseNumber>caseEnd) {
            System.out.println("### skip case "+caseNumber);
            return;
        }

        
        /// start solving problem
        System.out.println("  p[" + p.length + "]=" + Arrays.toString(p));
        System.out.println("  q[" + q.length + "]=" + Arrays.toString(q));
        double ret = 1e100;
        double[] a = new double[m];
        for (int i = 0; i < a.length; i++) {
            a[i]=area(p,q,i);
        }
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < m; ++j) {
//                double v=area(p,q,i,j);
//                ret = Math.min(ret, v);
//            }
//        }
        
        out.printf("Case #%d: ", caseNumber);
        for (int i = 0; i < a.length; i++) {
            out.printf("%f ", a[i]);
        }
        out.println();
//        out.printf("Case #%d:", caseNumber);
//        out.println();
    }
    
    private double area(XY[] p, XY[] q, int i) {
        XY p0=p[0];
        XY p1=p[1];
        XY q0=q[i];
        XY q1=q[i];
        double r0=d(p0,q0);
        double r1=d(p1,q1);
        double d=d(p0,p1);
        if(d>=r0+r1) {
            return 0;
        }
        if(d<=abs(r0-r1)) {
            double r=min(r0,r1);
            return PI*r*r;
        }
        // 扇形面積 = pi*r*r * angle/(2pi) = angle*r*r/2
        double r = ar(r0, d,q0,p0,p1);
        r += ar(r1, d,q0,p1,p0);
        return r;
    }

    private double ar(double r0, double d, XY p0, XY p1, XY p2) {
        double cross=(p0.x-p1.x)*(p2.x-p1.x)+(p0.y-p1.y)*(p2.y-p1.y);
        double ang0=2*acos(cross/r0/d);
//        System.out.println("  ang0=" + ang0/PI*180);
        double a1=r0*r0/2*(ang0-sin(ang0));
        return a1;
    }
    
    private double area(XY[] p, XY[] q, int i, int j) {
        XY p0=p[0];
        XY p1=p[1];
        XY q0=q[i];
        XY q1=q[j];
        double r0=d(p0,q0);
        double r1=d(p1,q1);
        double d01=d(p0,p1);
        if(d01>=r0+r1) {
            return 0;
        }
        if(d01<=abs(r0-r1)) {
            double r=min(r0,r1);
            return PI*r*r;
        }
        
        
        
        return INF;
    }

    private double d(XY p1, XY q1) {
        
        return hypot(p1.x-q1.x, p1.y-q1.y);
    }

    class XY implements Comparable<XY> {
        int x;
        int y;

        public XY(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public int hashCode() {
            int M = 31, r = M + x;
            r = M * r + y;
            return (int) r;
        }

        public boolean equals(Object a) {
            if (a == null || getClass() != a.getClass())
                return false;
            XY o = (XY) a;
            return x == o.x && y == o.y;
        }

        public int compareTo(XY o) {
            // < : -1 smallest 1st
            if (x != o.x)
                return x < o.x ? -1 : 1;
            return y < o.y ? -1 : (y == o.y ? 0 : 1);
        }
    }

    
    static boolean printInput=false;
//    static boolean printInput=false; // print input case
    
    static boolean redirectStdoutToFile=false;
//    static boolean redirectStdoutToFile=true; // redirect all STDOUT to "output.txt"

    
    static boolean writeToFile=true;
//    static boolean writeToFile=false;
    
//    static String testFilename=null;
//    static String testFilename="D-test.in";
    static String testFilename="D-small-attempt0.in";
//    static String testFilename="D-small-attempt1.in";
//    static String testFilename="D-small.in";
//    static String testFilename="D-small-practice.in";
//    static String testFilename="D-large.in";
//    static String testFilename="D-large-practice.in";
    
    static String resultFilename=testFilename+"-res.txt";
    
    static BufferedReader in;
    static StringTokenizer inTok = new StringTokenizer("");

//    static Scanner in;
    static PrintWriter out;

    //control the cases to run : [caseStart..csaeEnd]
    static int caseStart=1;
//    static int caseStart=1;
    static int caseEnd=Integer.MAX_VALUE;
//    static int caseEnd=caseStart+0;
    
    public static void main(String[] args) throws Exception {
        long start = System.currentTimeMillis();

//        myTest();        
        
        // $0 inputFile caseStart caseEnd
        if(args.length>0) {
            testFilename = args[0];
        }
        if(args.length>1) {
            caseStart=parseInt(args[0]);
        }
        if(args.length>2) {
            caseEnd=parseInt(args[1]);
        }
        
        // redirect sys out
        if(redirectStdoutToFile) {            
            String filename = "output.txt";
            System.out.println("NOTE: redirect stdout to file "+filename);
            FileOutputStream fos = new FileOutputStream(filename);
            PrintStream ps = new PrintStream(fos,true);
            System.setOut(ps);
        }
        
        if(testFilename==null) {
            myTest();
        } else {
//          in = new BufferedReader(new InputStreamReader(System.in));
            in = new BufferedReader(new FileReader(testFilename));
            int NN=INT();
//            in = new Scanner(System.in);
//            in = new Scanner(new File(testFilename));
//            int NN=in.nextInt();
            out = writeToFile ? new PrintWriter(new FileWriter(resultFilename),true) 
                              : new PrintWriter(System.out, true);
            for (int i = 1; i <= NN; i++) {
//                out.printf("Case #%d: ", i);
                if (printInput) System.out.println("\n### Case "+i);                
                new D().run(i);
            }
            in.close();
            
            if(writeToFile) {
                out.close();
            }
        }
        
        System.out.println("\nTime taken: "+((System.currentTimeMillis()-start)/1000.0)+" sec");
        
        if(writeToFile) {
            File ans=new File(testFilename+"-ans.txt");
            if(ans.exists()&&ans.length()>0) {
                boolean same=sameFileContent(ans,new File(resultFilename));
                if(same) {
                    System.out.println("Answer correct :)");
                } else {
                    System.out.println("ERROR : Answer not matched");
                }
            }            
        }
    }
    
    private static boolean sameFileContent(File ansFile, File resFile) throws IOException {
        System.out.println();
        BufferedReader ans = new BufferedReader(new FileReader(ansFile));
        BufferedReader res = new BufferedReader(new FileReader(resFile));
        boolean ok=true;
        List<Integer> wrong = new ArrayList<Integer>();
        int ln=1;
        while(true) {
            String sAns=ans.readLine(); 
            String sRes=res.readLine();
            if(sAns==null) {
                if(sRes!=null) {
                    System.out.println("### result has more lines than answer");
                    do {
                        System.out.println(sRes);
                    } while ((sRes=res.readLine())!=null);
                    System.out.println();
                    ok=false;
                }
                break;
            }
            if(sRes==null) {
                if(sAns!=null && !sAns.isEmpty()) {
                    System.out.println("### answer has more lines than result");
                    do {
                        System.out.println(sAns);
                    } while ((sAns=ans.readLine())!=null);
                    System.out.println();
                    ok=false;
                }
                break;
            }
//            if(!sAns.equals(sRes)) {
            if(!sAns.trim().equals(sRes.trim())) {
                System.out.println("### line "+ln+" not match:");
                System.out.println("ans = "+sAns);
                System.out.println("res = "+sRes);
                System.out.println();
                ok=false;
                wrong.add(ln);
            }
            ln++;
        }
        if(!ok) {
            System.out.println("wrong : "+wrong.size()+" lines, lines start from 1: "+wrong);
            System.out.println("total : "+ln+" lines");
        }
        ans.close();
        res.close();
        return ok;
    }

    private static void myTest() throws Exception {
//        int num=-1000;
        int num=1000;
        for (int i = 1; i <= num; ++i) {
//            System.out.println(i+" : "+new D().small(Rn.i(0,50)));
//            for (int j = 1; j <= i; ++j) {
//                System.out.println(i+","+j+" : "+i);
//            }
        }
    }

    static String LINE() throws IOException {
        String s=in.readLine();
        if (printInput) System.out.println(s);
        return s;
    }
    static String STR() throws IOException {
        while (!inTok.hasMoreTokens()) {
            String line = LINE();
            if (line == null) {
                return null;
            }
            inTok = new StringTokenizer(line);
        }
        return inTok.nextToken();
    }

    static int INT() throws IOException { return Integer.parseInt(STR()); }
    static long LONG() throws IOException { return Long.parseLong(STR()); }
    static double DOUBLE() throws IOException { return Double.parseDouble(STR()); }
    
    static int INT(String s) { return Integer.parseInt(s); }
    static double DOUBLE(String s) { return Double.parseDouble(s); }
    static long LONG(String s) { return Long.parseLong(s); }
}
