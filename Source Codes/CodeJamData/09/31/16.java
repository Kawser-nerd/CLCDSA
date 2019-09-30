package allyourbase;

import java.io.IOException;

public class Main extends Base {

    String alien;
    char app[];
    int apos;
    
    public static void main(String[] args) throws IOException {
        Main m = new Main();
        m.run("A", "large");        
    }

    @Override
    void init() {
        
    }

    @Override
    void load() {
        
    }

    void insert(char ch) {
        int i = 0;
        while (i < apos && app[i] != ch) i++;
        if (i < apos) return;
        app[apos] = ch;
        apos++;
    }
    
    @Override
    void solve() throws IOException {
        System.out.println("Case "+caseId);
        
        alien = br.readLine();
        System.out.println(alien);
        
        app = new char[alien.length()];
        apos = 0;
        for (int i = 0; i < alien.length(); i++) {
            insert(alien.charAt(i));
        }
        
        long base = apos;
        if (base == 1) base++;
        
        long res[] = new long[alien.length()];
        for (int i = 0; i < apos; i++) {
            int digit = i;
            if (digit == 0) digit = 1;
            else if (digit == 1) digit = 0;
            for (int j = 0; j < alien.length(); j++) {
                if (app[i] == alien.charAt(j)) {
                    res[j] = digit;
                }
            }
        }
        
        for (int i = 0; i < alien.length(); i++) {
            System.out.print(res[i]+" ");
        }
        System.out.println();
        
        long result = 0;
        long cur = 1;
        for (int j = res.length-1; j >= 0; j--) {
            result = result + cur*res[j];
            cur = cur*base;
        }
        printResult(""+result);
    }

}
