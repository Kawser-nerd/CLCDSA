import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
        String[] line = s.split("", 10);
        int count = 0;
        int max = 0;
        for(int i=0; i<line.length; i++){
          for(int j=0; j<line.length; j++){
        	if(line[j].equals("A") || line[j].equals("T") || line[j].equals("G") || line[j].equals("C")) {
              count++;
              if(count > max) {
           		 max = count;
              }
            }
            else count = 0;
          }
          count = 0;
        }
		System.out.println(max);
	}
}