import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

class Id {
    int i,j;
    Item b, t;

    Id(int i, int j, Item b, Item t) {
        this.i = i;
        this.j = j;
        this.b = b;
        this.t = t;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null) return false;

        Id id = (Id) o;

        if (i != id.i) return false;
        if (j != id.j) return false;
        if (b != null ? !b.equals(id.b) : id.b != null) return false;
        if (t != null ? !t.equals(id.t) : id.t != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = i;
        result = 31 * result + j;
        result = 31 * result + (b != null ? b.hashCode() : 0);
        result = 31 * result + (t != null ? t.hashCode() : 0);
        return result;
    }
}
class Item {
    long num;
    long type;

    Item(long num, long type) {
        this.num = num;
        this.type = type;
    }

    @Override
    public String toString() {
        return "{" +
                "num=" + num +
                ", type=" + type +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null) return false;

        Item item = (Item) o;

        if (num != item.num) return false;
        if (type != item.type) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = (int) (num ^ (num >>> 32));
        result = 31 * result + (int) (type ^ (type >>> 32));
        return result;
    }
}

public class Box {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                System.out.println("Case #" + (i + 1) + ": " + find(br));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static long find(BufferedReader br) throws IOException {
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        Item[] boxes = new Item[n];
        Item[] toys = new Item[m];

        s = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            boxes[i] = new Item(Long.parseLong(s[2*i]), Integer.parseInt(s[2*i+1]));
        }
        s = br.readLine().split(" ");
        for(int i = 0; i < m; i++) {
            toys[i] = new Item(Long.parseLong(s[2*i]), Integer.parseInt(s[2*i+1]));
        }
        HashMap<Id, Long> vv = new HashMap<Id, Long>();
        return find(boxes, toys, n-1, m-1, vv);
    }

    private static long find(Item[] boxes, Item[] toys, int i, int j, HashMap<Id, Long> vv) {
        if (i==-1 || j == -1) return 0;
        Id id = new Id(i, j, boxes[i], toys[j]);
        Long result = vv.get(id);
        if (result != null) return result;
        if (boxes[i].type == toys[j].type) {
            if (boxes[i].num > toys[j].num) {
                long used = toys[j].num;
                boxes[i].num -= used;
                toys[j].num -= used;
                long r = find(boxes, toys, i, j-1, vv);
                boxes[i].num += used;
                toys[j].num += used;
                vv.put(id, used+r);
                return used + r;
            } else {
                long used = boxes[i].num;
                boxes[i].num -= used;
                toys[j].num -= used;
                long r =find(boxes, toys, i-1, toys[j].num == 0 ? j-1 : j, vv);
                boxes[i].num += used;
                toys[j].num += used;
                vv.put(id, used+r);
                return used + r;
            }
        } else {
            long l = Math.max(find(boxes, toys, i-1, j, vv), find(boxes, toys, i, j-1, vv));
            vv.put(id, l);
            return l;
        }
    }

}
