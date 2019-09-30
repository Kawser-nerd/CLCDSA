import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int five = 0;
		int seven = 0;
		if (A == 5) {
		    five++;    
		} else if (A == 7) {
		    seven++;
		}
		if (B == 5) {
		    five++;    
		} else if (B == 7) {
		    seven++;
		}
		if (C == 5) {
		    five++;    
		} else if (C == 7) {
		    seven++;
		}
        if (five == 2 && seven == 1) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}