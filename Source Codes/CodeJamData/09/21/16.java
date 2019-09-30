import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A.in"));
        PrintWriter out = new PrintWriter("A.out");

        int t = in.nextInt();in.nextLine();
        for (int tn = 0; tn < t; tn++) {
            out.println("Case #" + (tn + 1) + ": " + solve(in));
        }

        out.close();

    }

    private static String solve(Scanner in) {
        int m = in.nextInt();in.nextLine();
        String s = "";
        for (int i = 0; i < m; i++) {
            String ss = in.nextLine();
            s = s + " " + ss;
        }
        s = s.replaceAll(" ", "");

        input = s;

        Tree root = readTree();

        String res = "";

        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String name = in.next();
            int k = in.nextInt();
            Set<String> features = new HashSet<String>();
            for (int j = 0; j < k; j++) features.add(in.next());
            res += "\n" + calc(root, features);
        }


        return res;
    }

    private static double calc(Tree tree, Set<String> features) {
        if (tree.feature == null)
            return tree.p;
        else
            return tree.p * calc((features.contains(tree.feature) ? tree.left : tree.rigth), features);
    }

    static String input;

    private static Tree readTree() {
        input = input.substring(1);
        int i = 0;
        while ("0123456789.".indexOf(input.charAt(i)) >= 0) i++;
        double p = Double.parseDouble(input.substring(0, i));
        Tree res;
        if (input.charAt(i) == ')') {
            input = input.substring(i);
            res =  new Tree(p, null, null, null);
        } else {
            input = input.substring(i);
            i = 0;
            while (input.charAt(i) != '(') i++;
            String feature = input.substring(0, i);
            input = input.substring(i);
            res = new Tree(p, feature, readTree(), readTree());
        }
        input = input.substring(1);
        return res;
    }

    private static int count(String s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') res++;
            if (s.charAt(i) == ')') res--;
        }
        return res;
    }

    static class Tree {
        double p;
        String feature;
        Tree left;
        Tree rigth;

        Tree(double p, String feature, Tree left, Tree rigth) {
            this.p = p;
            this.feature = feature;
            this.left = left;
            this.rigth = rigth;
        }
    }
}