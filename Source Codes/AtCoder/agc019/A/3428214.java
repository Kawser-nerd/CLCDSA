import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
	final static String SHORT = "0.25";
	final static String TALL = "0.5";
	final static String GRANDE = "1";
	final static String VENTI = "2";

	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader ( new InputStreamReader(System.in));
		String [] input = br.readLine().split(" ");
		String  input2 = br.readLine();
		HashMap<String,Integer> iceTeaMap = new HashMap<String,Integer>();
		iceTeaMap.put(SHORT,Integer.parseInt(input[0]));
		iceTeaMap.put(TALL,Integer.parseInt(input[1]));
		iceTeaMap.put(GRANDE,Integer.parseInt(input[2]));
		iceTeaMap.put(VENTI,Integer.parseInt(input[3]));
		int max = Integer.parseInt(input2);
		long first =(long)( max / Double.parseDouble(SHORT));
		long second = 0;
		long third = 0;
		long forth = 0;
		//long sf = iceTeaMap.get(TALL)/iceTeaMap.get(SHORT);
		if(iceTeaMap.get(SHORT)*2 > iceTeaMap.get(TALL) ) {
			second = first/2;
			first = first%2;
		}
		if(second > 0) {
			if(iceTeaMap.get(TALL)*2 > iceTeaMap.get(GRANDE)) {
				third = second/2;
				second = second%2;
			}
		}else {
			if(iceTeaMap.get(SHORT)*4 > iceTeaMap.get(GRANDE)) {
				third = first/4;
				first = first%4;
			}
		}
		if(third > 0) {
			if(iceTeaMap.get(GRANDE)*2 > iceTeaMap.get(VENTI)) {
				forth = third/2;
				third = third%2;
			}
		}else if(second > 0) {
			if(iceTeaMap.get(TALL)*4 > iceTeaMap.get(VENTI)) {
				forth = second/4;
				second = second%4;
			}
		}else {
			if(iceTeaMap.get(SHORT)*8 > iceTeaMap.get(VENTI)) {
				forth = first/8;
				first = first%8;
			}
		}
		System.out.println(first * iceTeaMap.get(SHORT) + second * iceTeaMap.get(TALL) + third * iceTeaMap.get(GRANDE) + forth * iceTeaMap.get(VENTI));
	}
}