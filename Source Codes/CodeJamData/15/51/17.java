package year2015.round3;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Fairland {
    static long D;
    
    public static void main(String[] args) throws Exception {
        Thread t = new Thread(null, new Runnable() {
            public void run() {
                try {
        File inputFile = new File("A-large.in");
        Scanner in = new Scanner(inputFile);
        File outputFile = new File("output2.txt");
        PrintWriter out = new PrintWriter(outputFile);

        int T = in.nextInt();
        for (int t=0; t<T; t++) {
            System.err.println(t);
            int N = in.nextInt();
            D = in.nextInt();
            long[] S = new long[N];
            long[] M = new long[N];
            S[0] = in.nextLong();
            long AS = in.nextLong();
            long CS = in.nextLong();
            long RS = in.nextLong();
            M[0] = in.nextLong();
            long AM = in.nextLong();
            long CM = in.nextLong();
            long RM = in.nextLong();
            for (int n=1; n<N; n++) {
                S[n] = (S[n-1]*AS+CS)%RS;
                M[n] = (M[n-1]*AM+CM)%RM;
            }
            Node[] nodes = new Node[N];
            for (int n=0; n<N; n++) {
                Node node = new Node();
                node.id = n;
                node.salary = S[n];
                nodes[n] = node;
            }
            for (int n=1; n<N; n++) {
                nodes[(int)(M[n]%n)].next.add(nodes[n]);
            }
            dfs(nodes[0], S[0]-D, S[0]);
            List<Event> events = new ArrayList<Event>();
            for (int n=1; n<N; n++) {
                if (nodes[n].min <= nodes[n].max) {
                    Event event = new Event();
                    event.start = true;
                    event.value = nodes[n].min;
                    events.add(event);
                    event = new Event();
                    event.value = nodes[n].max;
                    events.add(event);
                }
            }
            Collections.sort(events, new Comparator<Event>() {
                public int compare(Event o1, Event o2) {
                    long diff = o1.value-o2.value;
                    if (diff == 0) {
                        diff = (o1.start ? 0 : 1) - (o2.start ? 0 : 1);
                    }
                    return (int)Math.signum(diff);
                }
            });
            int max = 0;
            int current = 0;
            for (Event event : events) {
                if (event.start) {
                    current++;
                    max = Math.max(max, current);
                } else {
                    current--;
                }
            }

            out.println("Case #"+(t+1)+": "+(max+1));
        }

        out.close();

                } catch (Exception ex) {}
            }
        }, "", 100000000);
        t.start();
        t.join();
    }

    static class Event {
        boolean start;
        long value;
    }

    static void dfs(Node node, long min, long max) {
        node.min = Math.max(node.salary-D, min); 
        node.max = Math.min(node.salary, max);
        for (Node subNode : node.next) {
            dfs(subNode, node.min, node.max);
        }
    }

    static class Node {
        int id;
        List<Node> next = new ArrayList<Node>();
        long salary;
        long min;
        long max;
    }
    
}
