import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TrieSharding {
    //private static Scanner input = new Scanner(System.in);
    private static Scanner input;
    private static PrintWriter out;
    public static void main(String[] args) throws Exception {
        input = new Scanner(new FileReader("D-large.in"));
        out = new PrintWriter(new FileWriter("D-large.out"));
        choose = new int[101][101];
        for(int i=0;i<choose.length;i++) {
            choose[i][0] = 1;
            for(int j=1;j<=i;j++) {
                choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
            }
        }
        
        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ": " + solveCase());
        }
        out.close();
    }
    
    static class Node {
        //String prefix;
        List<Node> children = new ArrayList<Node>();
        public Node() { }
        public Node(String prefix, Set<String> match) {
            //this.prefix = prefix;
            if (match.contains(prefix))
                children.add(new Node());
            for(char next = 'A'; next <= 'Z'; next++) {
                String nextPrefix = prefix + next;
                Set<String> nextMatch = new HashSet<String>();
                for(String word: match)
                    if(word.startsWith(nextPrefix))
                        nextMatch.add(word);
                if(nextMatch.size() > 0) {
                    children.add(new Node(nextPrefix, nextMatch));
                }
            }
        }
        
        Answer solve() {
            Answer res = new Answer();
            int n = children.size();
            if(n == 0) {
                res.nodes = 0;
                res.sets = 1;
                res.ways = 1;
            } else {
                Answer[] childRes = new Answer[n];
                for(int i=0;i<n;i++) {
                    childRes[i] = children.get(i).solve();
                    res.sets = Math.min(MAX_SETS, res.sets + childRes[i].sets);
                    res.nodes += childRes[i].nodes;
                }
                res.nodes += res.sets;
                res.ways = computeWays(childRes, res.sets);
            }
            //out.println(prefix + " --> " + res);
            return res;
        }
    }
    static int computeWays(Answer[] children, int target) {
        memo = new int[children.length][target+1];
        for(int[] arr: memo)
            Arrays.fill(arr, -1);
        //out.println(Arrays.toString(children));
        return computeWays(children, target, 0, 0);
    }
    static int[][] memo, choose;
    static int computeWays(Answer[] children, int target, int index, int filled) {
        if(filled > target)
            return 0;
        if (index >= children.length)
            return filled == target ? 1 : 0;

        if (memo[index][filled] == -1) {
            int res = 0;
            for(int i = 0; i <= filled && i <= children[index].sets; i++) {
                int other = children[index].sets - i;
                res += (int)((long)computeWays(children, target, index + 1, filled + other) *
                        choose[filled][i] % MOD * choose[target-filled][other] % MOD *
                        children[index].ways % MOD);
                res %= MOD;
            }
            //out.println(index+ ", " +filled + " --> " +res);
            memo[index][filled] = res;
        }
        return memo[index][filled];
    }
    
    static class Answer {
        int sets, nodes, ways;
        public String toString() {
            return "(" + sets + ", " + nodes + ", " + ways + ")";
        }
    }
    
    static int MAX_SETS;
    static final int MOD = 1000000007;
    
    static String solveCase() {
        int m = input.nextInt();
        int n = input.nextInt();
        MAX_SETS = n;
        Set<String> words = new HashSet<String>();
        for(int i=0;i<m;i++)
            words.add(input.next());
        
        Node root = new Node("", words);
        Answer res = root.solve();

        return res.nodes + " " + res.ways;
    }

}
