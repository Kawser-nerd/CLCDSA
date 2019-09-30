package round3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class C {
    public static void main(String[] args) throws FileNotFoundException {
        Kattio io;

//        io = new Kattio(System.in, System.out);
//        io = new Kattio(new FileInputStream("round3/C-sample.in"), System.out);
        io = new Kattio(new FileInputStream("round3/C-small-0.in"), new FileOutputStream("round3/C-small-0.out"));
//        io = new Kattio(new FileInputStream("round3/C-large-0.in"), new FileOutputStream("round3/C-large-0.out"));

        int cases = io.getInt();
        for (int i = 1; i <= cases; i++) {
            io.print("Case #" + i + ": ");
            new C().solve(io);
            System.err.println(i);
        }
        io.close();
    }

    public class Event {
        public int id;
        public boolean enter;

        public Event(int id, boolean enter) {
            this.id = id;
            this.enter = enter;
        }
    }

    List<Integer> ids;
    int best;

    private void solve(Kattio io) {
        int n = io.getInt();
        ids = new ArrayList<Integer>();
        Event[] events = new Event[n];
        for (int i = 0; i < n; i++) {
            String word = io.getWord();
            int id = io.getInt();
            if (id > 0 && !ids.contains(id)) ids.add(id);
            events[i] = new Event(id, word.equals("E"));
        }
        int next = 2001;
        while (ids.size() < 15) {
            ids.add(next++);
        }
        Collections.sort(ids);

        best = Integer.MAX_VALUE;
        go(events, 0, new HashSet<Integer>(), new HashSet<Integer>(), 2000);
        if (best == Integer.MAX_VALUE) {
            io.println("CRIME TIME");
        } else {
            io.println(best);
        }
    }

    private void go(Event[] events, int cur, Set<Integer> inside, Set<Integer> outside, int highest) {
        if (cur == events.length) {
            best = Math.min(best, inside.size());
            return;
        }
        int curId = events[cur].id;
        for (Integer id : ids) {
            if (id > highest+1) break;
            if (curId != 0 && curId != id) continue;

            if (events[cur].enter && inside.contains(id)) continue;
            if (!events[cur].enter && outside.contains(id)) continue;

            boolean wasOut = false, wasIn = false;
            if (events[cur].enter) {
                inside.add(id);
                wasOut = outside.remove(id);
            } else {
                outside.add(id);
                wasIn = inside.remove(id);
            }

            go(events, cur+1, inside, outside, Math.max(highest, id));

            if (events[cur].enter) {
                inside.remove(id);
                if (wasOut) outside.add(id);
            } else {
                outside.remove(id);
                if (wasIn) inside.add(id);
            }
        }
    }
}
