import java.util.*;
import java.math.*;

public class B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        s.nextLine();
        for (int t = 1; t <= T; t++) {
            String line = s.nextLine();
            int loc = line.indexOf(' ');
            C = line.substring(0, loc).toCharArray();
            J = line.substring(loc + 1).toCharArray();
            n = C.length;
            ansC = new char[n];
            ansJ = new char[n];
            tmpAnsC = new char[n];
            tmpAnsJ = new char[n];
            diff = Long.MAX_VALUE;

            // Case 1 total equals

            if (valid(n)) {
                diff = 0;
                System.arraycopy(tmpAnsC, 0, ansC, 0, n);
                System.arraycopy(tmpAnsJ, 0, ansJ, 0, n);
            } else {
                for (int m = n - 1; m >= 0; m--) {
                    if (valid(m)) {
                        // C < J
                        boolean flag = false;
                        if (C[m] == '?') {
                            if (J[m] == '?') {
                                tmpAnsC[m] = '0';
                                tmpAnsJ[m] = '1';
                                flag = true;
                            } else if (J[m] != '0') {
                                tmpAnsC[m] = (char)(J[m] - 1);
                                tmpAnsJ[m] = J[m];
                                flag = true;
                            }
                        } else {
                            if (J[m] == '?') {
                                if (C[m] != '9') {
                                    tmpAnsC[m] = C[m];
                                    tmpAnsJ[m] = (char)(C[m] + 1);
                                    flag = true;
                                }
                            } else if (C[m] < J[m]) {
                                tmpAnsC[m] = C[m];
                                tmpAnsJ[m] = J[m];
                                flag = true;
                            }
                        }
                        if (flag) {
                            for (int i = m + 1; i < n; i++) {
                                if (C[i] == '?') {
                                    tmpAnsC[i] = '9';
                                } else {
                                    tmpAnsC[i] = C[i];
                                }
                                if (J[i] == '?') {
                                    tmpAnsJ[i] = '0';
                                } else {
                                    tmpAnsJ[i] = J[i];
                                }
                            }
                            // System.out.println("m:-->" + m + " " + new String(C) + " " + new String(J) + " " + new String(tmpAnsC) + " " + new String(tmpAnsJ));
                            check();
                        }

                        // C > J
                        flag = false;
                        if (J[m] == '?') {
                            if (C[m] == '?') {
                                tmpAnsJ[m] = '0';
                                tmpAnsC[m] = '1';
                                flag = true;
                            } else if (C[m] != '0') {
                                tmpAnsJ[m] = (char)(C[m] - 1);
                                tmpAnsC[m] = C[m];
                                flag = true;
                            }
                        } else {
                            if (C[m] == '?') {
                                if (J[m] != '9') {
                                    tmpAnsJ[m] = J[m];
                                    tmpAnsC[m] = (char)(J[m] + 1);
                                    flag = true;
                                }
                            } else if (J[m] < C[m]) {
                                tmpAnsC[m] = C[m];
                                tmpAnsJ[m] = J[m];
                                flag = true;
                            }
                        }
                        if (flag) {
                            for (int i = m + 1; i < n; i++) {
                                if (C[i] == '?') {
                                    tmpAnsC[i] = '0';
                                } else {
                                    tmpAnsC[i] = C[i];
                                }
                                if (J[i] == '?') {
                                    tmpAnsJ[i] = '9';
                                } else {
                                    tmpAnsJ[i] = J[i];
                                }
                            }
                            check();
                        }
                    }
                }
            }
            System.out.println(String.format("Case #%d: %s %s", t, new String(ansC), new String(ansJ)));
        }
        s.close();
    }

    public static void check() {
        long tmpC = Long.parseLong(new String(tmpAnsC)), tmpJ = Long.parseLong(new String(tmpAnsJ));
        long tmpDiff = Math.abs(tmpC - tmpJ);
        if (tmpDiff < diff || 
            (tmpDiff == diff && (tmpC < c || 
                (tmpC == c && tmpJ < j)))) {
            diff = tmpDiff;
            c = tmpC;
            j = tmpJ;
            System.arraycopy(tmpAnsC, 0, ansC, 0, n);
            System.arraycopy(tmpAnsJ, 0, ansJ, 0, n);
        }
    }

    public static boolean valid(int m) {
        boolean eq = true;
        int n = C.length;
        for (int i = 0; i < m; i++) {
            char ch = C[i];
            if (C[i] == '?' || J[i] == '?') {
                ch = '0';
                if (C[i] != '?') {
                    ch = C[i];
                } else if (J[i] != '?') {
                    ch = J[i];
                }
            } else if (C[i] != J[i]) {
                return false;
            }
            tmpAnsC[i] = tmpAnsJ[i] = ch;
        }
        return true;
    }

    public static long c = 0, j = 0, diff = Long.MAX_VALUE;
    public static char[] ansC, ansJ, tmpAnsC, tmpAnsJ, C, J;
    public static int n;
}