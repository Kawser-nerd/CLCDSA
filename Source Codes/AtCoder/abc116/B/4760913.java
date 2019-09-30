import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int s = sc.nextInt();
    int m = 1;
    for (int i = 0;i < 10000;i++) {
      if(s == 4 || s == 2 || s == 1) {
        break;
	  }
      if(s % 2 == 0) {
        s = s / 2;
        m = m + 1;
	  }
      else {
        s = (s * 3) + 1;
		m = m + 1;
	  }
	}
    m = m + 3;
	System.out.println(m);
  }
}