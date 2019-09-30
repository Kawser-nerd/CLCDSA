import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        
        int N = sc.nextInt();
        
        String base = "00";
        String h = base + (N / 3600);
        N %= 3600;
        
        String m = base + (N / 60);
        N %= 60;
        
        String s = base + N;
        
        
        System.out.println(h.substring(h.length()-2, h.length()) + ":" + m.substring(m.length()-2, m.length()) + ":" + s.substring(s.length()-2, s.length()));
    }
}