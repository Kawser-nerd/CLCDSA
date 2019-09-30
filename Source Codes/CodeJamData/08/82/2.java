import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

/**
 * @author Pavel Mavrin
 * @id {Id}
 */
public class B {

    static Scanner in;
    static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("b.in"));
        out = new PrintWriter("b.out");
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            out.println("Case #" + (i + 1) + ": " + new B().solve());
            System.out.println("Test " + i + " of " + n);
        }
        out.close();
    }

    private Object solve() {
        int n = in.nextInt();
        Map<String, List<Offer>> map = new HashMap<String, List<Offer>>();
        for (int i = 0; i < n; i++) {
            String color = in.next();
            List<Offer> list = map.get(color);
            if (list == null) {
                list = new ArrayList<Offer>();
                map.put(color, list);
            }
            Offer offer = new Offer(in.nextInt() - 1, in.nextInt());
            list.add(offer);
        }

        List<List<Offer>> offers = new ArrayList<List<Offer>>();
        for (String s : map.keySet()) {
            offers.add(map.get(s));
        }
        while (offers.size() < 3) offers.add(new ArrayList<Offer>());

        int res = 1000000000;

        for (int i = 0; i < offers.size(); i++) {
            for (int j = i + 1; j < offers.size(); j++) {
                for (int k = j + 1; k < offers.size(); k++) {
                    List<Offer> q = new ArrayList<Offer>();
                    q.addAll(offers.get(i));
                    q.addAll(offers.get(j));
                    q.addAll(offers.get(k));
                    Collections.sort(q);
                    int rb = 0;
                    int rrb = 0;
                    int c = 0;
                    boolean good = true;
                    for (Offer offer : q) {
                        if (offer.l > rb) {
                            if (offer.l > rrb) {
                                good = false;
                                break;
                            }
                            c++;
                            rb = rrb;
                        }
                        rrb = Math.max(rrb, offer.r);
                    }
                    if (rb < 10000) {
                        c++;
                        rb = rrb;
                    }
                    if (good && rb == 10000) {
                        res = Math.min(res, c);
                    }
                }
            }
        }

        return res == 1000000000 ? "IMPOSSIBLE" : res;
    }

    class Offer implements Comparable<Offer> {
        Offer(int l, int r) {
            this.l = l;
            this.r = r;
        }

        int l;
        int r;

        public int compareTo(Offer o) {
            return l - o.l;
        }
    }
}
