// uses http://introcs.cs.princeton.edu/java/stdlib/StdIn.java
public class Train {
    
    static final int MOD = 1_000_000_007;

    public static long calc(String[] cars) {
        long result = 1;
        int n = cars.length;
    
        for (char ch = 'a'; ch <= 'z'; ch++) {
            //System.out.println(java.util.Arrays.toString(cars));
            int solocount = 0;
            int start = -1;
            int mid = -1;
            int end = -1;
            int solo = -1;
            for (int i=0; i<n; i++) {
                if (cars[i] == null) {
                }
                else if (cars[i].matches(""+ch+'+')) {
                    solocount++;
                    result *= solocount;
                    result %= MOD;
                    cars[i] = null;
                    solo = i;
                }
                else if (cars[i].matches(ch+"+[^"+ch+"]+")) {
                    if (start != -1) return 0;
                    start = i;
                }
                else if (cars[i].matches("[^"+ch+"]+"+ch+"+")) {
                    if (end != -1) return 0;
                    end = i;
                }
                else if (cars[i].matches("[^"+ch+"]+"+ch+"+[^"+ch+"]+")) {
                    if (mid != -1) return 0;
                    mid = i;
                }
                else if (cars[i].matches("[^"+ch+"]+")) {
                }
                else return 0;
            }
            //System.out.println(ch+" "+solocount+" "+start+" "+solo+" "+end+" "+result);
            if (mid == -1 && solocount == 0 && start == -1 && end == -1)
                continue;
            if (mid != -1 && (solocount > 0 || start != -1 || end != -1))
                return 0;
            if (mid != -1)
                continue;
            String repl = "";
            if (end != -1) {repl += cars[end]; cars[end] = null;}
            if (solo != -1) repl += ch;
            if (start != -1) {repl += cars[start]; cars[start] = null;}
            if (start != -1) {cars[start] = repl;}
            else if (solo != -1) {cars[solo] = repl;}
            else cars[end] = repl;
        }
        int left = 0;
        for (String s : cars) if (s != null) {
            left ++;
            result *= left; result %= MOD;
        }
        return result;
    }
    
    public static void main(String[] args) {
        int q = StdIn.readInt();
        for (int j=1; j<=q; j++) {
            int n = StdIn.readInt();
            String[] cars = new String[n];
            { for (int i=0; i<n; i++) cars[i] = StdIn.readString(); }
            System.out.printf("Case #%d: %d\n", j, calc(cars));     
        }
    }
}    