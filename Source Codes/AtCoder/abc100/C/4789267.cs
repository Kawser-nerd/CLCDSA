using System;

class Myon{
	static void Main(){
    	Myon myon = new Myon();
    }
  
  	public Myon(){
    	int N = int.Parse(Console.ReadLine());
      
      	string[] input = Console.ReadLine().Split(' ');
      
      	int[] nums = new int[N];
      	for(int i = 0;i < N;i ++){
        	nums[i] = int.Parse(input[i]);
        }
      	int count = 0;
      	for(int i = 0;i < N;i ++){
        	int num = nums[i];	
          int max = 1;
          int amari = num % (int)Math.Pow(2,max);
          	while(amari == 0){
            	max ++;
              amari = num % (int)Math.Pow(2,max);
              	count ++;
              	
            }
        }
      	Console.WriteLine(count);
    }
}