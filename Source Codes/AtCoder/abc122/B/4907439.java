import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// ?????
		String b = sc.next();
		int max=0;
		for (int i = 0; i < b.length()+1; i++) {
			for (int j = 0; j < b.length()-i+1; j++) {
				outside:for (int j2 = 0; j2 < b.length()-i-j; j2++) {
					if (!(b.startsWith("A",j2+i))&&!(b.startsWith("T",j2+i))&&!(b.startsWith("C",j2+i))&&!(b.startsWith("G",j2+i))) {
						break outside;
					}
					else if (j2+1== b.length()-i-j&&max<j2+1) {
						max=j2+1;
					}
				}
			}
		}
		System.out.println(max);
  }
}