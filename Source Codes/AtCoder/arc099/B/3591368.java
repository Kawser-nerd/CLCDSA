import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        sc.close();

        ArrayList<Long> ll = new ArrayList<Long>();
        ArrayList<Double> dl = new ArrayList<Double>();
        ll.add(1L);
        dl.add(1.0);

        for (int i = 2; i < 1002; i++) {
            int s = 0;
            int ti = i;
            for (int j = 0; j < 8; j++) {
                int div = (int) (Math.pow(10, 7 - j));
                if (ti >= div) {
                    int ts = ti / div;
                    s += ts;
                    ti -= ts * div;
                }
            }
            double f = (double) i / (double) s;
            // System.out.println(f + " " + i + " " + s);
            while (dl.get(dl.size() - 1) > f) {
                ll.remove(ll.size() - 1);
                dl.remove(dl.size() - 1);
            }
            ll.add((long) i);
            dl.add(f);
        }

        long nine = 0;
        int count = 0;
        // for (int i = 0; i < 1; i++) {
        //     nine += (long) (Math.pow(10, count)) * 9;
        //     nine += (long) (Math.pow(10, count + 1)) * 9;
        //     count += 2;
        //     for (int j = 1; j <= 99; j++) {
        //         long tl = nine + j * (long) (Math.pow(10, count));
        //         long stl = tl;
        //         long s = 0;
        //         for (int m = 0; m < 17; m++) {
        //             long div = (long) (Math.pow(10, 16 - m));
        //             if (tl >= div) {
        //                 long ts = tl / div;
        //                 s += ts;
        //                 tl -= ts * div;
        //             }
        //         }
        //         double f = (double) stl / (double) s;
        //         // System.out.println(f + " " + i + " " + s);
        //         while (dl.get(dl.size() - 1) > f) {
        //             ll.remove(ll.size() - 1);
        //             dl.remove(dl.size() - 1);
        //         }
        //         ll.add(stl);
        //         dl.add(f);
        //         // System.out.println(stl + " " + f);
        //     }
        // }

        nine = 0;
        count = 0;
        for (int i = 0; i < 15; i++) {
            nine += (long) (Math.pow(10, count)) * 9;
            count += 1;
            for (int j = 100; j <= 999; j++) {
                long tl = nine + j * (long) (Math.pow(10, count));
                long stl = tl;
                long s = 0;
                for (int m = 0; m < 17; m++) {
                    long div = (long) (Math.pow(10, 16 - m));
                    if (tl >= div) {
                        long ts = tl / div;
                        s += ts;
                        tl -= ts * div;
                    }
                }
                double f = (double) stl / (double) s;
                // System.out.println(f + " " + i + " " + s);
                while (dl.get(dl.size() - 1) > f) {
                    ll.remove(ll.size() - 1);
                    dl.remove(dl.size() - 1);
                }
                ll.add(stl);
                dl.add(f);
                // System.out.println(stl + " " + f);
            }
        }

        for (int i = 0; i < k; i++) {
            System.out.println(ll.get(i));
        }
    }
}