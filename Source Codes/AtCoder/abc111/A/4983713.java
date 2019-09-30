import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = 0;
		String s="";
		try {
			s = br.readLine();
			//n = Integer.parseInt(br.readLine());
		} catch (NumberFormatException | IOException e) {
			// TODO ??????? catch ????
			e.printStackTrace();
		}
		String[] str = new String[3];
		str = s.split("");
		//System.out.println(str[0]);
		List<Integer> ret = new ArrayList<Integer>();

		for(int j = 0; j<3;j++){
			if(str[j].equals("1"))ret.add(9);
			else ret.add(1);
		}

		String ans = String.valueOf(ret.get(0)) + String.valueOf(ret.get(1)) + String.valueOf(ret.get(2));
		System.out.println(ans);



	}
}