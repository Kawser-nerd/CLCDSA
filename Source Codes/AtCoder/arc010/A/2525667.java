import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader bfr=new BufferedReader(new InputStreamReader(System.in));
		String str="";
		str=bfr.readLine();
		StringTokenizer stk=new StringTokenizer(str, " ");
		int meisi=Integer.parseInt(stk.nextToken());
		int nisuu=Integer.parseInt(stk.nextToken());
		int hoju_min=Integer.parseInt(stk.nextToken());
		int hmi=Integer.parseInt(stk.nextToken());
		int heru=0;
		boolean kubari=true;
		for(int i=0; i<nisuu; i++) {
			str=bfr.readLine();
			if(meisi<=hoju_min) {
				meisi+=hmi;
			}
			heru=Integer.parseInt(str);
			meisi-=heru;

			if(meisi<0) {
				System.out.println(i+1);
				kubari=false;
				System.exit(0);
			}
		}
		if(kubari==true) {System.out.println("complete");}

	}
}