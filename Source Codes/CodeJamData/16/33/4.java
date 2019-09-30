import java.util.*;

public class C {

    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int T = in.nextInt();
        for (int C = 1; C <= T; C++) {
            System.out.println("Case #" + C + ": " + solve());
        }
    }

    public static String solve() {
        String out = "";
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), limit = in.nextInt();
        int[] abT = new int[201];
        int[] bcT = new int[201];
        int[] acT = new int[201];

        int count = 0;

        for (int i = a; i >= 1; i--) {
            for (int j = b; j >= 1; j--) {
                for (int kk = c; kk >= 1; kk--) {
                    int k = (kk + (i) + (j)) % c;
                    k++;
                    //if (k > c) k = 1;
                    int ab = i * 15 + j;
                    int ac = i * 15 + k;
                    int bc = j * 15 + k;
                    if (abT[ab] < limit && bcT[bc] < limit && acT[ac] < limit) {
                        //System.out.println(i + "" + j + "" + k + " " + abT[ab] + " " + acT[ac] + " " + bcT[bc]);
                        out += "\n" + i + " " + j + " " + k;
                        count++;
                        abT[ab]++;
                        bcT[bc]++;
                        acT[ac]++;
                        //System.out.println(acT[23]);
                        //System.out.println(i + "" + j + "" + k + " " + abT[ab] + " " + acT[ac] + " " + bcT[bc]);
                    } else {
                        //System.out.println(acT[23]);
                        //System.out.println(i + "" + j + "" + k + " " + abT[ab] + " " + acT[ac] + " " + bcT[bc]);
                    }
                }
            }
        }
        System.err.println(count);
        return count + "" + out;
    }
}
