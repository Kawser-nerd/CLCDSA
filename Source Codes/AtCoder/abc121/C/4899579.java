import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// ??????
		Scanner sc = new Scanner(System.in);
		ArrayList<Data> list = new ArrayList<Data>();
		// ??????
		String[] line_list = sc.nextLine().split(" ");
		int N = Integer.parseInt(line_list[0]);
		int M = Integer.parseInt(line_list[1]);
		for(int i=0;i<N;i++) {
			line_list = sc.nextLine().split(" ");
			list.add(new Data(Long.parseLong(line_list[0]),Integer.parseInt(line_list[1])));
		}
		
		// ?????????
		list.sort((a,b)->a.compareTo(b));
		
		// ???????
		long kingaku=0;
		for(int i=0;i<list.size();i++) {
			Data data = list.get(i); 
			if(M < data.getSuryou()) {
				kingaku = kingaku + M * data.getTanka();
				break;
			}
			else {
				kingaku = kingaku + data.getSuryou() * data.getTanka();
				M = M - data.getSuryou();
			}
		}
		System.out.println(kingaku);
	}
	
	public static class Data implements Comparable<Data>{
		long tanka;
		int suryou;
		
		public Data(long p_tanka,int p_suryou){
			this.tanka=p_tanka;
			this.suryou=p_suryou;
		}
		
		@Override
		public int compareTo( Data d ){
			if(this.tanka < d.tanka) return -1;
			if(this.tanka > d.tanka) return 1;
			return 0;
		}
		  
		public long getTanka() {
			return tanka;
		}

		public void setTanka(long tanka) {
			this.tanka = tanka;
		}

		public int getSuryou() {
			return suryou;
		}

		public void setSuryou(int suryou) {
			this.suryou = suryou;
		}
	}
}