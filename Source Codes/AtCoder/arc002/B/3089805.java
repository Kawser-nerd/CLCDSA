import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    String DATE = sc.next();
	    String[] splitDate = DATE.split("/");

	    boolean today = false;

	    int y = Integer.parseInt(splitDate[0]);
		int m = Integer.parseInt(splitDate[1]);
		int d = Integer.parseInt(splitDate[2]);

		int x = y/m;
		if(y%m != 0 || x%d !=0) {
			Calendar cl = Calendar.getInstance();

			cl.set(Calendar.YEAR, y);
			cl.set(Calendar.MONTH, m-1);
			cl.set(Calendar.DATE , d);

			outer:
				while (true) {
					cl.add(Calendar.DAY_OF_MONTH , 1);

					y = cl.get(Calendar.YEAR);
					m = cl.get(Calendar.MONTH) + 1;
					d = cl.get(Calendar.DATE);

					if ( y%m == 0 && y/m %d == 0) {
					System.out.println(String.format("%04d/%02d/%02d", y,m,d));
		            break outer;
					}
				}
		} else {
			System.out.println(DATE);
		}

	    sc.close();
	}

}