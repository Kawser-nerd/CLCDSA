import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String day = scanner.next();
		if(day.equals("Monday")){
			System.out.println(5);
		}else if(day.equals("Tuesday")){
			System.out.println(4);
		}else if(day.equals("Wednesday")){
			System.out.println(3);
		}else if(day.equals("Thursday")){
			System.out.println(2);
		}else if(day.equals("Friday")){
			System.out.println(1);
		}else{
			System.out.println(0);
		}
	}
}