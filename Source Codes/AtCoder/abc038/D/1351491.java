import java.util.*;

public class Main {    

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);                
        
        ArrayList<Pair> list = new ArrayList<>();
               
        int N = sc.nextInt();
        
        for (int i = 0; i < N; i++) {
                int w = sc.nextInt();
                int h = sc.nextInt();
                list.add(new Pair(w, h));
        }
            
            Collections.sort(list);

            int ans = 0;

            RMQ rmq = new RMQ(100010);

            for (int i = 0; i < N; i++) {
                int lower = rmq.query(0, list.get(i).y - 1);
                rmq.update(list.get(i).y, lower + 1);
                
                ans = Math.max(ans, lower + 1);
            }

            System.out.println(ans);        
    }              
}

class Pair implements Comparable<Pair> {
            int x;
            int y;

            public Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public int compareTo(Pair p) {
                return x == p.x ? p.y - y : x - p.x;
            }
}
              
class RMQ{
       
        int n;
        int[] dat;

        public RMQ(int n1) {
            n = 1;

            while(n < n1)
              n *= 2;
            
            dat = new int[2 * n - 1];
            
        }

        public void update(int k, int a) {
            k += n - 1;
            dat[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                //dat[k] = Math.min(dat[k * 2 + 1], dat[k * 2 + 2]);
                dat[k] = Math.max(dat[k * 2 + 1], dat[k * 2 + 2]);
            }
        }

        public int query(int a, int b) {
            return query(a, b + 1, 0, 0, n);
        }

        private int query(int a, int b, int k, int l, int r) {
            //if (r <= a || b <= l) return Integer.MAX_VALUE;
            if (r <= a || b <= l) return 0;

            if (a <= l && r <= b) {
                return dat[k];
            } else {
                int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                //return Math.min(vl, vr);
                return Math.max(vl, vr);
            }
        }

    }