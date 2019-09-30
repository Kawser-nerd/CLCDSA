import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.nextLine();
		
        // Date???
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
        Date date1=null;
        Date date2=null;
		try {
			date1 = sdf.parse(S);
	        date2 = sdf.parse("2019/04/30");
		} catch (ParseException e) {
			// TODO ??????? catch ????
			e.printStackTrace();
		}
        if(date1.compareTo(date2) == -1 || date1.compareTo(date2) == 0) {
        	System.out.println("Heisei");
        }
        else {
            System.out.println("TBD");
        }
	}
}