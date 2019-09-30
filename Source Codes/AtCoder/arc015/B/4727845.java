import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
class Main{
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int N=Integer.parseInt(br.readLine());
		int[] stat=new int[6];
		Arrays.fill(stat,0);
		for(int i=0; i<N; i++) {
			String a=br.readLine();
			//pl(a);
			String[] mn=a.split(" ");
			if(mn[0].contains(".")) {
				mn[0]=mn[0].replaceAll("\\.", "");
			}
			else {
				mn[0]=mn[0]+"0";
			}

			if(mn[1].contains(".")) {
				mn[1]=mn[1].replaceAll("\\.", "");
			}
			else {
				mn[1]=mn[1]+"0";
			}
			//pl(mn[0]+" "+mn[1]);
			if(Integer.parseInt(mn[0])>=350) {
				stat[0]++;
			}
			if(Integer.parseInt(mn[0])<350 && Integer.parseInt(mn[0])>=300) {
				stat[1]++;
			}
			if(Integer.parseInt(mn[0])<300 && Integer.parseInt(mn[0])>=250) {
				stat[2]++;
			}
			if(Integer.parseInt(mn[1])>=250) {
				stat[3]++;
			}
			if(Integer.parseInt(mn[0])>=0 && Integer.parseInt(mn[1])<0) {
				stat[4]++;
			}
			if(Integer.parseInt(mn[0])<0) {
				stat[5]++;
			}
		}
		pl(stat[0]+" "+stat[1]+" "+stat[2]+" "+stat[3]+" "+stat[4]+" "+stat[5]);
	}
	public static void pl(Object o) {
		System.out.println(o);
	}
	public static void pl() {
		System.out.println();
	}
	public static void p(Object o) {
		System.out.print(o);
	}
}