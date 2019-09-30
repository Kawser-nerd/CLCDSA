import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] array;
		array = br.readLine().split(" ");
		int n = Integer.parseInt(array[0]);//??????
		int l = Integer.parseInt(array[1]);//??L
		ArrayList<Integer> list = new ArrayList<Integer>();//???????

		for(String str:br.readLine().split(" ")){
			list.add(Integer.parseInt(str));
		}

		int index = -1;//???2????????L????????????

		for(int i=0;i<n-1;i++){
			if(list.get(i)+list.get(i+1) >= l){
				index = i;
				break;
			}
		}

		if(index < 0){
			System.out.println("Impossible");
		}else{
			System.out.println("Possible");
			for(int i=0;i<index;i++){
				System.out.println(i+1);//index???????
			}
			for(int i=n-1;index<i;i--){
				System.out.println(i);//index???????
			}
		}

	}
//	public static void main(String[] args) throws Exception{
//		String answerText = "Possible";
//		ArrayList<Integer> answerList = new ArrayList<Integer>();
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		String[] array;
//		array = br.readLine().split(" ");
//		int n = Integer.parseInt(array[0]);//??????
//		int l = Integer.parseInt(array[1]);//??L
//		TreeMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
//
//		int cnt = 0;
//		for(String str:br.readLine().split(" ")){
//			map.put(cnt, Integer.parseInt(str));
//			cnt++;
//		}
//
//		int total = getLength(map);
//
//		while(true){
//			if(map.size() == 1){
//				break;
//			}
//			if(total >= l){
//				int first = map.firstKey();
//				int last = map.lastKey();
//				if(map.get(first) < map.get(last)){
//					total -= map.get(first);
//					answerList.add(first+1);
//					map.remove(first);
//				}else{
//					total -= map.get(last);
//					answerList.add(last);
//					map.remove(last);
//				}
//			}else{
//				answerText = "Impossible";
//				break;
//			}
//		}
//		System.out.println(answerText);
//		if(answerText.equals("Possible")){
//			for(Integer i:answerList){
//				System.out.println(String.valueOf(i));
//			}
//		}
//	}
//
//	private static Integer getLength(TreeMap<Integer,Integer> map){
//		int ret = 0;
//
//		for(int i:map.values()){
//			ret += i;
//		}
//		return ret;
//	}
}