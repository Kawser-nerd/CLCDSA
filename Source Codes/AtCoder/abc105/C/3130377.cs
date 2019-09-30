using System;
using System.Collections.Generic;


public class C{
	
	public static void Main(){
	
		int n = Int32.Parse( Console.ReadLine() );
		List<int> result = new List<int>();
		
		int rest = n;
		int i = 0;
		while(true){
			if( (rest & (1 << i)) == 0 ){
				result.Add(0);
				
			}else{
				result.Add(1);
				if( (i & 1) == 0 ){
					rest -= (1 << i);
				}else{
					rest += (1 << i);
				}
				
			}
			if( rest == 0 ) break;
			i++;
		}
		
		for( int j = 0; j < result.Count; j++ ){
			Console.Write( result[result.Count - 1 - j ] );
		}
		Console.WriteLine();
		
	}

}