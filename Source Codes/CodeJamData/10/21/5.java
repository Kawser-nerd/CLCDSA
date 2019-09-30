import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    
    static class Tree {
        final String name;
        final ArrayList<Tree> a = new ArrayList<Tree>();
        Tree(String name) { this.name = name; }
        int size() {
            if (a.size() == 0) return 1;
            int ans = 1;
            for (Tree t : a) ans += t.size();
            return ans;
        }
        void out(String s) {
            System.out.println(s + name);
            for (Tree t : a) t.out(s + "  ");
        }
        void out() { out(""); }
    }
    
    static void add(Tree t, String d) {
        String[] ss = d.substring(1).split("/");
        for (String s : ss) {
            Tree w = null;
            for (Tree r : t.a) if (r.name.equals(s)) {
                w = r;
                break;
            }
            if (w == null) {
                w = new Tree(s);
                t.a.add(w);
            }
            t = w;
        }
    }
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("Main.in"));
        PrintWriter out = new PrintWriter(new File("Main.out"));
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            int n = in.nextInt();
            int m = in.nextInt();
            in.nextLine();
            Tree t = new Tree("");
            for (int i = 0; i < n; i++) {
                String d = in.nextLine();
                add(t, d);
            }
            int was = t.size();
            for (int i = 0; i < m; i++) {
                String d = in.nextLine();
                add(t, d);
            }
            out.println(t.size() - was);
        }
        out.close();
    }
}
