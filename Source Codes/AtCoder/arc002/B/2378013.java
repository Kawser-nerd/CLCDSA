import java.util.Calendar;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] date = sc.next().split("/");
		Integer year = Integer.parseInt(date[0]);
		Integer month = Integer.parseInt(date[1]);
		Integer day = Integer.parseInt(date[2]);
		Calendar calendar = Calendar.getInstance();
		calendar.set(year,month-1,day);
		
		while (year%month!=0 || (year/month)%day!=0)  {
			calendar.add(Calendar.DATE, 1);
		    year = calendar.get(Calendar.YEAR);
		    month = calendar.get(Calendar.MONTH)+1;
		    day = calendar.get(Calendar.DATE);
		}
		
		String monthStr = month > 9 ? month.toString() : "0" + month.toString() ;
		String dayStr = day > 9 ? day.toString() : "0" + day.toString() ;
		System.out.println(year +"/"+ monthStr +"/"+ dayStr);
	}
}